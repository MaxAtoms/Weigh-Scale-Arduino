/*
 * Arduino project to read analog weight values from a connected HX711 chip.
 * 
 * Use the HX711 library from:
 * https://github.com/aguegu/ardulibs/tree/master/hx711
 * The readme file of this repo also explains how to find the calibration_ratio 
 */
#include "hx711.h" 
Hx711 scale(A1, A0); // Data and Serial Clock pin

double calibration_ratio = 13.21; // Adapt this value to fit your setup

void setup() {
  Serial.begin(9600);
  scale.setOffset(scale.averageValue());
  scale.setScale(calibration_ratio);
}

void loop() {
  Serial.println(scale.getGram()/1000,2);
  delay(50);
}
