#include <Servo.h>

int pos = 0;
char go_to = '0';

Servo jointOne;
Servo jointTwo;


void setup() {
  // put your setup code here, to run once:
  jointOne.attach(9);
  jointTwo.attach(10);

  Serial.begin(9600);
  Serial.println("Hello I am alive");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    go_to = Serial.read();
    Serial.println(go_to);
    if (go_to == 'w')
    { 
      jointOne.write(15);
      jointTwo.write(15);
      Serial.println(jointOne.read());
      Serial.println(jointTwo.read());
    }

    else if (go_to == 'x')
    {
      jointOne.write(30);
      jointTwo.write(30);
      Serial.println(jointOne.read());
      Serial.println(jointTwo.read());
    }

    else if (go_to == 'y')
    {
      jointOne.write(45);
      jointTwo.write(45);
      Serial.println(jointOne.read());
      Serial.println(jointTwo.read());
    }
  }

}
