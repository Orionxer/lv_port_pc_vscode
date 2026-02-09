#include "rk_drm.h"
#include "lvgl/lvgl.h"

#if LV_USE_LINUX_DRM
/* RGA with DMA-BUF support */
#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <stdint.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#include <rga/rga.h>
#include <rga/RgaApi.h>
#include <rga/im2d.h>
#include <rga/RgaUtils.h>


#include <xf86drm.h>
#include <xf86drmMode.h>
#include <drm_fourcc.h>

#if LV_USE_LINUX_DRM_GBM_BUFFERS

    #include <gbm.h>
    #include <linux/dma-buf.h>
    #include <sys/ioctl.h>

#endif


/*********************
 *      DEFINES
 *********************/
#if LV_COLOR_DEPTH == 32
    #define DRM_FOURCC DRM_FORMAT_XRGB8888
#elif LV_COLOR_DEPTH == 16
    #define DRM_FOURCC DRM_FORMAT_RGB565
#else
    #error LV_COLOR_DEPTH not supported
#endif

#define BUFFER_CNT 2

/**********************
 *      MACROS
 **********************/
#ifndef DIV_ROUND_UP
    #define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#endif

#ifndef PRIu64
    #define PRIu64 "lu"
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    uint32_t handle;
    uint32_t pitch;
    uint32_t offset;
    unsigned long int size;
    uint8_t * map;
    uint32_t fb_handle;
    int prime_fd;  // DMA-BUF file descriptor for RGA
} drm_buffer_t;

/* LVGL渲染缓冲区（用于非DIRECT模式） */
typedef struct {
    uint8_t *buf1;      /* 第一个渲染缓冲区 */
    uint8_t *buf2;      /* 第二个渲染缓冲区 */
    size_t buf_size;    /* 每个缓冲区的大小 */
} lvgl_render_buf_t;

typedef struct {
    int fd;
    uint32_t conn_id, enc_id, crtc_id, plane_id, crtc_idx;
    uint32_t width, height;
    uint32_t mmWidth, mmHeight;
    uint32_t fourcc;
    drmModeModeInfo mode;
    uint32_t blob_id;
    drmModeCrtc * saved_crtc;
    drmModeAtomicReq * req;
    drmEventContext drm_event_ctx;
    drmModePlane * plane;
    drmModeCrtc * crtc;
    drmModeConnector * conn;
    uint32_t count_plane_props;
    uint32_t count_crtc_props;
    uint32_t count_conn_props;
    drmModePropertyPtr plane_props[128];
    drmModePropertyPtr crtc_props[128];
    drmModePropertyPtr conn_props[128];
    drm_buffer_t drm_bufs[BUFFER_CNT];
    drm_buffer_t * act_buf;
    lvgl_render_buf_t render_buf;  /* LVGL渲染缓冲区 */
    uint32_t current_buf_idx;      /* 当前显示的buffer索引 */
    bo_t rga_bo;                   /* RGA buffer对象 */
    int rga_bo_fd;                 /* RGA buffer的文件描述符 */
    uint8_t *rga_buf_ptr;          /* RGA缓冲区虚拟地址 */
    size_t rga_buf_size;           /* RGA缓冲区大小 */
    bo_t bo_src;                    /* RGA源图像信息 */
    bo_t bo_dst;                    /* RGA目标图像信息 */
    rga_info_t rga_src_info;        /* RGA源图像结构体 */
    rga_info_t rga_dst_info;        /* RGA目标图像结构体 */
} drm_dev_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static uint32_t get_plane_property_id(drm_dev_t * drm_dev, const char * name);
static uint32_t get_crtc_property_id(drm_dev_t * drm_dev, const char * name);
static uint32_t get_conn_property_id(drm_dev_t * drm_dev, const char * name);
static void page_flip_handler(int fd, unsigned int sequence, unsigned int tv_sec, unsigned int tv_usec,
                              void * user_data);
static int drm_get_plane_props(drm_dev_t * drm_dev);
static int drm_get_crtc_props(drm_dev_t * drm_dev);
static int drm_get_conn_props(drm_dev_t * drm_dev);
static int drm_add_plane_property(drm_dev_t * drm_dev, const char * name, uint64_t value);
static int drm_add_crtc_property(drm_dev_t * drm_dev, const char * name, uint64_t value);
static int drm_add_conn_property(drm_dev_t * drm_dev, const char * name, uint64_t value);
static int find_plane(drm_dev_t * drm_dev, unsigned int fourcc, uint32_t * plane_id, uint32_t crtc_id,
                      uint32_t crtc_idx);
static int drm_find_connector(drm_dev_t * drm_dev, int64_t connector_id);
static int drm_open(const char * path);
static int drm_setup(drm_dev_t * drm_dev, const char * device_path, int64_t connector_id, unsigned int fourcc);
static int drm_allocate_dumb(drm_dev_t * drm_dev, drm_buffer_t * buf);
static int drm_setup_buffers(drm_dev_t * drm_dev);
static void drm_dmabuf_set_active_buf(lv_event_t * event);
static uint32_t tick_get_cb(void);
static int drm_dmabuf_set_plane(drm_dev_t * drm_dev, drm_buffer_t * buf);
static void drm_flush_wait(lv_display_t * disp);
static void drm_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);
void lv_linux_drm_set_file(lv_display_t * disp, const char * file, int64_t connector_id);

lv_display_t * drm_create(void)
{
    lv_tick_set_cb(tick_get_cb);

    drm_dev_t * drm_dev = (drm_dev_t *)lv_malloc_zeroed(sizeof(drm_dev_t));
    LV_ASSERT_MALLOC(drm_dev);
    if(drm_dev == NULL) return NULL;
    // 启动时用最小尺寸初始化，后续由 DRM 自动设置分辨率
    lv_display_t * disp = lv_display_create(1, 1);
    if(disp == NULL) {
        lv_free(drm_dev);
        return NULL;
    }
    drm_dev->fd = -1;
    lv_display_set_driver_data(disp, drm_dev);
    lv_display_set_flush_wait_cb(disp, drm_flush_wait);
    lv_display_set_flush_cb(disp, drm_flush);


    return disp;
}

