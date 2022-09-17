/*Description : 
ULTRASONIC SENSOR : 
The Ultrasonic Sensor is used for automatic door open and close. If the person comes near to the door , then buzzer goes on or else there is no buzzer sound.

GAS SENSOR : 
When gas leakage is detected and when the gas level readings exceeds 470 , the LED turns on otherwise the LED is turned off. This can be used to turn on/off emergency alarm light to indicate fire accidents.

*/
int trig =2;
int echo = 3;
int led = 12;
int buzzer = 8;
int gasSensor=A1;
void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode (echo,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  float dur = pulseIn(echo,HIGH);
  float dist = (dur*0.0343)/2;
  float avalue = analogRead(gasSensor);
  Serial.print("distance is");
  Serial.println(dist);
  if (dist <= 100)
  {
  
    digitalWrite(buzzer,HIGH);
  }
  else{
  
        digitalWrite(buzzer,LOW);

  }
  if(avalue>=470) {
    digitalWrite(led,HIGH);
    Serial.println(avalue);
  }
  else{
    digitalWrite(led,LOW);
    Serial.println(avalue);
  
  }
}
