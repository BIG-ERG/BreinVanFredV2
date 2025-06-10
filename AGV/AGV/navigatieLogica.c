#include <avr/io.h>
#include <math.h>
#include <util/delay.h>

#include "navigatieLogica.h"

int padbreedte;

void metingPadbreedte(void){
    //neemt afmeting van de breedte van het pad in cm
    padbreedte = distance_left + distance_right + 13;
}

void vooruit(void){
    //agv rijdt ongecontroleerd vooruit
    speedStepperLeft(1150);
    speedStepperRight(1150);
}

void stop(void){
    //agv stopt met rijden
    speedStepperLeft(0);
    speedStepperRight(0);
}

int ramping(int originalValue , int value){
    if(originalValue > value){
            originalValue --;
    }
    if(originalValue < value){
            originalValue ++;
    }
    return originalValue;
}

void rechtdoor(void){
    stepperForward();
    while((stopRequest==0)){
        if((distance_left>25)||(distance_right>25)){  //als agv buiten pad is
            sendByte(0x01); //stuur klaar met opdracht
            stopRequest=1;
        }
        else{
            if (distance_right==distance_left) {
            speedStepperLeft(1150);
            speedStepperRight(1150);
            }
            if (distance_right > distance_left){
                speedStepperLeft(ramping(1650, 1150));
                speedStepperRight(ramping(1150, 1650));
            }
            if(distance_left > distance_right){
                speedStepperRight(ramping(1650, 1150));
                speedStepperLeft(ramping(1150, 1650));
            }
        }
    }
    stop();
    stopRequest=0;
}

void achteruit(void){
    stepperBackward();
    while(((distance_right<30)||(distance_left<30))||(stopRequest==0)){ //while agv binnen pad
        if (distance_right==distance_left) {
            speedStepperLeft(1150);
            speedStepperRight(1150);
        }
        else{
            if (distance_right < distance_left){
                speedStepperLeft(ramping(1650, 1150));
                speedStepperRight(ramping(1150, 1650));
            }
            if(distance_left < distance_right){
                speedStepperRight(ramping(1650, 1150));
                speedStepperLeft(ramping(1150, 1650));
            }
        }
    }
    stop();
    stopRequest=0;
    sendByte(0x01);   //send klaar met opdracht
}

void linksom(void){
    toggleKnipperRechts();
    enableStepCnt();
    clearStepCnt();
    while(stepCounterLeft<6100){      //agv rijdt ietsjes verder buiten het pad
        vooruit();
    }
    clearStepCnt();
    toggleStepperDirectionRight();
    while(stepCounterLeft<2350){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionRight();
    clearStepCnt();
    while(stepCounterLeft<(5500)){    //agv rijdt naar volgende pad
        vooruit();
    }
    toggleStepperDirectionRight();      //agv draati 90 graden
    clearStepCnt();
    while(stepCounterLeft<(2350)){
        vooruit();
    }
    toggleStepperDirectionRight();
    clearStepCnt();
    vooruit();
    while(distance_left>15){           //agv is in het volgende pad
        vooruit();
    }
    stop();
    disableStepCnt();
    sendByte(0x01);   //send klaar met opdracht
    toggleKnipperRechts();
}

void rechtsom(void){
    toggleKnipperLinks();
    enableStepCnt();
    clearStepCnt();
    while(stepCounterLeft<6100){      //agv rijdt ietsjes verder buiten het pad
        vooruit();
    }
    clearStepCnt();
    toggleStepperDirectionLeft();
    while(stepCounterLeft<2250){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionLeft();
    clearStepCnt();
    while(stepCounterLeft<(5600)){    //agv rijdt naar volgende pad
        vooruit();
    }
    toggleStepperDirectionLeft();      //agv draati 90 graden
    clearStepCnt();
    while(stepCounterLeft<(2250)){
        vooruit();
    }
    toggleStepperDirectionLeft();
    disableStepCnt();
    vooruit();
    if(distance_left<15){           //agv is in het volgende pad
        stop();
    }
    stop();
    sendByte(0x01);      //send klaar met opdracht
    toggleKnipperLinks();
}

void kwartslagDraaienRechts(void){
    toggleKnipperRechts();
    enableStepCnt();
    clearStepCnt();
    toggleStepperDirectionLeft();
    while(stepCounterLeft<2350){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionLeft();
    disableStepCnt();
    toggleKnipperRechts();

}

void kwartslagDraaienLinks(void){
    toggleKnipperLinks();
    enableStepCnt();
    clearStepCnt();
    toggleStepperDirectionRight();
    while(stepCounterLeft<2350){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionRight();
    disableStepCnt();
    toggleKnipperLinks();
}

void Pirouette(void){
        toggleKnipperLinks();
    enableStepCnt();
    clearStepCnt();
    toggleStepperDirectionRight();
    while(stepCounterLeft<4700){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionRight();
    disableStepCnt();
    toggleKnipperLinks();
}
