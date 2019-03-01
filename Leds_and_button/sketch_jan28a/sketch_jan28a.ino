int leds[] = {4, 5, 6, 7};
int button_pin = 2;
int number_of_leds = 4;
int button_value = 0;
int button_pushing = 0;
int n = 0;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < number_of_leds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button_pin, INPUT);
}

void loop() {
  button_value = digitalRead(button_pin);
  Serial.println(n);
  if (button_value == HIGH) {
    digitalWrite(leds[n], HIGH);
    n++;
    if ( n == 5 ) {
        n = 0;
        for(int i = 0; i < number_of_leds; i++) {
            digitalWrite(leds[i], LOW);
          }
  }
  }
    delay(100);
  }
