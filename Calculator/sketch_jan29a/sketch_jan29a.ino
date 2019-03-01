#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,6,5,4,3);

int button_1 = 8;
int button_2 = 9;
int button_3 = 10;
int value1 = 0;
int value2 = 0;
int value3 = 0;

byte arrow[8] =
{
 B00000, B00000, B01000, B01100, B01110, B01100, B01000, B00000
};

char* options[] = {"Summation", "Substraction", "Multiplication", "Division"};
#define num_options 4

int position= -1;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2);
  
  lcd.createChar(byte(0), arrow);
  
  lcd.setCursor(0,0);
  lcd.print("Calculator 1.0");
  lcd.setCursor(0,1);
  lcd.print("Created by Akyuz");
  delay(2500);
  
  
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT);
}
  
void loop() {
  value1 = digitalRead(button_1);
  value2 = digitalRead(button_2);   
  value3 = digitalRead(button_3);
  Serial.println(position);
  if (value1 == HIGH) {
    position--;
    homeScreen();
  }
  if (value2 == HIGH) {
    position++;
    homeScreen();
  }
  if (value3 == HIGH) {
      if ( position == 0) {
        sum();
      }
    }
 }

 
void homeScreen() {
  lcd.clear();
  lcd.setCursor(0,0);
  
  // make sure cursor position is legal
  if (position<0) position=0;
  if (position>num_options-1) position = num_options-1;

  // write current selection and next option if there is another option
  lcd.write(byte(0)); //arrow character
  lcd.print(position+1);
  lcd.print("-");
  lcd.print(options[position]);
  if (position < num_options-1) {
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.print(position+2);
    lcd.print("-");
    lcd.print(options[position+1]);
  }
}
 
 
int n_1 = 0;
int n_2 = 0;
void sum() {
  value1 = digitalRead(button_1);
  value2 = digitalRead(button_2);   
  value3 = digitalRead(button_3);
  if (value1 == HIGH) {
    lcd.setCursor(0,0);
    lcd.print("First integer:");
    lcd.setCursor(0,1);
    lcd.print(n_1);
    n_1++;
    }
  delay(200);
  if (value2 == HIGH) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Second integer:");
    lcd.setCursor(0,1);
    lcd.print(n_2);
    n_2++;
    }
  if (value3 == HIGH) {
    n_1--;
    n_2--;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(n_1);
    lcd.print("+");
    lcd.print(n_2);
    lcd.setCursor(0,1);
    lcd.print("=");
    lcd.setCursor(1,1);
    lcd.print(n_1+n_2);
  }
}
 
   
