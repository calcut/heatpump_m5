// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: Thermostat_M5

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Header;
lv_obj_t *ui_Header_Date;
lv_obj_t *ui_Header_Time;
lv_obj_t *ui_Arc_Group;
lv_obj_t *ui_Label2;
void ui_event_Arc1( lv_event_t * e);
lv_obj_t *ui_Arc1;
lv_obj_t *ui_Label_Celsius;
void ui_event_Fan_Speed_Control( lv_event_t * e);
lv_obj_t *ui_Fan_Speed_Control;
lv_obj_t *ui_Label_Slider;
void ui_event_Button1( lv_event_t * e);
lv_obj_t *ui_Button1;
void ui_event_Button3( lv_event_t * e);
lv_obj_t *ui_Button3;
void ui_event_Button4( lv_event_t * e);
lv_obj_t *ui_Button4;

// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
lv_obj_t *ui_Screen2;
void ui_event_Button2( lv_event_t * e);
lv_obj_t *ui_Button2;
lv_obj_t *ui_Image1;
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Arc1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      _ui_arc_set_text_value( ui_Label_Celsius, target, "", "°");
      update_setpoint( e );
}
}
void ui_event_Fan_Speed_Control( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      fan_speed_value( e );
}
}
void ui_event_Button1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen2, LV_SCR_LOAD_ANIM_NONE, 150, 0, &ui_Screen2_screen_init);
}
}
void ui_event_Button3( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_slider_set_property(ui_Fan_Speed_Control, _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM, 0);
}
}
void ui_event_Button4( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_slider_set_property(ui_Fan_Speed_Control, _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM, 100);
}
}
void ui_event_Button2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Screen1, LV_SCR_LOAD_ANIM_NONE, 150, 0, &ui_Screen1_screen_init);
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen1_screen_init();
ui_Screen2_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_Screen1);
}
