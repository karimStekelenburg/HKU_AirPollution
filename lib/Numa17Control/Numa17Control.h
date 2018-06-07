#ifndef Numa17Control_H
#define Numa17Control_H

#include <arduino.h>

class Numa17Control {
  /* CALCULATIONS
    ray = 5mm
    circumference           = 0,005 * 3,14 = 0,0157
    total rounds for 100m  = 0,0157 * 99 = 6305,732484076

  */



  private:
    // hardware config
    static int const stepsPerRev = 200;
    static float const revsPerCoordinate = 0.37;
    static int const microsecondSpeedDelay = 2000;
    // 100px = 64 rounds

    // driver pins
    int dirPin;
    int stepPin;

    // position keeping
    int currentPos = 0;
    int nextPos = 0;
    long plannedSteps = 0;
    bool direction = false;


  public:
    Numa17Control(int dirPin, int stepPin);
    int calcPlannedCoordinates();
    int calcPlannedRevs();
    void updatePlannedSteps();
    void run();
    void move(bool dir, int steps);
    void calibrate();
    void setMax();
    void setPosition(int position);
    void noMove();
};
#endif
