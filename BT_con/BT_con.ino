#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BT(10, 11);
Servo myservo;
int servo_r = 90;
char a;

void setup()
{
  BT.begin(9600);
  myservo.attach(9);
  myservo.write(servo_r);
}

void loop()
{
  if (BT.available()) {
    a = (BT.read());
    if (a == '2') {
      BT.println("r+");
      if (servo_r <= 180){
      servo_r = servo_r + 10;
      }
      myservo.write(servo_r);
    }
    if (a == '1') {
      BT.println("r-");
      if (servo_r >= 0){
      servo_r = servo_r - 10;
      }
      myservo.write(servo_r);
    }
    if (a == '0') {
      BT.println("r_reset");
      servo_r = 90;
      myservo.write(servo_r);
    }
    }
}
