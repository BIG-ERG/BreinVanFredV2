#include "interface.h"

#include <avr/io.h>

void volgendeOpdracht(){
    unsigned int opdracht = 0;
    if(opdracht==0){
        opdracht ++;
        sendCommand();  //navigeer, detecteer, identificeer
    }
    if(opdracht==1){
        opdracht++;     //bocht ...om
        sendCommand();
    }
}
