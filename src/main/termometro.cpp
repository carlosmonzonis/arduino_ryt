#include "termometro.h"

DHT dht(termometro::data, termometro::type);

void termometro::check_status() {
  dht.begin();
  if (isnan(dht.readHumidity())) {
    Serial.println("****** Couldn't find DHT ******");
    Serial.flush();
    abort();
  } else {
    Serial.println("****** Correct status for DHT ******");
  }
}

void termometro::get_pins() {
  Serial.println("-- For developers --");
  Serial.print("Pins for temperature and humidity functions -> ");
  Serial.print("pin data: ");
  Serial.print(data);
  Serial.print(", DHT type: ");
  Serial.println(type);
}

float termometro::get_temperature() {
  return dht.readTemperature();
}

float termometro::get_humidity() {
  return dht.readHumidity();
}

void termometro::print_measurement(float temp, float hum) {
  Serial.print("Temperature: ");
  Serial.print(temp);

  Serial.print(" - ");

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("%");
}
