#include <Servo.h>

// Ultrasonic Sensor Pins
const int trigPin = 10;
const int echoPin = 11;

// Servo Pin
Servo myServo;

// LED Pins
const int redLedPin = 2;
const int yellowLedPin = 3;
const int greenLedPin = 4;

// Buzzer Pin
const int buzzerPin = 5;

// Variables
long duration;
int distance;
int angle = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  myServo.attach(12); // Servo on pin 12
  
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Sweep from 15° to 165°
  for (angle = 15; angle <= 165; angle++) {
    myServo.write(angle);
    delay(30);
    distance = calculateDistance();
    sendData(angle, distance);
    handleDistanceAlert(distance);
  }

  // Sweep from 165° to 15°
  for (angle = 165; angle >= 15; angle--) {
    myServo.write(angle);
    delay(30);
    distance = calculateDistance();
    sendData(angle, distance);
    handleDistanceAlert(distance);
  }
}

int calculateDistance() {
  // Trigger pulse to start the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse received
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in cm
  distance = duration * 0.034 / 2;
  
  return distance;
}

void sendData(int angle, int distance) {
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.println(".");
}

void handleDistanceAlert(int dist) {
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  noTone(buzzerPin);

  if (dist < 10) {
    digitalWrite(redLedPin, HIGH);
    tone(buzzerPin, 500);
  } else if (dist < 30) {
    digitalWrite(yellowLedPin, HIGH);
    tone(buzzerPin, 2800);
  } else if (dist < 50) {
    digitalWrite(greenLedPin, HIGH);
    tone(buzzerPin, 5600);
  } else if (dist < 100) {
    digitalWrite(greenLedPin, HIGH);
  }
}
