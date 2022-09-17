// C++ code
//
/*
Description:

Ultrasonic Sensor:
The Ultrasonic Sensor is used for automatic door open and close. If the person comes near to the door , 
then light goes on or else light goes off.

Temperature Sensor:
Temperature sensor - high voltage are detected ,the buzzer goes on or else there is no buzzer sound  ,
and it used for fire emergency cases

*/
const int TRIG_PIN = 6; 
const int ECHO_PIN = 7; 
const int LED_PIN  = 3; 
const int DISTANCE_THRESHOLD = 50; 


float duration_us, distance_cm;


void setup()
{
  Serial.begin (9600);       
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);  
  pinMode(LED_PIN, OUTPUT);
  
  
  pinMode(4,OUTPUT);
}

void loop()
{
 double avalue=analogRead(A2);
 Serial.print("avalue is :");
  Serial.println(avalue);
  double ca= avalue/1024;
  double v= ca* 5;
  Serial.print("voltage is:");
  Serial.println(v);
  double o =v-0.5;
  Serial.print("offset voltage:");
  Serial.println(o);
  double t= o*100;
  Serial.print("temeperature is");
  Serial.println(t);
  if (t>=50)
  {
  digitalWrite(4,HIGH);
    Serial.println("Alert");
  }
  else
  {
   digitalWrite(4,LOW);
    Serial.println("No alert");
  }
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  duration_us = pulseIn(ECHO_PIN, HIGH);
 
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    digitalWrite(LED_PIN, HIGH); 
  else
    digitalWrite(LED_PIN, LOW); 

  
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  
  
  delay(500);
  
  
}
