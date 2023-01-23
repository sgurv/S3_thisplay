#pragma once

#include "sdkconfig.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "driver/i2s_std.h"
#include "esp_lcd_touch.h"
#include "lvgl.h"

#define BSP_LCD_PIXEL_CLOCK_HZ     (40 * 1000 * 1000)

#define BSP_LCD_DATA0          (GPIO_NUM_18)
#define BSP_LCD_DATA1          (GPIO_NUM_17)
#define BSP_LCD_DATA2          (GPIO_NUM_16)
#define BSP_LCD_DATA3          (GPIO_NUM_15)
#define BSP_LCD_DATA4          (GPIO_NUM_7)
#define BSP_LCD_DATA5          (GPIO_NUM_6)
#define BSP_LCD_DATA6          (GPIO_NUM_5)
#define BSP_LCD_DATA7          (GPIO_NUM_4)

#define BSP_LCD_PCLK           (GPIO_NUM_3)//WR
#define BSP_LCD_CS             (GPIO_NUM_9)
#define BSP_LCD_DC             (GPIO_NUM_46)//RS
#define BSP_LCD_RST           (GPIO_NUM_8)
#define BSP_LCD_BK_LIGHT      (GPIO_NUM_10)

#define BSP_LCD_H_RES              (240)
#define BSP_LCD_V_RES              (280)

#define BSP_TP_INT              (GPIO_NUM_11)
#define BSP_TP_RST              (GPIO_NUM_12) //(ActiveLow)
#define BSP_TP_SDA              (GPIO_NUM_13)
#define BSP_TP_SCL              (GPIO_NUM_14)

#define BSP_TP_I2C_NUM            (I2C_NUM_0)

#define BUTTON_0_GPIO     0 /* For button 0 -- this is BOOT pin*/

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

#if CONFIG_BSP_ERROR_CHECK
#define BSP_ERROR_CHECK_RETURN_ERR(x)   ESP_ERROR_CHECK(x)
#define BSP_ERROR_CHECK_RETURN_NULL(x)  ESP_ERROR_CHECK(x)
#define BSP_NULL_CHECK(x, ret)          assert(x)
#else
#define BSP_ERROR_CHECK_RETURN_ERR(x) do { \
        esp_err_t err_rc_ = (x);            \
        if (unlikely(err_rc_ != ESP_OK)) {  \
            return err_rc_;                 \
        }                                   \
    } while(0)

#define BSP_ERROR_CHECK_RETURN_NULL(x)  do { \
        if (unlikely((x) != ESP_OK)) {      \
            return NULL;                    \
        }                                   \
    } while(0)

#define BSP_NULL_CHECK(x, ret)      do { \
        if ((x) == NULL) {      \
            return ret;                    \
        }                                   \
    } while(0)
#endif

esp_err_t bsp_i2c_init(void); // For large display touch

/**
 * @brief Initialize display and graphics library
 *
 * This function initializes SPI, display controller and starts LVGL handling task.
 *
 * @return Pointer to LVGL display or NULL when error occured
 */
lv_disp_t *bsp_display_start(void);

/**
 * @brief Take LVGL mutex
 *
 * @param timeout_ms Timeout in [ms]. 0 will block indefinitely.
 * @return true  Mutex was taken
 * @return false Mutex was NOT taken
 */
bool bsp_display_lock(uint32_t timeout_ms);

/**
 * @brief Give LVGL mutex
 *
 */
void bsp_display_unlock(void);

/* Backlight functions are not implemented - Kaluga board doesn't provide backlight control
   These functions are here to provide consistent API with other Board Support Packages */
esp_err_t bsp_display_backlight_on(void);
esp_err_t bsp_display_backlight_off(void);

/**
 * @brief Rotate screen
 *
 * Display must be already initialized by calling bsp_display_start()
 *
 * @param[in] disp Pointer to LVGL display
 * @param[in] rotation Angle of the display rotation
 */
void bsp_display_rotate(lv_disp_t *disp, lv_disp_rot_t rotation);

esp_lcd_touch_handle_t bsp_touch_panel_init(void);
