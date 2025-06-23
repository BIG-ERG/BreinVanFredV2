
#include "breekmechanisme.h"
#include <avr/io.h>
#include <util/delay.h>
void initinterface()
{
    DDR_switch&=~(1<<endswitch);
    PORT_switch|=(1<<endswitch);
    ddr_led2|=(1<<led2);
}

void interfacerun()
{

    if ((PIN_switch&(1<<endswitch))==0)
    {
        _delay_ms(20);
        //port_led2&=~(1<<led2);

        if ((PIN_switch&(1<<endswitch))==0)
        {
            port_led2|=(1<<led2);
        }

    }
    else
    {
         _delay_ms(20);
        if ((PIN_switch&(1<<endswitch))!=0)
        {
            port_led2&=~(1<<led2);

        }
    }
}

