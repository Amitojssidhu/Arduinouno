// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
// Variables for the duration and the distance
long duration;
int distance;
int MotorL1 = 6;
int MotorL2 = 7;

int MotorR1 = 8;
int MotorR2 = 9;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT); 
  
  Forward();
  delay(1000);
  Backward();
  delay(1000);
  Left();
  delay(1000);
  Right();
  delay(1000);
  Stop();
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  digitalWrite(9, LOW);
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
  if(Serial.available()>0)
  {
   int data = Serial.read();

    if(data=='1')
    {Forward(); 
     delay(200);
     data = 0;
    }

    else if(data=='2')
    {Backward();
     delay(200);
     data = 0;
    }

    else if(data=='3')
    {Right();
     delay(400);
     data = 0;
    }

    else if(data=='4')
    {Left();
     delay(400);
     data = 0;
    }

  }
    else
    {Stop();}
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
void Stop() {
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  Serial.println("STOP");
  }

void Forward() {
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  Serial.println("FORWARD");
  }

void Backward() {
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  Serial.println("FORWARD");
  }

void Left() {
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);//digitalWrite(MotorL2, LOW); 
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  //
  Serial.println("LEFT");
  }

void Right() {
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorR1, HIGH);//digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  Serial.println("RIGHT");
  }