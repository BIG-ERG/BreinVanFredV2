/*
 */

#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

int main(void)
{
    initNoodstop();
    initStepper();
    init_ultrasoon();
    initUsart();
    flushUsart2Buffer();

    while(1);       //everything is automated using interrupts so no need for a main loop

    return 0;
}
