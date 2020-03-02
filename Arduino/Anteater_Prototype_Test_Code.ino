#include <Servo.h>

Servo jointOne;
Servo jointTwo;

int pos = 0;
int pos1 = 0;
int pos2 = 0;
int max_move = 0;

char val = 0;

void setup() {
  // put your setup code here, to run once:
  jointOne.attach(9);
  jointTwo.attach(10);

  Serial.begin(9600);
  Serial.print("Hello I am alive");

}

void loop() {
  // put your main code here, to run repeatedly:

  //automatic increment TOGETHER
//  for (pos=0;pos <= 90; pos += 1){
//    jointOne.write(pos);
//    jointTwo.write(pos);
//    delay(30);
//  }
  //automatic decrement TOGETHER
//  for (pos = 90; pos >= 0; pos -= 1) {
//    jointOne.write(pos);
//    jointTwo.write(pos);
//    delay(30);
//  } 

  if (Serial.available())
  {
    val = Serial.read();
    Serial.println(val);
    if (val == 'd')
    {
      pos1 = jointOne.read();
      pos2 = jointTwo.read();
      //move motors downward together
      if (pos1 >= pos2)
      {
        max_move = 90 - pos1;
      }
      else if (pos2 > pos1)
      {
        max_move = 90 - pos2;
      }
      for (pos = 0; pos <= max_move; pos += 1)
      {
        jointOne.write(pos1 + pos);
        jointTwo.write(pos2 + pos);
        delay(30);
      }
      
    }
    else if (val == 'a')
    {
      //move motors against each other (one up, two down)
      pos = 0;
      pos1 = jointOne.read();
      pos2 = jointTwo.read();
      for (pos = 0; pos <= 5; pos += 1)
      {
        if (pos1+pos <=90){
        jointOne.write(pos1 + pos);
        }
        if (pos2-pos >= 0){
        jointTwo.write(pos2 - pos);
        }
        delay(30);
      }
    }
    else if (val == 'k')
    {
      //kill movement
      delay(3000); //3 second pause, may want more?
    }
    else if (val == 'u')
    {
      //upward together movement
      pos1 = jointOne.read();
      pos2 = jointTwo.read();
      if (pos1 <= pos2)
      {
        max_move = pos1;
      }
      else if (pos2 < pos1)
      {
        max_move = pos2;
      }
      for (pos = 0; pos <= max_move; pos += 1)
      {
        jointOne.write(pos1 - pos);
        jointTwo.write(pos2 - pos);
        delay(30);
      }
    }
    
  }

}
