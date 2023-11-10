#include <SoftwareSerial.h>

SoftwareSerial espSerial(2,3);

char serialData;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  espSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(espSerial.available())
  {
    serialData = espSerial.read();
    Serial.println(serialData);
    if(serialData == '2') {
      while(1) {
        while(!espSerial.available());
        serialData = espSerial.read();

        if(serialData == '0') {
          digitalWrite(8, LOW);
        }
        else if(serialData == '1') {
          digitalWrite(8, HIGH);
        }
        else if(serialData == '2') {
          break;
        }        
      }
    }
    else if (serialData == '4') {
      while(1) {
        while(!espSerial.available());
        serialData = espSerial.read();

        if(serialData == '0') {
          digitalWrite(7, LOW);
        }
        else if(serialData == '1') {
          digitalWrite(7, HIGH);
        }
        else if(serialData == '4') {
          break;
        }
      }
    }
  }
}
