#include "donk.h"

#include <avr/io.h>

#define DDR_IR  DDRD
#define PORT_IR PORTD
#define PIN_IR  PIND
#define IR      PD1 //pin 30

void initDonkInterrupt(void){
    DDR_IR &= ~(1<<IR);
    PORT_IR |= (1<<IR);

    EIMSK |= (1<<INT1);       //ENABLE HARDWARE INTERRUPT ON PD1
    EICRA |= (0<<ISC11) | (1<<ISC10);    //FALLING edge of INTn generates asynchronously an interrupt request
}

unsigned int aantalGedectecteerd = 0;

ISR(INT0_vect){
    aantalGedectecteerd++;
}
