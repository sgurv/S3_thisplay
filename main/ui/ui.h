// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.4
// PROJECT: cFit

#ifndef _CFIT_UI_H
#define _CFIT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

void ui_event_Screen1(lv_event_t * e);
extern lv_obj_t * ui_Screen1;
void ui_event_Screen2(lv_event_t * e);
extern lv_obj_t * ui_Screen2;
void ui_event_Colorwheel2(lv_event_t * e);
extern lv_obj_t * ui_Colorwheel2;
void ui_event_Switch2(lv_event_t * e);
extern lv_obj_t * ui_Switch2;
extern lv_obj_t * ui_Screen3;
extern lv_obj_t * ui_Screen4;
extern lv_obj_t * ui_Screen5;

void colorChanged(lv_event_t * e);
void switch1Clicked(lv_event_t * e);

LV_IMG_DECLARE(ui_img_unsplash_png);    // assets\unsplash.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
