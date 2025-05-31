/*
 */
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "main.h"

int main(void){
    sei();
    initUsart();
    flushUsart2Buffer();
    initDonkInterrupt();
    display_init();


    int bitch = 0;
    while(1){
        display_number(bitch);
        bitch++;
        _delay_ms(500);
    }


    return 1;
}
