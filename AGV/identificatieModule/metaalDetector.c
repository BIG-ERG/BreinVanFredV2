#include "metaalDetector.h"

#include <avr/io.h>
#include <util/delay.h>

#define pin_cap PF0
#define DDR_pin_cap DDRF
#define PORT_pin_cap PORTF

#define pin_pulse PF1
#define DDR_pin_pulse DDRF
#define PORT_pin_pulse PORTF

#define LED PF2
#define DDR_LED DDRF
#define PORT_LED PORTF

//instellingen voor metingen
#define pulseWidth 85
#define threshold 364   // Drempelwaarde om metaal te detecteren (zelf testen!)364 voor touw spoel met 100 micro seconde
#define nMeas 40

void initAdc(void){
    ADMUX = (0<<REFS1) | (1<<REFS0);
    ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<ADPS0);
    ADCSRA |= (1<<ADEN);
}

void initMetaalDetector(void) {
    //configure pins als output
    DDR_pin_pulse |= (1<<pin_pulse);
    DDR_LED |= (1<<LED);
    initAdc();
}

int detectMetaal(void) {
    ADCSRA |= (1<<ADSC);    //ADC start conversion [ALS DE ADC NIET WERKT KNAL DEZE LINE VOOR DAT JE HET STORED IN DE VARIABELE]
    long unsigned int sum = 0;

    //40 keer meten (meer = stabieler)
    for (int i=0; i< nMeas; i++) {
        // Condensator ontladen
        DDR_pin_cap |= (1<<DDR_pin_cap); //output
        PORT_pin_cap |= (1<<DDR_pin_cap); //pin low
        _delay_ms(20);
        DDR_pin_cap &= ~(1<<DDR_pin_cap); //input

        // Pulsen geven
        for (int j = 0; j < 8; j++) {//aantal pulsen per meting
            PORT_pin_pulse &= ~(1<<DDR_pin_cap); //pin hoog
            _delay_ms(pulseWidth);
            PORT_pin_pulse |= (1<<DDR_pin_cap); //pin hoog
            _delay_ms(pulseWidth);
        }

    // Meet de spanning
    int val = ADC;  // Leest tussen 0 en 1023
    sum += val;
    }

    // Gemiddelde berekenen
    int avg = sum / nMeas;//rekenen sturen
    //Serial.print("Gemiddelde waarde: ");
    //Serial.print(avg);

    // Metaaldetectie
    if (avg < threshold) {//rekenen sturen
        //Serial.println(" --> METAAL GEDETECTEERD!");
        PORT_LED &= ~(1<<LED); //led aan
    return 1;
    }
    else {
        //Serial.println(" --> Geen metaal.");
        PORT_LED |= (1<<LED); //led uit
    return 0;
  }
}
