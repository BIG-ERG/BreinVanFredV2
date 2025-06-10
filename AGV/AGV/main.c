/*
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "main.h"
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

int main(void)
{
    initNoodstop();
    initStepper();
    init_ultrasoon();
    initUsart();
    flushUsart2Buffer();
    initKnipperLicht();
    sei();

    while(1){
        interpreter();
    }

    return 0;
}
