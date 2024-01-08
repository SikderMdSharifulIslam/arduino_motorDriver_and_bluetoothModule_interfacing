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
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);
  pinMode(motorIN3, OUTPUT);
  pinMode(motorIN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    State = Serial.read();
    executeCommand(State); // Execute the command received
  }

  measureDistance(); // Measure distance and turn on LED if obstacle is close
}

void measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;

  if (distance <= 50) {
    digitalWrite(led_pin, HIGH);
    delay(500);
    //digitalWrite(led_pin, LOW);
  } else {
    digitalWrite(led_pin, LOW);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'f': // forward
      moveForward();
      break;
    case 'b': // backward
      moveBackward();
      break;
    case 'l': // turn left
      turnLeft();
      break;
    case 'r': // turn right
      turnRight();
      break;
    case 's': // stop
      stopMovement();
      break;  
    default:
      stopMovement();
      break;
  }
}

void moveForward() {
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, HIGH);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, HIGH);
}

void moveBackward() {
  digitalWrite(motorIN1, HIGH);
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, HIGH);
  digitalWrite(motorIN4, LOW);
}

void turnLeft() {
  digitalWrite(motorIN1, HIGH);
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, HIGH);
  delay(400); // Adjust this delay to control the turning angle
  stopMovement();
}

void turnRight() {
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, HIGH);
  digitalWrite(motorIN3, HIGH);
  digitalWrite(motorIN4, LOW);
  delay(400); // Adjust this delay to control the turning angle
  stopMovement();
}

void stopMovement() {
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, LOW);
}
