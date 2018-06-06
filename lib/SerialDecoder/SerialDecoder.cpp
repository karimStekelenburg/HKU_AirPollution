#include <arduino.h>
#include "SerialDecoder.h"

SerialDecoder::SerialDecoder(int bautrate){
  this->bautrate = bautrate;
}

void SerialDecoder::open(){
  Serial.begin(this->bautrate);
}




void SerialDecoder::readCommand(){
  String readString = "";
  while(Serial.available() <= 0) {} // wait for stuff to come in
  delay(this->bufferDelay); // let the buffer fill
  while (Serial.available()) {
    if (Serial.available() > 0) {
      char c = Serial.read();
      readString += c;
    }
  }

}
