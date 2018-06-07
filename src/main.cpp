#include <arduino.h>
#include <Numa17Control.h>
String readString;
Numa17Control steppers[8] = {
  Numa17Control(4, 3),
  Numa17Control(7, 6),
  Numa17Control(10, 9),
  Numa17Control(13, 12),
  Numa17Control(34, 35),
  Numa17Control(42, 43),
  Numa17Control(28, 29),
  Numa17Control(22, 23)
};

void setup() {
  Serial.begin(9600);
  readString = "";

  for(unsigned int i = 0; i < 8; i++){
    steppers[i].noMove();
  }
}

void loop() {
  Serial.flush();
  if(Serial.available()){
    delay(1000);
    readString = "";
    while (Serial.available()) {
      if (Serial.available() > 0) {
        char c = Serial.read();
        readString += c;
      }
    }
  }

  // Serial.println(readString.substring(0,3));
  String commandType = readString.substring(0,3);

  Serial.println(commandType);
  if (commandType == "POS"){
    steppers[0].setPosition(readString.substring(3,5).toInt());
    steppers[1].setPosition(readString.substring(5,7).toInt());
    steppers[2].setPosition(readString.substring(7,9).toInt());
    steppers[3].setPosition(readString.substring(9,11).toInt());
    steppers[4].setPosition(readString.substring(11,13).toInt());
    steppers[5].setPosition(readString.substring(13,15).toInt());
    steppers[6].setPosition(readString.substring(15,17).toInt());
    steppers[7].setPosition(readString.substring(17,19).toInt());

    for(unsigned int i = 0; i < 8; i++){
      // Serial.println("Running for stepper: " + String(i));
      steppers[i].run();
    }
  }
  else if (commandType =="CAL"){
    for(int i = 0; i < 8; i++){
      steppers[i].calibrate();
    }

// POS4020304050607080
  }
  else if (commandType == "MVE"){
    int stepperId = readString.substring(3,4).toInt();
    int steps = readString.substring(4,7).toInt();
    int dirr = readString.substring(7,8).toInt(); // 0 is false, 1 is true
    steppers[stepperId].move(dirr, steps);
  }
  else if (commandType == "STP"){
    for(int i = 0; i < 8; i++){
      steppers[i].noMove();
    }
  }
  else if (commandType == "MAX"){
    for(int i = 0; i < 8; i++){
      steppers[i].setMax();
    }
  }
}
//
// #include <arduino.h>
//
// int dirPin = 3;
// int stepPin = 4;
//
// int stepsPerRev = 200;
//
//
// void setup(){
//   pinMode(stepPin, OUTPUT);
//   pinMode(dirPin, OUTPUT);
// }
//
// void loop(){
//   digitalWrite(dirPin, LOW);
//   digitalWrite(stepPin, HIGH);
//   delayMicroseconds(2000);
//   digitalWrite(stepPin, LOW);
//   delayMicroseconds(2000);
//
//
// }



// #include <arduino.h>
// #include <Numa17Control.h>
//
// Numa17Control numa = Numa17Control(3, 16);
//
// void setup(){
//   numa.calibrate();
//   numa.setPosition(40);
// }
//
// void loop(){
//
//   numa.run();
//
// }
