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

//  IR_init();
//    initUsart();
    initinterface();
    while(1)
    {
  //  IR_RUN();
    interfacerun();
    }

    return 0;
}
