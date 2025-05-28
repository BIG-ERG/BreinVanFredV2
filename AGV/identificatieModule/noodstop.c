#include "noodstop.h"

#include <avr/interrupt.h>
#include <avr/io.h>

#define NOODKNOP PD0
#define DDR_NOOD DDRD
#define PORT_NOOD PORTD
#define PIN_NOOD PIND
#define start PA6 // pin 28
#define DDR_knop DDRA
#define PIN_knop PINA
#define PORT_knop PORTA


void initNoodstop(void){
    DDR_NOOD &= ~(1<<NOODKNOP);
    PORT_NOOD |= (1<<NOODKNOP);

    EIMSK |= (1<<INT0);       //ENABLE HARDWARE INTERRUPT ON PD0
    EICRA |= (0<<ISC01) | (1<<ISC00);   //Any edge of INTn generates asynchronously an interrupt request
    sei();
}


//TO BE DETERMINED IF NECESSARY FOR THIS MODULE
ISR(INT0_vect){

    /*
    while(1){
        while((PIN_NOOD & (1<<NOODKNOP))){//while noodknop ingedrukt en start niet ingedrukt is (twee handeling voor noodstop)
            stop();
        }
        if(!(PIN_knop&(1<<start))){
            //uitvoer();
            break;
        }
    }*/
}
