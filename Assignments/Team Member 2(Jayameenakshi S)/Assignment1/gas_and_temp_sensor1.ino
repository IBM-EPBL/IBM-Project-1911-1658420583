/*
Description:

Gas Sensor:
When gas leakage is detected and when the gas level readings exceeds 100 , the LED turns on otherwise the LED is turned off. 
This can be used to turn on/off emergency alarm light to indicate fire accidents.


Temperature Sensor:
Temperature sensor - high voltage are detected ,the buzzer goes on or else there is no buzzer sound  ,
and it used for fire emergency cases

*/

int LED = A1;
const int gas = 0;
int MQ2pin = A0;


void setup() {
  Serial.begin(9600);
  pinMode(4,OUTPUT);
}

void loop() {
  float sensorValue,MQ2pin;
sensorValue = analogRead(MQ2pin);
  if(sensorValue >=100){
    digitalWrite(LED,LOW);
    Serial.print(sensorValue);
    Serial.println(" |SMOKE DETECTED");
    
  
  }
  else{
  	digitalWrite(LED,HIGH);
    Serial.println("Sensor Value: ");
    Serial.println(sensorValue);
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
	float getsensorValue(int pin){
  	return (analogRead(pin));
}