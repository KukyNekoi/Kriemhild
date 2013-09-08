/**
Controlador RC arduino
**/
#include <Servo.h>

const int motorPin1 = 8;
const int motorPin2 = 9;
const int motorPin3 = 11;
const int motorPin4 = 12;
const int pulseServoPin = 10;
Servo directionServo;

int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  directionServo.attach(pulseServoPin);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    
    //Serial.println(incomingByte);
    if (incomingByte == 'L' || incomingByte == 'l') {
        //directionServo.write(50); 
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
        //Serial.println("Moving Left!");
    }
    if (incomingByte == 'C' || incomingByte == 'c') {
        //directionServo.write(85); 
        
      digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin3, LOW);
        //Serial.println("Moving Center!");
    }
    if (incomingByte == 'R' || incomingByte == 'r') {
        directionServo.write(125); 
      digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin3, HIGH);
        //Serial.println("Moving Right!");
    }
    if (incomingByte == 'F' || incomingByte == 'f') {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
        //Serial.println("Moving Fowards!");
    }
    if (incomingByte == 'B' || incomingByte == 'b') {
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin1, LOW);
        //Serial.println("Moving Backwards!");
    }
    if (incomingByte == 'N' || incomingByte == 'n') {
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin1, LOW);
    }
  }
}

