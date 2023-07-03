#ifndef YOTTA_MODULE_H
#define YOTTA_MODULE_H

#include <Arduino.h>
#include <ArduinoModbus.h>

class YottaModule {

    private:
        int slave_id;

    public:
        YottaModule(int slave_id);
        void readTC_float(float_t *tc);
        void readTC_int(int32_t *tc);
        void readTC_int_decimal(int32_t *tc);
        void setTypeTC();
        void getType();
        void getModuleName();
};

#endif