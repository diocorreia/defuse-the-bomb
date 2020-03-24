# [FEUP][MIEEC][SELE] Final Project: DEFUSE THE BOMB

This project is composed by: an SPI library, a PCD8544 library and a small game-like demonstrator, called 'Defuse the BOMB' for the ATMega32 microcontroller. This project also includes a PCB design, in Arduino's Shield format, with all the required components for the demonstrator.

## Motivation
This project was developed by Diogo Correia (@PeachBug) and Pedro Augusto (@PetrusAugustus) for the course of Electronic Systems (EEC0152) of the Master in Electrical and Computers Engineering (MIEEC) at Faculty of Engineering of University of Porto (FEUP).
The objective of this project was to develope a system, that used a I2C or SPI module, for the ATMega32 microcontroller.

## PCD8544 and SPI Library

### SPI Library
This library was developed with the Philips PCD8544 Module as a slave device in mind. Our implementation of the SPI Protocol covers only the initialization and transmission phases. The reception of data from the slave was not implemented because the slave device doesn't transmit any data back to the master.

```cpp
void SPInit(){
    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    SPSR = (1 << SPI2X);
}
```

```cpp
void SPISend(uint8_t payload){
    SPDR = payload;
    while(!(SPSR & (1 << SPIF)));
}
```

### PCD8455 Library
The PCD8455 Middleware Library was developed in order to facilitate the communication between the microcontroller and the PCD8455 display driver. Our library has 3 core functions: initialization, send commands and send data. Other functions, such as PCD8544SendNumber() are available too.


```cpp
void PCD8544Init(){
    digitalWrite(RST, HIGH);
    delay(1);
    digitalWrite(RST, LOW);
    delay(1);
    digitalWrite(RST, HIGH);
    SPInit();
}
```

```cpp
void PCD8544SendCommand(uint8_t command){
    digitalWrite(DC, LOW); //DC set LOW to send data
    SPISend(command);
}
```

```cpp
void PCD8544SendData(uint8_t data){
    digitalWrite(DC, HIGH);
    SPISend(data);
}
```

## DEFUSE THE BOMB - Demonstrator

<img src="https://i.imgur.com/62OK2zr.jpg" height="160"/>
<img src="https://i.imgur.com/ycz6VgL.jpg" height="160"/>
<img src="https://i.imgur.com/awCuO76.jpg" height="160"/>
<img src="https://i.imgur.com/ULM2cmb.jpg" height="160"/>

To demonstratre the capabilities of our two libraries a mini-game was developed. 
*DEFUSE THE BOMB* is a mini-game that uses the Nokia 5110 LCD Display and a set of three wires to simulate a bomb ready to explode. The game starts with a countdown clock. The user needs to disconnect the correct wire in order to stop the bomb from exploding, if the countdown reaches zero or two wrong wires are disconnected the bomb explodes and the game is over.
