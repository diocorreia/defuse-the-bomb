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
#include <SPI_SELE.h>

void PCD8544Init();
void PCD8544SendCommand(uint8_t command);
void PCD8544SendData(uint8_t data);
void PCD8544Sendletter(char letter);
void PCD8544SendNumber(int number);
void PCD8544SendTwoPoints();
void PCD8544Send1920();
void intro();
