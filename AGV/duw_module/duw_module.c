/*
#include "duw_module.h"
#include <avr/io.h>
#include "UART.h"
#include "flyingfischIR.h"
#include<util/delay.h>
#include "noodstop.h"
void start()
{
    DDR_start&=~(1<<startknop);
    if ((PIN_start&(1<<startknop))==0)
    {
        _delay_ms(20); // debounce
        if ((PIN_start&(1<<startknop))==0)
        {

            sendByte(0x01); // vooruit

        }
    }
}
void omdraaien()
{

    while(stopRequest!=1)
    {
    }
        stopRequest=0;
        sendByte(0xD3);//180 gaden draaien

    while(stopRequest!=1)
    {
    }
        stopRequest =0;
        sendByte(0xA1); //achteruit



}

void duwen()
{
    while((pin_ir&(1<<pinnummer_ir))!=0)// zolang IR niks ziet
    {
     // blokje uit pad duwen
    }
        if (stopRequest!=0)// einde pad
            stopRequest=0;
        {
            sendByte(0x01); // vooruit

        }
    while(stopRequest!=1)// not rechterkand geen plank
    {
    }
            stopRequest=0;
            sendByte(0xB1);// bocht rechts

    while (stopRequest!=1)
    {
    }
            stopRequest=0;
            sendByte(0xD3); // 180 graden draaien

    while (stopRequest!=1)
    {
    }
            stopRequest=0;
            sendByte(0xA1); //achteruit

    while((pin_ir&(1<<pinnummer_ir))!=0)
    {
        // blokje uit pad duwen
    }
        if (stopRequest!=1)// einde pad
            stopRequest=0;
        {
            sendByte(0x02); // vooruit

        }
    while(stopRequest!=1)// geen planken aan liks en rechts
    {
    }
        stopRequest=0;
        sendByte(0xFF);// stop

}
*/
