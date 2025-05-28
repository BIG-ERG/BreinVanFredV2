/*
 */
#include <avr/interrupt.h>
#include <avr/io.h>
#include "main.h"

int main(void){
    sei();
    initUsart();
    flushUsart2Buffer();
    initDonkInterrupt();

    _delay_ms(2000); //genoeg tijd geven aan AVR om UART op te stellen

    volgendeOpdracht();

    while(1)
        _delay_ms(10);

    return 1;
}
}
