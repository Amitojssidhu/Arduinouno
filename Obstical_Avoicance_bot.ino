
const int trigPin = 2;
const int echoPin = 3;

const int MotorL1 = 9;
const int MotorL2 = 10;

const int MotorR1 = 11;
const int MotorR2 = 12;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  
  pinMode(MotorL1 , OUTPUT);
  pinMode(MotorL2 , OUTPUT);
  pinMode(MotorR1 , OUTPUT);
  pinMode(MotorR2 , OUTPUT);

//to test motor forward motion & stop motor
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  delay(1000);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);  
  
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;    // Distance = (Time * Speed) /2

  Serial.print("Distance: ");
  Serial.println(distance);

      if(distance < 15)
      {  //Stop the Motor
        digitalWrite(MotorL1, LOW);
        digitalWrite(MotorL2, LOW);
        digitalWrite(MotorR1, LOW);
        digitalWrite(MotorR2, LOW); 
      }
      
      else
      { //Move Forward
        digitalWrite(MotorL1, HIGH);
        digitalWrite(MotorL2, LOW);
        digitalWrite(MotorR1, HIGH);
        digitalWrite(MotorR2, LOW); 
      }

  
}
