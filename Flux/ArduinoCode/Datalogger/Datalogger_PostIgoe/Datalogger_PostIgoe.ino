//  SD card datalogger

#include <SD.h>
#include <Time.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 8; //for MicroSD CARD Sparkfun it's 8
String dataString;
File dataFile;
int timeHour;
int timeMinute;
int timeSecond;
int timeDay;
int timeMonth;
int timeYear;

int currentMinute = 0;
int previousMinute = 0;

volatile int pulses = 0;



void setup()
{
  attachInterrupt(0, readPulse, RISING);//What is this?
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  ///SET TIME OF START...(APPROXIMATE)
  setTime(12,11,0,1,12,2012); // another way to set the time

  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
  // make a string for assembling the data to log:
  //  String dataString = "";
  dataString = "";

  //ADD TIME STAMP
  timeHour=hour();
  timeMinute=minute();
//  timeMinute=currentMinute;  
  currentMinute=timeMinute;
  timeSecond=second();
  timeDay=day();
  timeMonth=month();
  timeYear=year();
//    Serial.println(timeMinute);
//  Serial.println("Current Minute" + timeMinute);
//  Serial.println("previous Minute" + previousMinute);

  // if the current time - the previous time > = 10 minutes, saveStuff(timeMinute, lastSaveMinute)

  if (currentMinute - previousMinute >=1 ) {
    saveStuff(); 
    if (saveStuff() == true) {
      previousMinute = currentMinute;
      pulses = 0;
    }
  }
}



boolean saveStuff() {
  boolean result = false;
  dataString += String(timeHour);
  dataString += ",";
  dataString += String(timeMinute);
  dataString += ",";
  dataString += String(timeSecond);
  dataString += ",";
  dataString += String(timeDay);
  dataString += ",";
  dataString += String(timeMonth);
  dataString += ",";
  dataString += String(timeYear);
  dataString += ",";
  dataString += pulses;

  digitalWrite(13, !digitalRead(13));    // Toggle LED on pin 13
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  //  Serial.print("hello");

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    result = true;
    Serial.print("saved!");

    // print to the serial port too:
    //    Serial.println(dataString);

  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }  
  // tell the calling function whether we saved or not
  return result;
}


void readPulse() {
  pulses++;
}

