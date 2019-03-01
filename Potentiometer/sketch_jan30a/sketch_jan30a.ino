#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,6,5,4,3);

int potan_pin = A0;
float value = 0;
float final;

byte bar[8] = {B11111,
              B11111,
              B11111,
              B11111,
              B11111,
              B11111,
              B11111,
              B11111};

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar(0, bar);
  
}

void loop() {
  value = analogRead(potan_pin);
  final = (value / 1023) * 100;
  Serial.println(final);
  if (final == 0) {
    lcd.clear();
  }
  if (final> 0 && final<13) {

    lcd.setCursor(0,0);
    lcd.write(byte(0));
  
  for (int i = 0; i<7; i++) {
       lcd.setCursor(i+1,0);
       lcd.write(" ");
     }
  }
   if (final >=13 && final < 25) {
     for (int i = 0; i<2; i++) {
       lcd.setCursor(i,0);
       lcd.write(byte(0));
     }
     for (int i = 0; i<6; i++) {
       lcd.setCursor(i+2,0);
       lcd.write(" ");
     }
   }
   if (final >=25 && final < 38) {
     for (int i = 0; i<3; i++) {
       lcd.setCursor(i,0);
       lcd.write(byte(0));
     }
     for (int i = 0; i<5; i++) {
       lcd.setCursor(i+3,0);
       lcd.write(" ");
     }
   }
   if (final >=38 && final < 50) {
     for (int i = 0; i<4; i++) {
       lcd.setCursor(i,0);
       lcd.write(byte(0));
     }
     for (int i = 0; i<4; i++) {
       lcd.setCursor(i+4,0);
       lcd.write(" ");
     }
   }
   if (final >=50 && final < 63) {
     for (int i = 0; i<5; i++) {
       lcd.setCursor(i,0);
       lcd.write(byte(0));
     }
     for (int i = 0; i<3; i++) {
       lcd.setCursor(i+5,0);
       lcd.write(" ");
     }
   }
   if (final >=63 && final < 75) {
     for (int i = 0; i<6; i++) {
       lcd.setCursor(i,0);
       lcd.write(byte(0));
     }
     for (int i = 0; i<2; i++) {
       lcd.setCursor(i+6,0);
       lcd.write(" ");
     }
   }
   if (final >=75 && final < 88) {
     for (int i = 0; i<7; i++) {
       lcd.setCursor(i,0);
       lcd.write(byte(0));
     }
     lcd.setCursor(7,0);
     lcd.write(" ");
   }
   if (final >=88 && final <= 100) {
     for (int i = 0; i<8; i++) {
       lcd.setCursor(i,0);
       lcd.write(byte(0));
     }
   }
   lcd.setCursor(0,1);
   lcd.print(final);
   delay(100);
   
}
