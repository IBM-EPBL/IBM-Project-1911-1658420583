/*
Description:

Temperature Sensor:
Temperature sensor - high voltage are detected ,the buzzer goes on or else there is no buzzer sound  ,
and it used for fire emergency cases.

PIR Sensor:
The PIR Sensor is used to conserve power by turning on/off. 
If motion of the person detected inside the room then lights turn on or else turn off the lights. 
*/




void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop()
{
  digitalWrite(3,LOW);
  int read = digitalRead(2);
  if(read==HIGH){
    digitalWrite(3,HIGH);
    Serial.println(1);
    delay(1000);
  }
  else{
    Serial.println(0);
  }
  
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
  
  delay(2000);
}


