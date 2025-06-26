#include "noodstop.h"
#include "navigatieLogica.h"

#include <avr/interrupt.h>
#include <avr/io.h>

void initNoodstop(void){
    DDR_NOOD &= ~(1<<NOODKNOP);
    PORT_NOOD |= (1<<NOODKNOP);

    EIMSK |= (1<<INT0);       //ENABLE HARDWARE INTERRUPT ON PD0
    EICRA |= (0<<ISC01) | (1<<ISC00);   //Any edge of INTn generates asynchronously an interrupt request
    sei();
}

ISR(INT0_vect){
    while(1){
        while((PIN_NOOD & (1<<NOODKNOP))){//while noodknop ingedrukt en start niet ingedrukt is (twee handeling voor noodstop)
            stop();
            toggleKnipperNood();
        }
        toggleKnipperNood();
    }
}
