#include "hx711.h"

Hx711 scale(A1, A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(scale.averageValue());
  delay(200);
}
