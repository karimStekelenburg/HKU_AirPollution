#ifndef Numa17Control_H
#define Numa17Control_H

#include <arduino.h>

class Numa17Control {
  private:
    // hardware config
    static int const stepsPerRev = 200;
    static float const revsPerCoordinate = 1;
    static int const microsecondSpeedDelay = 2000;

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
    void setPosition(int position);
    void noMove();
};
#endif
