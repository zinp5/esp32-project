/*
simple IR detection device

---------note that---------
bright lights (ie your lamp) will activate the IR sensor 
this IR sensor will set input to LOW when there is detection

irpin only defines which pin to look at for incoming data
    to actually recieve that data, we need receiver = digitalRead(incomingpin)

we can utilize the led on the ir sensor by setting the IRpin pinMode to output 
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
bool detector = false;
int pattern[] = {1, 1, 1};
void setup() {
    pinMode(IRpin, INPUT);      //set pinmode for IR pin to input
    Serial.begin(9600);         //open serial monitor for basic output
}


void loop() {

    receiver = digitalRead(IRpin);
    
    //pattern[0] = pattern[1];
    //pattern[1] = pattern[2];
    pattern[2] = receiver;

    if(pattern[2] == 0){
        Serial.write("object ");
    }
    
    delay(250);
}