// 正确的RGA加速示例
void rga_test(drm_dev_t * drm_dev, int width,int height,int format, uint8_t *src_ptr, uint8_t *dst_ptr)
{
    // printf("######################################################\n"); 
    int ret = 0;
#if 0
	bo_t bo_src, bo_dst;

    // 已经初始化过了
	// c_RkRgaInit();
	/********** apply for src buffer and dst buffer **********/
    //char* buf = NULL;
    // int bits = (format == RK_FORMAT_RGB_565) ? 16 : 32;
    // ! 不能传入16，否则RGA一直提示 Rga err irq! INT[701],STATS[0]
    int bits = 32;
    printf("rga_test: width=%d height=%d format=%d bits=%d\n",width,height,format,bits);
	ret = c_RkRgaGetAllocBuffer(&bo_src, width, height, bits);
	ret = c_RkRgaGetAllocBuffer(&bo_dst, width, height, bits);

	/********** map buffer_address to userspace **********/
	c_RkRgaGetMmap(&bo_src);
	c_RkRgaGetMmap(&bo_dst);
#endif

	/********** read data from *.bin file **********/   
#if 0
    get_buf_from_file(bo_src.ptr, format, width, height, 0);
#else
    // int bytes_per_pixel = 4;
    // memset(bo_src.ptr,0x55,bytes_per_pixel*width*height);
    if(src_ptr) {
        memcpy(drm_dev->bo_src.ptr, src_ptr, 4 * width * height);
    } else {
        return;
    }
#endif

    // ****** 关键修复：打印DRM返回的实际pitch ******
    printf("bo_src.pitch=%zu bytes, bo_dst.pitch=%zu bytes\n", drm_dev->bo_src.pitch, drm_dev->bo_dst.pitch);

    rga_info_t src;
    rga_info_t dst;
    
    memset(&src, 0, sizeof(rga_info_t));
    src.fd = -1;
    src.mmuFlag = 1;
    
    memset(&dst, 0, sizeof(rga_info_t));
    dst.fd = -1;
    dst.mmuFlag = 1;
    
    /********** get src_Fd **********/
    ret = c_RkRgaGetBufferFd(&drm_dev->bo_src, &src.fd);
    printf("src.fd =%d \n",src.fd);
    if (ret) {
        printf("rgaGetsrcFd fail : %s\n", strerror(errno));
    }
    /********** get dst_Fd **********/
    ret = c_RkRgaGetBufferFd(&drm_dev->bo_dst, &dst.fd);
    printf("dst.fd =%d \n",dst.fd);
    if (ret) {
        printf("rgaGetdstFd error : %s\n", strerror(errno));
    }
    /********** if not fd, try to check phyAddr and virAddr **************/
    if(src.fd <= 0|| dst.fd <= 0)
    {
    /********** check phyAddr and virAddr ,if none to get virAddr **********/
        if (( src.phyAddr != 0 || src.virAddr != 0 ) || src.hnd != 0 ){
            //ret = RkRgaGetHandleMapAddress( gbs->handle, &src.virAddr );
            printf("src.virAddr =%p\n",src.virAddr);
            if(!src.virAddr){
                printf("err! src has not fd and address for render ,Stop!\n");
                return;
            }
        }
        
        /********** check phyAddr and virAddr ,if none to get virAddr **********/
        if (( dst.phyAddr != 0 || dst.virAddr != 0 ) || dst.hnd != 0 ){
            //ret = RkRgaGetHandleMapAddress( gbd->handle, &dst.virAddr );
            printf("dst.virAddr =%p\n",dst.virAddr);
            if(!dst.virAddr){
                printf("err! dst has not fd and address for render ,Stop!\n");
                return;
            }		
        }
    }
    /********** set the rect_info **********/
    rga_set_rect(&src.rect, 0,0,width,height,width/*stride*/,height,format);
    rga_set_rect(&dst.rect, 0,0,width,height,width/*stride*/,height,format);
    
    /************ set the rga_mod ,rotation\composition\scale\copy .... **********/
    if (dst_ptr) {
        memcpy(dst_ptr, drm_dev->bo_dst.ptr, 4 * width * height);
    }else {
        printf("err! dst_ptr is NULL ,Stop!\n");
        return;
    }
    /********** call rga_Interface **********/
    struct timeval tpend1, tpend2;
    long usec1 = 0;
    gettimeofday(&tpend1, NULL);
    ret = c_RkRgaBlit(&src, &dst, NULL);
    gettimeofday(&tpend2, NULL);
    usec1 = 1000 * (tpend2.tv_sec - tpend1.tv_sec) + (tpend2.tv_usec - tpend1.tv_usec) / 1000;
    printf("cost_time=%ld ms\n", usec1);
    if (ret) {
        printf("rgaFillColor error : %s\n",
                                        strerror(errno));
    }
    // printf("######################################################\n"); 
}

