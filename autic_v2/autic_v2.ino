#include <stdlib.h>


const int trigPinL = 6;
const int echoPinL = 5;
const int trigPinR= 12;
const int echoPinR = 11;

const int foward_l = 9;
const int foward_r = 10;
const int back_l = 7;
const int back_r = 8;

const int redR = 16;
const int greenR = 17;
const int redL = 14;
const int greenL = 15;

void setup() {
  pinMode(back_r, OUTPUT);     
  pinMode(back_l, OUTPUT);     
  pinMode(foward_r, OUTPUT);   
  pinMode(foward_l, OUTPUT);   

  pinMode(redR, OUTPUT);
  pinMode(greenR, OUTPUT);
  pinMode(redL, OUTPUT);
  pinMode(greenL, OUTPUT);
  
  
  //pinMode(6, INPUT);     //ir
  
  pinMode(13, OUTPUT);    //onboard led
  
}

void loop() {
  //drive(100);

  lights();
  
  if(distR() < 30 or distL() < 30){
    int s = rand();
    brake();
    
    drive(-100);
    delay(700);
    lights();
    if (s % 2 == 0) {
      leftMotor(100);
      rightMotor(-100);
    }
    else {
      rightMotor(100);
      leftMotor(-100);
    }
    while(distL() <= 85 or distR() <= 85);
    lights();
    delay(rand()%200 + 100);
    lights();
    brake();
  }
  if(distR() < 60 and distL() < 60){
    drive(75);
  }
  else if(distR() < 60){
    leftMotor(100);
    rightMotor(0);
    delay(400);
  }
  else if(distL() < 60){
    leftMotor(0);
    rightMotor(100);
    delay(400);
  }
  //else if(distR() < 30
  
  drive(100);
  
  lights();
  
  
  /*
  for(int i = -100; i <= 100; i++){
    drive(i);
    delay(50);
  }
  for(int i = 100; i >= -100; i--){
    drive(i);
    delay(50);
  }
  */

  
}




void leftMotor(int percent){
  int power = (percent * 255)/100;
  if(power >= 0){
    if(digitalRead(back_l == HIGH)){
      digitalWrite(back_l, LOW);
      //delay(150);
    }
    analogWrite(foward_l, power);
  }
  else{
    digitalWrite(back_l, HIGH);
    analogWrite(foward_l, 255+power);
  }
}
void rightMotor(int percent){
  int power = (percent * 255)/100;
  if(power >= 0){
    if(digitalRead(back_r == HIGH)){
      digitalWrite(back_r, LOW);
      //delay(150);
    }
    analogWrite(foward_r, power);
  }
  else{
    digitalWrite(back_r, HIGH);
    analogWrite(foward_r, 255+power);
  }
}

void lights(){
  
  if(distL() < 30){
    digitalWrite(greenL, LOW);
    digitalWrite(redL, HIGH);
  }
  else if(distL() < 60){
    digitalWrite(greenL, HIGH);
    digitalWrite(redL, HIGH);
  }
  else{
    digitalWrite(greenL, HIGH);
    digitalWrite(redL, LOW);
  }

  
  if(distR() < 30){
    digitalWrite(greenR, LOW);
    digitalWrite(redR, HIGH);
  }
  else if(distR() < 60){
    digitalWrite(greenR, HIGH);
    digitalWrite(redR, HIGH);
  }
  else{
    digitalWrite(greenR, HIGH);
    digitalWrite(redR, LOW);
  }
  
}

void drive(int power){
  rightMotor(power);
  leftMotor(power);
}
void brake(){
  leftMotor(0);
  rightMotor(0);
  delay(150);
}



int distR(){
  int duration, cm;
  
  pinMode(trigPinR, OUTPUT);
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPinR, LOW);

  pinMode(echoPinR, INPUT);
  duration = pulseIn(echoPinR, HIGH, 300*2*29);

  cm = microsecondsToCentimeters(duration);
  return cm;
}
int distL(){
  int duration, cm;
  
  pinMode(trigPinL, OUTPUT);
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPinL, LOW);

  pinMode(echoPinL, INPUT);
  duration = pulseIn(echoPinL, HIGH, 300*2*29);

  cm = microsecondsToCentimeters(duration);
  return cm;
}

long microsecondsToCentimeters(long microseconds) {
  if(microseconds == 0) return 1000;
  return microseconds / 29 / 2;
}
