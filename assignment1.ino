#include <Servo.h>
Servo servo1;
int potpin=0;
int Red = 2;
int Blue = 3;
int Green=4;
int val;
int trigpin=5;
int echopin=6;
long distance;
long duration;
 
void setup()
{
servo1.attach(9); 
 pinMode(Red, OUTPUT);
 pinMode(Blue, OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}
 
void loop() {
  //ultra();
  servo1.write(0);
  val=analogRead(potpin);
  val = map(val, 0,1023,0,100);
  servo1.write(val);
  delay(15);
   if(distance <=100){
  digitalWrite(Red,HIGH);
  delay(3000);
  digitalWrite(Red, LOW);
  delay(3000);
   servo1.write(60);
  }
   else  { servo1.write(0);}
  if (distance<=100){
  digitalWrite(Blue, HIGH);
  delay(2000);
  digitalWrite(Blue,LOW);
  delay(2000);   
   servo1.write(120);
 }
 
  else { servo1.write(0);}
   if (distance<=100){
  digitalWrite(Green,HIGH);
  delay(1000);
  digitalWrite(Green,LOW);
  delayMicroseconds(1000);
  servo1.write(180);
    }
  
    
  else{ servo1.write(0);}
}
void ultra(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  //digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  //distance=duration*0.343/2;
}
  

