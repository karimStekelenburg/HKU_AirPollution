/**
    HKU_AirPollution, steppa.cpp
    Purpose:  Object for controlling a single stepper motor through Arduino.
              Tested with:
                - Arduino Uno
                - ULN2003A Stepper Motor
    @author Karim Stekelenburg
    @version 0.1 22/05/2018
*/

#include <arduino.h>
#include "steppa.h"

Steppa::Steppa(int pin0, int pin1, int pin2, int pin3) {
  _pin0 = pin0;
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  Serial.println(pin0);
  Serial.println(pin1);
  Serial.println(pin2);
  Serial.println(pin3);
  pinMode(_pin0, OUTPUT);
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, OUTPUT);
  pinMode(_pin3, OUTPUT);
}

void Steppa::runFullCycle(int delayTime){
  this->setPhase1();
  delay(delayTime);
  this->setPhase2();
  delay(delayTime);
  this->setPhase3();
  delay(delayTime);
  this->setPhase4();
  delay(delayTime);
}

void Steppa::setPhase1(){
  digitalWrite(_pin0, HIGH);
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);
  digitalWrite(_pin3, LOW);
}

void Steppa::setPhase2(){
  digitalWrite(_pin0, LOW);
  digitalWrite(_pin1, HIGH);
  digitalWrite(_pin2, LOW);
  digitalWrite(_pin3, LOW);
}

void Steppa::setPhase3(){
  digitalWrite(_pin0, LOW);
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, HIGH);
  digitalWrite(_pin3, LOW);
}

void Steppa::setPhase4(){
  digitalWrite(_pin0, LOW);
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);
  digitalWrite(_pin3, HIGH);
}
