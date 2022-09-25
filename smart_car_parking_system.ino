// Include the Servo library 
#include <Servo.h>
//assigning of pins for our components
//servo motors
int s1=2; //servo motor at entrance
int s2=3; //servo motor at exit
// Create a servo object 
Servo Servo1; 
Servo Servo2;
//ir sensors
int ir1=4; //ir sensor at entrance
int ir2=5; //ir sensor at parking slot1
int ir3=6; //ir sensor at parking slot2
int ir4=7; //ir sensor at parking slot3
int ir5=8; //ir sensor at parking slot4
int ir6=9; //ir sensor at exit
//red leds
int r1=A0; //at entrance
int r2=A1; //at slot1
int r3=A2; //at slot2
int r4=A3; //at slot3
int r5=A4; //at slot4
//green leds
int g1=A5; //at entrance
int g2=10;//at slot1
int g3=11; //at slot2
int g4=12; //at slot3
int g5=13; //at slot4

void setup() {
  Serial.begin(9600);
  // We need to attach the servo to the used pin number 
  Servo1.attach(s1); 
  Servo1.attach(s2);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
  pinMode(ir5,INPUT);
  pinMode(ir6,INPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  pinMode(r5,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(g2,OUTPUT);
  pinMode(g3,OUTPUT);
  pinMode(g4,OUTPUT);
  pinMode(g5,OUTPUT);

}

void loop() {
  //at the entrance
{
if((digitalRead(ir2)==LOW) || (digitalRead(ir3)==LOW) || (digitalRead(ir3)==LOW) || (digitalRead(ir4)==LOW))
    {
     analogWrite(A5,HIGH);
     analogWrite(A0,LOW);
     
     if(digitalRead(ir1)==LOW)
        {
         Servo1.write(0);
         delay(1000);
         Servo1.write(90); 
         delay(100000);
         Servo1.write(0);
         }
    }
else
    {
    analogWrite(A5,LOW);
    analogWrite(A0,HIGH);
    }
}
//Inside the parking lot
 //inside the parking slot1
 {
  if(digitalRead(ir2)==LOW)
   {
     analogWrite(r2,HIGH);
     digitalWrite(g2,LOW);
   }
  else
    {
       analogWrite(r2,LOW);
       digitalWrite(g2,HIGH);    
    }
 }
 //inside the parking slot2
 {
  if(digitalRead(ir3)==LOW)
   {
     analogWrite(r3,HIGH);
     digitalWrite(g3,LOW);
   }
  else
    {
       analogWrite(r3,LOW);
       digitalWrite(g3,HIGH);    
    }
 }

 //inside the parking slot3
 {
  if(digitalRead(ir4)==LOW)
   {
     analogWrite(r4,HIGH);
     digitalWrite(g4,LOW);
   }
  else
    {
       analogWrite(r4,LOW);
       digitalWrite(g4,HIGH);    
    }
 }

 //inside the parking slot4
 {
  if(digitalRead(ir5)==LOW)
   {
     analogWrite(r5,HIGH);
     digitalWrite(g5,LOW);
   }
  else
    {
       analogWrite(r5,LOW);
       digitalWrite(g5,HIGH);    
    }
 }

 //At the exit
 if(digitalRead(ir6)==LOW)
        {
         Servo2.write(0);
         delay(1000);
         Servo2.write(90); 
         delay(100000);
         Servo2.write(0);
         }   
 
       }
