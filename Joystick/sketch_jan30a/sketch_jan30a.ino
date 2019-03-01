#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,6,5,4,3);

int joy=A0;
int value ;


void setup()
{
 pinMode(joy,INPUT);
 lcd.begin(16,2);
}


void loop ()
{
  value=analogRead(joy);
  lcd.setCursor(0,0);
  if ( value > 1000 ) {
    lcd.write("+y");
  }
  if ( value == 512 ) {
    lcd.clear();
    lcd.write("0");
  }
  if ( value == 0 ) {
    lcd.write("-y");
  }
}



