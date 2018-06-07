#include <arduino.h>
#include "Numa17Control.h"


Numa17Control::Numa17Control(int dirPin, int stepPin) {
  this->dirPin = dirPin;
  this->stepPin = stepPin;
  pinMode(this->dirPin, OUTPUT);
  pinMode(this->stepPin, OUTPUT);
  digitalWrite(this->stepPin, HIGH);
  delayMicroseconds(300);
  digitalWrite(this->stepPin, LOW);

}

int Numa17Control::calcPlannedCoordinates() {
  return this->nextPos - this->currentPos;
}

void Numa17Control::setMax() {
  this->currentPos = 99;
}


// int Numa17Control::calcPlannedRevs() {
//   return this->calcPlannedCoordinates() * this->revsPerCoordinate;
// }
//
// void Numa17Control::updatePlannedSteps() {
//   // Serial.println("Planned steps:");
//   // Serial.println(this->calcPlannedRevs() * this->stepsPerRev);
//   this->plannedSteps = this->calcPlannedRevs() * this->stepsPerRev;
// }
//
void Numa17Control::setPosition(int position) {
  this->nextPos = position;
}


void Numa17Control::calibrate(){
  this->currentPos = 0;
}

void Numa17Control::move(bool dir, int steps){
  digitalWrite(this->dirPin, dir);
  for(int i = 0; i < steps; i++){
    digitalWrite(this->stepPin, LOW);
    delayMicroseconds(this->microsecondSpeedDelay);
    digitalWrite(this->stepPin, HIGH);
    delayMicroseconds(this->microsecondSpeedDelay);
  }
}



void Numa17Control::run(){
  Serial.println(this->currentPos);
  Serial.println();


  this->plannedSteps = (this->nextPos - this->currentPos) * this->revsPerCoordinate * this->stepsPerRev;
  if(this->plannedSteps == 0){
    digitalWrite(this->stepPin, LOW);
    return;
  }
  if(this->plannedSteps < 0){
    this->direction = true;
    this->currentPos -= 1;
  } else {
    this->direction = false;
    this->currentPos += 1;
  }

  digitalWrite(this->dirPin, this->direction);
  for(int i = 0; i < revsPerCoordinate * stepsPerRev; i++){
    digitalWrite(this->stepPin, LOW);
    delayMicroseconds(this->microsecondSpeedDelay);
    digitalWrite(this->stepPin, HIGH);
    delayMicroseconds(this->microsecondSpeedDelay);
  }
}

void Numa17Control::noMove(){
  digitalWrite(this->stepPin, HIGH);
  delayMicroseconds(this->microsecondSpeedDelay);
  digitalWrite(this->stepPin, LOW);
  delayMicroseconds(this->microsecondSpeedDelay);
}
