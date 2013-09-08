// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);  
} 
 
boolean left = false;
int value = 0;
void loop() 
{ 
  String in = unlimitedRead();
  int data = value;
  if(in.length()  > 0){
    data = in.toInt();
  }
  if(data != value){
    myservo.write(value = data);          
    Serial.print("Rotating to ");
    Serial.print(data);
    Serial.println("°");
  }
  /*
  int chars = 0;
  if ((chars=Serial.available())>0)            // Check to see if there are any serial input
  {
    char *vector[chars];
    for(int i=0; i<chars;i++){
      vector[i] = Serial.read();
    }
    
    int new_value = atoi(vector);
    if(new_value >= 0){
      if(new_value != value){
        myservo.write(new_value);
        value = new_value; 
      } 
    }
  }*/
  /*
  //while there are data to recieve...
  char buffer[32];
  int pos=0;
  while(Serial.available()>0){
    // read the incoming byte:
    char inByte = Serial.read();
    // add to our read buffer
    buffer[pos++] = inByte;
    
    Serial.print("Input serial: "+ inByte);
    if (inByte == ';')
    {
      buffer[pos-1] = 0;
      int servoNumber = atoi(buffer);
      Serial.print("Servo degree: "+ servoNumber);
    }
  }*/
  delay(100);
} 

String unlimitedRead(){
  String content = "";
  char character;

  while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
  }

  if (content != "") {
    //Serial.print(content);
  }
  return content;
}
