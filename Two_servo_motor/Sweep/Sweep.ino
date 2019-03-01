#include <Servo.h> 

class Sweeper
{
  Servo servo;
  // the servo
  int pos;
  // current servo position
  int increment;
  // increment to move for each interval
  int updateInterval;
  // interval between updates
  unsigned long lastUpdate; // last update of position
public:
  Sweeper(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  void Attach(int pin)
  {
    servo.attach(pin);
  }

  void Detach()
  {
    servo.detach();
  }
  void Update()
  {
    if((millis() - lastUpdate) > updateInterval) // time to update
    {
      lastUpdate = millis();
      pos += increment;
      servo.write(pos);
      Serial.println(pos);
      if ((pos >= 180) || (pos <= 0)) // end of sweep
      {
        // reverse direction
        increment = -increment;
      }
    }
  }
};

Sweeper sweeper1(10);

int potPin = A0;
int value = 0;

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 

void setup() 
{ 
  Serial.begin(9600);
  sweeper1.Attach(10);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 


void loop() 
{
  sweeper1.Update();
  value = analogRead(potPin);
  value = map(value, 0, 1023, 0, 180);
  Serial.println(value);
  myservo.write(value);              // tell servo to go to position in variable 'pos' 
  delay(15);                       // waits 15ms for the servo to reach the position 
} 

