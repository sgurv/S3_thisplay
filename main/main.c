#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <netdb.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "driver/i2c.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_attr.h"
#include "esp_sleep.h"
#include "nvs_flash.h"
#include "esp_sntp.h"
#include "lvgl.h"
#include "bsps3thisplay.h"

static const char *TAG = "s3";

static lv_disp_t *disp;

// //LED global
lv_obj_t * led1;

void app_main(void)
{

    bsp_i2c_init(); // Required for Touch I2C to work

    //--Display
    disp = bsp_display_start();

    bsp_display_lock(0);
    //Button 1
    lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 5, 5);                            /*Set its position*/
    lv_obj_set_size(btn, 70, 30);                          /*Set its size*/
    //lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/

    lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/
    lv_obj_center(label);

    /*Create a LED and switch it OFF*/
    led1  = lv_led_create(lv_scr_act());
    lv_obj_set_pos(led1, 20, 50);
    //lv_obj_align(led1, LV_ALIGN_CENTER, -80, 0);
    lv_led_set_color(led1, lv_palette_main(LV_PALETTE_AMBER));
    lv_led_on(led1);

    const char * data = "Sandeep Guria";

    // /*Create a 80x80 QR code*/
    // lv_obj_t * qr = lv_qrcode_create(lv_scr_act(), 80, lv_color_hex3(0x33f), lv_color_hex3(0xeef));
    // lv_obj_set_pos(qr, 80, 0);
    // /*Set data*/
    // lv_qrcode_update(qr, data, strlen(data));
    bsp_display_unlock();

    while(1){
        vTaskDelay(pdMS_TO_TICKS(1000));

        bsp_display_lock(0);
        lv_led_toggle(led1);
        bsp_display_unlock();
    }
}
