//#include <Arduino.h>

const int IRpin = 33;       //set the input pin
int currstatus;             //holds the status of the IR sensor
void setup() {
  pinMode(IRpin, INPUT);    //set pinmode for IR pin to input
  Serial.begin(9600);       //open serial monitor for basic output
}

void loop() {
  currstatus = digitalRead(IRpin);
  if(currstatus == LOW){                   //if input pin says LOW
    Serial.write("{=}+");
    
  }
  currstatus = LOW;
  
}
