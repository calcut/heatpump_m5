#include <gui_helpers.h>

int timer_nc_info = 0;
int timer_pid_info = 0;
char text_buffer[64];

void display_pid_info(){
    if (millis() - timer_pid_info > db_vars.pid_info_interval_s * 1000) {
        timer_pid_info = millis();

        Serial.printf("PID info poll\n");

        sprintf(text_buffer, "%.3g", compressorPID.GetKp());
        lv_label_set_text(ui_Label4_Kp_val, text_buffer);

        sprintf(text_buffer, "%.3g", compressorPID.GetKi());
        lv_label_set_text(ui_Label4_Ki_val, text_buffer);

        sprintf(text_buffer, "%.3g", compressorPID.GetKd());
        lv_label_set_text(ui_Label4_Kd_val, text_buffer);

        sprintf(text_buffer, "%.3g", compressorPID.GetPterm());
        lv_label_set_text(ui_Label4_Pterm_val, text_buffer);

        //This is just the most recent term, not the integrated history
        // sprintf(text_buffer, "%.3g", compressorPID.GetIterm()); 

        sprintf(text_buffer, "%.3g", compressorPID.GetOutputSum()); //include history
        lv_label_set_text(ui_Label4_Iterm_val, text_buffer);

        sprintf(text_buffer, "%.3g", compressorPID.GetDterm());
        lv_label_set_text(ui_Label4_Dterm_val, text_buffer);

        sprintf(text_buffer, "%.3g", qo_vars.compressor_speed);
        lv_label_set_text(ui_Label4_Output_val, text_buffer);

        sprintf(text_buffer, "%.3g", db_vars.setpoint);
        lv_label_set_text(ui_Label4_Setpoint_val, text_buffer);

        sprintf(text_buffer, "%.3g", qo_vars.tc[0]);
        lv_label_set_text(ui_Label4_Input_val, text_buffer);

        sprintf(text_buffer, "%.3g", db_vars.setpoint - qo_vars.tc[0]);
        lv_label_set_text(ui_Label4_Error_val, text_buffer);

    }
}


void display_notecard_info(){
    if (millis() - timer_nc_info > db_vars.nc_info_interval_s * 1000) {
        timer_nc_info = millis();

        Serial.printf("Notecard info poll\n");
        lv_obj_add_state(ui_Button3_Refresh, LV_STATE_CHECKED);
        lv_obj_clear_state(ui_Button3_Refresh, LV_STATE_DISABLED);

    
        if(notecardManager.connected){
            lv_label_set_text(ui_LabelConnected, "Connected: Yes");
        }
        else{
            lv_label_set_text(ui_LabelConnected, "Connected: No");
        }
        notecardManager.hubGet();
        lv_timer_handler();
        notecardManager.cardStatus();
        lv_timer_handler();
        notecardManager.getEnvironment();
        lv_timer_handler();
        notecardManager.hubStatus();
        lv_timer_handler();
        notecardManager.hubSyncStatus();
        lv_timer_handler();
        notecardManager.cardWireless();
        lv_timer_handler();


        sprintf(text_buffer, "UID: %s", notecardManager.deviceUID);
        lv_label_set_text(ui_LabelDevice, text_buffer);
        
        sprintf(text_buffer, "SN: %s", notecardManager.sn);
        lv_label_set_text(ui_LabelSerial, text_buffer);

        sprintf(text_buffer, "RSSI: %d dB", notecardManager.rssi);
        lv_label_set_text(ui_LabelRSSI, text_buffer);

        sprintf(text_buffer, "RAT: %s", notecardManager.rat);
        lv_label_set_text(ui_LabelRat, text_buffer);

        sprintf(text_buffer, "Band: %s", notecardManager.band);
        lv_label_set_text(ui_LabelBand, text_buffer);

        // fill in ui_BarX depending on reported bars
        if (notecardManager.bars > 0){
            lv_bar_set_value(ui_Bar1, 100, LV_ANIM_OFF);
        };
        if (notecardManager.bars > 1){
            lv_bar_set_value(ui_Bar2, 100, LV_ANIM_OFF);
        };
        if (notecardManager.bars > 2){
            lv_bar_set_value(ui_Bar3, 100, LV_ANIM_OFF);
        };
        if (notecardManager.bars > 3){
            lv_bar_set_value(ui_Bar4, 100, LV_ANIM_OFF);
        };

        lv_textarea_set_text(ui_TextAreaHubStatus, notecardManager.hub_status);
        lv_textarea_set_text(ui_TextAreaSyncStatus, notecardManager.hub_sync_status);
        lv_obj_clear_state(ui_Button3_Refresh, LV_STATE_CHECKED);
        lv_obj_add_state(ui_Button3_Refresh, LV_STATE_DISABLED);
    }
}

void display_sensor_info(){

    // gather the ui objects into arrays for easier looping
       lv_obj_t *tc_values[8] = {
        ui_Label2_value1,
        ui_Label2_value2,
        ui_Label2_value3,
        ui_Label2_value4,
        ui_Label2_value5,
        ui_Label2_value6
    };

    lv_obj_t *pr_values[8] = {
        ui_Label2_value7,
        ui_Label2_value8
    };

    lv_obj_t *tc_bars[8] = {
        ui_Bar2_value1,
        ui_Bar2_value2,
        ui_Bar2_value3,
        ui_Bar2_value4,
        ui_Bar2_value5,
        ui_Bar2_value6
    };

    lv_obj_t *pr_bars[8] = {
        ui_Bar2_value7,
        ui_Bar2_value8
    };

    // loop over all ui_Label2_valueX objects and update with new values
    for (int i = 0; i < 6; i++){
        sprintf(text_buffer, "%0.1f °C", qo_vars.tc[i]);
        // dtostrf(qo_vars.tc[i], 0, FLOAT_DECIMALS, buffer);
        lv_label_set_text(tc_values[i], text_buffer);
        lv_bar_set_value(tc_bars[i], qo_vars.tc[i], LV_ANIM_OFF);
    }
}

void display_date_time_labels(){
    //Get Time from system, then update the label on the display
    struct tm *time_info;
    struct timeval tv;
    char time_str[64];

    gettimeofday(&tv, NULL);
    time_info = localtime(&tv.tv_sec);

    // to show only the time
    strftime(time_str, sizeof(time_str), "%X", time_info);
    lv_label_set_text(ui_Header_Time1, time_str);
    lv_label_set_text(ui_Header_Time2, time_str);
    lv_label_set_text(ui_Header_Time3, time_str);

    // to show the full date and time
    // strftime(time_str, sizeof(time_str), "%Y-%m-%d %X", time_info);
    // lv_label_set_text(ui_Header_Time1, time_str);
    // lv_label_set_text(ui_Header_Time3, time_str);
}