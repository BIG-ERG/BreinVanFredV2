
#include "flyingfischIR.h"
#include <avr/io.h>
#include<util/delay.h>


int tel=0;

void IR_init()
{
    ddr_irout&=~(1<<pinnummer_ir);
    ddr_led|=(1<<led1);
    port_led|=(1<<led1);
}


void IR_RUN()// check of pin hoog of laag is
{

    if ((pin_ir&(1<<pinnummer_ir))==0)
    {
        _delay_ms(20); // debounce
        if ((pin_ir&(1<<pinnummer_ir))==0)
        {

            port_led|=(1<<led1);//led uit
        }
    }
    else
    {
        _delay_ms(20); // debounce
        if ((pin_ir&(1<<pinnummer_ir))!=0)
        {

            port_led&=~(1<<led1);//led aan

        }
    }
}

