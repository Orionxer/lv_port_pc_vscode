/**
 * @file hal.h
 *
 */
#include "lvgl/lvgl.h"
#ifdef LV_USE_LINUX_DRM_RGA

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void rk_drm_init(void);

void rk_drm_deinit(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_USE_LINUX_DRM_RGA*/
