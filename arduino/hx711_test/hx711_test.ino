/*
 * This Arduino program is used to find the right value for the calibration_ratio
 * 
 * Use the HX711 library from:
 * https://github.com/aguegu/ardulibs/tree/master/hx711
 * The readme file of this repo also explains how to find the calibration_ratio 
 */
#include "hx711.h"

Hx711 scale(A1, A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(scale.averageValue());
  delay(200);
}