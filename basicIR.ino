/*
simple IR detection device

---------note that---------
bright lights (ie your lamp) will activate the IR sensor 
this IR sensor will set input to LOW when there is detection

irpin only defines which pin to look at for incoming data
    to actually recieve that data, we need receiver = digitalRead(incomingpin)

we can utilize the led on the ir sensor by setting the IRpin pinMode to output 

ir current draw = 45mA

though the sensor will have trouble seeing object more than 4in away, 
    the sensor will pick up another IR signal (from another IRsensor) from 6+in

to mitigate noise / debounce the input signal, include a :::delay(1):::: at the end of your prog

---------detecting motion---------
motion is defined as an object being at a point different from the point it was at previously
i detect motion using a 1d array that holds two values, current(index 1) and previous(index 0)
    the method runs in three steps:
        first step: input >>> current
        check status
        second step: current >>> previous
    before second step I check status ::::if current != previous:::: then i deduce that something has moved / motion detected 
        (given that an object is at/not at the point that it was not at/was at previously)

---------input path-----------
physical world >>> IR sensor >>> sensor output >>> esp32 pin >>> reciever

---------pesudo---------
setup
    set pin & open it for signal
    create receiver variable to grab signals
    open serial

loop
    constantly scan and place signal value into reciever
    if receiver low ---> signal found

-------------TO DO-------------
show image files in git

*/

//#include <Arduino.h> //one day this will be necessary maybe


//------------------------global vars------------------------
const int IRpin = 33;           //location ofinput pin

int receiver;                   //holds the input of the IR sensor,, not quite necessary but good for readability

int pattern[] = {1, 1};         //pre-initializing (given that default mode of IR (no detection) = 1 i deduce the best default value for the pattern holding to be 1,1)
//------------------------global vars------------------------


//------------------------setup------------------------
void setup() {  
    pinMode(IRpin, INPUT);      //set pinmode for IR pin to input
    Serial.begin(9600);         //open serial monitor for basic output
}
//------------------------setup------------------------

//------------------------mainloop------------------------
void loop() {
    
    receiver = digitalRead(IRpin);  //take input from pin and put into var
    
    pattern[1] = receiver;          //input >>> current

    //viewandtestpattern();                      //print pattern for personal viewing (beware of the 500ms delay included for testing and readability)
    
    checkformotion();               //check for motion
    
    pattern[0] = pattern[1];        //current >>> previous 

    delay(1);//for some reason, the program will spit multiple of the same input upon motion detection,, including this short delay stops that
            /*
            apparently it has something to do with noise and setup time (Like with flipflops and such!)
            more specifically called debouncing
            */
}
//------------------------mainloop------------------------


//===================================personal functions===================================


//------------------------checkformotion-------------------------
void checkformotion(){
    if(pattern[0] != pattern[1]){           //if current != previous
        Serial.println("\tmotion detected ");
    }
}
//------------------------checkformotion-------------------------

//------------------------viewandtestpattern-------------------------
void viewandtestpattern(){
    Serial.print(pattern[0]);
    Serial.print("\t");
    Serial.println(pattern[1]); 
    delay(500);
}
//------------------------viewandtestpattern-------------------------
