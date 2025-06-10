/*
 */
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "main.h"

int main(void){
    sei();
    initNoodstop();
    initUsart();
    flushUsart2Buffer();
    initDonkInterrupt();
    display_init();
    initStartKnop();


    while(1){
        display_number(0000);
        if(!(PINA&(1<<PA6))){          //START CONDITION (start knop is pressed
            _delay_ms(10);
            volgendeOpdracht();
        }

    }

    return 1;
}
