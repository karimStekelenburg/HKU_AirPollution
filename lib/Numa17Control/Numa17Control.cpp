#include <arduino.h>
#include "Numa17Control.h"


Numa17Control::Numa17Control(int dirPin, int stepPin) {
  this->dirPin = dirPin;
  this->stepPin = stepPin;
}

int Numa17Control::calcPlannedCoordinates() {
  return this->nextPos - this->currentPos;
}

int Numa17Control::calcPlannedRevs() {
  return this->calcPlannedCoordinates() * this->revsPerCoordinate;
}

void Numa17Control::updatePlannedSteps() {
  this->plannedSteps = this->calcPlannedRevs() * this->stepsPerRev;
}

void Numa17Control::setPosition(int position) {
  this->nextPos = position;
}

void Numa17Control::run(){
  this->updatePlannedSteps();
  if(this->plannedSteps == 0){ return;}

  if(this->plannedSteps < 0){
    this->direction = false;
    this->plannedSteps = this->plannedSteps - this->stepsPerRev * this->revsPerCoordinate;
    this->currentPos -= 1;
  } else {
    this->direction = true;
    this->plannedSteps = this->plannedSteps + this->stepsPerRev * this->revsPerCoordinate;
    this->currentPos += 1;
  }
  digitalWrite(this->dirPin, this->direction);
  digitalWrite(this->stepPin, HIGH);
  delayMicroseconds(this->microsecondSpeedDelay);
  digitalWrite(this->stepPin, LOW);
  delayMicroseconds(this->microsecondSpeedDelay);
}
