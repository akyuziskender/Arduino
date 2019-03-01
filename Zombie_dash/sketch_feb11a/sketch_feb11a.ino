#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,6,5,4,3);

int score = 0;

int joystick_x = A0;  // attaching vr_x to A0
int joystick_y = A1;  // attaching vr_y to A1
int joy_switch = 2;  // attaching switch to 2
int value_x;
int value_y;
int value_sw;

long randnumber;
int a = 15;
int start_creature = 1;
int moving = 0;

static bool joyPushed = false;

int x = 0;  // man's x coordinate
int y = 0;  // man's y coordinate

// setting time of creature's motion
unsigned long previousMillis1 = 0;
long OnTime_creature = 100;
long OffTime_creature = 900;
// setting time of bullet's motion
unsigned long previousMillis2 = 0;
long OnTime_bullet = 100;
long OffTime_bullet = 200;
int bullet_goes = 0;
int x_1;  // bullet's x coordinate
int y_1;  // bullet's y coordinate
int loop_bullet;

int buzzerPin = 10;  // attaching buzzer to 10
int B = 494;  // a note for crash
static bool crash_sound = false;

// drawing man
byte man[8] = {
	0b11100,
	0b10100,
	0b11100,
	0b01011,
	0b01110,
	0b01000,
	0b10100,
	0b10100
};

// drawing bullet
byte bullet[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

// drawing bulet
byte creature[8] = {
	0b11001,
	0b11111,
	0b10101,
	0b11111,
	0b10001,
	0b11111,
	0b11101,
	0b01100
};

void game_over() {
  if ( crash_sound == true ) {
    tone(buzzerPin, B);
    delay(300);
    noTone(buzzerPin);
    delay(20);
    crash_sound = false;
  }
  
  start_creature = 0;
  bullet_goes = 0;
  moving = 0;
  OffTime_creature = 900;
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.write("GAME OVER!");
  lcd.setCursor(3,1);
  lcd.write("Score: ");
  lcd.print(score);
  
  value_x = digitalRead(joystick_x);
  if ( value_x == 0 ) {
    lcd.clear();
    start_creature = 1;
    score = 0;
    x = 0;
    y = 0;
    game_loop();
  }
}

void game_loop() {
  unsigned long currentMillis = millis();
  value_sw = digitalRead(joy_switch);  // reading value of joy_switch
  value_x = analogRead(joystick_x);  // reading value of joy_x
  value_y = analogRead(joystick_y);  // reading value of joy_y
  
  if (start_creature == 1) {
    a = 15;
    randnumber = random (0,2);
    moving = 1;
    start_creature = 0;
  }
  
  if ( moving == 1 ) {
    if ( ( a > -1 ) && (currentMillis - previousMillis1 >= OnTime_creature ) ) {
      lcd.setCursor(a, randnumber);  // updating the position of creature
      lcd.write(byte(2));
    }
    if ( ( a > -1 ) && ( currentMillis - previousMillis1 >= OffTime_creature ) ) {
      lcd.setCursor(a, randnumber);
      lcd.write(" ");
      previousMillis1 = currentMillis;  // remember the time
      a -= 1;
      if ( a == -1 ) {
        a = 15;
        randnumber = random (0,2);
        start_creature = 1;
      }
    }
  }
  lcd.setCursor(x,y);
  lcd.write(byte(0));
  
  // moving in +x direction
  if ( value_x >= 990 && x < 15) {
      lcd.setCursor(x,y);
      lcd.write(" ");
      x += 1;
      lcd.setCursor(x,y);
      lcd.write(byte(0));
  }
  // moving in -x direction
  if ( value_x <= 5 && x >= 0) {
    lcd.setCursor(x,y);
    lcd.write(" ");
    x -= 1;
    lcd.setCursor(x,y);
    lcd.write(byte(0));
  }
  // moving in -y direction
  if ( value_y <= 5 && y > 0 )  {
    lcd.setCursor(x,y);
    lcd.write(" ");
    y -= 1;
    lcd.setCursor(x,y);
    lcd.write(byte(0));
  }
  // moving in +y direction
  if ( value_y >= 1000 && y < 1 ) {
    lcd.setCursor(x,y);
    lcd.write(" ");
    y += 1;
    lcd.setCursor(x,y);
    lcd.write(byte(0));
  }
  
  if ( value_sw == 0 ) {
    bullet_goes = 1;
    x_1 = x + 1;
    y_1 = y;
    loop_bullet = 0;
  }
  
  if (bullet_goes == 1) {
    if ( (loop_bullet < 16) && (currentMillis - previousMillis2 >= OnTime_bullet ) ) {
      lcd.setCursor(x_1, y_1);  // updating the position of bullet
      lcd.write(byte(1));
    }
    if ( (loop_bullet < 16) && ( currentMillis - previousMillis2 >= OffTime_bullet ) ) {
      lcd.setCursor(x_1, y_1);
      lcd.write(" ");
      previousMillis2 = currentMillis;  // remember the time
      x_1++;;
      if ( x_1 == 16 ) {
        x_1 = 0;
        bullet_goes = 0;
      }
    }
  }
  // killing creature
  if ( (a == x_1) && (randnumber == y_1) ) {
    lcd.setCursor(x_1, y_1);
    lcd.write(" ");
    
    score++;
    
    bullet_goes = 0;
    moving = 0;
    start_creature = 1;
    x_1 = 0;
    y_1 = 0;
    // while score is less than 11, speed up creature with 25
    if ( score <= 15 ) { 
      OffTime_creature -= 25;
    }
    // while score is between 10 and 15, speed up creature with 20
    else if ( (score > 15) && (score <= 25) ) {
      OffTime_creature -= 20;
    }
    // while score is between 25 and 30, speed up creature with 15
    else if ( (score > 25) && (score <= 30) ) {
      OffTime_creature -= 15;
    }
    // while score is between 30 and 40, speed up creature with 10
    else if ( (score > 30) && (score <= 40) ) {
      OffTime_creature -= 10;
    }
  }
  
  crash_sound = true;
}

void home_screen() {
  lcd.setCursor(0,0);
  lcd.print("Zombie Dash 1.0");
  lcd.setCursor(2,1);
  lcd.print("By marnop");
  delay(1500);
  lcd.clear();
}

void setup() {
  Serial.begin(9600);  // starting serial port
  pinMode(joystick_x, INPUT);  
  pinMode(joystick_y, INPUT);
  pinMode(joy_switch, INPUT_PULLUP);
  lcd.begin(16,2);
  lcd.createChar(0, man);
  lcd.createChar(1, bullet);
  lcd.createChar(2, creature);
  
  randnumber = random(0,1);  // getting random number for the creature
  home_screen();
}

void loop() {
  
  if ( ((a == x) && (randnumber == y)) || (a == 0) ) {
    game_over();
  }
  else {
    game_loop();
  }
  delay(100);
}

