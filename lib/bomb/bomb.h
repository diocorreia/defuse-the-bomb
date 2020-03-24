/*
    Faculty of Engineering - University of Porto
    SELE [EEC0152] - Electronic Systems
    Professor:
            Hélio Mendonça [hsm@fe.up.pt]
    Authors:
            Diogo Faria Correia [up201504726@fe.up.pt]
            Pedro Miguel Coutinho Augusto [up201503495@fe.up.pt]
*/

#include <PCD8544_SELE.h>
#define GAMEDURATION 30

void zByte(uint8_t num);
void ffByte(uint8_t num);
void initBOMB(uint8_t* counter, uint8_t* kaboom, uint8_t* win, long* wire);
void checkWires(long wire, uint8_t* win, uint8_t* kaboom, uint8_t* lstkaboom,uint8_t* triggeredWire);
void winscreen();
void updatecounter(unsigned long* t, uint8_t* counter);
void explosion(uint8_t* expSTATE,unsigned long* t);
