
#include "duw_module.h"
#include <avr/io.h>
#include "UART.h"
#include <util/delay.h>
#include "noodstop.h"
#include "breekmechanisme.h"
void initstart()
{
    DDR_start&=~(1<<startknop);
    PORT_start|=(1<<startknop);
}
void start()
{

    if ((PIN_start&(1<<startknop))==0)
    {
        _delay_ms(20); // debounce
        if ((PIN_start&(1<<startknop))!=0)
            {
                sendByte(0xEF);// rij pad
                stopRequest=0;
            }
    }

}



