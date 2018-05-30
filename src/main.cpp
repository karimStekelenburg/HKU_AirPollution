#include <arduino.h>
#include <Numa17Control.h>

Numa17Control numa(12, 13);

void setup(){

}

void loop(){
  numa.setPosition(100);
  numa.run();
}