#if LV_USE_LINUX_DRM_RGA_FLUSH
void rga_flush(drm_dev_t * drm_dev, int width,int height,int format, uint8_t *src_ptr, uint8_t *dst_ptr)
{
#if 0 // 软件拷贝
    if (src_ptr == NULL || dst_ptr == NULL)
    {
        printf("err! src_ptr or dst_ptr is NULL ,Stop!\n");
        return;
    }
    memcpy(drm_dev->bo_src.ptr, src_ptr, 2 * width * height);
    rga_info_t *src = &drm_dev->rga_src_info;
    rga_info_t *dst = &drm_dev->rga_dst_info;
    rga_set_rect(&src->rect, 0,0,width,height,width/*stride*/,height,format);
    rga_set_rect(&dst->rect, 0,0,width,height,width/*stride*/,height,format);
    int ret = c_RkRgaBlit(src, dst, NULL);
    if (ret)
    {
        printf("rgaFillColor error : %s\n", strerror(errno));
        return;
    }
    memcpy(dst_ptr, drm_dev->bo_dst.ptr, 2 * width * height);
#else
    // ** 使用DMA-BUF方式进行RGA加速
    /* 查找 DST DMA-BUF FD */
    int dst_fd = -1;
    for (int i = 0; i < BUFFER_CNT; i++) {
        if (drm_dev->drm_bufs[i].map == dst_ptr) {
            dst_fd = drm_dev->drm_bufs[i].prime_fd;
            break;
        }
    }

    if(dst_fd < 0) {
        LV_LOG_ERROR("rga_flush: destination buffer fd not found");
        return;
    }

    rga_info_t src = {0};
    rga_info_t dst = {0};
#if LV_COLOR_DEPTH == 16
    // ! 这是RGA的Bug，即便是RGB565格式，RGA分配buffer时也必须使用32位对齐，否则显示异常
    #error "无法在RGB565格式下使用RGA加速，请切换到32位色深或禁用RGA加速"
#endif
    src.fd = -1;
    // static uint8_t test_data[480*800*4] = {0}; // 32bit对齐的缓冲区
    // memcpy(test_data, src_ptr, 2 * width * height);
    /* 配置源 (Virtual Address, LVGL Render Buffer) */
    // RGA 参考工程路径 /home/orionxer/tspi/sdk/Release/external/linux-rga
    src.virAddr = src_ptr;
    src.mmuFlag = 1;
    /* 使用全屏 stride */
    // rga_set_rect(&src.rect, x, y, w, h, drm_dev->width, drm_dev->height, format);
    rga_set_rect(&src.rect, 0, 0, width, height, drm_dev->width, drm_dev->height, format);

    /* 配置目标 (DMA-BUF FD, DRM Dumb Buffer) */
    dst.fd = dst_fd;
    dst.mmuFlag = 1; 
    /* 使用全屏 stride */
    // rga_set_rect(&dst.rect, x, y, w, h, drm_dev->width, drm_dev->height, format);
    rga_set_rect(&dst.rect, 0, 0, width, height, drm_dev->width, drm_dev->height, format);
    /* 执行 RGA Blit */
    if (c_RkRgaBlit(&src, &dst, NULL) < 0) {
        LV_LOG_ERROR("c_RkRgaBlit failed: %s", strerror(errno));
    }
#endif
}
#endif
void rk_drm_init(void)
{
#if LV_USE_LINUX_DRM_RGA
    c_RkRgaInit();  // 初始化RGA
    printf("%s\n", querystring(RGA_EXPECTED));  // 打印版本信息
#endif
#if 0 // 正确的RGA加速示例
    rga_test(480, 800, RK_FORMAT_RGB_565);
    // 主动结束，RGA测试完成删除
    return;
#endif
    // 参考链接 https://docs.lvgl.io/master/integration/embedded_linux/drivers/drm.html
    /* DRM device node */
    const char *device = "/dev/dri/card0";

    /* Create a DRM display */
    lv_display_t *disp = drm_create();

    /* Set DRM device file and connector */
    /* The 2nd argument is the DRM device path */
    /* The 3rd argument is the connector_id (-1 = auto-select first available) */
    lv_linux_drm_set_file(disp, device, -1);
#if LV_USE_LINUX_DRM_RGA
    // 初始化bo_src和bo_dst
    drm_dev_t * drm_dev = (drm_dev_t *)lv_display_get_driver_data(disp);
    // ! 即便是RGB565格式，RGA分配buffer时也必须使用32位对齐，否则RGA会报错
    int bits = 32;
    // printf("rga_test: width=%d height=%d format=%d bits=%d\n", width, height, format, bits);
    c_RkRgaGetAllocBuffer(&drm_dev->bo_src, 480, 800, bits);
    c_RkRgaGetAllocBuffer(&drm_dev->bo_dst, 480, 800, bits);

    /********** map buffer_address to userspace **********/
    c_RkRgaGetMmap(&drm_dev->bo_src);
    c_RkRgaGetMmap(&drm_dev->bo_dst);
    rga_info_t *src = &drm_dev->rga_src_info;
    rga_info_t *dst = &drm_dev->rga_dst_info;
    int ret = 0;
    memset(src, 0, sizeof(rga_info_t));
    src->fd = -1;
    src->mmuFlag = 1;
    
    memset(dst, 0, sizeof(rga_info_t));
    dst->fd = -1;
    dst->mmuFlag = 1;
    
    /********** get src_Fd **********/
    ret = c_RkRgaGetBufferFd(&drm_dev->bo_src, &src->fd);
    printf("src.fd =%d \n",src->fd);
    if (ret) {
        printf("rgaGetsrcFd fail : %s\n", strerror(errno));
    }
    /********** get dst_Fd **********/
    ret = c_RkRgaGetBufferFd(&drm_dev->bo_dst, &dst->fd);
    printf("dst.fd =%d \n",dst->fd);
    if (ret) {
        printf("rgaGetdstFd error : %s\n", strerror(errno));
    }
    /********** if not fd, try to check phyAddr and virAddr **************/
    if(src->fd <= 0|| dst->fd <= 0)
    {
    /********** check phyAddr and virAddr ,if none to get virAddr **********/
        if (( src->phyAddr != 0 || src->virAddr != 0 ) || src->hnd != 0 ){
            //ret = RkRgaGetHandleMapAddress( gbs->handle, &src->virAddr );
            printf("src.virAddr =%p\n",src->virAddr);
            if(!src->virAddr){
                printf("err! src has not fd and address for render ,Stop!\n");
                return;
            }
        }
        
        /********** check phyAddr and virAddr ,if none to get virAddr **********/
        if (( dst->phyAddr != 0 || dst->virAddr != 0 ) || dst->hnd != 0 ){
            //ret = RkRgaGetHandleMapAddress( gbd->handle, &dst->virAddr );
            printf("dst.virAddr =%p\n",dst->virAddr);
            if(!dst->virAddr){
                printf("err! dst has not fd and address for render ,Stop!\n");
                return;
            }		
        }
    }
#endif
}

