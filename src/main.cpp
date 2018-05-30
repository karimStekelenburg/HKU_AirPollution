#include <arduino.h>
#include <Numa17Control.h>

Numa17Control numa(12, 13);
int inputPos;
void setup(){
  Serial.begin(9600);
}

void loop(){
  inputPos = 200;
  if(Serial.available() > 0){
      inputPos = Serial.parseInt();
  }

  if(inputPos != 200){
    numa.setPosition(inputPos);
  }
  numa.run();
}
