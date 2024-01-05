int motorIN1 = 12;
int motorIN2 = 11;
int motorIN3 = 10;
int motorIN4 = 9;

#define led_pin 5
#define echoPin 2
#define trigPin 3

long duration;
int distance;

char State;


void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (motorIN1, OUTPUT);
  pinMode (motorIN2, OUTPUT);
  pinMode (motorIN3, OUTPUT);
  pinMode (motorIN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0)
  {
    State = Serial.read();
  }

  digitalWrite(led_pin, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;
  if(distance <= 10)
  { 
    digitalWrite(led_pin, HIGH);
    delay(500);
  }

  if(State == 'f') //forward
  {
    	digitalWrite(motorIN1, LOW);
	    digitalWrite(motorIN2, HIGH);
	    digitalWrite(motorIN3, LOW);
	    digitalWrite(motorIN4, HIGH);
  }
  else if(State == 'b') //backward
  {
    	digitalWrite(motorIN1, HIGH);
    	digitalWrite(motorIN2, LOW);
    	digitalWrite(motorIN3, HIGH);
    	digitalWrite(motorIN4, LOW);
  }
  else if(State == 'l') //turn left
  {
    	digitalWrite(motorIN1, HIGH);
    	digitalWrite(motorIN2, LOW);
    	digitalWrite(motorIN3, LOW);
    	digitalWrite(motorIN4, HIGH);
  }
  else if(State == 'r') //turn right
  {
    	digitalWrite(motorIN1, LOW);
    	digitalWrite(motorIN2, HIGH);
    	digitalWrite(motorIN3, HIGH);
    	digitalWrite(motorIN4, LOW);
  }
  else
  {
    	digitalWrite(motorIN1, LOW);
    	digitalWrite(motorIN2, LOW);
    	digitalWrite(motorIN3, LOW);
    	digitalWrite(motorIN4, LOW);
  }
  
}
