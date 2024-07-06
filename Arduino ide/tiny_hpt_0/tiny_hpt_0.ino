/*
 tiny_htp

 Tiny portable weather station, which measures humidity, temperature and barometric pressure.
 the sensor used is the BME280.
 The measured data is shown on a 0.96 inch OLED display.
 The controller used is ATtiny85.
  
 Versions:

  - Ver. 0.00 date 27/06/2024 created by Sergio Ghirardelli (first release)

*/

#include <Wire.h>
#include <Tiny4kOLED.h>
#include "SimpleBME280.h"

SimpleBME280 bme280;
float pbase, t_amb, p, hum;


void setup() {
  
  Wire.begin();
  bme280.begin();
  delay(100);
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.clear();
  oled.on();
  oled.setFontX2(FONT6X8);
  oled.setContrast(1);
  oled.setCursor(0, 0);
  oled.print("H =      %");
  oled.setCursor(0, 3);
  oled.print("AT=     ^C");
  oled.setCursor(0, 6);
  oled.print("P =");
  
  }
  


void loop() {

  bme280.update();
  t_amb = bme280.getT();
  p = bme280.getP()/100;
  hum = bme280.getH();

   
                      oled.setCursor(40, 0);
                      if ((hum > 100)||(hum < 0)) {oled.print("####");}
                         
                         else if (hum > 99) {
                          oled.print(" ");
                          oled.print(hum,0);
                          } 
                         else if (hum > 9) {
                          oled.print("  ");
                          oled.print(hum,0);
                          } 
                         else {
                          oled.print("   ");
                         oled.print(hum,0);
                          }
                    oled.setCursor(40, 3);
                      if ((t_amb > 85)||(hum < -40)) {oled.print("####");}
                      
                          else if ((t_amb > 99)||(t_amb < -9)) {
                          oled.print(" ");
                          oled.print(t_amb,0);
                          } 
                         else if ((t_amb > 9)||(t_amb < 0)) {
                          oled.print("  ");
                          oled.print(t_amb,0);
                          } 
                         else if (t_amb >= 0) {
                          oled.print("   ");
                          oled.print(t_amb,0);
                          }
                    oled.setCursor(40, 6);
                      if ((p > 1100)||(p < 300)) {oled.print("####");}
                          else if (p > 999) {oled.print(p,1);}
                          else if (p > 99) {
                          oled.print(" ");
                          oled.print(p,1);
                          } 
                        

                 
               
}
