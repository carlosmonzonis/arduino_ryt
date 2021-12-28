// reloj
#include "Arduino.h"
#include <RTClib.h>

class reloj {
  private:
    static const int pin_sda = 20, pin_scl = 21;
  public:
    static void check_status();
    static void get_pins();
    static void set_time();
    static DateTime get_time();
    static void print_time(DateTime time);
};
