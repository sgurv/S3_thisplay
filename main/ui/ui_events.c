// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.4
// PROJECT: cFit

#include "ui.h"
#include "bsps3thisplay.h"

static uint8_t led_strip_pixels[BSP_RMT_LED_NUMBERS * 3];
static lv_color32_t col;

void colorChanged(lv_event_t * e)
{
	// Your code here
	
	lv_obj_t * obj = lv_event_get_target(e);
	col.full = lv_color_to32(lv_colorwheel_get_rgb(obj));

	if(lv_obj_has_state(ui_Switch2, LV_STATE_CHECKED)){
		led_strip_pixels[0] = col.ch.green;//G
		led_strip_pixels[1] = col.ch.red;//R
		led_strip_pixels[2] = col.ch.blue;//B
		bsp_rmt_led_transmit(led_strip_pixels, sizeof(led_strip_pixels));
	}
	
}

void switch1Clicked(lv_event_t * e)
{
	// Your code here

	lv_obj_t * obj = lv_event_get_target(e);

	if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
		col.full = lv_color_to32(lv_colorwheel_get_rgb(ui_Colorwheel2));
		led_strip_pixels[0] = col.ch.green;//G
    	led_strip_pixels[1] = col.ch.red;//R
    	led_strip_pixels[2] = col.ch.blue;//B
	} else {
		led_strip_pixels[0] = 0x00;//G
    	led_strip_pixels[1] = 0x00;//R
    	led_strip_pixels[2] = 0x00;//B
	}
	
    bsp_rmt_led_transmit(led_strip_pixels, sizeof(led_strip_pixels));
}
