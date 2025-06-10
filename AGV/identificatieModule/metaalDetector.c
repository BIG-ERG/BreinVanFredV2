#include "metaalDetector.h"
#include "main.h"

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
#include <stdlib.h>

#include <avr/io.h>
#include <util/delay.h>

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



#define pinCapRechts PF0
#define DDRCapRechts DDRF
#define PORTCapRechts PORTF

#define pinPulseRechts PF1
#define DDRPulseRechts DDRF
#define PORTPulseRechts PORTF

//instellingen voor metingen
#define pulseWidth 85
#define thresholdRechts 999   // Drempelwaarde om metaal te detecteren (zelf testen!)364 voor touw spoel met 100 micro seconde
#define nMeas 40

///metaal detector Rechts
void initMetaalDetectorRechts(void) {
    //configure pins als output
    DDRPulseRechts |= (1<<pinPulseRechts);
}

void initAdcRechts(void){
    ADMUX = (0<<REFS1) | (1<<REFS0) | (0<<MUX3) | (0<<MUX2) | (0<<MUX1) | (0<<MUX0);
    ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<ADPS0);
    ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // ADC enable, prescaler 128
}

int detectMetaalRechts(void) {
    initSerialCom(MYUBRR);
    initMetaalDetectorRechts();
    initAdcRechts();
    long unsigned int sum = 0;

    //40 keer meten (meer = stabieler)
    for (int i=0; i< nMeas; i++) {
        // Condensator ontladen
        DDRCapRechts |= (1<<pinCapRechts); //output
        PORTCapRechts &= ~(1<<pinCapRechts); //pin low
        _delay_us(500);
        DDRCapRechts &= ~(1<<pinCapRechts); //input

        // Pulsen geven
        for (int j = 0; j < 8; j++) {//aantal pulsen per meting
            PORTPulseRechts |= (1<<pinPulseRechts); //pin hoog
            _delay_us(pulseWidth);
            PORTPulseRechts &= ~(1<<pinPulseRechts); //pin low
            _delay_us(pulseWidth);
        }

    // Meet de spanning
    ADCSRA |= (1<<ADSC);    //start adc
    while (ADCSRA & (1<<ADSC)); // wait until done
    int val = ADC;  // Leest tussen 0 en 1023
    sum += val;
    }

    // Gemiddelde berekenen
    int avg = sum / nMeas;//rekenen sturen



                    //voor serial debugging
                    char buffer[10];  // enough space for an int

                    itoa(avg, buffer, 10);  // convert int to decimal string

                    Serialprint("Average: ");
                    Serialprint(buffer);
                    Serialprint("\r\n");     // newline

    // Metaaldetectie
    if (avg > thresholdRechts) {//rekenen sturen
        Serialprint("geen metaal Links\r\n");
        return 0;

    }
    else {
        Serialprint("metaal Links\r\n");
        return 1;
  }
}

///metaal detector links

#define pinCapLinks PF4
#define DDRCapLinks DDRF
#define PORTCapLinks PORTF

#define pinPulseLinks PF5
#define DDRPulseLinks DDRF
#define PORTPulseLinks PORTF

#define thresholdLinks 999

void initMetaalDetectorLinks(void) {
    //configure pins als output
    DDRPulseLinks |= (1<<pinPulseLinks);
}

void initAdcLinks(void){
    ADMUX = (0<<REFS1) | (1<<REFS0) | (0<<MUX3) | (1<<MUX2) | (0<<MUX1) | (0<<MUX0);
    ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<ADPS0);
    ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // ADC enable, prescaler 128
}

int detectMetaalLinks(void) {
    initSerialCom(MYUBRR);
    initMetaalDetectorLinks();
    initAdcLinks();
    long unsigned int sum = 0;

    //40 keer meten (meer = stabieler)
    for (int i=0; i< nMeas; i++) {
        // Condensator ontladen
        DDRCapLinks |= (1<<pinCapLinks); //output
        PORTCapLinks &= ~(1<<pinCapLinks); //pin low
        _delay_us(500);
        DDRCapLinks &= ~(1<<pinCapLinks); //input

        // Pulsen geven
        for (int j = 0; j < 8; j++) {//aantal pulsen per meting
            PORTPulseLinks |= (1<<pinPulseLinks); //pin hoog
            _delay_us(pulseWidth);
            PORTPulseLinks &= ~(1<<pinPulseLinks); //pin low
            _delay_us(pulseWidth);
        }

    // Meet de spanning
    ADCSRA |= (1<<ADSC);    //start adc
    while (ADCSRA & (1<<ADSC)); // wait until done
    int val = ADC;  // Leest tussen 0 en 1023
    sum += val;
    }

    // Gemiddelde berekenen
    int avg = sum / nMeas;//rekenen sturen

                    //voor serial debugging
                    char buffer[10];  // enough space for an int

                    itoa(avg, buffer, 10);  // convert int to decimal string

                    Serialprint("Average: ");
                    Serialprint(buffer);
                    Serialprint("\r\n");     // newline

    // Metaaldetectie
    if (avg > thresholdLinks) {//rekenen sturen
        Serialprint("geen metaal RECHTS\r\n");
        return 0;
    }
    else {
        Serialprint("metaal RECHTS\r\n");
        return 1;
  }
}
