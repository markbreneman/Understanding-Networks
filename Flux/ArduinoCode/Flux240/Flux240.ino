#include <Servo.h>      // include the servo library

Servo servoMotor1,servoMotor2, servoMotor3;
// creates an instance of the servo object to control a servo
int servoPin1 = 3; // SMALL - smart average of rooms
int servoPin2 = 5; // MEDIUM - system
int servoPin3 = 9; // LARGE - outdoor
int servo1Angle,servo2Angle,servo3Angle = 0;

int currentValue = 0;
int values[] = {
  0,0,0,0,0,0,0,0,0,0};
int avgApt=0; 
int previouseservo2Angle;

void setup() 
{ 
  Serial.begin(9600);
  // AttachServo's
  servoMotor1.attach(servoPin1);  
  servoMotor2.attach(servoPin2);
  servoMotor3.attach(servoPin3);
} 

void loop() 
{ 
  if(Serial.available()){
    int incomingValue = Serial.read();//READ
    values[currentValue] = incomingValue;
    currentValue++;

    if(currentValue > 10){
      currentValue = 0;
    }
  }

  for( int i=0; i<8; i++){
    int avgApt=+values[i];
//    Serial.println(avgApt);
    //Why 50-270
    int servo1Angle = map(avgApt,0,8,50,270);
  }

  int currentservo2Angle = map(values[8], 0, 1, 0, 180);
  int servo3Angle = map(values[10],0, 1, 50,270);

  //  Serial.println(servo1Angle);
  //  servoMotor1.write(servoAngle1);      
  
 
  Serial.println(servo2Angle);
  if(currentservo2Angle!=previouseservo2Angle){
  servoMotor2.write(servo2Angle);
  //  servoMotor3.write(servoAngle3);
  }
  previouseservo2Angle= currentservo2Angle;
}








