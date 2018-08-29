#include <stdlib.h>

const int trigPin[0] = 3;
const int echoPin[0] = 2;
const int trigPin[1] = 4;
const int echoPin[1] = 5;
const int foward_l = 10;
const int foward_r = 9;
const int back_l = 8;
const int back_r = 7;



void setup() {
  pinMode(back_r, OUTPUT);     
  pinMode(back_l, OUTPUT);     
  pinMode(foward_r, OUTPUT);   
  pinMode(foward_l, OUTPUT);   
  
  //pinMode(6, INPUT);     //ir
  
  pinMode(13, OUTPUT);    //onboard led
  
  pinMode(12, OUTPUT);    //GND
  pinMode(11, OUTPUT);    //5V
  pinMode(4, OUTPUT);     //5V
  digitalWrite(12, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(11, HIGH);
  
}

void loop() {
  
  
}


void leftMotor(int percent){
  int power = (percent * 255)/100;
  if(power >= 0){
    analogWrite(foward_l, power);
  }
  else{
    digitalWrite(back_l, HIGH)
    analogWrite(255+power);
  }
}


void brake(){
  digitalWrite(foward_l, LOW);
  digitalWrite(back_l, LOW);
  digitalWrite(foward_r, LOW);
  digitalWrite(back_r, LOW);
  delay(150);
}

int dist(side){
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

long microsecondsToCentimeters(long microseconds) {
  if(microseconds == 0) return 1000;
  return microseconds / 29 / 2;
}
