#include "uartReceiver.h"

//vb code nick ootes

/*
#include <avr/io.h>

#define BAUD 9600   // BAUD rate
const uint16_t BRC = 103; // BAUD rate 9600 omgerekent

void send_byte(int c) { // versturen van 1 HEX getal
  loop_until_bit_is_set(UCSR1A, UDRE1); // programma blijven loopen todat de vorige command helemaal is weg geschreven
  UDR1 = c; // hex in verstuur box zetten
}

void init(void) {   // initializeren USART 1
  UBRR1H = ((uint8_t)(BRC >> 8));   // USART 1 BAUD RATE HIGH instellen
  UBRR1L = ((uint8_t)(BRC & 0xFF)); // USART 1 BAUD RATE LOW instellen
  UCSR1B = (1 << TXEN1);    // TX PIN 1 hoog zetten GEEN INTERRUPT
  UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);   // 8 bit (hex) sturen
}

int send(void) {
  init();   // initializeren USART 1
    char data_shift=0;  // ARRAY SHIFT 0 tot en met 3
    int serialschrijven[4]; // array serieel schrijven 0,1,2,3 (4 hex totaal)
  while (1)
    {
      while (data_shift!=4) {   // schrijf data als nog niet alle data is verstuurd
        send_byte(serialschrijven[data_shift]); // schrijven van data naar TX pin
        data_shift++;   // data shift +1 zodat hij het volgende hex stuurt
      }
      data_shift = 0;   // data shift resetten voor de volgende keer dat hij moet schrijven
    }
  return 0;
}
*/
