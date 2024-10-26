#include <Servo.h>

Servo myservo;

int pos = 0;
const int trigger = 2;
const int echo = 3;

int getUltrasonicDistance(){
  long duration;
  int distance;
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  distance = distance * 0.3937008;

  return distance;
}

void setup() {
  myservo.attach(9);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance: ");
  int distance2 = getUltrasonicDistance();
  Serial.println(getUltrasonicDistance());
  myservo.write(distance2 * 3);
  delay(100);
}
