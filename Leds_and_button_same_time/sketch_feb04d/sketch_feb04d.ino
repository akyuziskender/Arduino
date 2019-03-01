int ledPin1 = 12;  // the number of the LED pin
int ledState1 = LOW;  // ledState used to set the LED
unsigned long previousMillis1 = 0;  // will store last time LED was updated
long OnTime1 = 330;  // milliseconds of on-time
long OffTime1 = 400;  // milliseconds of off-time

int ledPin2 = 13;  // the number of the LED pin
int ledState2 = LOW;  // ledState used to set the Led was updated
unsigned long previousMillis2 = 0;  // will store last time LED was updated
long OnTime2 = 330;  // milliseconds of on-time
long OffTime2 = 400;  // milliseconds of off-time

int buttonPin = 11;
int buttonState = 0;
unsigned long previousMillis3 = 0;
long OnTime3 = 330;
long OffTime3 = 400;


void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  buttonState = digitalRead(buttonPin);
  
  if (( ledState1 == HIGH ) && ( currentMillis - previousMillis1 >= OnTime1 )) {
    ledState1 = LOW;  // turn it off
    previousMillis1 = currentMillis;  // remember the time
    digitalWrite(ledPin1, ledState1);  // update the actual LED
  }
  else if (( ledState1 == LOW ) && ( currentMillis - previousMillis1 >= OffTime1 )) {
    ledState1 = HIGH;  // turn it on
    previousMillis1 = currentMillis;  // remember the time
    digitalWrite(ledPin1, ledState1);  // update the actual LED
  }
  
  if (( ledState2 == HIGH ) && ( currentMillis - previousMillis2 >= OnTime2 )) {
    ledState2 = LOW;  // turn it off
    previousMillis2 = currentMillis;  // remember the time
    digitalWrite(ledPin2, ledState2);  // update the actual LED
  }
  else if (( ledState2 == LOW ) && ( currentMillis - previousMillis2 >= OffTime2 )) {
    ledState2 = HIGH; // turn it on
    previousMillis2 = currentMillis; // remmeber the time
    digitalWrite(ledPin2, ledState2); // update the actual LED
  }
  
  if ( buttonState == 1 ) {
    Serial.println("Button is being pushed.");
  }
}

