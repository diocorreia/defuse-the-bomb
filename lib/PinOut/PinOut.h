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

#define SS  PORTB2 //Uno: 10
#define RST  3 //Uno: 3
#define DC   2 //Uno: 2
#define MOSI PORTB3 //Uno: 11
#define SCK  PORTB5 //Uno: 13

#define DD_SCK  DDB5 //Uno: 13
#define DD_MOSI DDB3 //Uno: 11
#define DD_DC   DDD2 //Uno: 2
#define DD_SCE  DDB2 //Uno: 10
#define DD_RST  DDD3 //Uno: 3

#define wire1 4
#define wire2 5
#define wire3 6
#define rstbtn 7