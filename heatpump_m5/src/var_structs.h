#ifndef VAR_STRUCTS_H
#define VAR_STRUCTS_H

typedef struct {
  float dhw_setpoint = 25.0;
  bool enabled = true;
  int mode = 1;
  int poll_interval_ms = 2000;
  int nc_time_sync_interval_s = 10;
  int nc_info_interval_s = 5;
  int pid_info_interval_s = 2;
  int thr_flex = 0;
} db_variables_t;

typedef struct{
  float tc[8] = {0,0,0,0,0,0,0,0};
  float t_ambient = 0;
  float tw_dhw = 0;
  float tr_comp_in = 0;
  float tr_comp_out = 0;
  float tr_cond_out = 0;
  float tr_flex = 0;
  float tw_flex = 0;
  float pr_comp_in = 0;
  float pr_comp_out = 0;
  time_t last_poll_time = 0;
  float compressor_speed = 50.0;
  float fan_speed = 50.0;
} qo_variables_t;

// A struct to cache the values of environment variables.
typedef struct {
    char serial_number[32];
    float kp = 20.0;
    float ki = 1.0;
    float kd = 0.0;
    float defrost_thr_ambient = 5.0;
    float comp_speed_max = 100.0;
    float comp_speed_min = 0.0;
    float fan_speed_max = 100.0;
    float fan_speed_min = 0.0;
    float pump_speed_max = 100.0;
    float pump_speed_min = 0.0;
    float tw_flex_min = 20.0;
    float tw_flex_max = 40.0;
} env_variables_t;

#endif