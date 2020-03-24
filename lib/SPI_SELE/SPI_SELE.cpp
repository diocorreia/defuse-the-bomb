/*
    Faculty of Engineering - University of Porto
    SELE [EEC0152] - Electronic Systems
    Professor:
            Hélio Mendonça [hsm@fe.up.pt]
    Authors:
            Diogo Faria Correia [up201504726@fe.up.pt]
            Pedro Miguel Coutinho Augusto [up201503495@fe.up.pt]
*/

#include <SPI_SELE.h>

void SPInit(){
    //Set SS, MOSI and SCK as output
    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);
    //Enable SPI, Master and set clock frequency as fck/8
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    SPSR = (1 << SPI2X);
}
void SPISend(uint8_t payload){
    //Start the transmission
    SPDR = payload;
    //Wait for the completion of the transmission
    while(!(SPSR & (1 << SPIF)));
}
