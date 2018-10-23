#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
void setup()
{
  BT.begin(9600);
}
char a;
void loop()
{
  if (BT.available()) {
    a = (BT.read());
    if (a == '2') {
      
      BT.println("Do you know u n t i _ k o n g ?");
    }
    if (a == '1') {
      BT.println("HC-06_Bluetooth_module_Standby!");
    }
  }
}
