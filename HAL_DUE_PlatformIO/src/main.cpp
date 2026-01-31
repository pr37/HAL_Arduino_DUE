#include <Arduino.h>
//sudo chmod 777 /dev/ttyACM3
//sudo usermod -a -G dialout $USER
//sudo usermod -a -G plugdev $USER
void setup() 
{  
  pinMode(13, OUTPUT);
}

void loop() {
  while(1)
  {
    digitalWrite(13,LOW);
    delay(1000);
    digitalWrite(13,HIGH);
    delay(1000);
  }

}