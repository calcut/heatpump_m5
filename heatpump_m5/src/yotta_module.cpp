#include "yotta_module.h"


YottaModule::YottaModule(int slave_id) {
    ModbusRTUClient.begin(9600, SERIAL_8N1);
    slave_id = slave_id;
    // ModbusRTUClient.master();
    // ModbusRTUClient.slave(slave_id);
}
void YottaModule::readTC_float(float_t tc[8]) {

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                736, 16)) {  //ABCD

        // float_t tc[8];
        for (int i = 0; i < 8; i++) {
            byte byte_array[4];
            uint16_t msbs = ModbusRTUClient.read();
            uint16_t lsbs = ModbusRTUClient.read();

            // Put bytes in the correct order
            memcpy(&byte_array[2], &msbs, 2);
            memcpy(&byte_array[0], &lsbs, 2);

            // Convert to float and print
            memcpy(&tc[i], &byte_array, 4);
            Serial.printf("TC[%i]: ", i);
            Serial.println(tc[i]);
        }
    }
}
void YottaModule::readTC_int(int32_t tc[8]) {

        if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                    96, 8)) {
            Serial.print("Input Values integer: ");
            while (ModbusRTUClient.available()) {
                int16_t temperature = ModbusRTUClient.read();
                Serial.print(temperature, DEC);
                Serial.print(' ');
            }
            Serial.println();
        }
}

void YottaModule::readTC_int_decimal(int32_t tc[8]) {

        if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                128, 8)) {
            Serial.print("Input Values integer_decimal" );
            while (ModbusRTUClient.available()) {
                int16_t temperature = ModbusRTUClient.read();
                Serial.print(temperature, DEC);
                Serial.print(' ');
            }
            Serial.println();
        }
}



void YottaModule::setTypeTC(){

    // Set the input types to K type thermocouple
    Serial.println("Setting input types to K type thermocouple");

    ModbusRTUClient.beginTransmission(slave_id, HOLDING_REGISTERS, 64, 8);
    for (int i = 0; i < 8; i++) {
        ModbusRTUClient.write(0x0003);
    }
    ModbusRTUClient.endTransmission();
}

void YottaModule::getType(){
    // Read the input types
    Serial.println("Reading input types");

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                64, 8)) {
        Serial.print("Input types: 0x ");
        while (ModbusRTUClient.available()) {
            Serial.print(ModbusRTUClient.read(), HEX);
            Serial.print(' ');
        }
        Serial.println();
    }
}

void YottaModule::getModuleName(){
    // Read the module name
    Serial.println("Reading module name");

    if (ModbusRTUClient.requestFrom(slave_id, HOLDING_REGISTERS,
                                MODULE_NAME_ADDR, 1)) {
        Serial.print("Module Detected: A-");
        while (ModbusRTUClient.available()) {
            Serial.print(ModbusRTUClient.read(), HEX);
            Serial.print(' ');
        }
        Serial.println();
    }
}