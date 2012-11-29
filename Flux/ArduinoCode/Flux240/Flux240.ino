
int incomingData[9];
byte incomingValue;   // Where to store the Bytes read
byte index = 0;   // Index into array; where to store the Bytes

int ledPin1=13;
int ledPin2=12;
int ledPin3=11;
int ledPin4=10;

void setup() 
{ 
  Serial.begin(9600);
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  pinMode (ledPin4, OUTPUT);
} 

void loop() 
{ 
  if(Serial.available()){

    if(index<9){
      incomingValue = Serial.read();//READ
      incomingData[index] = incomingValue;//STORE THE BYTE IN THE ARRAY
      index++;
      Serial.println(incomingValue);
    }
  }
  index=0;
}

//  Serial.println(incomingData);

//  Serial.println(values[0]);
//  Serial.println(values[1]);
//  Serial.println(values[2]);


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
//}




