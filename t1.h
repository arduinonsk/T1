#ifndef _T1_H_
#define _T1_H_

#define PIN_SONAR_TRIG A2
#define PIN_SONAR_ECHO A3

#define PIN_SENSOR_LEFT A7
#define PIN_SENSOR_RIGHT A0

#define PIN_BUTTON 2

#define PIN_IN1 9
#define PIN_IN2 3
#define PIN_IN3 6
#define PIN_IN4 5

class T1 {
  public:
    T1();
    int readSensorL();
    int readSensorR();
    long readSonar();
    bool buttonPressed();
    void drive(int , int );
  private:
    void leftMotorForw(int );
    void leftMotorBack(int );
    void rightMotorForw(int );
    void rightMotorBack(int );
};

#endif