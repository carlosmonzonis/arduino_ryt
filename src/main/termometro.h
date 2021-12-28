// termometro
#include "Arduino.h"
#include <DHT.h>

class termometro{
  public:
    static const uint8_t data = 2;
    static const uint8_t type = DHT11;
  public:
    static void check_status();
    static void get_pins();
    static float get_temperature();
    static float get_humidity();
    static void print_measurement(float temp, float hum);
};
