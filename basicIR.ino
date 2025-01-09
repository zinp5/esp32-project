//#include <Arduino.h>

const int IRpin = 33;       //set the input pin

void setup() {
  pinMode(IRpin, INPUT);    //set pinmode for IR pin to input
  Serial.begin(9600);       //open serial monitor for basic output
}

void loop() {
  if(IRpin == HIGH){                   //if input pin says high
    Serial.write("Detected\n");
  }
  else{
    Serial.write("---\n");            //if input pin says low
  }
}
