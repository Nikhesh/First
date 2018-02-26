#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7
#define trigPin4 8
#define echoPin4 10
#define trigPin5 11
#define echoPin5 12
#define buzz 9

long duration, distance, RightSensor,LeftSensor,FrontSensor, DitchSensor, BumpSensor, Measure1, Measure2,Measure3, Measure4, Measure5, Threshold, Threshold1, Threshold2, Threshold3, Threshold4, Threshold5;
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(trigPin5, OUTPUT);
pinMode(echoPin5, INPUT);
pinMode(buzz, OUTPUT);
}

void loop() 
{
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
SonarSensor(trigPin3, echoPin3);
FrontSensor = distance;
SonarSensor(trigPin4, echoPin4);
DitchSensor = distance;
SonarSensor(trigPin5, echoPin5);
BumpSensor = distance;
Serial.println("LEFT");
Serial.println(LeftSensor);
Serial.println("RIGHT");
Serial.println(RightSensor);
Serial.println("FRONT");
Serial.println(FrontSensor);
Serial.println("DITCH");
Serial.println(DitchSensor);
Serial.println("BUMP");
Serial.println(BumpSensor);
  if(RightSensor<100 && RightSensor>0)
  {
    digitalWrite(buzz,HIGH);
    tone(500,1000);
    delay(10);
  }
  if(LeftSensor<100 && LeftSensor>0)
  {
    digitalWrite(buzz,HIGH);
    tone(700,1000);
    delay(10);
  }
  if(FrontSensor<100 && FrontSensor>0)
  {
    digitalWrite(buzz,HIGH);
    tone(1000,4000);
    delay(10);
  }
  if(DitchSensor>45)
  {
    delay(2);
    SonarSensor(trigPin4, echoPin4);
    Measure1 = distance;
    delay(10);
    SonarSensor(trigPin4, echoPin4);
    Measure2 = distance;
    Threshold=Measure2-Measure1;
    Threshold1=DitchSensor-Measure1;
    Threshold2=DitchSensor-Measure2;
    if(Threshold>20 || Threshold1>20 || Threshold2>20)  
    {
      digitalWrite(buzz,HIGH);
      delay(10);
    }
  }
  if(BumpSensor<150)
  {
    delay(2);
    SonarSensor(trigPin5, echoPin5);
    Measure3 = distance;
    delay(10);
    SonarSensor(trigPin5, echoPin5);
    Measure4 = distance;
    Threshold3=Measure2-Measure1;
    Threshold4=DitchSensor-Measure1;
    Threshold5=DitchSensor-Measure2;
    if(Threshold<10 || Threshold1<10 || Threshold2<10)  
    {
      digitalWrite(buzz,HIGH);
      tone(80,10000);
      delay(10);
    }
  }
  else
  {
    digitalWrite(buzz,LOW);
    delay(10);
    
  }
}

void SonarSensor(int trigPin,int echoPin)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
}

