int MotorL1 = 6;
int MotorL2 = 7;

int MotorR1 = 8;
int MotorR2 = 9;

//int data;

void setup() 
{
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

void loop() 
{
  if(Serial.available()>0)
  {
   int data = Serial.read();

   switch (data) 
         {
            case 'F':
            Forward();
            break;

            case 'B':
            Backward();
            break;

            case 'L':
            Left();
            break;

            case'R':
            Right();
            break;

            default:
            Serial.print ("Invalid");
            Stop();
            
         }
  } 

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