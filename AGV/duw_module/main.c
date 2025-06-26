/*
 */

#include <avr/io.h>
#include "flyingfischIR.h"
#include "UART.h"
#include "duw_module.h"
#include "noodstop.h"
#include "breekmechanisme.h"
#include <util/delay.h>

int main(void)
{
    initstart();
    IR_init();
    initUsart();
    flushUsart2Buffer();
    initinterface();
    while(1)
    {
        start();
        IR_RUN();
        interfacerun();
    }

    return 0;
}
