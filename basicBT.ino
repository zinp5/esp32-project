/*
basics of bluetooth

-------------pseudo-------------
include bluetoothserial.h

create bluetooth object

setup
    open serial monitor
    short delay for error checking prints
    initialize  bluetooth device & give name

loop
    if signal recieved ---> print signal recieved
*/

//----------------- create bt object ------------
#include "BluetoothSerial.h"
BluetoothSerial btinput;                                //initialize the bluetooth object
//----------------- create bt object ------------

//----------------------- setup -----------------------
void setup() {

    Serial.begin(9600);                                 //open serial monitor for basic output from esp32
    delay(300);                                         //insert short delay, may cause bugs if not present, something to do with serial monitor not being ready,,, only necessary for early prints in setup

    //----------- bt init ---------------
    if( btinput.begin("Umbrella") ){                    //begin turning the esp32 into a bluetooth device,,, currently named:::: Umbrella
        Serial.println("bluetooth up and running now");                         //error checking
    }
    else{
        Serial.println("shits fucked");                 //error checking
    }
    //----------- bt init ---------------
}
//----------------------- setup -----------------------


//----------------------- main loop -----------------------
void loop() {
    if( btinput.available() ){                          //everytime a singal is read from the bluetooth, do...
        Serial.println( btinput.read() );               //print out what the bluetooth signal reads
    }
}
//----------------------- main loop -----------------------
