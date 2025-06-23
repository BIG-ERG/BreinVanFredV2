/*
#include "noodstop.h"
#include "noodstop.h"
#include "UART.h"

#include <avr/interrupt.h>
#include <avr/io.h>




void initNoodstop(void){
    DDR_NOOD &= ~(1<<NOODKNOP);
    PORT_NOOD |= (1<<NOODKNOP);

    EIMSK |= (1<<INT0);       //ENABLE HARDWARE INTERRUPT ON PD0
    EICRA |= (0<<ISC01) | (1<<ISC00);   //Any edge of INTn generates asynchronously an interrupt request
    sei();

    DDRlAMP |= (1<<NOODLAMP);
    PORTLAMP &= ~(1<<NOODLAMP);
}

ISR(INT0_vect){
    while(1){
       while(!(PIN_NOOD & (1<<NOODKNOP))){//while noodknop ingedrukt en start niet ingedrukt is (twee handeling voor noodstop)
            PORTLAMP |= (1<<NOODLAMP);
        }
        if(!(PIN_start&(1<<startknop))){
            //uitvoer();
            PORTLAMP &= ~(1<<NOODLAMP);
            sendByte(0xFF);
            break;
        }
    }
}


//cant be bothered to create an extra file just for this function
void initStartKnop(void){
    DDR_start &= ~(1<<startknop);
    PORT_start|= (1<<startknop);
}
*/
