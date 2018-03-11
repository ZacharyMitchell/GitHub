//-----------------------------
//    Robotic Arm V1.0
//-----------------------------
// This test moves the robotic arm to the angular limits
#include <DynamixelSerial.h>

const int servo01 = 17;
const int servo02 = 15;
const int servo03 = 13;
const int servo04 = 1;


void setup() {

  Dynamixel.begin(1000000);
  Dynamixel.ledStatus(servo01, ON);
  Dynamixel.ledStatus(servo02, ON);
  Dynamixel.ledStatus(servo03, ON);
  Dynamixel.ledStatus(servo04, ON);
  delay(1000);
  
  Dynamixel.move(servo01, 511.5);
  Dynamixel.move(servo02, 511.5);
  Dynamixel.move(servo03, 511.5);
  Dynamixel.move(servo04, 511.5);
  delay(4000);
}

void loop() {
  Dynamixel.move(servo01, 511.5);
  Dynamixel.move(servo02, 511.5);
  Dynamixel.move(servo03, 511.5);
  Dynamixel.move(servo04, 511.5);
  delay(6000);

  Dynamixel.move(servo01, 818.4);
  Dynamixel.move(servo02, 204.6);
  Dynamixel.move(servo03, 204.6);
  Dynamixel.move(servo04, 204.6);
  delay(6000);

  Dynamixel.move(servo01, 204.6);
  Dynamixel.move(servo02, 818.4);
  Dynamixel.move(servo03, 818.4);
  Dynamixel.move(servo04, 818.4);
  delay(6000);

}
