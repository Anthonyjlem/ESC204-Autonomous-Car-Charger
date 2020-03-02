#include <Servo.h>

int pos = 0;
int pos1 = 0;
int pos2 = 0;
int min_pos = 0;

char val = '0';

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
    val = Serial.read();
    if (val == 'r')
    {
      jointOne.write(0);
      jointTwo.write(0);

      pos1 = 0;
      pos2 = 0;
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
    else if (val == 'w')
    {
      for (pos = pos1; pos <= pos1+5; pos +=1)
      {
        jointOne.write(pos);
        delay(30);
      }
      pos1 += 5;
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
    else if (val == 'x')
    {
      for (pos = pos2; pos <= pos2+5; pos +=1)
      {
        jointTwo.write(pos);
        delay(30);
      }
      pos2 += 5;
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
    else if (val == 'e')
    {
      for (pos = pos1; pos >= pos1 -5; pos -=1)
      {
        jointOne.write(pos);
        delay(30);
      }
      pos1 -= 5;
      
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
    else if (val == 'c')
    {
      for (pos = pos2; pos >= pos2 -5; pos -=1)
      {
        jointTwo.write(pos);
        delay(30);
      }
      pos2 -= 5;
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
    else if (val == 'k')
    {
      min_pos = min(pos1, pos2);
      for (pos = 0; pos <= 90 - pos1; pos += 1)
      {
        while (pos1 + pos <= 90)
        {
          jointOne.write(pos1+pos);
        }
        while (pos2 + pos <= 90)
        {
          jointTwo.write(pos2+pos);
        }
        delay(30);
      }
      
      pos1 = 90;
      pos2 = 90;
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }

    else if (val == 'a')
    {
      //move apart, decreasing
      for (pos = 0; pos <= 5; pos +=1)
      {
        jointOne.write(pos1 + pos);
        jointTwo.write(pos2 + 4*pos);
        delay(30);
      }
      pos1 += 5;
      pos2 += 20;
      
//      for (pos = pos2; pos <= pos2 +20; pos +=1)
//      {
//        jointTwo.write(pos);
//        delay(30);
//      }
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
      
    }
    else if (val == 's')
    {
      //move apart 2, increasing
      for (pos = 0; pos <= 5; pos +=1)
      {
        jointOne.write(pos1 - pos);
        jointTwo.write(pos2 - 4*pos); 
        delay(30);
      }
      pos1 -= 5;
      pos2 -= 20;
      
//      for (pos = pos2; pos >= pos2 -20; pos -=1)
//      {
//        jointTwo.write(pos);
//        delay(30);
//      }
//      pos2 -= 20;
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
    else if (val == 'm')
    {
      //move down together
      for (pos = 0; pos <= 5; pos +=1)
      {
        jointOne.write(pos1 + pos);
        jointTwo.write(pos2 + pos);
        delay(30);
      }
      pos1 += 5;
      pos2 += 5;
      
//      for (pos = pos2; pos <= pos2 +5; pos +=1)
//      {
//        jointTwo.write(pos);
//        delay(30);
//      }
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
    else if (val == 'n')
    {
      //move up together
      for (pos = 0; pos <= 5; pos +=1)
      {
        jointOne.write(pos1 - pos);
        jointTwo.write(pos2 - pos);
        delay(30);
      }
      pos1 -= 5;
      pos2 -= 5;
      
//      for (pos = pos2; pos >= pos2 -5; pos -=1)
//      {
//        jointTwo.write(pos);
//        delay(30);
//      }
      Serial.print("Upper Arm: ");
      Serial.println(pos1);
      Serial.print("Lower Arm: ");
      Serial.println(pos2);
    }
  }

}

//Key:
//a: move second arm down more than first arm
//s: move second arm up more than first arm
//n: move both arms up together
//m: move both arms down together
//k: kill arms (set to bottom location)
//r: reset arms (set to top location)
