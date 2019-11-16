#include <SoftwareSerial.h>
#include <Servo.h>

#define tx 11
#define rx 10
#define ctl 9

SoftwareSerial btSerial(rx,tx);
Servo myservo;

char mode = '0';
int servo_r = 90;

void setup() {
  btSerial.begin(9600);
  myservo.attach(ctl);
  myservo.write(servo_r);

}

void loop() {

  if(btSerial.available()){
    mode = btSerial.read();

    switch(mode){
    case '0':
      btSerial.println("REST\n");
      servo_r = 90;
      myservo.write(servo_r);
      break;
    case '1':
      btSerial.println("R+\n");
      if (servo_r > 0) {
        servo_r = servo_r - 10;
      }
      myservo.write(servo_r);
      break;
    case '2':
      btSerial.println("R-\n");
      if (servo_r < 180) {
        servo_r = servo_r + 10;
      }
      myservo.write(servo_r);
      break;
    }
  }

}
