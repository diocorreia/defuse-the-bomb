/*
    Faculty of Engineering - University of Porto
    SELE [EEC0152] - Electronic Systems
    Professor:
            Hélio Mendonça [hsm@fe.up.pt]
    Authors:
            Diogo Faria Correia [up201504726@fe.up.pt]
            Pedro Miguel Coutinho Augusto [up201503495@fe.up.pt]
*/

#include <Arduino.h>
#include <bomb.h>


uint8_t explosionw[] = {
	0x3f, 0x3f, 0x1f, 0x0f, 0x0f, 0x07, 0x67, 0x63, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 
	0x73, 0x73, 0x73, 0x73, 0x6f, 0x67, 0xc7, 0xc7, 0xcf, 0x1f, 0x1f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xef, 
	0xcf, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd6, 0xd6, 0x10, 0x00, 0x06, 0x80, 0x80, 0x00, 0x00, 0x00, 
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0xd6, 
	0xd6, 0xd7, 0xd7, 0xd7, 0xd7, 0xe7, 0xe7, 0xe7, 0xe7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfd, 0xfd, 
	0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xc1, 0x01, 0x01, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 
	0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x9f, 0xc7, 0xc3, 0x99, 
	0x9b, 0x9b, 0x9f, 0x83, 0xc7, 0x87, 0x87, 0x87, 0xbf, 0x9f, 0xbf, 0xbd, 0xbc, 0x9c, 0x9c, 0x80, 
	0xc3, 0x83, 0x9b, 0x9b, 0x83, 0xe3, 0xa3, 0x87, 0x9f, 0x87, 0xa7, 0x3f, 0x3f, 0xff, 0xbf, 0xbf, 
	0xbf, 0xbf, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

void zByte(uint8_t num){
    for (int i=0; i < num; i++) PCD8544SendData(0x00);
}

void ffByte(uint8_t num){
    for (int i=0; i < num; i++) PCD8544SendData(0xff);
}

void initBOMB(uint8_t* counter, uint8_t* kaboom, uint8_t* win, long* wire){
    *counter = (uint8_t) GAMEDURATION;
    *kaboom = (uint8_t) 0;
    randomSeed(micros());
    *wire = (long) random(1, 4);
    *win = (uint8_t) 0;
}

void checkWires(long wire, uint8_t* win, uint8_t* kaboom, uint8_t* lstkaboom, uint8_t* triggeredWire){
  
  *lstkaboom = *kaboom;
  uint8_t w1 = digitalRead(wire1);
  uint8_t w2 = digitalRead(wire2);
  uint8_t w3 = digitalRead(wire3);

  if(w1 && (*kaboom == 0)) *triggeredWire = 1;
  if(w2 && (*kaboom == 0)) *triggeredWire = 2;
  if(w3 && (*kaboom == 0)) *triggeredWire = 3;

  if(w1 && (wire != 1) && (*kaboom == 0)) *kaboom = 1;
  else if(w2 && (wire != 2) && (*kaboom == 0)) *kaboom = 1;
  else if(w3 && (wire != 3) && (*kaboom == 0)) *kaboom = 1;
  else if(w1 && (wire != 1) && (*triggeredWire != 1) && (*kaboom == 1)) *kaboom = 2;
  else if(w2 && (wire != 2) && (*triggeredWire != 2) && (*kaboom == 1)) *kaboom = 2;
  else if(w3 && (wire != 3) && (*triggeredWire != 3) && (*kaboom == 1)) *kaboom = 2;
  
  if(w1 && (wire == 1)) *win = 1;
  else if(w2 && (wire == 2)) *win = 1;
  else if(w3 && (wire == 3)) *win = 1;
}

void winscreen(){

  PCD8544SendCommand(0b00100000); //Chip Active, Horizontal Addressing,Basic instruction set
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('C');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('N');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('G');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('R');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('A');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('T');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('U');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('L');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('A');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('T');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('I');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('N');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('S');
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00010111);
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00010111);
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00010111);
  PCD8544SendData(0b00000000);
  for(int i = 0; i<84; i++) PCD8544SendData(0b00000000);
  for(int i = 0; i<35; i++) PCD8544SendData(0b00000000);
  PCD8544Sendletter('Y');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('U');
  for(int i = 0; i<35; i++) PCD8544SendData(0b00000000);
  for(int i = 0; i<84; i++) PCD8544SendData(0b00000000);
  for(int i = 0; i<33; i++) PCD8544SendData(0b00000000);
  PCD8544Sendletter('W');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('I');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('N');
  for(int i = 0; i<34; i++) PCD8544SendData(0b00000000);
  for(int i = 0; i<84; i++) PCD8544SendData(0b00000000);
}

void updatecounter(unsigned long* t, uint8_t* counter){
    long tnow;
    tnow = millis();

    if(((tnow-*t)>=1000) && (*counter > 0)){
        *t = tnow;
        *counter = (uint8_t) *counter-1;
    }
    PCD8544SendCommand(0b00100010); //Set vertical addressing
    if(counter <= 0){
      PCD8544SendNumber(0);
      PCD8544SendNumber(0);
      PCD8544SendTwoPoints();
      PCD8544SendNumber(0);
      PCD8544SendNumber(0);
      delay(500);
    }else{
      PCD8544SendNumber(0);
      PCD8544SendNumber(0);
      PCD8544SendTwoPoints();
      PCD8544SendNumber(*counter/10);
      PCD8544SendNumber(*counter%10);
    }
}
void explosion(uint8_t* expSTATE, unsigned long* t){
    unsigned long timediff = millis()-*t;
    
    if((*expSTATE == 0) && (timediff >= (unsigned long)200)) *expSTATE = 1;
    else if(*expSTATE == 1) *expSTATE = 2;
    else if((*expSTATE == 2) && (timediff >= (unsigned long)400)) *expSTATE = 3;
    else if(*expSTATE == 3) *expSTATE = 0;

    if(*expSTATE == 1){
      PCD8544SendCommand(0b00100000); //Chip Active, Horizontal Addressing,Basic instruction set
      ffByte(194);
      for (int i=0; i < 310; i++) PCD8544SendData(explosionw[i]);
    } else if(*expSTATE == 3){
      PCD8544SendCommand(0b00100000); //Chip Active, Horizontal Addressing,Basic instruction set
      zByte(194);
      for (int i=0; i < 310; i++) PCD8544SendData(~explosionw[i]);
      *t = millis();
    } else {

    }
   
}
