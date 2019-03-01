#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,6,5,4,3);

byte batman1[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00011,
	0b00111,
	0b01111
};
byte batman2[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00001,
	0b00001,
	0b00011,
	0b11111
};
byte batman3[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b10000,
	0b10000,
	0b11000,
	0b11111
};
byte batman4[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11000,
	0b11100,
	0b11110
};
byte batman5[] = {
	0b01111,
	0b01111,
	0b00110,
	0b00010,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
byte batman6[] = {
	0b11111,
	0b11111,
	0b00001,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
byte batman7[] = {
	0b11111,
	0b11111,
	0b10000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
byte batman8[] = {
	0b11110,
	0b11110,
	0b01100,
	0b01000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

void setup() {
  lcd.createChar(0, batman1);
  lcd.createChar(1, batman2);
  lcd.createChar(2, batman3);
  lcd.createChar(3, batman4);
  lcd.createChar(4, batman5);
  lcd.createChar(5, batman6);
  lcd.createChar(6, batman7);
  lcd.createChar(7, batman8);
  lcd.begin(16,2);
  
}

void loop() {
  for (int i = 6; i<10; i++) {
    lcd.setCursor(i,0);
    lcd.write(byte(i-6));
  }
  for (int i = 6; i<10; i++) {
    lcd.setCursor(i,1);
    lcd.write(byte(i-2));
  }
}

