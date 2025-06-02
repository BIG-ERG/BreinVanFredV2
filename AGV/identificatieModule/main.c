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

    sendCommand(0x01,0xFF, 0x00, 0x00); //vooruit
    _delay_ms(1000);
    sendCommand(0x02,0x00, 0x00, 0x00); //achteruit


    return 1;
}
