// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: Thermostat_M5

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x464B55), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_Screen1, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT );

ui_Arc_Group = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Arc_Group, 292);
lv_obj_set_height( ui_Arc_Group, 250);
lv_obj_set_x( ui_Arc_Group, -19 );
lv_obj_set_y( ui_Arc_Group, 15 );
lv_obj_set_align( ui_Arc_Group, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_Arc_Group, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Arc_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Arc_Group, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Arc_Group, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label2 = lv_label_create(ui_Arc_Group);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2, -113 );
lv_obj_set_y( ui_Label2, 11 );
lv_obj_set_align( ui_Label2, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label2,"Set\nPoint");
lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Arc1 = lv_arc_create(ui_Arc_Group);
lv_obj_set_width( ui_Arc1, 200);
lv_obj_set_height( ui_Arc1, 200);
lv_obj_set_align( ui_Arc1, LV_ALIGN_CENTER );
lv_arc_set_range(ui_Arc1, 15,35);
lv_arc_set_value(ui_Arc1, 23);
lv_obj_set_style_radius(ui_Arc1, 250, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_Arc1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Arc1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Arc1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Arc1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Arc1, 15, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x36B9F6), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Arc1, 15, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Arc1, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Label_Celsius = lv_label_create(ui_Arc_Group);
lv_obj_set_width( ui_Label_Celsius, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label_Celsius, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label_Celsius, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label_Celsius,"23°");
lv_obj_set_style_text_color(ui_Label_Celsius, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label_Celsius, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_Celsius, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Fan_Speed_Control = lv_slider_create(ui_Screen1);
lv_slider_set_value( ui_Fan_Speed_Control, 50, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Fan_Speed_Control)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Fan_Speed_Control, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_Fan_Speed_Control, 10);
lv_obj_set_height( ui_Fan_Speed_Control, 180);
lv_obj_set_x( ui_Fan_Speed_Control, 140 );
lv_obj_set_y( ui_Fan_Speed_Control, 41 );
lv_obj_set_align( ui_Fan_Speed_Control, LV_ALIGN_TOP_MID );
lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_color(ui_Fan_Speed_Control, lv_color_hex(0x1E242D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_outline_opa(ui_Fan_Speed_Control, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_width(ui_Fan_Speed_Control, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_pad(ui_Fan_Speed_Control, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x37B9F5), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_Fan_Speed_Control, lv_color_hex(0x1464F0), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_grad_dir(ui_Fan_Speed_Control, LV_GRAD_DIR_HOR, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x5F6464), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_Fan_Speed_Control, lv_color_hex(0x3C424B), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_grad_dir(ui_Fan_Speed_Control, LV_GRAD_DIR_VER, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_outline_color(ui_Fan_Speed_Control, lv_color_hex(0x373C46), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_outline_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_outline_width(ui_Fan_Speed_Control, 2, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_outline_pad(ui_Fan_Speed_Control, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_Fan_Speed_Control, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_Fan_Speed_Control, 150, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Fan_Speed_Control, 20, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Fan_Speed_Control, 2, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_Fan_Speed_Control, 10, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Fan_Speed_Control, 10, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Fan_Speed_Control, 10, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Fan_Speed_Control, 10, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Fan_Speed_Control, lv_color_hex(0x0096FF), LV_PART_KNOB | LV_STATE_PRESSED );
lv_obj_set_style_border_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB| LV_STATE_PRESSED);
lv_obj_set_style_border_width(ui_Fan_Speed_Control, 4, LV_PART_KNOB| LV_STATE_PRESSED);

}
