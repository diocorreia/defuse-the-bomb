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

void PCD8544Init(){
    digitalWrite(RST, HIGH);
    delay(1);
    digitalWrite(RST, LOW);
    delay(1);
    digitalWrite(RST, HIGH);
    SPInit();
}

void PCD8544SendCommand(uint8_t command){
    digitalWrite(DC, LOW); //DC set LOW to send data
    SPISend(command);
}

void PCD8544SendData(uint8_t data){
    digitalWrite(DC, HIGH);
    SPISend(data);
}

void PCD8544SendTwoPoints(){

    for(int i = 0; i<6; i++) PCD8544SendData(0b00000000); 
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b01111000);
    PCD8544SendData(0b00011110);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00000000);
    for(int i = 0; i<3; i++){
        PCD8544SendData(0b00000000);
        PCD8544SendData(0b00000000);
        PCD8544SendData(0b01001000);
        PCD8544SendData(0b00010010);
        PCD8544SendData(0b00000000);
        PCD8544SendData(0b00000000);
    }
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b01111000);
    PCD8544SendData(0b00011110);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00000000);
    for(int i = 0; i<12; i++) PCD8544SendData(0b00000000); 
}

void PCD8544Send1920(){
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00000001); //Number 1
    PCD8544SendData(0b00011111);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00010111); //Number 9
    PCD8544SendData(0b00010101);
    PCD8544SendData(0b00011111);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00010000);
    PCD8544SendData(0b00001000); //'/' character
    PCD8544SendData(0b00000100);
    PCD8544SendData(0b00000010);
    PCD8544SendData(0b00000001);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00011101); //Number 2
    PCD8544SendData(0b00010101);
    PCD8544SendData(0b00010111);
    PCD8544SendData(0b00000000);
    PCD8544SendData(0b00011111); //Number 0
    PCD8544SendData(0b00010001);
    PCD8544SendData(0b00011111);
}

void intro(){

  PCD8544Sendletter('F');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('E');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('U');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('P');
  for(int i=0;i<24;i++)PCD8544SendData(0b00000000);
  PCD8544Sendletter('S');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('E');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('L');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('E');
  PCD8544SendData(0b00000000);
  PCD8544Send1920();
  for(int i=0;i<84;i++)PCD8544SendData(0b00000000);
  for(int i=0;i<11;i++)PCD8544SendData(0b00000000);
  PCD8544Sendletter('D');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('I');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('G');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('C');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('R');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('R');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('E');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('I');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('A');
  for(int i=0;i<11;i++)PCD8544SendData(0b00000000);
  for(int i=0;i<11;i++)PCD8544SendData(0b00000000);
  PCD8544Sendletter('P');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('E');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('D');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('R');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00000000);
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('A');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('U');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('G');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('U');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('S');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('T');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('O');
  for(int i=0;i<11;i++)PCD8544SendData(0b00000000);
  for(int i=0;i<34;i++)PCD8544SendData(0b00000000);
  for(int i=0;i<84;i++)PCD8544SendData(0b00000000);
  PCD8544Sendletter('H');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('S');
  PCD8544SendData(0b00000000);
  PCD8544Sendletter('M');
  for(int i=0;i<34;i++)PCD8544SendData(0b00000000);
}


void PCD8544SendNumber(int number){
    digitalWrite(DC, HIGH); //DC set HIGH to send data
    switch(number){
        case 1:
            for(int i = 0; i<72; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<5;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 2:
            for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 3:
            for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 4:
            for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11000000);
                PCD8544SendData(0b00000011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 5:
            for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 6:
            for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 7:
            for(int i = 0; i<30; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00001111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 8:
             for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 9:
            for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<8;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11001111);
                PCD8544SendData(0b11110011);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<4;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
        case 0:
            for(int i = 0; i<6; i++) PCD8544SendData(0b00000000);
            for(int i = 0; i<5;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<6;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00011111);
                PCD8544SendData(0b11111000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<5;i++){                
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b11111111);
                PCD8544SendData(0b00000000);
                PCD8544SendData(0b00000000);
            }
            for(int i = 0; i<12; i++) PCD8544SendData(0b00000000);
            break;
    }
}

void PCD8544Sendletter(char letter){
    digitalWrite(DC, HIGH); //DC set HIGH to send data
    switch(letter){
        case 'A':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000101);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'B':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010101);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00001010);
            PCD8544SendData(0b00000000);
            break;
        case 'C':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00000000);
            break;
        case 'D':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00001110);
            PCD8544SendData(0b00000000);
            break;
        case 'E':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010101);
            PCD8544SendData(0b00010101);
            PCD8544SendData(0b00000000);
            break;
        case 'F':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000101);
            PCD8544SendData(0b00000101);
            PCD8544SendData(0b00000000);
            break;
        case 'G':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00011101);
            PCD8544SendData(0b00000000);
            break;
        case 'H':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000100);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'I':
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00000000);
            break;
        case 'J':
            PCD8544SendData(0b00011001);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'K':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000100);
            PCD8544SendData(0b00011011);
            PCD8544SendData(0b00000000);
            break;
        case 'L':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010000);
            PCD8544SendData(0b00010000);
            PCD8544SendData(0b00000000);
            break;
        case 'M':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000010);
            PCD8544SendData(0b00000100);
            PCD8544SendData(0b00000010);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'N':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000010);
            PCD8544SendData(0b00000100);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'O':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'P':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000101);
            PCD8544SendData(0b00000111);
            PCD8544SendData(0b00000000);
            break;
        case 'Q':
            PCD8544SendData(0b00001111);
            PCD8544SendData(0b00001001);
            PCD8544SendData(0b00001101);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'R':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00001101);
            PCD8544SendData(0b00010111);
            PCD8544SendData(0b00000000);
            break;
        case 'S':
            PCD8544SendData(0b00010111);
            PCD8544SendData(0b00010101);
            PCD8544SendData(0b00011101);
            PCD8544SendData(0b00000000);
            break;
        case 'T':
            PCD8544SendData(0b00000001);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000001);
            PCD8544SendData(0b00000000);
            break;
        case 'U':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00010000);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'V':
            PCD8544SendData(0b00001111);
            PCD8544SendData(0b00010000);
            PCD8544SendData(0b00001111);
            PCD8544SendData(0b00000000);
            break;
        case 'W':
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00001000);
            PCD8544SendData(0b00000100);
            PCD8544SendData(0b00001000);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
        case 'X':
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00001010);
            PCD8544SendData(0b00000100);
            PCD8544SendData(0b00001010);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00000000);
            break;
        case 'Y':
            PCD8544SendData(0b00000011);
            PCD8544SendData(0b00011100);
            PCD8544SendData(0b00000011);
            PCD8544SendData(0b00000000);
            break;
        case 'Z':
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00011001);
            PCD8544SendData(0b00010101);
            PCD8544SendData(0b00010011);
            PCD8544SendData(0b00010001);
            PCD8544SendData(0b00000000);
            break;
        case ' ':
            PCD8544SendData(0b00000000);
            PCD8544SendData(0b00000000);
            PCD8544SendData(0b00000000);
            break;
        default:
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00011111);
            PCD8544SendData(0b00000000);
            break;
    }
}
