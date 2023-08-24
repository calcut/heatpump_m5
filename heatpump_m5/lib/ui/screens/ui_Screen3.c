// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: Thermostat_M5

#include "../ui.h"

void ui_Screen3_screen_init(void)
{
ui_Screen3 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button3a = lv_btn_create(ui_Screen3);
lv_obj_set_width( ui_Button3a, 100);
lv_obj_set_height( ui_Button3a, 40);
lv_obj_set_x( ui_Button3a, -105 );
lv_obj_set_y( ui_Button3a, 0 );
lv_obj_set_align( ui_Button3a, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_Button3a, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button3a, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_border_color(ui_Button3a, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Button3a, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_Button3a, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_Button3a, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button3b = lv_btn_create(ui_Screen3);
lv_obj_set_width( ui_Button3b, 100);
lv_obj_set_height( ui_Button3b, 40);
lv_obj_set_align( ui_Button3b, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_Button3b, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button3b, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button3c = lv_btn_create(ui_Screen3);
lv_obj_set_width( ui_Button3c, 100);
lv_obj_set_height( ui_Button3c, 40);
lv_obj_set_x( ui_Button3c, 105 );
lv_obj_set_y( ui_Button3c, 0 );
lv_obj_set_align( ui_Button3c, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_Button3c, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button3c, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Bar1 = lv_bar_create(ui_Screen3);
lv_obj_set_width( ui_Bar1, 10);
lv_obj_set_height( ui_Bar1, 20);
lv_obj_set_x( ui_Bar1, 100 );
lv_obj_set_y( ui_Bar1, -195 );
lv_obj_set_align( ui_Bar1, LV_ALIGN_BOTTOM_MID );

ui_Header1 = lv_obj_create(ui_Screen3);
lv_obj_set_height( ui_Header1, 25);
lv_obj_set_width( ui_Header1, lv_pct(100));
lv_obj_set_align( ui_Header1, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_Header1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Header1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Header1, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Header1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Header1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Header_Title = lv_label_create(ui_Header1);
lv_obj_set_width( ui_Header_Title, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Title, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Header_Title, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_Header_Title,"Notecard Info");
lv_obj_set_style_text_color(ui_Header_Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Title, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Header_Time3 = lv_label_create(ui_Header1);
lv_obj_set_width( ui_Header_Time3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Header_Time3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Header_Time3, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Header_Time3,"--:--:--");
lv_obj_set_style_text_color(ui_Header_Time3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Header_Time3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Bar2 = lv_bar_create(ui_Screen3);
lv_obj_set_width( ui_Bar2, 10);
lv_obj_set_height( ui_Bar2, 30);
lv_obj_set_x( ui_Bar2, 115 );
lv_obj_set_y( ui_Bar2, -195 );
lv_obj_set_align( ui_Bar2, LV_ALIGN_BOTTOM_MID );

ui_Bar3 = lv_bar_create(ui_Screen3);
lv_obj_set_width( ui_Bar3, 10);
lv_obj_set_height( ui_Bar3, 40);
lv_obj_set_x( ui_Bar3, 130 );
lv_obj_set_y( ui_Bar3, -195 );
lv_obj_set_align( ui_Bar3, LV_ALIGN_BOTTOM_MID );

ui_Bar4 = lv_bar_create(ui_Screen3);
lv_obj_set_width( ui_Bar4, 10);
lv_obj_set_height( ui_Bar4, 50);
lv_obj_set_x( ui_Bar4, 145 );
lv_obj_set_y( ui_Bar4, -195 );
lv_obj_set_align( ui_Bar4, LV_ALIGN_BOTTOM_MID );

ui_LabelRSSI = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelRSSI, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelRSSI, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelRSSI, 12 );
lv_obj_set_y( ui_LabelRSSI, 35 );
lv_label_set_text(ui_LabelRSSI,"RSSI: ----");

ui_LabelBand = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelBand, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelBand, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelBand, 135 );
lv_obj_set_y( ui_LabelBand, 35 );
lv_label_set_text(ui_LabelBand,"Band: ----");

ui_LabelRat = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelRat, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelRat, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelRat, 135 );
lv_obj_set_y( ui_LabelRat, 60 );
lv_label_set_text(ui_LabelRat,"RAT: ----");

ui_LabelConnected = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelConnected, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelConnected, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelConnected, 12 );
lv_obj_set_y( ui_LabelConnected, 60 );
lv_label_set_text(ui_LabelConnected,"Connected: ----");

ui_LabelSerial = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelSerial, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelSerial, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelSerial, 12 );
lv_obj_set_y( ui_LabelSerial, 85 );
lv_label_set_text(ui_LabelSerial,"SN: ----");

ui_LabelSyncStatus = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelSyncStatus, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelSyncStatus, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelSyncStatus, 12 );
lv_obj_set_y( ui_LabelSyncStatus, 185 );
lv_label_set_text(ui_LabelSyncStatus,"Sync Status :");

ui_LabelDevice = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelDevice, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelDevice, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelDevice, 12 );
lv_obj_set_y( ui_LabelDevice, 110 );
lv_label_set_text(ui_LabelDevice,"DeviceUID : ----");

ui_LabelHubStatus = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_LabelHubStatus, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelHubStatus, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelHubStatus, 12 );
lv_obj_set_y( ui_LabelHubStatus, 135 );
lv_label_set_text(ui_LabelHubStatus,"Hub Status :");

ui_TextAreaSyncStatus = lv_textarea_create(ui_Screen3);
lv_obj_set_width( ui_TextAreaSyncStatus, 200);
lv_obj_set_height( ui_TextAreaSyncStatus, 50);
lv_obj_set_x( ui_TextAreaSyncStatus, 110 );
lv_obj_set_y( ui_TextAreaSyncStatus, 178 );
lv_textarea_set_placeholder_text(ui_TextAreaSyncStatus,"none");
lv_obj_clear_flag( ui_TextAreaSyncStatus, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE );    /// Flags

ui_TextAreaHubStatus = lv_textarea_create(ui_Screen3);
lv_obj_set_width( ui_TextAreaHubStatus, 200);
lv_obj_set_height( ui_TextAreaHubStatus, 50);
lv_obj_set_x( ui_TextAreaHubStatus, 110 );
lv_obj_set_y( ui_TextAreaHubStatus, 128 );
lv_textarea_set_placeholder_text(ui_TextAreaHubStatus,"none");
lv_obj_clear_flag( ui_TextAreaHubStatus, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE );    /// Flags

lv_obj_add_event_cb(ui_Button3a, ui_event_Button3a, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button3b, ui_event_Button3b, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button3c, ui_event_Button3c, LV_EVENT_ALL, NULL);

}
