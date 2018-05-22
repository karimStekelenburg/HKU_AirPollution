#include <arduino.h>
#include <steppa.h>

Steppa stepper(8, 9, 10, 11);

void setup() {
  Serial.begin(9600);
}

void loop() {
  stepper.runFullCycle(5);
}
