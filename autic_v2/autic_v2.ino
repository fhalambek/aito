#include <stdlib.h>

/*
const int trigPin[0] = 3;
const int echoPin[0] = 2;
const int trigPin[1] = 4;
const int echoPin[1] = 5;
*/
const int foward_l = 10;
const int foward_r = 9;
const int back_l = 12;
const int back_r = 11;



void setup() {
  pinMode(back_r, OUTPUT);     
  pinMode(back_l, OUTPUT);     
  pinMode(foward_r, OUTPUT);   
  pinMode(foward_l, OUTPUT);   
  
  //pinMode(6, INPUT);     //ir
  
  pinMode(13, OUTPUT);    //onboard led
  
}

void loop() {
  digitalWrite(10, HIGH);
  
  //digitalWrite(9, HIGH);
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
      delay(150);
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
      delay(150);
    }
    analogWrite(foward_r, power);
  }
  else{
    digitalWrite(back_r, HIGH);
    analogWrite(foward_r, 255+power);
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
/*
int dist(int side){
  int duration, cm;
  
  pinMode(trigPin[side], OUTPUT);
  digitalWrite(trigPin[side], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[side], HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin[side], LOW);

  pinMode(echoPin[side], INPUT);
  duration = pulseIn(echoPin[side], HIGH, 300*2*29);

  cm = microsecondsToCentimeters(duration);
  return cm;
}
*/
long microsecondsToCentimeters(long microseconds) {
  if(microseconds == 0) return 1000;
  return microseconds / 29 / 2;
}
