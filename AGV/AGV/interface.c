#include "interface.h"
#include "ultrasoon.h"
#include "UART.h"

#include <avr/io.h>

//serialOntvangen[4];
//void receiveCommand();
/*
Hex 1: commando
Hex 2: parameter
Hex 3: Snelheid (indien nodig kan ook genegeerd worden door de AGV, schrijf dan 0xFF).
Hex 4: Acceleratie (indien nodig kan ook genegeerd worden door AGV, schrijf dan 0xFF).

Signaal omlaag (vanuit module naar AGV)
COMMANDO:
0x01: Rechtuit bewegen
Parameter:
1.	0x00 = langzaam achteruit
2.	0x7E = snel achteruit
3.	0X7F = stop (precies het midden)
4.	0x80 = langzaam vooruit
5.	0xFF = snel vooruit

0x02: Keer bocht R/L
Parameter:
1.	0x01 = Linksom
2.	0x02 = Rechtsom

0x03: Opdracht ga van duwblokje 1 naar duwblokje 2
Parameter:
1.	0x01 =naar links 1 vak opschuiven
2.	0x02 =naar rechts 1 vak opschuiven

Signaal omhoog (vanuit AGV naar Module)
0x01: Klaar met opdracht, einde pad of einde bocht geen parameters nodig.
*/

void interpreter(){
    receiveCommand();   //this function may have to be called more often within the while to be able to update if any new information comes in
    if(serialOntvangen[0]==0x01){    //commmando bewegen
        while((distance_right<30)||(distance_left<30)){ //while agv binnen pad
            if(serialOntvangen[1]>0x7F)
                rechtdoor();
            if(serialOntvangen[1]<0x7F)
                achteruit();
            if(serialOntvangen[1]==0x7F)
                stop();
        }
    }
    if(serialOntvangen[0]==0x02){
        if(serialOntvangen[1]==0x01)
            linksom();
        if(serialOntvangen[1]==0x02)
            rechtsom();
    }
}
}//<--that bracket has no reason to exist but god has decided to toy with me today, anywho this is to fix a compiler error
