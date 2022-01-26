#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>
modbusDevice regBank;
modbusSlave slave;
#define ExdVfdRunCommand 54


void setup()
{   
  regBank.setId(1);

//Add Digital Output registers 00001-00016 to the register bank
  regBank.add(1);
  regBank.add(2);
  regBank.add(3);
  regBank.add(4);
  regBank.add(5);
  regBank.add(6);
  regBank.add(7);
  regBank.add(8);
  regBank.add(9);
  regBank.add(10);
  regBank.add(11);
  regBank.add(12);
  regBank.add(13);
  regBank.add(14);
  regBank.add(15);
  regBank.add(16);

//Add Digital Input registers 10001-10008 to the register bank
  regBank.add(10001);  
  regBank.add(10002);  
  regBank.add(10003);  
  regBank.add(10004);  
  regBank.add(10005);  
  regBank.add(10006);  
  regBank.add(10007);  
  regBank.add(10008);  

//Add Analog Input registers 30001-10010 to the register bank
  regBank.add(30001);  
  regBank.add(30002);  
  regBank.add(30003);  
  regBank.add(30004);  
  regBank.add(30005);  
  regBank.add(30006);  
  regBank.add(30007);  
  regBank.add(30008);  
  regBank.add(30009);  
  regBank.add(30010);  

//Add Analog Output registers 40001-40020 to the register bank
  regBank.add(40001);  
  regBank.add(40002);  
  regBank.add(40003);  
  regBank.add(40004);  
  regBank.add(40005);  
  regBank.add(40006);  
  regBank.add(40007);  
  regBank.add(40008);  
  regBank.add(40009);  
  regBank.add(40010);  
  regBank.add(40011);  
  regBank.add(40012);  
  regBank.add(40013);  
  regBank.add(40014);  
  regBank.add(40015);  
  regBank.add(40016);  
  regBank.add(40017);  
  regBank.add(40018);  
  regBank.add(40019);  
  regBank.add(40020);  
  slave._device = &regBank;    
  slave.setBaud(9600);   
}

