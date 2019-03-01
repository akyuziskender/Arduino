const int ledPin = 13;

int ledState = LOW;  // ledState used to set the LED
long previousMillis = 0;  // will store last time LED was updated

long interval = 1000;  // interval at which to blink (millisconds)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if ( currentMillis - previousMillis > interval ) {
    previousMillis = currentMillis; // save the last time you blinked the Led
    
    if ( ledState == LOW) // if the LED is off turn it on and vice-versa
      ledState = HIGH;
    else
      ledState = LOW;
      
    digitalWrite(ledPin, ledState);
  }
}
