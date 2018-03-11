//-----------------------------
//
//    Robotic Arm V1.1
//    Zachary Mitchell
//
//-----------------------------
//Robot Arm moves with controller, limits set to prevent Robot from coliding with itself
//-----------------------------
#include <DynamixelSerial.h>

//Dynamixel ID
const int servo01 = 17;
const int servo02 = 15;
const int servo03 = 13;
const int servo04 = 1;
const int servo05 = 3;

//Button pins
const int button01 = 13;
const int button02 = 12;
const int button03 = 11;
const int button04 = 10;
const int button05 = 9;
const int button06 = 8;
const int button07 = 7;
const int button08 = 6;
const int button09 = 5;
const int button10 = 4;

//Servo limits
const float servoCenter = 511.5;
const float maxAngle = 818.4;
const float minAngle = 204.6;

//Servo position
int pos01 = 0;
int pos02 = 0;
int pos03 = 0;
int pos04 = 0;
int pos05 = 0;



void setup() {
  //Setting up I/O
  pinMode(button01, INPUT);
  pinMode(button02, INPUT);
  pinMode(button03, INPUT);
  pinMode(button04, INPUT);
  pinMode(button05, INPUT);
  pinMode(button06, INPUT);
  pinMode(button07, INPUT);
  pinMode(button08, INPUT);
  pinMode(button09, INPUT);
  pinMode(button10, INPUT);

  //Setting initial button state to low
  digitalWrite(button01, LOW);
  digitalWrite(button02, LOW);
  digitalWrite(button03, LOW);
  digitalWrite(button04, LOW);
  digitalWrite(button05, LOW);
  digitalWrite(button06, LOW);
  digitalWrite(button07, LOW);
  digitalWrite(button08, LOW);
  digitalWrite(button09, LOW);
  digitalWrite(button10, LOW);
  
  //Starting Dynamixel servo communication
  Dynamixel.begin(1000000);
  Dynamixel.ledStatus(servo01, ON);
  Dynamixel.ledStatus(servo02, ON);
  Dynamixel.ledStatus(servo03, ON);
  Dynamixel.ledStatus(servo04, ON);
  Dynamixel.ledStatus(servo05, ON);
  delay(2000);
  Dynamixel.ledStatus(servo01, OFF);
  Dynamixel.ledStatus(servo02, OFF);
  Dynamixel.ledStatus(servo03, OFF);
  Dynamixel.ledStatus(servo04, OFF);
  Dynamixel.ledStatus(servo05, OFF);
  delay(1000);

  //Moving servos to starting position
  Dynamixel.move(servo01, servoCenter);
  Dynamixel.ledStatus(servo01, ON);
  delay(2000);
  Dynamixel.ledStatus(servo01, OFF);
  delay(10);
  Dynamixel.move(servo02, servoCenter);
  Dynamixel.ledStatus(servo02, ON);
  delay(2000);
  Dynamixel.ledStatus(servo02, OFF);
  delay(10);
  Dynamixel.move(servo03, servoCenter);
  Dynamixel.ledStatus(servo03, ON);
  delay(2000);
  Dynamixel.ledStatus(servo03, OFF);
  delay(10);
  Dynamixel.move(servo04, servoCenter);
  Dynamixel.ledStatus(servo04, ON);
  delay(2000);
  Dynamixel.ledStatus(servo04, OFF);
  delay(10);
  Dynamixel.move(servo05, servoCenter);
  Dynamixel.ledStatus(servo05, ON);
  delay(2000);
  Dynamixel.ledStatus(servo05, OFF);
  delay(10);
  
}

