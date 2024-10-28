
#define Leftmotor1F 8
#define Leftmotor1R 9
#define Rightmotor2F 10
#define Rightmotor2R 11
#define UnloadF 12
#define UnloadR 13

#define LME 5
#define RME 6

#define LMS 10
#define RMS 10

char t;
 
void setup() {

pinMode(Leftmotor1F,OUTPUT);
pinMode(Leftmotor1R,OUTPUT);
pinMode(LME,OUTPUT);
pinMode(Rightmotor2F,OUTPUT);
pinMode(Rightmotor2R,OUTPUT);
pinMode(RME,OUTPUT);

pinMode(UnloadF,OUTPUT);
pinMode(UnloadR,OUTPUT);

analogWrite(LME,100);
analogWrite(RME,100);

Serial.begin(9600);
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){  
  Serial.println("Move  Forward");

  digitalWrite(Leftmotor1F,LMS);
  digitalWrite(Leftmotor1R,0);

  digitalWrite(Rightmotor2F,RMS);
  digitalWrite(Rightmotor2R,0);
}
 
else if(t == 'B'){
  Serial.println("Move  Reverse");

  digitalWrite(Leftmotor1F,0);
  digitalWrite(Leftmotor1R,LMS);

  digitalWrite(Rightmotor2F,0);
  digitalWrite(Rightmotor2R,RMS);
}
  
else if(t == 'L'){
  Serial.println("Move  Left");

  digitalWrite(Leftmotor1F,0);
  digitalWrite(Leftmotor1R,0);

  digitalWrite(Rightmotor2F,RMS);
  digitalWrite(Rightmotor2R,0);
}
 
else  if(t == 'R'){ 
  Serial.println("Move  Right");
  digitalWrite(Leftmotor1F,LMS);
  digitalWrite(Leftmotor1R,0);

  digitalWrite(Rightmotor2F,0);
  digitalWrite(Rightmotor2R,0);
}

else if(t ==  'U'){
  Serial.println("UnloadF");
  digitalWrite(UnloadF,HIGH);
  digitalWrite(UnloadR,LOW);
}
else if(t == 'u'){
  Serial.println("UnloadR");
  digitalWrite(UnloadF,LOW);
  digitalWrite(UnloadR,HIGH);
}

delay(100);
t='x';
 //Serial.println("OFF");

  digitalWrite(Leftmotor1F,0);
  digitalWrite(Leftmotor1R,0);

  digitalWrite(Rightmotor2F,0);
  digitalWrite(Rightmotor2R,0);

  digitalWrite(UnloadF,0);
  digitalWrite(UnloadR,0);
}