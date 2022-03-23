/**
   @file main.ino
   @author Carlos Monzonis Marti (carlosmonzonis@outlook.es)
   @brief
   @version 0.1
   @date 2021-12-15

   @copyright Copyright (c) 2021

*/

/*
  .####.##....##..######..##.......##.....##.########..########..######.
  ..##..###...##.##....##.##.......##.....##.##.....##.##.......##....##
  ..##..####..##.##.......##.......##.....##.##.....##.##.......##......
  ..##..##.##.##.##.......##.......##.....##.##.....##.######....######.
  ..##..##..####.##.......##.......##.....##.##.....##.##.............##
  ..##..##...###.##....##.##.......##.....##.##.....##.##.......##....##
  .####.##....##..######..########..#######..########..########..######.
*/
#include "reloj.h"
#include "termometro.h"

// include the library code:
#include <LiquidCrystal.h>

/*
  .########..########.########.####.##....##.########..######.
  .##.....##.##.......##........##..###...##.##.......##....##
  .##.....##.##.......##........##..####..##.##.......##......
  .##.....##.######...######....##..##.##.##.######....######.
  .##.....##.##.......##........##..##..####.##.............##
  .##.....##.##.......##........##..##...###.##.......##....##
  .########..########.##.......####.##....##.########..######.
*/

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

/*
  ..######..########.########.##.....##.########.
  .##....##.##..........##....##.....##.##.....##
  .##.......##..........##....##.....##.##.....##
  ..######..######......##....##.....##.########.
  .......##.##..........##....##.....##.##.......
  .##....##.##..........##....##.....##.##.......
  ..######..########....##.....#######..##.......
*/

/**
   @brief inicializador para las ocasiones que se quede sin bateria el reloj interno del aparato y el aparato.
   Solo se tendrá que llamar una vez. Se tendra que llamar siempre que el arduino este conectado al pc.

*/
void setup() {
  Serial.begin(9600);
  reloj::check_status();
  reloj::set_time();
  termometro::check_status();
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

/**
   @brief inicializador general.
   Se llamará siempre que se reinicie normalmente el aparato.

*/
// void setup(){
// reloj::check_status();
// termometro::check_status();
// }


/*
  .##........#######...#######..########.
  .##.......##.....##.##.....##.##.....##
  .##.......##.....##.##.....##.##.....##
  .##.......##.....##.##.....##.########.
  .##.......##.....##.##.....##.##.......
  .##.......##.....##.##.....##.##.......
  .########..#######...#######..##.......
*/

void loop() {
 //reloj::print_time(reloj::get_time());
 //termometro::print_measurement(termometro::get_temperature(), termometro::get_humidity());
 
 lcd.setCursor(0, 0);
 lcd.print(reloj::get_time().day() / 10);
 lcd.print(reloj::get_time().day() % 10);
 lcd.print("/"); 
 lcd.print(reloj::get_time().month() / 10);
 lcd.print(reloj::get_time().month() % 10);
 lcd.print("/");
 lcd.print(reloj::get_time().year() % 100);
 //lcd.print(" - ");
 lcd.setCursor(10, 0);
 //lcd.print("T:");
 lcd.print(termometro::get_temperature());
 lcd.print((char)223);
 lcd.print("C");
 lcd.setCursor(0, 1);
 lcd.print(reloj::get_time().hour() / 10);
 lcd.print(reloj::get_time().hour() % 10);
 lcd.print(":");
 lcd.print(reloj::get_time().minute() / 10);
 lcd.print(reloj::get_time().minute() % 10);
 lcd.print(":");
 lcd.print(reloj::get_time().second() / 10);
 lcd.print(reloj::get_time().second() % 10);
  //lcd.print(" - ");
 lcd.setCursor(10, 1);
 //lcd.print("H:");
 lcd.print(termometro::get_humidity());
 lcd.print("%");
 delay(1000);
}
