#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7
#define buzz 9

long duration, distance, RightSensor,LeftSensor,FrontSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
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
Serial.println(LeftSensor);
Serial.println(RightSensor);
Serial.println(FrontSensor);
if(RightSensor<20 && RightSensor>0)
  {
    digitalWrite(buzz,HIGH);
    tone(700,100);
    delay(10);
  }
  if(LeftSensor<20 && LeftSensor>0)
  {
    digitalWrite(buzz,HIGH);
    tone(700,2000);
    delay(10);
    
  }
  if(FrontSensor<20 && FrontSensor>0)
  {
    digitalWrite(buzz,HIGH);
    tone(700,3500);
    delay(10);
    
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