void rk_drm_deinit(void)
{
#if LV_USE_LINUX_DRM_RGA
    c_RkRgaDeInit();
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static uint32_t get_plane_property_id(drm_dev_t * drm_dev, const char * name)
{
    uint32_t i;

    LV_LOG_TRACE("Find plane property: %s", name);

    for(i = 0; i < drm_dev->count_plane_props; ++i)
        if(!lv_strcmp(drm_dev->plane_props[i]->name, name))
            return drm_dev->plane_props[i]->prop_id;

    LV_LOG_TRACE("Unknown plane property: %s", name);

    return 0;
}

static uint32_t get_crtc_property_id(drm_dev_t * drm_dev, const char * name)
{
    uint32_t i;

    LV_LOG_TRACE("Find crtc property: %s", name);

    for(i = 0; i < drm_dev->count_crtc_props; ++i)
        if(!lv_strcmp(drm_dev->crtc_props[i]->name, name))
            return drm_dev->crtc_props[i]->prop_id;

    LV_LOG_TRACE("Unknown crtc property: %s", name);

    return 0;
}

static uint32_t get_conn_property_id(drm_dev_t * drm_dev, const char * name)
{
    uint32_t i;

    LV_LOG_TRACE("Find conn property: %s", name);

    for(i = 0; i < drm_dev->count_conn_props; ++i)
        if(!lv_strcmp(drm_dev->conn_props[i]->name, name))
            return drm_dev->conn_props[i]->prop_id;

    LV_LOG_TRACE("Unknown conn property: %s", name);

    return 0;
}

static void page_flip_handler(int fd, unsigned int sequence, unsigned int tv_sec, unsigned int tv_usec,
                              void * user_data)
{
    LV_UNUSED(fd);
    LV_UNUSED(sequence);
    LV_UNUSED(tv_sec);
    LV_UNUSED(tv_usec);
    LV_LOG_TRACE("flip");
    drm_dev_t * drm_dev = (drm_dev_t *)user_data;
    if(drm_dev->req) {
        drmModeAtomicFree(drm_dev->req);
        drm_dev->req = NULL;
    }
}

static int drm_get_plane_props(drm_dev_t * drm_dev)
{
    uint32_t i;

    drmModeObjectPropertiesPtr props = drmModeObjectGetProperties(drm_dev->fd, drm_dev->plane_id,
                                                                  DRM_MODE_OBJECT_PLANE);
    if(!props) {
        LV_LOG_ERROR("drmModeObjectGetProperties failed");
        return -1;
    }
    LV_LOG_TRACE("Found %u plane props", props->count_props);
    drm_dev->count_plane_props = props->count_props;
    for(i = 0; i < props->count_props; i++) {
        drm_dev->plane_props[i] = drmModeGetProperty(drm_dev->fd, props->props[i]);
        LV_LOG_TRACE("Added plane prop %u:%s", drm_dev->plane_props[i]->prop_id, drm_dev->plane_props[i]->name);
    }
    drmModeFreeObjectProperties(props);

    return 0;
}

static int drm_get_crtc_props(drm_dev_t * drm_dev)
{
    uint32_t i;

    drmModeObjectPropertiesPtr props = drmModeObjectGetProperties(drm_dev->fd, drm_dev->crtc_id,
                                                                  DRM_MODE_OBJECT_CRTC);
    if(!props) {
        LV_LOG_ERROR("drmModeObjectGetProperties failed");
        return -1;
    }
    LV_LOG_TRACE("Found %u crtc props", props->count_props);
    drm_dev->count_crtc_props = props->count_props;
    for(i = 0; i < props->count_props; i++) {
        drm_dev->crtc_props[i] = drmModeGetProperty(drm_dev->fd, props->props[i]);
        LV_LOG_TRACE("Added crtc prop %u:%s", drm_dev->crtc_props[i]->prop_id, drm_dev->crtc_props[i]->name);
    }
    drmModeFreeObjectProperties(props);

    return 0;
}

static int drm_get_conn_props(drm_dev_t * drm_dev)
{
    uint32_t i;

    drmModeObjectPropertiesPtr props = drmModeObjectGetProperties(drm_dev->fd, drm_dev->conn_id,
                                                                  DRM_MODE_OBJECT_CONNECTOR);
    if(!props) {
        LV_LOG_ERROR("drmModeObjectGetProperties failed");
        return -1;
    }
    LV_LOG_TRACE("Found %u connector props", props->count_props);
    drm_dev->count_conn_props = props->count_props;
    for(i = 0; i < props->count_props; i++) {
        drm_dev->conn_props[i] = drmModeGetProperty(drm_dev->fd, props->props[i]);
        LV_LOG_TRACE("Added connector prop %u:%s", drm_dev->conn_props[i]->prop_id, drm_dev->conn_props[i]->name);
    }
    drmModeFreeObjectProperties(props);

    return 0;
}

static int drm_add_plane_property(drm_dev_t * drm_dev, const char * name, uint64_t value)
{
    int ret;
    uint32_t prop_id = get_plane_property_id(drm_dev, name);

    if(!prop_id) {
        LV_LOG_ERROR("Couldn't find plane prop %s", name);
        return -1;
    }

    ret = drmModeAtomicAddProperty(drm_dev->req, drm_dev->plane_id, get_plane_property_id(drm_dev, name), value);
    if(ret < 0) {
        LV_LOG_ERROR("drmModeAtomicAddProperty (%s:%" PRIu64 ") failed: %d", name, value, ret);
        return ret;
    }

    return 0;
}

static int drm_add_crtc_property(drm_dev_t * drm_dev, const char * name, uint64_t value)
{
    int ret;
    uint32_t prop_id = get_crtc_property_id(drm_dev, name);

    if(!prop_id) {
        LV_LOG_ERROR("Couldn't find crtc prop %s", name);
        return -1;
    }

    ret = drmModeAtomicAddProperty(drm_dev->req, drm_dev->crtc_id, get_crtc_property_id(drm_dev, name), value);
    if(ret < 0) {
        LV_LOG_ERROR("drmModeAtomicAddProperty (%s:%" PRIu64 ") failed: %d", name, value, ret);
        return ret;
    }

    return 0;
}

static int drm_add_conn_property(drm_dev_t * drm_dev, const char * name, uint64_t value)
{
    int ret;
    uint32_t prop_id = get_conn_property_id(drm_dev, name);

    if(!prop_id) {
        LV_LOG_ERROR("Couldn't find conn prop %s", name);
        return -1;
    }

    ret = drmModeAtomicAddProperty(drm_dev->req, drm_dev->conn_id, get_conn_property_id(drm_dev, name), value);
    if(ret < 0) {
        LV_LOG_ERROR("drmModeAtomicAddProperty (%s:%" PRIu64 ") failed: %d", name, value, ret);
        return ret;
    }

    return 0;
}

static int find_plane(drm_dev_t * drm_dev, unsigned int fourcc, uint32_t * plane_id, uint32_t crtc_id,
                      uint32_t crtc_idx)
{
    LV_UNUSED(crtc_id);
    drmModePlaneResPtr planes;
    drmModePlanePtr plane;
    unsigned int i;
    unsigned int j;
    int ret = 0;
    unsigned int format = fourcc;

    planes = drmModeGetPlaneResources(drm_dev->fd);
    if(!planes) {
        LV_LOG_ERROR("drmModeGetPlaneResources failed");
        return -1;
    }

    LV_LOG_TRACE("drm: found planes %u", planes->count_planes);

    for(i = 0; i < planes->count_planes; ++i) {
        plane = drmModeGetPlane(drm_dev->fd, planes->planes[i]);
        if(!plane) {
            LV_LOG_ERROR("drmModeGetPlane failed: %s", strerror(errno));
            break;
        }

        if(!(plane->possible_crtcs & (1 << crtc_idx))) {
            drmModeFreePlane(plane);
            continue;
        }

        for(j = 0; j < plane->count_formats; ++j) {
            if(plane->formats[j] == format)
                break;
        }

        if(j == plane->count_formats) {
            drmModeFreePlane(plane);
            continue;
        }

        *plane_id = plane->plane_id;
        drmModeFreePlane(plane);

        LV_LOG_TRACE("found plane %d", *plane_id);

        break;
    }

    if(i == planes->count_planes)
        ret = -1;

    drmModeFreePlaneResources(planes);

    return ret;
}

static int drm_find_connector(drm_dev_t * drm_dev, int64_t connector_id)
{
    drmModeConnector * conn = NULL;
    drmModeEncoder * enc = NULL;
    drmModeRes * res;
    int i;

    if((res = drmModeGetResources(drm_dev->fd)) == NULL) {
        LV_LOG_ERROR("drmModeGetResources() failed");
        return -1;
    }

    if(res->count_crtcs <= 0) {
        LV_LOG_ERROR("no Crtcs");
        goto free_res;
    }

    /* find all available connectors */
    for(i = 0; i < res->count_connectors; i++) {
        conn = drmModeGetConnector(drm_dev->fd, res->connectors[i]);
        if(!conn)
            continue;

        if(connector_id >= 0 && conn->connector_id != connector_id) {
            drmModeFreeConnector(conn);
            continue;
        }

        if(conn->connection == DRM_MODE_CONNECTED) {
            LV_LOG_TRACE("drm: connector %d: connected", conn->connector_id);
        }
        else if(conn->connection == DRM_MODE_DISCONNECTED) {
            LV_LOG_TRACE("drm: connector %d: disconnected", conn->connector_id);
        }
        else if(conn->connection == DRM_MODE_UNKNOWNCONNECTION) {
            LV_LOG_TRACE("drm: connector %d: unknownconnection", conn->connector_id);
        }
        else {
            LV_LOG_TRACE("drm: connector %d: unknown", conn->connector_id);
        }

        if(conn->connection == DRM_MODE_CONNECTED && conn->count_modes > 0)
            break;

        drmModeFreeConnector(conn);
        conn = NULL;
    };

    if(!conn) {
        LV_LOG_ERROR("suitable connector not found");
        goto free_res;
    }

    drm_dev->conn_id = conn->connector_id;
    LV_LOG_TRACE("conn_id: %d", drm_dev->conn_id);
    drm_dev->mmWidth = conn->mmWidth;
    drm_dev->mmHeight = conn->mmHeight;

    lv_memcpy(&drm_dev->mode, &conn->modes[0], sizeof(drmModeModeInfo));

    if(drmModeCreatePropertyBlob(drm_dev->fd, &drm_dev->mode, sizeof(drm_dev->mode),
                                 &drm_dev->blob_id)) {
        LV_LOG_ERROR("error creating mode blob");
        goto free_res;
    }

    drm_dev->width = conn->modes[0].hdisplay;
    drm_dev->height = conn->modes[0].vdisplay;

    for(i = 0 ; i < res->count_encoders; i++) {
        enc = drmModeGetEncoder(drm_dev->fd, res->encoders[i]);
        if(!enc)
            continue;

        LV_LOG_TRACE("enc%d enc_id %d conn enc_id %d", i, enc->encoder_id, conn->encoder_id);

        if(enc->encoder_id == conn->encoder_id)
            break;

        drmModeFreeEncoder(enc);
        enc = NULL;
    }

    if(enc) {
        drm_dev->enc_id = enc->encoder_id;
        LV_LOG_TRACE("enc_id: %d", drm_dev->enc_id);
        drm_dev->crtc_id = enc->crtc_id;
        LV_LOG_TRACE("crtc_id: %d", drm_dev->crtc_id);
        drmModeFreeEncoder(enc);
    }
    else {
        /* Encoder hasn't been associated yet, look it up */
        for(i = 0; i < conn->count_encoders; i++) {
            int crtc, crtc_id = -1;

            enc = drmModeGetEncoder(drm_dev->fd, conn->encoders[i]);
            if(!enc)
                continue;

            for(crtc = 0 ; crtc < res->count_crtcs; crtc++) {
                uint32_t crtc_mask = 1 << crtc;

                crtc_id = res->crtcs[crtc];

                LV_LOG_TRACE("enc_id %d crtc%d id %d mask %x possible %x", enc->encoder_id, crtc, crtc_id, crtc_mask,
                             enc->possible_crtcs);

                if(enc->possible_crtcs & crtc_mask)
                    break;
            }

            if(crtc_id > 0) {
                drm_dev->enc_id = enc->encoder_id;
                LV_LOG_TRACE("enc_id: %d", drm_dev->enc_id);
                drm_dev->crtc_id = crtc_id;
                LV_LOG_TRACE("crtc_id: %d", drm_dev->crtc_id);
                break;
            }

            drmModeFreeEncoder(enc);
            enc = NULL;
        }

        if(!enc) {
            LV_LOG_ERROR("suitable encoder not found");
            goto free_res;
        }

        drmModeFreeEncoder(enc);
    }

    drm_dev->crtc_idx = UINT32_MAX;

    for(i = 0; i < res->count_crtcs; ++i) {
        if(drm_dev->crtc_id == res->crtcs[i]) {
            drm_dev->crtc_idx = i;
            break;
        }
    }

    if(drm_dev->crtc_idx == UINT32_MAX) {
        LV_LOG_ERROR("drm: CRTC not found");
        goto free_res;
    }

    LV_LOG_TRACE("crtc_idx: %d", drm_dev->crtc_idx);

    return 0;

free_res:
    drmModeFreeResources(res);

    return -1;
}

static int drm_open(const char * path)
{
    int fd, flags;
    uint64_t has_dumb;
    int ret;

    fd = open(path, O_RDWR);
    if(fd < 0) {
        LV_LOG_ERROR("cannot open \"%s\"", path);
        return -1;
    }

    /* set FD_CLOEXEC flag */
    if((flags = fcntl(fd, F_GETFD)) < 0 ||
       fcntl(fd, F_SETFD, flags | FD_CLOEXEC) < 0) {
        LV_LOG_ERROR("fcntl FD_CLOEXEC failed");
        goto err;
    }

    /* check capability */
    ret = drmGetCap(fd, DRM_CAP_DUMB_BUFFER, &has_dumb);
    if(ret < 0 || has_dumb == 0) {
        LV_LOG_ERROR("drmGetCap DRM_CAP_DUMB_BUFFER failed or \"%s\" doesn't have dumb "
                     "buffer", path);
        goto err;
    }

    return fd;
err:
    close(fd);
    return -1;
}

static int drm_setup(drm_dev_t * drm_dev, const char * device_path, int64_t connector_id, unsigned int fourcc)
{
    int ret;

    drm_dev->fd = drm_open(device_path);
    if(drm_dev->fd < 0)
        return -1;

    ret = drmSetClientCap(drm_dev->fd, DRM_CLIENT_CAP_ATOMIC, 1);
    if(ret) {
        LV_LOG_ERROR("No atomic modesetting support: %s", strerror(errno));
        goto err;
    }

    ret = drm_find_connector(drm_dev, connector_id);
    if(ret) {
        LV_LOG_ERROR("available drm devices not found");
        goto err;
    }

    ret = find_plane(drm_dev, fourcc, &drm_dev->plane_id, drm_dev->crtc_id, drm_dev->crtc_idx);
    if(ret) {
        LV_LOG_ERROR("Cannot find plane");
        goto err;
    }

    drm_dev->plane = drmModeGetPlane(drm_dev->fd, drm_dev->plane_id);
    if(!drm_dev->plane) {
        LV_LOG_ERROR("Cannot get plane");
        goto err;
    }

    drm_dev->crtc = drmModeGetCrtc(drm_dev->fd, drm_dev->crtc_id);
    if(!drm_dev->crtc) {
        LV_LOG_ERROR("Cannot get crtc");
        goto err;
    }

    drm_dev->conn = drmModeGetConnector(drm_dev->fd, drm_dev->conn_id);
    if(!drm_dev->conn) {
        LV_LOG_ERROR("Cannot get connector");
        goto err;
    }

    ret = drm_get_plane_props(drm_dev);
    if(ret) {
        LV_LOG_ERROR("Cannot get plane props");
        goto err;
    }

    ret = drm_get_crtc_props(drm_dev);
    if(ret) {
        LV_LOG_ERROR("Cannot get crtc props");
        goto err;
    }

    ret = drm_get_conn_props(drm_dev);
    if(ret) {
        LV_LOG_ERROR("Cannot get connector props");
        goto err;
    }

    drm_dev->drm_event_ctx.version = DRM_EVENT_CONTEXT_VERSION;
    drm_dev->drm_event_ctx.page_flip_handler = page_flip_handler;
    drm_dev->fourcc = fourcc;
    // 自动获取的宽和高
    LV_LOG_INFO("DRM display resolution is %ux%u", drm_dev->width, drm_dev->height);

    LV_LOG_INFO("drm: Found plane_id: %u connector_id: %d crtc_id: %d",
                drm_dev->plane_id, drm_dev->conn_id, drm_dev->crtc_id);

    LV_LOG_INFO("drm: %dx%d (%dmm X% dmm) pixel format %c%c%c%c",
                drm_dev->width, drm_dev->height, drm_dev->mmWidth, drm_dev->mmHeight,
                (fourcc >> 0) & 0xff, (fourcc >> 8) & 0xff, (fourcc >> 16) & 0xff, (fourcc >> 24) & 0xff);

    return 0;

err:
    close(drm_dev->fd);
    return -1;
}

static int drm_allocate_dumb(drm_dev_t * drm_dev, drm_buffer_t * buf)
{
    struct drm_mode_create_dumb creq;
    struct drm_mode_map_dumb mreq;
    uint32_t handles[4] = {0}, pitches[4] = {0}, offsets[4] = {0};
    int ret;

    /* create dumb buffer */
    lv_memzero(&creq, sizeof(creq));
    creq.width = drm_dev->width;
    creq.height = drm_dev->height;
    creq.bpp = LV_COLOR_DEPTH;
    ret = drmIoctl(drm_dev->fd, DRM_IOCTL_MODE_CREATE_DUMB, &creq);
    if(ret < 0) {
        LV_LOG_ERROR("DRM_IOCTL_MODE_CREATE_DUMB fail");
        return -1;
    }

    buf->handle = creq.handle;
    buf->pitch = creq.pitch;
    buf->size = creq.size;

    /* prepare buffer for memory mapping */
    lv_memzero(&mreq, sizeof(mreq));
    mreq.handle = creq.handle;
    ret = drmIoctl(drm_dev->fd, DRM_IOCTL_MODE_MAP_DUMB, &mreq);
    if(ret) {
        LV_LOG_ERROR("DRM_IOCTL_MODE_MAP_DUMB fail");
        return -1;
    }

    buf->offset = mreq.offset;
    LV_LOG_INFO("size %lu pitch %u offset %u", buf->size, buf->pitch, buf->offset);

    /* perform actual memory mapping */
    buf->map = (uint8_t *)mmap(0, creq.size, PROT_READ | PROT_WRITE, MAP_SHARED, drm_dev->fd, mreq.offset);
    if(buf->map == MAP_FAILED) {
        LV_LOG_ERROR("mmap fail");
        return -1;
    }

    /* clear the framebuffer to 0 (= full transparency in ARGB8888) */
    lv_memzero(buf->map, creq.size);

    /* create framebuffer object for the dumb-buffer */
    handles[0] = creq.handle;
    pitches[0] = creq.pitch;
    offsets[0] = 0;
    ret = drmModeAddFB2(drm_dev->fd, drm_dev->width, drm_dev->height, drm_dev->fourcc,
                        handles, pitches, offsets, &buf->fb_handle, 0);
    if(ret) {
        LV_LOG_ERROR("drmModeAddFB fail");
        return -1;
    }

    /* Export dumb buffer as DMA-BUF for RGA access */
    ret = drmPrimeHandleToFD(drm_dev->fd, creq.handle, 0, &buf->prime_fd);
    if(ret) {
        LV_LOG_ERROR("drmPrimeHandleToFD failed");
        return -1;
    }
    LV_LOG_TRACE("Exported DRM buffer as prime_fd=%d", buf->prime_fd);

    return 0;
}

static int drm_setup_buffers(drm_dev_t * drm_dev)
{
    int ret;

    /* Use dumb buffers */
    ret = drm_allocate_dumb(drm_dev, &drm_dev->drm_bufs[0]);
    if(ret)
        return ret;

    ret = drm_allocate_dumb(drm_dev, &drm_dev->drm_bufs[1]);
    if(ret)
        return ret;

    /* 初始化当前显示buffer索引为buffer 0 */
    drm_dev->current_buf_idx = 0;

    return 0;
}

static void drm_dmabuf_set_active_buf(lv_event_t * event)
{
    drm_dev_t * drm_dev;
    lv_display_t * disp;
    lv_draw_buf_t * act_buf;
    int i;

    disp = (lv_display_t *) lv_event_get_current_target(event);
    drm_dev = (drm_dev_t *) lv_display_get_driver_data(disp);
    act_buf = lv_display_get_buf_active(disp);

    if(drm_dev->act_buf == NULL) {

        for(i = 0; i < BUFFER_CNT; i++) {
            if(act_buf->unaligned_data == drm_dev->drm_bufs[i].map) {
                drm_dev->act_buf = &drm_dev->drm_bufs[i];
                LV_LOG_TRACE("Set active buffer idx: %d", i);
                break;
            }
        }
    }
    else {
        LV_LOG_TRACE("active buffer already set");
    }
}

void lv_linux_drm_set_file(lv_display_t * disp, const char * file, int64_t connector_id)
{
    drm_dev_t * drm_dev = (drm_dev_t *)lv_display_get_driver_data(disp);
    int ret;

    ret = drm_setup(drm_dev, file, connector_id, DRM_FOURCC);
    if(ret) {
        close(drm_dev->fd);
        drm_dev->fd = -1;
        return;
    }

    ret = drm_setup_buffers(drm_dev);
    if(ret) {
        LV_LOG_ERROR("DRM buffer allocation failed");
        close(drm_dev->fd);
        drm_dev->fd = -1;
        return;
    }

    LV_LOG_INFO("DRM subsystem and buffer mapped successfully");

    int32_t hor_res = drm_dev->width;
    int32_t ver_res = drm_dev->height;
    int32_t width = drm_dev->mmWidth;
#if LV_USE_LINUX_DRM_RGA
    /* 设置分辨率 */
    lv_display_set_resolution(disp, hor_res, ver_res);
    /* 分配LVGL渲染缓冲区（用于非DIRECT模式） */
    /* 计算需要的缓冲区大小 */
    lv_color_format_t format = (LV_COLOR_DEPTH == 16) ? LV_COLOR_FORMAT_RGB565 : LV_COLOR_FORMAT_ARGB8888;
    drm_dev->render_buf.buf_size = hor_res * ver_res * LV_COLOR_FORMAT_GET_SIZE(format);
    /* 使用LVGL的内存分配器分配两个缓冲区 */
    drm_dev->render_buf.buf1 = (uint8_t *)lv_malloc(drm_dev->render_buf.buf_size);
    drm_dev->render_buf.buf2 = (uint8_t *)lv_malloc(drm_dev->render_buf.buf_size);

    if(!drm_dev->render_buf.buf1 || !drm_dev->render_buf.buf2) {
        LV_LOG_ERROR("Failed to allocate LVGL render buffers");
        if(drm_dev->render_buf.buf1) lv_free(drm_dev->render_buf.buf1);
        if(drm_dev->render_buf.buf2) lv_free(drm_dev->render_buf.buf2);
        close(drm_dev->fd);
        drm_dev->fd = -1;
        return;
    }

    LV_LOG_INFO("Allocated LVGL render buffers: %zu bytes each", drm_dev->render_buf.buf_size);

    /* 使用FULL模式以启用RGA优化的部分区域更新 */
    /* LVGL渲染到独立的render buffer，然后在flush时使用RGA只拷贝变化的区域到DRM buffer */
    lv_display_set_buffers(disp, drm_dev->render_buf.buf1, drm_dev->render_buf.buf2,
                           drm_dev->render_buf.buf_size, LV_DISPLAY_RENDER_MODE_FULL);

    /* 分配RGA工作缓冲区 */
    /* 使用RGA的分配器分配可以被RGA硬件访问的缓冲区 */
    ret = c_RkRgaGetAllocBuffer(&drm_dev->rga_bo, hor_res, ver_res, LV_COLOR_DEPTH);
    if(ret != 0) {
        LV_LOG_ERROR("Failed to allocate RGA working buffer: %d", ret);
        lv_free(drm_dev->render_buf.buf1);
        lv_free(drm_dev->render_buf.buf2);
        close(drm_dev->fd);
        drm_dev->fd = -1;
        return;
    }
    /* 映射RGA缓冲区到虚拟地址 */
    ret = c_RkRgaGetMmap(&drm_dev->rga_bo);
    if(ret != 0) {
        LV_LOG_ERROR("Failed to mmap RGA working buffer: %d", ret);
        c_RkRgaFree(&drm_dev->rga_bo);
        lv_free(drm_dev->render_buf.buf1);
        lv_free(drm_dev->render_buf.buf2);
        close(drm_dev->fd);
        drm_dev->fd = -1;
        return;
    }
    /* 获取RGA buffer的文件描述符（用于RGA操作） */
    ret = c_RkRgaGetBufferFd(&drm_dev->rga_bo, &drm_dev->rga_bo_fd);
    if(ret != 0 || drm_dev->rga_bo_fd <= 0) {
        LV_LOG_ERROR("Failed to get RGA buffer fd: %d (fd=%d)", ret, drm_dev->rga_bo_fd);
        c_RkRgaUnmap(&drm_dev->rga_bo);
        c_RkRgaFree(&drm_dev->rga_bo);
        lv_free(drm_dev->render_buf.buf1);
        lv_free(drm_dev->render_buf.buf2);
        close(drm_dev->fd);
        drm_dev->fd = -1;
        return;
    }

    // printf("drm_dev->rga_bo_fd =%d \n",drm_dev->rga_bo_fd);
    /* 保存RGA缓冲区指针和大小 */
    drm_dev->rga_buf_ptr = (uint8_t *)drm_dev->rga_bo.ptr;
    drm_dev->rga_buf_size = drm_dev->rga_bo.size;

    LV_LOG_INFO("Allocated RGA working buffer: %zu bytes at %p (fd=%d)",
                drm_dev->rga_buf_size, drm_dev->rga_buf_ptr, drm_dev->rga_bo_fd);
#else
    size_t buf_size = LV_MIN(drm_dev->drm_bufs[1].size, drm_dev->drm_bufs[0].size);
    /* Resolution must be set first because if the screen is smaller than the size passed
     * to lv_display_create then the buffers aren't big enough for LV_DISPLAY_RENDER_MODE_DIRECT.
     */
    lv_display_set_resolution(disp, hor_res, ver_res);
    lv_display_set_buffers(disp, drm_dev->drm_bufs[1].map, drm_dev->drm_bufs[0].map, buf_size,
                           LV_DISPLAY_RENDER_MODE_DIRECT);


#endif
    lv_display_add_event_cb(disp, drm_dmabuf_set_active_buf, LV_EVENT_REFR_START, drm_dev);
    
    if(width) {
        lv_display_set_dpi(disp, DIV_ROUND_UP(hor_res * 25400, width * 1000));
    }

    LV_LOG_INFO("Resolution is set to %" LV_PRId32 "x%" LV_PRId32 " at %" LV_PRId32 "dpi with RGA acceleration",
                hor_res, ver_res, lv_display_get_dpi(disp));

}

static int drm_dmabuf_set_plane(drm_dev_t * drm_dev, drm_buffer_t * buf)
{
    int ret;
    static int first = 1;
    uint32_t flags = DRM_MODE_PAGE_FLIP_EVENT | DRM_MODE_ATOMIC_NONBLOCK;

#if LV_USE_LINUX_DRM_GBM_BUFFERS

    struct dma_buf_sync sync_req;

    sync_req.flags = DMA_BUF_SYNC_END | DMA_BUF_SYNC_RW;
    if(ioctl(buf->handle, DMA_BUF_IOCTL_SYNC, &sync_req) != 0) {
        LV_LOG_ERROR("Failed to end DMA-BUF R/W SYNC");
    }

#endif

    drm_dev->req = drmModeAtomicAlloc();

    /* On first Atomic commit, do a modeset */
    if(first) {
        LV_LOG_INFO("First atomic commit - adding modeset flags");
        drm_add_conn_property(drm_dev, "CRTC_ID", drm_dev->crtc_id);

        drm_add_crtc_property(drm_dev, "MODE_ID", drm_dev->blob_id);
        drm_add_crtc_property(drm_dev, "ACTIVE", 1);

        flags |= DRM_MODE_ATOMIC_ALLOW_MODESET;
        LV_LOG_INFO("Flags after ALLOW_MODESET: 0x%x", flags);

        first = 0;
    }

    LV_LOG_TRACE("Atomic commit flags: 0x%x, fb_handle=%u", flags, buf->fb_handle);

    drm_add_plane_property(drm_dev, "FB_ID", buf->fb_handle);
    drm_add_plane_property(drm_dev, "CRTC_ID", drm_dev->crtc_id);
    drm_add_plane_property(drm_dev, "SRC_X", 0);
    drm_add_plane_property(drm_dev, "SRC_Y", 0);
    drm_add_plane_property(drm_dev, "SRC_W", drm_dev->width << 16);
    drm_add_plane_property(drm_dev, "SRC_H", drm_dev->height << 16);
    drm_add_plane_property(drm_dev, "CRTC_X", 0);
    drm_add_plane_property(drm_dev, "CRTC_Y", 0);
    drm_add_plane_property(drm_dev, "CRTC_W", drm_dev->width);
    drm_add_plane_property(drm_dev, "CRTC_H", drm_dev->height);

    ret = drmModeAtomicCommit(drm_dev->fd, drm_dev->req, flags, drm_dev);
    if(ret) {
        LV_LOG_ERROR("drmModeAtomicCommit failed: %s (%d), fb_handle=%u, flags=0x%x",
                     strerror(errno), errno, buf->fb_handle, flags);
        drmModeAtomicFree(drm_dev->req);
        drm_dev->req = NULL;  /* 清理req指针，避免flush_wait死锁 */
        return ret;
    }

    return 0;
}

static void drm_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
    drm_dev_t * drm_dev = (drm_dev_t *)lv_display_get_driver_data(disp);

    /* LVGL在FULL模式下，最后一次flush时需要完整刷新 */
    if(!lv_display_flush_is_last(disp)) {
        return;
    }

    LV_ASSERT(area != NULL);
    LV_ASSERT(px_map != NULL);
    /* 双缓冲策略：使用下一个可用的buffer（与当前显示的buffer不同） */
    uint32_t next_buf_idx = (drm_dev->current_buf_idx + 1) % BUFFER_CNT;
    drm_buffer_t *drm_buf = &drm_dev->drm_bufs[next_buf_idx];
    LV_ASSERT(drm_buf != NULL);

#if LV_USE_LINUX_DRM_RGA
    /* 暂时禁用RGA，使用软件拷贝 */
    /* TODO: 修复RGA配置后重新启用 */

    /* 获取需要更新的区域 */
    int32_t x1 = area->x1;
    int32_t y1 = area->y1;
    int32_t x2 = area->x2;
    int32_t y2 = area->y2;
    int32_t w = x2 - x1 + 1;
    int32_t h = y2 - y1 + 1;

    /* 边界检查 */
    if(x1 < 0) x1 = 0;
    if(y1 < 0) y1 = 0;
    if(x2 >= (int32_t)drm_dev->width) x2 = drm_dev->width - 1;
    if(y2 >= (int32_t)drm_dev->height) y2 = drm_dev->height - 1;
    w = x2 - x1 + 1;
    h = y2 - y1 + 1;

#if LV_USE_LINUX_DRM_RGA_FLUSH // RGA硬件加速：直接拷贝到DRM buffer
    static int format = (LV_COLOR_DEPTH == 16) ? RK_FORMAT_RGB_565 : RK_FORMAT_ARGB_8888;
    rga_flush(drm_dev, w, h, format, px_map, drm_buf->map);
    // printf("size_t px_map_len = %d\n", drm_dev->render_buf.buf_size);
    LV_LOG_TRACE("Software copy: rect[%d,%d]-[%d,%d] size=%dx%d", x1, y1, x2, y2, w, h);
#else // CPU拷贝：逐行复制（CPU memcpy 耗时1ms左右）
    uint32_t y;
    uint32_t stride = drm_buf->pitch;
    uint32_t bpp = LV_COLOR_DEPTH / 8;  /* bytes per pixel */
    for(y = y1; y <= y2; y++) {
        uint32_t src_offset = (y * drm_dev->width + x1) * bpp;
        uint32_t dst_offset = (y * stride) + x1 * bpp;
        memcpy((uint8_t*)drm_buf->map + dst_offset, px_map + src_offset, w * bpp);
    }
    // printf("rect[%d,%d]-[%d,%d] size=%dx%d\n", x1, y1, x2, y2, w, h);
    //         rect[0,0]-[479,799] size=480x800
#endif
#endif
    /* 提交后缓冲区到显示 - 这会触发VSync同步 */
    if(drm_dmabuf_set_plane(drm_dev, drm_buf)) {
        LV_LOG_ERROR("Flush fail");
        return;
    }

    /* 更新当前显示的buffer索引 */
    drm_dev->current_buf_idx = next_buf_idx;

}

static void drm_flush_wait(lv_display_t * disp)
{
    drm_dev_t * drm_dev = (drm_dev_t *)lv_display_get_driver_data(disp);

    struct pollfd pfd;
    pfd.fd = drm_dev->fd;
    pfd.events = POLLIN;

    while(drm_dev->req) {
        int ret;
        do {
            ret = poll(&pfd, 1, -1);
        } while(ret == -1 && errno == EINTR);

        if(ret > 0)
            drmHandleEvent(drm_dev->fd, &drm_dev->drm_event_ctx);
        else {
            LV_LOG_ERROR("poll failed: %s", strerror(errno));
            return;
        }
    }
}


static uint32_t tick_get_cb(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    uint64_t time_ms = t.tv_sec * 1000 + (t.tv_nsec / 1000000);
    return time_ms;
}


#endif
