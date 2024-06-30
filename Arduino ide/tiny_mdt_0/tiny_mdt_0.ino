


//#include "degree.h"

#include <TinyWireM.h>
#include <Adafruit_MiniMLX90614.h>

#include <Wire.h>
#include <VL53L0X.h>
/*#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"*/

#include <Tiny4kOLED.h>

VL53L0X sensor;
#define LONG_RANGE
#define HIGH_ACCURACY

Adafruit_MiniMLX90614 mlx = Adafruit_MiniMLX90614();

/*// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

SSD1306AsciiWire oled;*/


//int dist_filtered, dist_index, dist_mem[10];


void setup() {
  mlx.begin();
  Wire.begin();
  delay(100);
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.clear();
  oled.on();
  oled.setFontX2(FONT6X8);
  oled.setCursor(0, 0);
  oled.print("D =     cm");
  oled.setCursor(0, 3);
  oled.print("AT=     ^C");
  oled.setCursor(0, 6);
  oled.print("OT=     ^C");
  sensor.setTimeout(500);
  sensor.init();
  sensor.startContinuous();
/*
#if RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
#endif // RST_PIN >= 0

#if RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
#endif // RST_PIN >= 0
  // Call oled.setI2cClock(frequency) to change from the default frequency.
  oled.setFont(System5x7);
  //oled.setFont(ZevvPeep8x16);
  oled.clear();
 // oled.print("D = 15,7 °C");*/

}
  


void loop() {
 
  unsigned long t1;
  float pippo = mlx.readAmbientTempC();
  float pluto = mlx.readObjectTempC();
  int t_amb = int (pippo);
  int t_obj = int (pluto); 
  int dist;
  if (millis() - t1 >= 500) 
                  {
                     
                    
                    dist = map(sensor.readRangeContinuousMillimeters(), 0, 2000, 0, 200);
                    
                    oled.setCursor(40, 0);
                    //oled.print(dist);
                      if ((dist > 200)||(dist < 0)) {oled.print("####");}
                         
                         else if (dist > 99) {
                          oled.print(" ");
                          oled.print(dist);
                          } 
                         else if (dist > 9) {
                          oled.print("  ");
                          oled.print(dist);
                          } 
                         else {
                          oled.print("   ");
                         oled.print(dist);
                          } 
                    oled.setCursor(40, 3);
                      if ((t_amb < -99)) {oled.print(t_amb);}
                          else if ((t_amb > 99)||(t_amb < -9)) {
                          oled.print(" ");
                          oled.print(t_amb);
                          } 
                         else if ((t_amb > 9)||(t_amb < 0)) {
                          oled.print("  ");
                          oled.print(t_amb);
                          } 
                         else if (t_amb >= 0) {
                          oled.print("   ");
                          oled.print(t_amb);
                          }
                    oled.setCursor(40, 6);
                    if ((t_obj < -99)) {oled.print(t_amb);}
                          else if ((t_obj > 99)||(t_obj < -9)) {
                          oled.print(" ");
                          oled.print(t_obj);
                          } 
                         else if ((t_obj > 9)||(t_obj < 0)) {
                          oled.print("  ");
                          oled.print(t_obj);
                          } 
                         else if (t_obj >= 0) {
                          oled.print("   ");
                          oled.print(t_obj);
                          }
                    t1 += 500;
                  }

}
