#include <Servo.h>      // include the servo library

Servo servoMotor;       // creates an instance of the servo object to control a servo
int servoPin = 3;       // SMALL - smart average of rooms

Servo servoMotor2;
int servoPin2 = 5; // MEDIUM - system

Servo servoMotor3;
int servoPin3 = 9; // LARGE - outdoor


void setup() { 
  Serial.begin(9600);       // initialize serial communications
  servoMotor.attach(servoPin);  // attaches the servo to the servo object
  servoMotor2.attach(servoPin2);
  servoMotor3.attach(servoPin3);
} 

void loop() 
{ 
  int analogValue = analogRead(A1); // read the analog input 
  // Serial.println(analogValue);      // print it

  // if your sensor's range is less than 0 to 1023, you'll need to
  // modify the map() function to use the values you discovered:
  int servoAngle = map(analogValue, 0, 500, 50, 270);
  if(analogValue>700) servoAngle = 179;
  
  Serial.println(servoAngle);
  
  //int servoAngle = 50;
  
  // move the servo using the angle from the sensor:
  servoMotor.write(servoAngle);      
  servoMotor2.write(servoAngle);
  servoMotor3.write(servoAngle);
//for (int i = 0; i<180; i++){
//  servoMotor.write(5*i);      
//  servoMotor2.write(10*i);
//  if (i = 180){
//  i=0;
//  }
//}
 servoMotor3.write(servoAngle);
}
