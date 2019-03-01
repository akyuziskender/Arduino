// Turn on and off the led with sound

int led_pin = 8; 
int sensor_pin = A0;
int led_condition = 0;
int number_of_voices = 0;
unsigned long start_time = 0;
unsigned long elapsed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
}

void loop() {
  int value = analogRead(sensor_pin);
  if ( value > 100 ) {
    if ( number_of_voices == 0 ) {
      start_time = elapsed = millis();
      number_of_voices += 1;
    }
    else if ( number_of_voices > 0 && millis() - elapsed >= 50) {
      elapsed = millis();
      number_of_voices += 1;
    }
  }
  
  if ( millis() - start_time >= 400 ) {
    if (number_of_voices == 2) {
      if (led_condition == 0) {
        led_condition = 1;
        digitalWrite(led_pin, HIGH);
        Serial.println("Led ON");
        Serial.println(millis());
      }
      else if (led_condition == 1) {
        led_condition = 0;
        digitalWrite(led_pin, LOW);
        Serial.println("Led OFF");
      }
    }
    number_of_voices = 0;
  }
}