void loop() {
//Servo 1 - Link 1
//-------------------------------------------------
   if (digitalRead(button08) == HIGH) {
    pos01 = pos01 + 10;
    if ((servoCenter + pos01) >= 818.4){
      pos01 = maxAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo01, ON);
    Dynamixel.move(servo01, (servoCenter + pos01));
    delay(10);
  }else {
    digitalWrite(button08, LOW);
    Dynamixel.ledStatus(servo01, OFF);
  }
  
   if (digitalRead(button07) == HIGH) {
    pos01 = pos01 - 10;
    if ((servoCenter + pos01) <= 204.6){
      pos01 = minAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo01, ON);
    Dynamixel.move(servo01, (servoCenter + pos01));
    Dynamixel.setAngleLimit (servo01, 200, 800);
    delay(10);
  }else {
    digitalWrite(button07, LOW);
    Dynamixel.ledStatus(servo01, OFF);
  }
//-------------------------------------------------

//Servo 2 - Link 2
//-------------------------------------------------
   if (digitalRead(button06) == HIGH) {
    pos02 = pos02 + 10;
    if ((servoCenter + pos02) >= 818.4){
      pos02 = maxAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo02, ON);
    Dynamixel.move(servo02, (servoCenter + pos02));
    delay(10);
  }else {
    digitalWrite(button06, LOW);
    Dynamixel.ledStatus(servo02, OFF);
  }
  
   if (digitalRead(button05) == HIGH) {
    pos02 = pos02 - 10;
    if ((servoCenter + pos02) <= 204.6){
      pos02 = minAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo02, ON);
    Dynamixel.move(servo02, (servoCenter + pos02));
    delay(10);
  }else {
    digitalWrite(button05, LOW);
    Dynamixel.ledStatus(servo02, OFF);
  }
//-------------------------------------------------

//Servo 3 - Link 3
//-------------------------------------------------
   if (digitalRead(button04) == HIGH) {
    pos03 = pos03 + 10;
    if ((servoCenter + pos03) >= 818.4){
      pos03 = maxAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo03, ON);
    Dynamixel.move(servo03, (servoCenter + pos03));
    delay(10);
  }else {
    digitalWrite(button04, LOW);
    Dynamixel.ledStatus(servo03, OFF);
  }

   if (digitalRead(button03) == HIGH) {
    pos03 = pos03 - 10;
    if ((servoCenter + pos03) <= 204.6){
      pos03 = minAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo03, ON);
    Dynamixel.move(servo03, (servoCenter + pos03));
    delay(10);
  }else {
    digitalWrite(button03, LOW);
    Dynamixel.ledStatus(servo03, OFF);
  }
//-------------------------------------------------

//Servo 4 - Link 4
//-------------------------------------------------
  if (digitalRead(button02) == HIGH) {
    pos04 = pos04 + 10;
    if ((servoCenter + pos04) >= 818.4){
      pos04 = maxAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo04, ON);
    Dynamixel.move(servo04, (servoCenter + pos04));
    delay(10);
  }else {
    digitalWrite(button02, LOW);
    Dynamixel.ledStatus(servo04, OFF);
  }
  
   if (digitalRead(button01) == HIGH) {
    pos04 = pos04 - 10;
    if ((servoCenter + pos04) <= 204.6){
      pos04 = minAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo04, ON);
    Dynamixel.move(servo04, (servoCenter + pos04));
    delay(10);
  }else {
    digitalWrite(button01, LOW);
    Dynamixel.ledStatus(servo04, OFF);
  }
//-------------------------------------------------

//Servo 5- Rotating Base
//-------------------------------------------------
  if (digitalRead(button09) == HIGH) {
    pos05 = pos05 + 10;
    if ((servoCenter + pos05) >= 818.4){
      pos05 = maxAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo05, ON);
    Dynamixel.move(servo05, (servoCenter + pos05));
    delay(10);
  }else {
    digitalWrite(button09, LOW);
    Dynamixel.ledStatus(servo05, OFF);
  }
  
   if (digitalRead(button10) == HIGH) {
    pos05 = pos05 - 10;
    if ((servoCenter + pos05) <= 204.6){
      pos05 = minAngle - servoCenter;
    }
    Dynamixel.ledStatus(servo05, ON);
    Dynamixel.move(servo05, (servoCenter + pos05));
    delay(10);
  }else {
    digitalWrite(button10, LOW);
    Dynamixel.ledStatus(servo05, OFF);
  }
//-------------------------------------------------

}
