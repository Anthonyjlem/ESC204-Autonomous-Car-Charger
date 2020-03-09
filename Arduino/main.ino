#include <Servo.h>

Servo jointOneL;
Servo jointOneR;
Servo jointTwo;

//Motor Connections
#define EnA 6
#define EnB 5
#define In1 7
#define In2 8
#define In3 13
#define In4 12

// define stuff for the arm
int pos = 0;
int posLeft = 90;
//int pos1L = 0;
//int pos1R = 0;
int pos2 = 90;
int min_pos = 0;

// serial line
char val = 0;

// define pins for stepper motor
int stepPin = 3; // step pin
int dirPin = 2; // direction pin

void setup() {
  // servos
  jointOneL.attach(9);
  jointOneR.attach(10);
  jointTwo.attach(11);

  for (pos = 30; pos <= 90; pos += 1){
      jointOneL.write(180-pos);
      jointOneR.write(pos);
      jointTwo.write(pos);
      delay(100);
  }

  // stepper pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // serial
  Serial.begin(9600);
  Serial.print("Hello I am alive");

  // All motor control pins are outputs
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop() {
  //digitalWrite(stepPin, LOW);
  if (Serial.available())
  {
    val = Serial.read();
    Serial.println(val);
    // move forwards
    if (val == 'w')
    {
      // turn on motor A
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      // set speed of motor A
      analogWrite(EnA, 200);
      // turn on motor B
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
      // set speed of motor B
      analogWrite(EnB, 200);
    }
    // move back
    else if (val == 's')
    {
      // turn on motor A
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      // set speed of motor A
      analogWrite(EnA, 200);
      // turn on motor B
      digitalWrite(In3, HIGH);
      digitalWrite(In4, LOW);
      // set speed of motor B
      analogWrite(EnB, 200);
    }
    // turn right
    else if (val == 'd')
    {
      // turn on motor A
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      // set speed of motor A
      analogWrite(EnA, 255);
      // turn on motor B
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
      // set speed of motor B
      analogWrite(EnB, 255);
    }
    // turn left
    else if (val == 'a')
    {
      // turn on motor A
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      // set speed of motor A
      analogWrite(EnA, 255);
      // turn on motor B
      digitalWrite(In3, HIGH);
      digitalWrite(In4, LOW);
      // set speed of motor B
      analogWrite(EnB, 255);
    }
    // stepper moves base left
    else if (val == 'o') {
      Serial.println("Entered o condition");
      digitalWrite(dirPin, LOW); // Enables the motor to move in a particular direction. HIGH = forward.
      // Makes 200 for making one full cycle rotation
      while (1) {
        val = Serial.read();
        if (Serial.available() > 0) {
          break;
        }
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2500);
      }
      Serial.println("End of conditional");
    }
    // stepper moves base right
    else if (val == 'p') {
      digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction. HIGH = forward.
      // Makes 200 pulses for making one full cycle rotation
      //      for(int x = 0; x < 200; x++){
      while (1) {
        val = Serial.read();
        if (Serial.available() > 0) {
          break;
        }
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2500);
      }
      //        digitalWrite(stepPin, LOW);
      //        digitalWrite(stepPin, LOW);
      //      delay(1000);
    }
//    if (val == 'r')
//    {
//      jointOneL.write(90);
//      jointOneR.write(90);
//      jointTwo.write(90);
//
//      pos1L = 90;
//      pos1R = 90;
//      pos2 = 90;
//      Serial.print("Upper Arm: ");
////      Serial.println(pos1);
//      Serial.print("Lower Arm: ");
//      Serial.println(pos2);
//    }
    //    else if (val == 'w')
    //    {
    //      for (pos = pos1; pos <= pos1+5; pos +=1)
    //      {
    //        jointOne.write(pos);
    //        delay(30);
    //      }
    //      pos1 += 5;
    //      Serial.print("Upper Arm: ");
    //      Serial.println(pos1);
    //      Serial.print("Lower Arm: ");
    //      Serial.println(pos2);
    //    }
    //    else if (val == 'x')
    //    {
    //      for (pos = pos2; pos <= pos2+5; pos +=1)
    //      {
    //        jointTwo.write(pos);
    //        delay(30);
    //      }
    //      pos2 += 5;
    //      Serial.print("Upper Arm: ");
    //      Serial.println(pos1);
    //      Serial.print("Lower Arm: ");
    //      Serial.println(pos2);
    //    }
    //    else if (val == 'e')
    //    {
    //      for (pos = pos1; pos >= pos1 -5; pos -=1)
    //      {
    //        jointOne.write(pos);
    //        delay(30);
    //      }
    //      pos1 -= 5;
    //
    //      Serial.print("Upper Arm: ");
    //      Serial.println(pos1);
    //      Serial.print("Lower Arm: ");
    //      Serial.println(pos2);
    //    }
    //    else if (val == 'c')
    //    {
    //      for (pos = pos2; pos >= pos2 -5; pos -=1)
    //      {
    //        jointTwo.write(pos);
    //        delay(30);
    //      }
    //      pos2 -= 5;
    //      Serial.print("Upper Arm: ");
    //      Serial.println(pos1);
    //      Serial.print("Lower Arm: ");
    //      Serial.println(pos2);
    //    }
    //    else if (val == 'a')
    //    {
    //      //move apart, decreasing
    //      for (pos = 0; pos <= 5; pos +=1)
    //      {
    //        jointOne.write(pos1 + pos);
    //        jointTwo.write(pos2 + 4*pos);
    //        delay(30);
    //      }
    //      pos1 += 5;
    //      pos2 += 20;

    //      for (pos = pos2; pos <= pos2 +20; pos +=1)
    //      {
    //        jointTwo.write(pos);
    //        delay(30);
    ////      }
    //      Serial.print("Upper Arm: ");
    //      Serial.println(pos1);
    //      Serial.print("Lower Arm: ");
    //      Serial.println(pos2);
    //
    //    }
    //    else if (val == 's')
    //    {
    //      //move apart 2, increasing
    //      for (pos = 0; pos <= 5; pos +=1)
    //      {
    //        jointOne.write(pos1 - pos);
    //        jointTwo.write(pos2 - 4*pos);
    //        delay(30);
    //      }
    //      pos1 -= 5;
    //      pos2 -= 20;
    //
    //      for (pos = pos2; pos >= pos2 -20; pos -=1)
    //      {
    //        jointTwo.write(pos);
    //        delay(30);
    //      }
    //      pos2 -= 20;
    //      Serial.print("Upper Arm: ");
    //      Serial.println(pos1);
    //      Serial.print("Lower Arm: ");
    //      Serial.println(pos2);
    //    }
        if (val == 'u'){
    for (pos = posLeft; pos <= posLeft+10; pos += 1){
      jointOneL.write(180-pos);
      jointOneR.write(pos);
      jointTwo.write(pos);
      delay(100);
      }
    posLeft = posLeft + 10;
    }
    if (val == 'i'){
    for (pos = posLeft; pos >= posLeft-10; pos -= 1){
      jointOneL.write(180-pos);
      jointOneR.write(pos);
      jointTwo.write(pos);
      delay(100);
      }
    posLeft = posLeft - 10;
    }
  else if (val == 'k')
  {
    //kill movement
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
    //      min_pos = min(pos1, pos2);
    //      for (pos = 0; pos <= 90 - pos1; pos += 1)
    //      {
    //        while (pos1 + pos <= 90)
    //        {
    //          jointOne.write(pos1+pos);
    //        }
    //        while (pos2 + pos <= 90)
    //        {
    //          jointTwo.write(pos2+pos);
    //        }
    //        delay(30);
    //      }
    //
    //      pos1 = 90;
    //      pos2 = 90;
    //      Serial.print("Upper Arm: ");
    //      Serial.println(pos1);
    //      Serial.print("Lower Arm: ");
    //      Serial.println(pos2);
    while (1) {
      if (Serial.available() > 0) {
        break;
      }
    }

    //      delay(3000); //3 second pause, may want more?
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
