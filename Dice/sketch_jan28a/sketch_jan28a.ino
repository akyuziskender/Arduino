int leds[] = {2,3,4,5,6,7};
int number_of_leds = 6;
int button_pin = 8;
long randnumber;
int button_value = 0;

void setup() {
  for (int i = 0; i < number_of_leds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button_pin, INPUT);
  Serial.begin(9600);
  Serial.println(button_value);
  randomSeed(analogRead(0));
}

void loop() {
  button_value = digitalRead(button_pin);
  Serial.println(button_value);
  if ( button_value == HIGH) {
    randnumber = random(1,7);
    delay(100);
    if (randnumber == 1) {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
      digitalWrite(leds[4], LOW);
      digitalWrite(leds[5], LOW);
      delay(2000);
      digitalWrite(leds[0], LOW);
    }
    if (randnumber == 2) {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
      digitalWrite(leds[4], LOW);
      digitalWrite(leds[5], LOW);
      delay(2000);
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
    }
    if (randnumber == 3) {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], LOW);
      digitalWrite(leds[4], LOW);
      digitalWrite(leds[5], LOW);
      delay(2000);
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
    }
    if (randnumber == 4) {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], HIGH);
      digitalWrite(leds[4], LOW);
      digitalWrite(leds[5], LOW);
      delay(2000);
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
    }
    if (randnumber == 5) {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], HIGH);
      digitalWrite(leds[4], HIGH);
      digitalWrite(leds[5], LOW);
      delay(2000);
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
      digitalWrite(leds[4], LOW);
    }
    if (randnumber == 6) {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], HIGH);
      digitalWrite(leds[4], HIGH);
      digitalWrite(leds[5], HIGH);
      delay(2000);
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
      digitalWrite(leds[4], LOW);
      digitalWrite(leds[5], LOW);
    }
  }
  delay(100);
}
    
