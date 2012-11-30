int currentValue = 0;
int values[] = {
  0,0,0,0,0,0,0,0,0};


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
    int incomingValue = Serial.read();//READ
    values[currentValue] = incomingValue;
    currentValue++;

    if(currentValue > 8){
      currentValue = 0;
    }
  }

  if (values[5] == 1){
    digitalWrite (ledPin1, HIGH);
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

  //   myservo.write(outputValue3);
  //}
}






