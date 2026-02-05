/**
 * RGA调试工具 - 检查内存越界问题
 *
 * 编译: arm-linux-gnueabihf-gcc rga_debug.c -lrga -o rga_debug
 * 运行: ./rga_debug
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include "rga/RgaApi.h"

#define TEST_WIDTH   480
#define TEST_HEIGHT  800
#define TEST_FORMAT  RK_FORMAT_RGB_565

int main(void)
{
    rga_info_t src, dst;
    void *src_buf, *dst_buf;
    int ret;

    /* 获取RGA版本 */
    int version = 0;
    c_RkRgaGetRgaVersion(&version);
    printf("RGA Version: 0x%x\n", version);

    /* 分配测试buffer */
    size_t buf_size = TEST_WIDTH * TEST_HEIGHT * 2; /* RGB565 = 2 bytes */

    /* 测试1: 错误的stride配置（当前代码的问题） */
    printf("\n=== Test 1: Wrong stride (using width instead of real stride) ===\n");

    src_buf = malloc(buf_size);
    dst_buf = malloc(buf_size);

    memset(src_buf, 0xAA, buf_size);
    memset(dst_buf, 0x00, buf_size);

    memset(&src, 0, sizeof(rga_info_t));
    memset(&dst, 0, sizeof(rga_info_t));

    src.fd = -1;
    src.virAddr = src_buf;
    src.format = TEST_FORMAT;
    src.mmuFlag = 1;

    dst.fd = -1;
    dst.virAddr = dst_buf;
    dst.format = TEST_FORMAT;
    dst.mmuFlag = 1;

    /* 关键问题：虚拟宽度使用的是width，而不是stride！ */
    rga_set_rect(&src.rect, 0, 0, TEST_WIDTH, TEST_HEIGHT,
                 TEST_WIDTH, TEST_HEIGHT, TEST_FORMAT);  /* 错误！第5个参数 */
    rga_set_rect(&dst.rect, 0, 0, TEST_WIDTH, TEST_HEIGHT,
                 TEST_WIDTH, TEST_HEIGHT, TEST_FORMAT);  /* 错误！第5个参数 */

    printf("Source: virAddr=%p, rect.w=%d, rect.h=%d, rect.wstride=%d (WRONG!)\n",
           src.virAddr, src.rect.width, src.rect.height, src.rect.wstride);
    printf("Dest:   virAddr=%p, rect.w=%d, rect.h=%d, rect.wstride=%d (WRONG!)\n",
           dst.virAddr, dst.rect.width, dst.rect.height, dst.rect.wstride);

    ret = c_RkRgaBlit(&src, &dst, NULL);
    printf("RGA Blit Result: %d (%s)\n", ret, ret == 0 ? "SUCCESS" : "FAILED");

    free(src_buf);
    free(dst_buf);

    /* 测试2: 正确的stride配置 */
    printf("\n=== Test 2: Correct stride (using actual stride in pixels) ===\n");

    /* GBM通常会添加padding，例如512的stride而不是480 */
    uint32_t real_stride_bytes = 512;  /* GBM常见对齐 */
    uint32_t real_stride_pixels = real_stride_bytes / 2;  /* RGB565 */

    /* 分配带padding的buffer */
    size_t real_buf_size = real_stride_bytes * TEST_HEIGHT;

    src_buf = malloc(real_buf_size);
    dst_buf = malloc(real_buf_size);

    memset(src_buf, 0xBB, real_buf_size);
    memset(dst_buf, 0x00, real_buf_size);

    memset(&src, 0, sizeof(rga_info_t));
    memset(&dst, 0, sizeof(rga_info_t));

    src.fd = -1;
    src.virAddr = src_buf;
    src.format = TEST_FORMAT;
    src.mmuFlag = 1;

    dst.fd = -1;
    dst.virAddr = dst_buf;
    dst.format = TEST_FORMAT;
    dst.mmuFlag = 1;

    /* 正确：使用实际的stride（像素单位） */
    rga_set_rect(&src.rect, 0, 0, TEST_WIDTH, TEST_HEIGHT,
                 real_stride_pixels, TEST_HEIGHT, TEST_FORMAT);
    rga_set_rect(&dst.rect, 0, 0, TEST_WIDTH, TEST_HEIGHT,
                 real_stride_pixels, TEST_HEIGHT, TEST_FORMAT);

    printf("Source: virAddr=%p, rect.w=%d, rect.h=%d, rect.wstride=%d (CORRECT)\n",
           src.virAddr, src.rect.width, src.rect.height, src.rect.wstride);
    printf("Dest:   virAddr=%p, rect.w=%d, rect.h=%d, rect.wstride=%d (CORRECT)\n",
           dst.virAddr, dst.rect.width, dst.rect.height, dst.rect.wstride);

    ret = c_RkRgaBlit(&src, &dst, NULL);
    printf("RGA Blit Result: %d (%s)\n", ret, ret == 0 ? "SUCCESS" : "FAILED");

    free(src_buf);
    free(dst_buf);

    /* 测试3: 完全错误的小stride（模拟内存越界） */
    printf("\n=== Test 3: Intentionally wrong stride (smaller than width - causes overrun!) ===\n");

    src_buf = malloc(buf_size);
    dst_buf = malloc(buf_size);

    memset(src_buf, 0xCC, buf_size);
    memset(dst_buf, 0x00, buf_size);

    memset(&src, 0, sizeof(rga_info_t));
    memset(&dst, 0, sizeof(rga_info_t));

    src.fd = -1;
    src.virAddr = src_buf;
    src.format = TEST_FORMAT;
    src.mmuFlag = 1;

    dst.fd = -1;
    dst.virAddr = dst_buf;
    dst.format = TEST_FORMAT;
    dst.mmuFlag = 1;

    /* 故意使用错误的stride（小于实际宽度）- 这会导致内存越界！ */
    rga_set_rect(&src.rect, 0, 0, TEST_WIDTH, TEST_HEIGHT,
                 400, TEST_HEIGHT, TEST_FORMAT);  /* 小于480！ */
    rga_set_rect(&dst.rect, 0, 0, TEST_WIDTH, TEST_HEIGHT,
                 400, TEST_HEIGHT, TEST_FORMAT);

    printf("Source: virAddr=%p, rect.w=%d, rect.h=%d, rect.wstride=%d (TOO SMALL!)\n",
           src.virAddr, src.rect.width, src.rect.height, src.rect.wstride);
    printf("Dest:   virAddr=%p, rect.w=%d, rect.h=%d, rect.wstride=%d (TOO SMALL!)\n",
           dst.virAddr, dst.rect.width, dst.rect.height, dst.rect.wstride);
    printf("WARNING: This will cause RGA to access beyond buffer bounds!\n");

    ret = c_RkRgaBlit(&src, &dst, NULL);
    printf("RGA Blit Result: %d (%s)\n", ret, ret == 0 ? "SUCCESS" : "FAILED");
    printf("Check dmesg for RGA error irq!\n");

    free(src_buf);
    free(dst_buf);

    printf("\n=== Summary ===\n");
    printf("The wstride parameter in rga_set_rect must match the actual buffer stride!\n");
    printf("For RGB565: wstride = pitch / 2\n");
    printf("For RGB888: wstride = pitch / 4\n");
    printf("\nIf stride doesn't match, RGA will access invalid memory -> IRQ error!\n");

    return 0;
}
