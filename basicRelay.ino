int pin = 32;

void setup() {
    pinMode(pin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(pin, HIGH);
    Serial.println("up");
    delay(2000);
    
    digitalWrite(pin, LOW);
    Serial.println("down");
    delay(2000);
}
