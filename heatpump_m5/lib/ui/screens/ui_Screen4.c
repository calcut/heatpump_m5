// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: Thermostat_M5

#include "../ui.h"

void ui_Screen4_screen_init(void)
{
ui_Screen4 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen4, lv_color_hex(0x464B55), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Header4 = lv_obj_create(ui_Screen4);
lv_obj_set_height( ui_Header4, 25);
lv_obj_set_width( ui_Header4, lv_pct(100));
lv_obj_set_align( ui_Header4, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_Header4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Header4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Header4, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Header4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Header4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Header_Title4 = lv_label_create(ui_Header4);
lv_obj_set_width( ui_Header_Title4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Title4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Header_Title4, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_Header_Title4,"PID Tuning");
lv_obj_set_style_text_color(ui_Header_Title4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Title4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Header_Time4 = lv_label_create(ui_Header4);
lv_obj_set_width( ui_Header_Time4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Time4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Header_Time4, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Header_Time4,"--:--:--");
lv_obj_set_style_text_color(ui_Header_Time4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Time4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel4_Kp = lv_obj_create(ui_Screen4);
lv_obj_set_width( ui_Panel4_Kp, 50);
lv_obj_set_height( ui_Panel4_Kp, 41);
lv_obj_set_x( ui_Panel4_Kp, 120 );
lv_obj_set_y( ui_Panel4_Kp, 50 );
lv_obj_clear_flag( ui_Panel4_Kp, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel4_Kp, lv_color_hex(0x72FFB2), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4_Kp, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel4_Kp, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel4_Kp, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Kp = lv_label_create(ui_Panel4_Kp);
lv_obj_set_width( ui_Label4_Kp, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Kp, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Kp, 0 );
lv_obj_set_y( ui_Label4_Kp, -12 );
lv_label_set_text(ui_Label4_Kp,"Kp");

ui_Label4_Kp_val = lv_label_create(ui_Panel4_Kp);
lv_obj_set_width( ui_Label4_Kp_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Kp_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Kp_val, 0 );
lv_obj_set_y( ui_Label4_Kp_val, 8 );
lv_obj_set_align( ui_Label4_Kp_val, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4_Kp_val,"--.-");

ui_Panel4_Ki = lv_obj_create(ui_Screen4);
lv_obj_set_width( ui_Panel4_Ki, 50);
lv_obj_set_height( ui_Panel4_Ki, 41);
lv_obj_set_x( ui_Panel4_Ki, 120 );
lv_obj_set_y( ui_Panel4_Ki, 110 );
lv_obj_clear_flag( ui_Panel4_Ki, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel4_Ki, lv_color_hex(0x72FFB2), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4_Ki, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel4_Ki, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel4_Ki, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Ki = lv_label_create(ui_Panel4_Ki);
lv_obj_set_width( ui_Label4_Ki, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Ki, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Ki, 0 );
lv_obj_set_y( ui_Label4_Ki, -12 );
lv_label_set_text(ui_Label4_Ki,"Ki");

ui_Label4_Ki_val = lv_label_create(ui_Panel4_Ki);
lv_obj_set_width( ui_Label4_Ki_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Ki_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Ki_val, 0 );
lv_obj_set_y( ui_Label4_Ki_val, 8 );
lv_obj_set_align( ui_Label4_Ki_val, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4_Ki_val,"--.-");

ui_Panel4_Kd = lv_obj_create(ui_Screen4);
lv_obj_set_width( ui_Panel4_Kd, 50);
lv_obj_set_height( ui_Panel4_Kd, 41);
lv_obj_set_x( ui_Panel4_Kd, 121 );
lv_obj_set_y( ui_Panel4_Kd, 170 );
lv_obj_clear_flag( ui_Panel4_Kd, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel4_Kd, lv_color_hex(0x72FFB2), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4_Kd, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel4_Kd, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel4_Kd, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Kd = lv_label_create(ui_Panel4_Kd);
lv_obj_set_width( ui_Label4_Kd, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Kd, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Kd, 0 );
lv_obj_set_y( ui_Label4_Kd, -12 );
lv_label_set_text(ui_Label4_Kd,"Kd");

ui_Label4_Kd_val = lv_label_create(ui_Panel4_Kd);
lv_obj_set_width( ui_Label4_Kd_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Kd_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Kd_val, 0 );
lv_obj_set_y( ui_Label4_Kd_val, 8 );
lv_obj_set_align( ui_Label4_Kd_val, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4_Kd_val,"--.-");

ui_Panel4_In = lv_obj_create(ui_Screen4);
lv_obj_set_width( ui_Panel4_In, 35);
lv_obj_set_height( ui_Panel4_In, 35);
lv_obj_set_x( ui_Panel4_In, 43 );
lv_obj_set_y( ui_Panel4_In, 110 );
lv_obj_clear_flag( ui_Panel4_In, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel4_In, 100, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel4_In, lv_color_hex(0xFEEC93), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4_In, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel4_In, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel4_In, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_inplus = lv_label_create(ui_Panel4_In);
lv_obj_set_width( ui_Label4_inplus, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_inplus, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_inplus, -2 );
lv_obj_set_y( ui_Label4_inplus, -5 );
lv_label_set_text(ui_Label4_inplus,"+");

ui_Panel4_Out = lv_obj_create(ui_Screen4);
lv_obj_set_width( ui_Panel4_Out, 35);
lv_obj_set_height( ui_Panel4_Out, 35);
lv_obj_set_x( ui_Panel4_Out, 222 );
lv_obj_set_y( ui_Panel4_Out, 111 );
lv_obj_clear_flag( ui_Panel4_Out, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel4_Out, 100, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel4_Out, lv_color_hex(0xFEEC93), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4_Out, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel4_Out, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel4_Out, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_outplus = lv_label_create(ui_Panel4_Out);
lv_obj_set_width( ui_Label4_outplus, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_outplus, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_outplus, -2 );
lv_obj_set_y( ui_Label4_outplus, -5 );
lv_label_set_text(ui_Label4_outplus,"+");

ui_Button4b = lv_btn_create(ui_Screen4);
lv_obj_set_width( ui_Button4b, 100);
lv_obj_set_height( ui_Button4b, 40);
lv_obj_set_align( ui_Button4b, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_Button4b, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button4b, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button4a = lv_btn_create(ui_Screen4);
lv_obj_set_width( ui_Button4a, 100);
lv_obj_set_height( ui_Button4a, 40);
lv_obj_set_x( ui_Button4a, -105 );
lv_obj_set_y( ui_Button4a, 0 );
lv_obj_set_align( ui_Button4a, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_Button4a, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button4a, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_border_color(ui_Button4a, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Button4a, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_Button4a, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_Button4a, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button4c = lv_btn_create(ui_Screen4);
lv_obj_set_width( ui_Button4c, 100);
lv_obj_set_height( ui_Button4c, 40);
lv_obj_set_x( ui_Button4c, 105 );
lv_obj_set_y( ui_Button4c, 0 );
lv_obj_set_align( ui_Button4c, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_Button4c, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button4c, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label4_Error = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Error, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Error, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Error, 80 );
lv_obj_set_y( ui_Label4_Error, 100 );
lv_label_set_text(ui_Label4_Error,"Error");

ui_Label4_Error_val = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Error_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Error_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Error_val, 85 );
lv_obj_set_y( ui_Label4_Error_val, 120 );
lv_label_set_text(ui_Label4_Error_val,"--.-");
lv_obj_set_style_text_color(ui_Label4_Error_val, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label4_Error_val, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Output = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Output, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Output, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Output, 260 );
lv_obj_set_y( ui_Label4_Output, 100 );
lv_label_set_text(ui_Label4_Output,"Output");

ui_Label4_Setpoint = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Setpoint, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Setpoint, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Setpoint, 8 );
lv_obj_set_y( ui_Label4_Setpoint, 70 );
lv_label_set_text(ui_Label4_Setpoint,"Set\npoint");

ui_Label4_Setpoint_val = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Setpoint_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Setpoint_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Setpoint_val, 8 );
lv_obj_set_y( ui_Label4_Setpoint_val, 110 );
lv_label_set_text(ui_Label4_Setpoint_val,"--.-");
lv_obj_set_style_text_color(ui_Label4_Setpoint_val, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label4_Setpoint_val, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Input = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Input, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Input, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Input, 8 );
lv_obj_set_y( ui_Label4_Input, 150 );
lv_label_set_text(ui_Label4_Input,"Input");

ui_Label4_Input_val = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Input_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Input_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Input_val, 8 );
lv_obj_set_y( ui_Label4_Input_val, 170 );
lv_label_set_text(ui_Label4_Input_val,"--.-");
lv_obj_set_style_text_color(ui_Label4_Input_val, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label4_Input_val, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Pterm = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Pterm, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Pterm, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Pterm, 180 );
lv_obj_set_y( ui_Label4_Pterm, 40 );
lv_label_set_text(ui_Label4_Pterm,"Pterm");

ui_Label4_Dterm = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Dterm, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Dterm, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Dterm, 180 );
lv_obj_set_y( ui_Label4_Dterm, 160 );
lv_label_set_text(ui_Label4_Dterm,"Dterm");

ui_Label4_Iterm = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Iterm, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Iterm, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Iterm, 180 );
lv_obj_set_y( ui_Label4_Iterm, 100 );
lv_label_set_text(ui_Label4_Iterm,"Iterm");

ui_Label4_Iterm_val = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Iterm_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Iterm_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Iterm_val, 185 );
lv_obj_set_y( ui_Label4_Iterm_val, 120 );
lv_label_set_text(ui_Label4_Iterm_val,"--.-");
lv_obj_set_style_text_color(ui_Label4_Iterm_val, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label4_Iterm_val, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Output_val = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Output_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Output_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Output_val, 265 );
lv_obj_set_y( ui_Label4_Output_val, 120 );
lv_label_set_text(ui_Label4_Output_val,"--.-");
lv_obj_set_style_text_color(ui_Label4_Output_val, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label4_Output_val, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Pterm_val = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Pterm_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Pterm_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Pterm_val, 185 );
lv_obj_set_y( ui_Label4_Pterm_val, 60 );
lv_label_set_text(ui_Label4_Pterm_val,"--.-");
lv_obj_set_style_text_color(ui_Label4_Pterm_val, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label4_Pterm_val, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4_Dterm_val = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Label4_Dterm_val, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4_Dterm_val, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4_Dterm_val, 185 );
lv_obj_set_y( ui_Label4_Dterm_val, 180 );
lv_label_set_text(ui_Label4_Dterm_val,"--.-");
lv_obj_set_style_text_color(ui_Label4_Dterm_val, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label4_Dterm_val, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_Button4a, ui_event_Button4a, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button4c, ui_event_Button4c, LV_EVENT_ALL, NULL);

}