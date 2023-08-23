

typedef struct {
  float setpoint;
  int mode;
} db_variables_t;

typedef struct{
  float tc[8];
  float compressor_speed;
  float fan_speed;
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