void loop()
{
//put some data into the registers
  regBank.set(1, 1);  
  regBank.set(2, 1);  
  regBank.set(3, 0);  
  regBank.set(4, 1);  
  regBank.set(5, 1);  
  regBank.set(6, 0);  
  regBank.set(7, 1);  
  regBank.set(8, 0);  

  regBank.set(10001, 1);
  regBank.set(10002, 1);  
  regBank.set(10003, 1);  
  regBank.set(10004, 1);  
  regBank.set(10005, 0);  
  regBank.set(10006, 0);  
  regBank.set(10007, 0);  
  regBank.set(10008, 0);  


  regBank.set(30001,1);
  regBank.set(30002,2);
  regBank.set(30003,3);
  regBank.set(30004,4);
  regBank.set(30005,5);
  regBank.set(30006,6);
  regBank.set(30007,7);
  regBank.set(30008,8);
  regBank.set(30009,9);
  regBank.set(30010,10);

  regBank.set(40001,1);
  regBank.set(40002,2);
  regBank.set(40003,2);
  regBank.set(40004,4);
  regBank.set(40005,5);
  regBank.set(40006,6);
  regBank.set(40007,7);
  regBank.set(40008,8);
  regBank.set(40009,9);
  regBank.set(40010,10);
  
 while(1)
  {
    //put a random number into registers 1, 10001, 30001 and 40001
    regBank.set(1, (byte) random(0, 2));
    regBank.set(10001, (byte) random(0, 2));
    regBank.set(30001, (word) random(0, 32767));
    regBank.set(40001, (word) random(0, 32767));
    
     slave.run();  
  }
}
/*
#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

/* PINS
Add more registers if needed
Digital input pins 2,3,4,5,6,7
Digital output pins 8,9,12,13
Analog output pins 10,11 (PWM)
Analog input pins 0,1,2,3,4,5



modbusDevice regBank;
modbusSlave slave;

int AI0,AI1,AI2,AI3,AI4,AI5;


void setup()
{   
  regBank.setId(1); ///Set Slave ID

//Add Digital Input registers
  regBank.add(10002);
  regBank.add(10003);
  regBank.add(10004);
  regBank.add(10005);
  regBank.add(10006);
  regBank.add(10007);
// Add Digital Output registers
  regBank.add(8);
  regBank.add(9);
  regBank.add(12);
  regBank.add(13);
//Analog input registers
  regBank.add(30001);
  regBank.add(30002);
  regBank.add(30003);
  regBank.add(30004);
  regBank.add(30005);
  regBank.add(30006);
//Analog Output registers
  regBank.add(40010);  
  regBank.add(40011);  

  slave._device = &regBank;  
  slave.setBaud(9600);   
  
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
   
}
void loop(){

  while(1){   
  //Digital Input
    byte DI2 = digitalRead(2);
    if (DI2 >= 1)regBank.set(10002,1);
    if (DI2 <= 0)regBank.set(10002,0);
    byte DI3 = digitalRead(3);
    if (DI3 >= 1)regBank.set(10003,1);
    if (DI3 <= 0)regBank.set(10003,0);
    byte DI4 = digitalRead(4);
    if (DI4 >= 1)regBank.set(10004,1);
    if (DI4 <= 0)regBank.set(10004,0);
    byte DI5 = digitalRead(5);
    if (DI5 >= 1)regBank.set(10005,1);
    if (DI5 <= 0)regBank.set(10005,0);
    byte DI6 = digitalRead(6);
    if (DI6 >= 1)regBank.set(10006,1);
    if (DI6 <= 0)regBank.set(10006,0);
    byte DI7 = digitalRead(7);
    if (DI7 >= 1)regBank.set(10007,1);
    if (DI7 <= 0)regBank.set(10007,0);
                                
  //Digital output
    int DO8 = regBank.get(8);
      if (DO8 <= 0 && digitalRead(8) == HIGH)digitalWrite(8,LOW);
      if (DO8 >= 1 && digitalRead(8) == LOW)digitalWrite(8,HIGH);
    int DO9 = regBank.get(9);
      if (DO9 <= 0 && digitalRead(9) == HIGH)digitalWrite(9,LOW);
      if (DO9 >= 1 && digitalRead(9) == LOW)digitalWrite(9,HIGH);
    int DO12 = regBank.get(12);
      if (DO12 <= 0 && digitalRead(12) == HIGH)digitalWrite(12,LOW);
      if (DO12 >= 1 && digitalRead(12) == LOW)digitalWrite(12,HIGH);
    int DO13 = regBank.get(13);
      if (DO13 <= 0 && digitalRead(13) == HIGH)digitalWrite(13,LOW);
      if (DO13 >= 1 && digitalRead(13) == LOW)digitalWrite(13,HIGH);
            
  //Analog input  ***READ Twice deliberately
    AI0 = analogRead(0);
    delay(10);
    AI0 = analogRead(0);
    regBank.set(30001, (word) AI0);
    delay(10);
    
    AI1 = analogRead(1);
    delay(10);
    AI1 = analogRead(1);
    regBank.set(30002, (word) AI1);
    delay(10);
    
    AI2 = analogRead(2);
    delay(10);
    AI2 = analogRead(2);
    regBank.set(30003, (word) AI2);
    delay(10);
    
    AI3 = analogRead(3);
    delay(10);
    AI3 = analogRead(3);
    regBank.set(30004, (word) AI3);
    delay(10);
    
    AI4 = analogRead(4);
    delay(10);
    AI4 = analogRead(4);
    regBank.set(30005, (word) AI4);
    delay(10);
    
    AI5 = analogRead(5);
    delay(10);
    AI5 = analogRead(5);
    regBank.set(30006, (word) AI5);
    delay(10);
        
  //Analog output 
    word AO10 = regBank.get(40010);
    analogWrite(10,AO10);
    delay(10);
    word AO11 = regBank.get(40011);
    analogWrite(11,AO11);
    delay(10);
        
  slave.run();  
  }
}*/
