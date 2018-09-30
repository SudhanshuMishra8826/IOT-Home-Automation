#include <dht.h>
#include <Servo.h>
dht DHT;
Servo s;
int pos=0;
void setup() {
//select Outoput pins
pinMode(7,OUTPUT);
//Serial Monitor Initialization
Serial.begin(9600);
//Output pin for the servo
s.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  //code for alternating blinking of three led.
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
  digitalWrite(5,HIGH);
  delay(100);
  digitalWrite(5,LOW);
  delay(100);
  digitalWrite(2,HIGH);
  delay(100);
  digitalWrite(2,LOW);
  */
  
  /*
  //code for displaying temperature and humidity sensed by DHT on the serial monitor
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(300);
  */
  /*Code for checking temperature and blinking different led as per the temperature value also rotating 
   the servo by 45 degrees whwn temperature is under 32 degrees */
  int chk = DHT.read11(10);
  Serial.println(DHT.temperature);
  if(DHT.temperature<32){
    
    digitalWrite(7,HIGH);//for turning on one led
    digitalWrite(2,LOW);//for turning of one led
    digitalWrite(5,LOW);
  for(pos=0;pos<=45;pos++){
  s.write(pos); //for rotating the servo
  }
  for(pos=45;pos>=0;pos--){
  s.write(pos); 
  }
  }
   else if(DHT.temperature>32&&DHT.temperature<=34){
    digitalWrite(5,HIGH);
    digitalWrite(2,LOW);
  digitalWrite(7,LOW);
   }
   else if(DHT.temperature>34){
   digitalWrite(2,HIGH);
   digitalWrite(7,LOW);
  digitalWrite(5,LOW);
   }
     delay(300);   
   }
