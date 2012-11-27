////Encoder Library
#include <PinChangeInt.h> // necessary otherwise we get undefined reference errors.
#include <AdaEncoder.h>
#define a_PINA 2
#define a_PINB 3
int8_t clicks=0;
char id=0;
////CREATE A STRING TO HOLD ENCODER "VALUE"
String encoderValue;

////CONTROL VARIABLES
int currentTilt;
int tiltRead;
int tilt;

int currentFocus;
int focusRead;
int focus;

int currentZoom;
int zoomRead;
int zoom;

int currentIris;
int irisRead;
int iris;

int increment;


void setup(){
  //Begin Serial Communication 
  Serial.begin(9600);

  //Encoder object creation
   AdaEncoder::addEncoder('a', a_PINA, a_PINB);
  increment=10;
}

void loop () {

  //___READING THE DATA___//
  tiltRead = analogRead(A0);
  delay(1);

  focusRead = analogRead(A1);
  delay(1);

  zoomRead= analogRead(A2);
  delay(1);

  irisRead = analogRead(A3);
  delay(1);

  int cameraSelectX = analogRead(A4);
  delay(1);

  int cameraSelectY = analogRead(A5);
  delay(1);


  //Pan-Encoder 
   encoder *thisEncoder;
   thisEncoder=AdaEncoder::genie(&clicks, &id);
   if (thisEncoder != NULL) {
     if (clicks > 0) {
       encoderValue = "Going Right";
     }
     if (clicks < 0) {
       encoderValue = "Going Left";
     }
   }
  
   else if (thisEncoder == NULL){
     encoderValue = "Not Changing";
   }

//Tilt Logic - watch for change
  if(currentTilt>tiltRead+increment){
    tilt=1;
  }
  if(currentTilt<tiltRead-increment){
    tilt=-1;
  }
  else if(currentTilt==tiltRead){
    tilt=0;
  }

//Zoom Logic - watch for change
  if(currentZoom>zoomRead+increment){
    zoom=1;
  }
  if(currentZoom<zoomRead-increment){
    zoom=-1;
  }
  else if(currentZoom==zoomRead){
    zoom=0;
  }

//Focus Logic - watch for change
  if(currentFocus>focusRead+increment){
    focus=1;
  }
  if(currentFocus<focusRead-increment){
    focus=-1;
  }
  else if(currentFocus==focusRead){
    focus=0;
  }

//Iris Logic - watch for change
  if(currentIris>irisRead+increment){
    iris=1;
  }
  if(currentIris<irisRead-increment){
    iris=-1;
  }
  else if(currentIris==irisRead){
    iris=0;
  }


  // form a JSON-formatted string:
  String jsonString = "{\"tilt\":\"";
   jsonString += tilt;
   jsonString +="\",\"focus\":\"";
   jsonString += focus;
   jsonString +="\",\"zoom\":\"";
   jsonString += zoom;
   jsonString +="\",\"iris\":\"";
   jsonString += iris;
   jsonString +="\",\"cameraSelectX\":\"";
   jsonString += cameraSelectX;
   jsonString +="\",\"cameraSelectY\":\"";
   jsonString += cameraSelectY;
   jsonString +="\",\"encoderValue\":\"";
   jsonString += encoderValue;
  jsonString +="\"}";

  // print it:
  Serial.println(jsonString);

  currentTilt=tiltRead;
  currentZoom=zoomRead;
  currentFocus=focusRead;
  currentIris=irisRead;


}








