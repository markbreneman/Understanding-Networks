//  SD card datalogger

#include <SD.h>
#include <Time.h>
#include <avr/interrupt.h>

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

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  ///SET TIME OF START...(APPROXIMATE)
  setTime(1,40,0,1,12,2012); // another way to set the time

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

  pinMode(2, INPUT);
  digitalWrite(2, HIGH);    // Enable pullup resistor
  sei();                    // Enable global interrupts
  EIMSK |= (1 << INT0);     // Enable external interrupt INT0
  EICRA |= (1 << ISC01);    // Trigger INT0 on falling edge

}

void loop()
{
  // make a string for assembling the data to log:
  //  String dataString = "";
  dataString = "";

  //ADD TIME STAMP
  timeHour=hour();
  timeMinute=minute();  
  timeSecond=second();
  timeDay=day();
  timeMonth=month();
  timeYear=year();

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
}


// Interrupt Service Routine attached to INT0 vector
ISR(INT0_vect)
{
  digitalWrite(13, !digitalRead(13));    // Toggle LED on pin 13
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  //  Serial.print("hello");

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    //    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}

