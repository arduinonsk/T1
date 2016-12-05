#include <t1.h>
#include <Arduino.h>

T1::T1(){
  pinMode(PIN_SONAR_TRIG, OUTPUT); 
  pinMode(PIN_SONAR_ECHO, INPUT); 
  pinMode(PIN_BUTTON, INPUT_PULLUP); 
  pinMode(PIN_IN1, OUTPUT); 
  pinMode(PIN_IN2, OUTPUT); 
  pinMode(PIN_IN3, OUTPUT); 
  pinMode(PIN_IN4, OUTPUT);   
}

int T1::readSensorL(){
  return analogRead(PIN_SENSOR_LEFT);
}

int T1::readSensorR(){
  return analogRead(PIN_SENSOR_RIGHT);
}

long T1::readSonar(){
  digitalWrite(PIN_SONAR_TRIG, LOW); 
  delayMicroseconds(5); 
  digitalWrite(PIN_SONAR_TRIG, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(PIN_SONAR_TRIG, LOW); 
  pinMode(PIN_SONAR_ECHO, INPUT); 
  long _duration = pulseIn(PIN_SONAR_ECHO, HIGH); 
  return (_duration/2) / 29.1; 
}

bool T1::buttonPressed(){
  return !digitalRead(PIN_BUTTON);
}

void T1::drive(int lvel, int rvel){
  if (lvel > 0) leftMotorForw(lvel);
  else leftMotorBack(abs(lvel));
  if (rvel > 0) rightMotorForw(rvel);
  else rightMotorBack(abs(rvel));
}

void T1::leftMotorForw(int vel){
  int _lmfv = vel;
  digitalWrite(PIN_IN1, LOW);
  analogWrite(PIN_IN2, _lmfv);
}

void T1::leftMotorBack(int vel){
  int _lmbv = vel;
  digitalWrite(PIN_IN2, LOW);
  analogWrite(PIN_IN1, _lmbv);
}

void T1::rightMotorForw(int vel){
  int _rmfv = vel;
  digitalWrite(PIN_IN3, LOW);
  analogWrite(PIN_IN4, _rmfv);  
}

void T1::rightMotorBack(int vel){
  int _rmbv = vel;
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_IN3, _rmbv);  
}