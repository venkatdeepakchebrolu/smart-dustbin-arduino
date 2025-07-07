#include <Servo.h>

Servo lidServo;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  lidServo.attach(3);  // Servo on pin 3
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  if (distance < 20) {
    lidServo.write(90);  // Open lid
    delay(3000);         // Wait for 3 seconds
    lidServo.write(0);   // Close lid
  }
  delay(500);  // Wait before next check
}
