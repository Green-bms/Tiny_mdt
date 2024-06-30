
/*
 tiny_htt

 Tiny portable gadget, which measures:
 - humidity and ambient temperature by HTU21D sensor
 - object temperature by MLX90614 sensor
 
 The measured data is shown on a 0.96 inch OLED display.
 The controller used is ATtiny85.
  
 Versions:

  - Ver. 0.00 date 27/06/2024 created by Sergio Ghirardelli (first release)

*/



#include <TinyWireM.h>
#include <Adafruit_MiniMLX90614.h>

#include <Wire.h>
#include "SparkFunHTU21D.h"


#include <Tiny4kOLED.h>



Adafruit_MiniMLX90614 mlx = Adafruit_MiniMLX90614();

HTU21D htu21d_sensor;






void setup() {
  mlx.begin();
  Wire.begin();
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
  oled.print("OT=     ^C");
  htu21d_sensor.begin();
  }
  


void loop() {

   float hum = htu21d_sensor.readHumidity();
   float t_amb = htu21d_sensor.readTemperature();
   float t_obj = mlx.readObjectTempC();
   
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
                      if ((t_amb > 125)||(hum < -40)) {oled.print("####");}
                      
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
                    if ((t_obj < -99)) {oled.print(t_obj,0);}
                          else if ((t_obj > 99)||(t_obj < -9)) {
                          oled.print(" ");
                          oled.print(t_obj,0);
                          } 
                         else if ((t_obj > 9)||(t_obj < 0)) {
                          oled.print("  ");
                          oled.print(t_obj,0);
                          } 
                         else if (t_obj >= 0) {
                          oled.print("   ");
                          oled.print(t_obj,0);
                          } 

                 
               
}
