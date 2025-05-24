#include "UART.h"

#include <avr/io.h>
#include <util/delay.h>

const uint16_t BRCR = 103; // BAUD rate 9600 omgerekent

void initUsartReceive(void) {   // initializeren USART 2
  UBRR2H = ((uint8_t)(BRCR >> 8));   // USART 1 BAUD RATE HIGH instellen
  UBRR2L = ((uint8_t)(BRCR & 0xFF)); // USART 1 BAUD RATE LOW instellen
  UCSR2B = (1 << RXEN2);    // ENABLE RX
  UCSR2C = (1 << UCSZ21) | (1 << UCSZ20);   // 8 bit (hex) sturen
}

void flushUsart2Buffer(void) {
    unsigned char dummy;
    while (UCSR2A & (1 << RXC2)) {
        dummy = UDR2; // Read and discard
    }
    dummy--; //to avoid compiler warning "variable set but not used"
}

int receiveByte() { //ontvangen van 1 hex getal
    while ( !(UCSR2A & (1<<RXC2))); //Wait for data to be received
    return UDR2;
}

unsigned int serialOntvangen[4];

void receiveCommand(){
    for(int i = 0; i<4; i++){
        serialOntvangen[i] = receiveByte();
    }
}
