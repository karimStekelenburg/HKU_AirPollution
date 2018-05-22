/**
    HKU_AirPollution, steppa.h
    Purpose:  Object for controlling a single stepper motor through Arduino.
              Tested with:
                - Arduino Uno
                - ULN2003A Stepper Motor
    @author Karim Stekelenburg
    @version 0.1 22/05/2018
*/
#ifndef Steppa_h
#define Steppa_h

#include <arduino.h>

class Steppa
{
private:
  int _pin0;
  int _pin1;
  int _pin2;
  int _pin3;

public:
  Steppa(int pin0, int pin1, int pin2, int pin3);
  void runFullCycle(int delayTime);
  void setPhase1();
  void setPhase2();
  void setPhase3();
  void setPhase4();

};

#endif
