#include "UART.h"

#include <avr/io.h>

#define BAUD 9600   // BAUD rate
const uint16_t BRC = 103; // BAUD rate 9600 omgerekent

void initUsartSend(void) {   // initializeren USART 1
  UBRR1H = ((uint8_t)(BRC >> 8));   // USART 1 BAUD RATE HIGH instellen
  UBRR1L = ((uint8_t)(BRC & 0xFF)); // USART 1 BAUD RATE LOW instellen
  UCSR1B = (1 << TXEN1);    // TX PIN 1 hoog zetten GEEN INTERRUPT
  UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);   // 8 bit (hex) sturen
}

void sendByte(int byte) { // versturen van 1 HEX getal
  loop_until_bit_is_set(UCSR1A, UDRE1); // programma blijven loopen todat de vorige command helemaal is weg geschreven
  UDR1 = byte; // hex in verstuur box zetten
}

void sendCommand(int command, int parameter, int snelheid, int acceleratie){
    int serialschrijven[4] = {command, parameter, snelheid, acceleratie}; // array serieel schrijven 0,1,2,3 (4 hex totaal)
    for(int i = 0; i<4; i++){
        sendByte(serialschrijven[i]);
    }
}
