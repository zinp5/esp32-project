/*
basics of bluetooth

use #include "BluetoothSerial.h"
https://randomnerdtutorials.com/esp32-bluetooth-classic-arduino-ide/


aparently the esp32 pin #2 can manipulate the board's built-in LED,,, simply do :::: pinmode(2, OUTPUT)

------TO DO------
compile basic comments into a single file
add pseudo
refine & understand bt process

*/

#include "BluetoothSerial.h"

BluetoothSerial btinput;

void setup() {

    Serial.begin(9600);
    delay(1000);    
    if( btinput.begin("clock") ){
        Serial.println("epic");
    }
    else{
        Serial.println("shits fucked");
    }
    
    Serial.println("running this properly so far...");
}

void loop() {
    if( btinput.available() ){
        Serial.println( btinput.read() );
    }
}
