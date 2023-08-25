#ifndef VAR_STRUCTS_H
#define VAR_STRUCTS_H

typedef struct {
  float setpoint = 20.0;
  int mode = 1;
  int poll_interval_ms = 2000;
  int nc_time_sync_interval_s = 10;
  int nc_info_interval_s = 5;
} db_variables_t;

typedef struct{
  float tc[8] = {0,0,0,0,0,0,0,0};
  time_t last_poll_time = 0;
  float compressor_speed = 50.0;
  float fan_speed = 50.0;
} qo_variables_t;

// A struct to cache the values of environment variables.
typedef struct {
    char serial_number[32];
    float kp = 100.0;
    float ki = 100.0;
    float kd = 100.0;
    float comp_speed_max = 100.0;
    float comp_speed_min = 0.0;
    float fan_speed_max = 100.0;
    float fan_speed_min = 0.0;
    float pump_speed_max = 100.0;
    float pump_speed_min = 0.0;
} env_variables_t;

#endif