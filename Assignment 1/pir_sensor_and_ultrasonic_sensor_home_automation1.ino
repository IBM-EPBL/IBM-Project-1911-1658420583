/* DESCRIPTION:
   The PIR Sensor is used to conserve power. If motion of the person detected inside the room, then lights turn on or else turn off the lights.
   The Ultrasonic Sensor is used for automatic door open and close. If the person comes near to the door, then buzzer goes on or else there is no buzzer sound.
 */

int trig =2;
int echo = 3;
int led = 12;
int buzzer = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode (echo,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(4, INPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  float dur = pulseIn(echo,HIGH);
  float dist = (dur*0.0343)/2;
 
  Serial.print("distance is");
  Serial.println(dist);
  if (dist <= 100)
  {
  
    digitalWrite(buzzer,HIGH);
  }
  else{
  
        digitalWrite(buzzer,LOW);

  }
  
  digitalWrite(5, LOW);
  int read=digitalRead(4);
  if(read == HIGH)
  {
    digitalWrite(5,HIGH);
    Serial.println(1);
    delay(1000); 
  }
  else{
     Serial.println(0);
  }
  delay(1000); 
  
}
