/*
simple IR detection device

---------pesudo---------
setup
    set pin & open it for signal
    create receiver variable to grab signals
    open serial

loop
    constantly scan and place signal value into reciever
    if receiver low ---> signal found
*/


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
