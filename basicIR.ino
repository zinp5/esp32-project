/*
simple IR detection device

---------note that---------
bright lights (ie your lamp) will activate the IR sensor 
this IR sensor will set input to LOW when there is detection

irpin only defines which pin to look at for incoming data
    to actually recieve that data, we need receiver = digitalRead(incomingpin)

---------pesudo---------
setup
    set pin & open it for signal
    create receiver variable to grab signals
    open serial

loop
    constantly scan and place signal value into reciever
    if receiver low ---> signal found
*/

//#include <Arduino.h>

const int IRpin = 33;           //set the input pin
int receiver;                   //holds the status of the IR sensor
void setup() {
    pinMode(IRpin, INPUT);      //set pinmode for IR pin to input
    Serial.begin(9600);         //open serial monitor for basic output
}

void loop() {
    receiver = digitalRead(IRpin);
    if(receiver == LOW){                   //if input pin says LOW
        Serial.write("{=}+");
        delay(200);
    }
  
}
