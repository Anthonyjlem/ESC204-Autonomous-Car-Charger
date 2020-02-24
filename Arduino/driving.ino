int enA = 9;
int enB = XXX;
int inA1 = 8;
int inA2 = 7;
int inB1 = XXX;
int inB2 = XXX;
char letter = ' ';

void setup() {
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  Serial.begin(9600);
  digitalWrite(inA1,LOW);
  digitalWrite(inA2,LOW);
  digitalWrite(inB1,LOW);
  digitalWrite(inB2,LOW);
}

void loop() {
  if(Serial.available()){
    letter = Serial.read();
    if(letter == 'w'){
      digitalWrite(inA1,HIGH);
      digitalWrite(inA2,LOW);
      digitalWrite(inB1,HIGH);
      digitalWrite(inB2,LOW);
    }else if(letter == 'a'){
      digitalWrite(inA1,HIGH);
      digitalWrite(inA2,LOW);
      digitalWrite(inB1,LOW);
      digitalWrite(inB2,HIGH);
    }else if(letter == 's'){
      digitalWrite(inA1,LOW);
      digitalWrite(inA2,HIGH);
      digitalWrite(inB1,LOW);
      digitalWrite(inB2,HIGH);
    }else if(letter == 'd'){
      digitalWrite(inA1,LOW);
      digitalWrite(inA2,HIGH);
      digitalWrite(inB1,HIGH);
      digitalWrite(inB2,LOW);
    }
  }
}
