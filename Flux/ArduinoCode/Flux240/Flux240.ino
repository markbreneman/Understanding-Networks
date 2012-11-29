#include <Servo.h> 

int currentValue = 0;
int values[] = {
  0,0,0,0};

int ledPin1=13;
int ledPin2=12;
int ledPin3=11;
int ledPin4=10;

Servo myservo;  // create servo object to control a servo 

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object 
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  pinMode (ledPin4, OUTPUT);
} 

void loop() 
{ 
  if(Serial.available()){
    int incomingValue = Serial.read();
//    Serial.println(incomingValue);
    values[currentValue] = incomingValue;
    currentValue++;
    if(currentValue > 3){ 
      currentValue = 0;
    }
  }
  Serial.println(values[0]);
  Serial.println(values[1]);
  Serial.println(values[2]);


  //    if (values[0] == 1){
  //     digitalWrite (ledPin1, HIGH);
  //    }
  //    else if (values[0]==0){
  //      digitalWrite (ledPin1, LOW);
  //    } 
  //  //
  //      if (values[1] == 1){
  //     digitalWrite (ledPin2, HIGH);
  //    }
  //    else if (values[1]==0){
  //      digitalWrite (ledPin2, LOW);
  //    }
  //  //  
  //      if (values[2] == 1){
  //     digitalWrite (ledPin3, HIGH);
  //    }
  //    else if (values[2]==0){
  //      digitalWrite (ledPin3, LOW);
  //    }
  //  
  //    if (values[3] == 1){
  //   digitalWrite (ledPin4, HIGH);
  //  }
  //  else if (values[3]==0){
  //    digitalWrite (ledPin4, LOW);
  //  }

  //   myservo.write(outputValue3);
}



