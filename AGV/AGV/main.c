/*
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "main.h"

int main(void)
{
    //initNoodstop();
    initStepper();
    init_ultrasoon();
    initUsart();
    flushUsart2Buffer();
    sei();


    while(1);    //everything is automated using interrupts so no need for a main loop


    return 0;
}
