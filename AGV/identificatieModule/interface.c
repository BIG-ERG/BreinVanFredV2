#include "interface.h"
#include "main.h"
#include "UART.h"

#include <avr/io.h>
#include <util/delay.h>

void volgendeOpdracht(){
    static unsigned int opdracht = 0;
    if(opdracht==0){
        opdracht ++;            //om te onthouden welke opdracht al geweest is
        while(stopRequest!=1){
            sendByte(0x01);  //navigeer, detecteer, identificeer
            if(irDetect()==0){  //als de agv iets detecteerd stop 1 seconde
                    sendByte(0xFF);  //stop agv
                    _delay_ms(1000);
            }
            display_number(aantalGedectecteerd);
        }
    }
    if(opdracht==1){
        opdracht++;     //bocht rechtsom
        sendByte(0xB1);
    }
    if(opdracht==2){
        sendByte(0xFF);
    }
}
