#define F_CPU 16000000UL
#include <stdlib.h>

#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
#include "Debugging.h"

///serial com for debugging
void initSerialCom(unsigned int ubrr) {
    // Set baud rate
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    // Enable transmitter
    UCSR0B = (1 << TXEN0);

    // Set frame format: 8data, 1stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void SerialComTransmit(unsigned char data) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));
    // Put data into buffer, sends the data
    UDR0 = data;
}

void Serialprint(const char *s) {
    while (*s) {
        SerialComTransmit(*s++);
    }
}

///voor GETALLEN
/*
                    char buffer[10];  // enough space for an int

                    itoa(avg, buffer, 10);  // convert int to decimal string

                    Serialprint("Average: ");
                    Serialprint(buffer);
                    Serialprint("\r\n");     // newline
*/


///voor zinnen

        /*
        Serialprint("metaal Links\r\n");
        */
