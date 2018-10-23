#include <Servo.h>

Servo myservo;

void setup() {
  int servo_r = 90;
  myservo.attach(9);
  myservo.write(servo_r);
}

void loop() {}
