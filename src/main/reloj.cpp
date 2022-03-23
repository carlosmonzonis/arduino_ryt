#include "reloj.h"

RTC_DS1307 rtc;

void reloj::check_status() {
  if (!rtc.begin()) {
    Serial.println("****** Couldn't find RTC ******");
    Serial.flush();
    abort();
  } else {
    Serial.println("****** Correct status for RTC ******");
  }
}

void reloj::get_pins() {
  Serial.println("-- For developers --");
  Serial.print("Pins for clock functions -> ");
  Serial.print("pin sda: ");
  Serial.print(pin_sda);
  Serial.print(", pin scl: ");
  Serial.println(pin_scl);
}

void reloj::set_time() {
  DateTime old_time = rtc.now();
  rtc.adjust(DateTime(__DATE__, __TIME__));
  DateTime new_time = rtc.now();

  Serial.println("New time has been set");
  Serial.print("Old time: ");
  Serial.println(String("DateTime::TIMESTAMP_FULL:\t ") + old_time.timestamp(DateTime::TIMESTAMP_FULL));
  Serial.print("New time: ");
  Serial.println(String("DateTime::TIMESTAMP_FULL:\t ") + new_time.timestamp(DateTime::TIMESTAMP_FULL));
}

DateTime reloj::get_time() {
  return rtc.now();
}

void reloj::print_time(DateTime time) {
  Serial.print("Current time: ");
  Serial.print(time.day() / 10);
  Serial.print(time.day() % 10);
  Serial.print("/");
  Serial.print(time.month() / 10);
  Serial.print(time.month() % 10);
  Serial.print("/");
  Serial.print(time.year());
  Serial.print(" - ");

  Serial.print(time.hour() / 10);
  Serial.print(time.hour() % 10);
  Serial.print(":");
  Serial.print(time.minute() / 10);
  Serial.print(time.minute() % 10);
  Serial.print(":");
  Serial.print(time.second() / 10);
  Serial.println(time.second() % 10);
}
