
#include <Servo.h>

int pos = 0;
Servo jointOne;
Servo jointTwo;


void setup() {
  // put your setup code here, to run once:
  jointOne.attach(9);
  jointTwo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos=0;pos <= 90; pos += 1){
    jointOne.write(pos);
    jointTwo.write(pos);
    delay(30);
  }
  
  for (pos = 90; pos >= 0; pos -= 1) {
    jointOne.write(pos);
    jointTwo.write(pos);
    delay(30);
  } 

}
