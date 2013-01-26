#include <Servo.h>      // include the servo library

Servo servoMotor1, servoMotor2, servoMotor3;       // creates an instance of the servo object to control a servo
int servoPin1 = 3; // SMALL - smart average of rooms
int servoPin2 = 5; // MEDIUM - system
int servoPin3 = 9; // LARGE - outdoor
int servoAngle1;
int servoAngle2;
int servoAngle3;

int currentValue = 0;
int values[] = {0,0,0,0,0,0,0,0,0,0};
int avgApt=0; 
 

/*
int ledPin1=13;
int ledPin2=12;
int ledPin3=11;
int ledPin4=10;
*/

void setup() 
{ 
  Serial.begin(9600);
//  pinMode (ledPin1, OUTPUT);
//  pinMode (ledPin2, OUTPUT);
//  pinMode (ledPin3, OUTPUT);
//  pinMode (ledPin4, OUTPUT);

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

    if(currentValue > 8){
      currentValue = 0;
    }
  }

   
  for( int i=0; i<8; i++){
   int avgApt=+values[i];
   Serial.println(avgApt);
   //Why 50-270
   int servo1Angle=map(avgApt,0,8,50,270);
  }
  
  int servo2Angle=map(values[9],0,1,50,270);
  int servo3Angle=map(values[10],0,1,50,270);
  
  servoMotor1.write(servoAngle1);      
  servoMotor2.write(servoAngle2);
  servoMotor3.write(servoAngle3);
  
  
/*
  if (values[5] == 1){
//    digitalWrite (ledPin1, HIGH);
  }
  else if (values[5]==0){
    digitalWrite (ledPin1, LOW);
  } 
  //
  if (values[6] == 1){
    digitalWrite (ledPin2, HIGH);
  }
  else if (values[6]==0){
    digitalWrite (ledPin2, LOW);
  }
  //  
  if (values[7] == 1){
    digitalWrite (ledPin3, HIGH);
  }
  else if (values[7]==0){
    digitalWrite (ledPin3, LOW);
  }

  if (values[8] == 1){
    digitalWrite (ledPin4, HIGH);
  }
  else if (values[8]==0){
    digitalWrite (ledPin4, LOW);
  }
  */

//  myservo.write(outputValue3);
  //}
}






