#include "interface.h"
#include "ultrasoon.h"
#include "UART.h"

#include <avr/io.h>
#include <util/delay.h>

/*
commmandos die ontvangen kunnen worden
0x01 = vooruit or
0x02 = vooruit and
0xA1 = achteruit
0xB1 = bocht rechts
0xB2 = bocht links
0xFF = stop
0xD1 = draai 90 graden naar rechts --->> moet nog geprogrameerd worden
0xD2 = draai 90 graden naar links --->> moet nog geprogrameerd worden
0xD3 = draai 180 graden --->> moet nog geprogrameerd worden
0xD4 = draai 180 graden 2
*/



void interpreter(){
    if(serialData==0x01){    //commmando bewegen
        rechtdoor();
    }
    if(serialData==0x02){    //commmando bewegen
        rechtdoorAnd();
    }
    if(serialData==0xA1){
        achteruit();
    }
    if(serialData==0xB1){
        rechtsom();
    }
    if(serialData==0xB2){
        linksom();
    }
    if(serialData==0xD1){
        kwartslagDraaienRechts();
    }
    if(serialData==0xD2){
        kwartslagDraaienLinks();
    }
    if(serialData==0xD3){
        Pirouette();
    }
    if(serialData==0xD4){
        Pirouette2();
    }
    if(serialData==0xFF){
        stop();
    }
    if(serialData==0xEF){
        serialData=0x00;
        ongecontroleerdVooruit();
        Pirouette();
        ongecontroleerdAchteruit();
        ongecontroleerdVooruit2();
        kleinBeetjeVooruit();
        kwartslagDraaienRechts();
        minderBeetjeVooruit();
        Pirouette2();
        kleinBeetjeAchteruit();
        kwartslagDraaienRechts();
        kleinBeetjeAchteruit();
        kleinBeetjeAchteruit();
        kleinBeetjeAchteruit();
        kleinBeetjeAchteruit();
        ongecontroleerdAchteruit();
        grootBeetjeVooruit();
        stop();
    }
}
