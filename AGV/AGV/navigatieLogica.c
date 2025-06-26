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
    speedStepperLeft(750);     //1150
    speedStepperRight(750);

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

void rechtdoorAnd(void){
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
    stopRequest=0;
    while(distance_left>20){
        vooruit();
    }
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
    while((stopRequest==0)){ //while agv binnen pad
        if((distance_right>35)&&(distance_left>35)){
            sendByte(0x01);
            stopRequest=1;
        }
        else{
        if (distance_right==distance_left) {
            speedStepperLeft(1150);
            speedStepperRight(1150);
        }
        if (distance_right < distance_left){
            speedStepperLeft(ramping(1350, 1150));
            speedStepperRight(ramping(1150, 1350));
            }
        if(distance_left < distance_right){
            speedStepperRight(ramping(1350, 1150));
            speedStepperLeft(ramping(1150, 1350));
            }
        }
    }
    stepperForward();
    while((distance_left>15)&&(distance_right>15)){
        vooruit();  //rij naar volgende pad
    }
    stop();
    stopRequest=0;
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
    while(stepCounterLeft<(5300)){    //agv rijdt naar volgende pad
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
    toggleKnipperLinks();
    enableStepCnt();
    clearStepCnt();
    toggleStepperDirectionLeft();
    while(stepCounterLeft<2300){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionLeft();
    disableStepCnt();
    toggleKnipperLinks();
    sendByte(0x01);
}

void kwartslagDraaienLinks(void){
    toggleKnipperRechts();
    enableStepCnt();
    clearStepCnt();
    toggleStepperDirectionRight();
    while(stepCounterLeft<2300){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionRight();
    disableStepCnt();
    toggleKnipperRechts();
    sendByte(0x01);
}

void Pirouette(void){
    toggleKnipperRechts();
    enableStepCnt();
    clearStepCnt();
    stepperForward();
    while(stepCounterLeft<7500){    //agv rijdt ietsjes vooruit
        vooruit();
    }
    clearStepCnt();
    toggleStepperDirectionRight();
    while(stepCounterLeft<4600){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionRight();
    disableStepCnt();
    toggleKnipperRechts();
    stepperBackward();
    while((distance_right>15)){
        vooruit();  //rij naar volgende pad
    }
    stop();
    stopRequest=0;
    sendByte(0x01);
}

void Pirouette2(void){
    toggleKnipperLinks();
    enableStepCnt();
    clearStepCnt();
    toggleStepperDirectionLeft();
    while(stepCounterLeft<4600){   //agv draait 180 graden
        vooruit();
    }
    toggleStepperDirectionLeft();
    disableStepCnt();
    toggleKnipperLinks();
    stop();
    stopRequest=0;
    sendByte(0x01);
}

void calibrate(void){
    stepperBackward();
    enableStepCnt();
    while(stepCounterLeft<1000){
        vooruit();
    }
    stop();
    disableStepCnt();
    stepperForward();
    while(distance_left != distance_right){     //first calibration
        if(distance_left>distance_right){
            speedStepperLeft(3000);
            speedStepperRight(0);
        }
        if(distance_left<distance_right){
            speedStepperRight(3000);
            speedStepperLeft(0);
        }
    }
    stop();
}

void ongecontroleerdAchteruit(void){
    stepperBackward();
    while((distance_left<25)&&(distance_right<25)){
        vooruit();
    }
    stop();
    stepperForward();
    clearStepCnt();
    enableStepCnt();
    while(stepCounterLeft<1000){
        vooruit();
    }
    disableStepCnt();
    stop();
}

void ongecontroleerdVooruit(void){
    stepperForward();
    while((distance_left<20)){
        vooruit();
    }
    stop();
}

void ongecontroleerdVooruit2(void){
    stepperForward();
    while((distance_right<20)){
        vooruit();
    }
    stop();
}

void kleinBeetjeVooruit(void){
    stepperForward();
    enableStepCnt();
    clearStepCnt();
    while(stepCounterLeft<7550){
        vooruit();
    }
    stop();
    disableStepCnt();
}

void minderBeetjeVooruit(void){
    stepperForward();
    enableStepCnt();
    clearStepCnt();
    while(stepCounterLeft<3050){
        vooruit();
    }
    stop();
    disableStepCnt();
}

void kleinBeetjeAchteruit(void){
    stepperBackward();
    enableStepCnt();
    clearStepCnt();
    while(stepCounterLeft<3050){
        vooruit();
    }
    stop();
    disableStepCnt();
    stepperForward();
}

void grootBeetjeVooruit(void){
    stepperForward();
    enableStepCnt();
    while(stepCounterLeft<29500){
        vooruit();
    }
    disableStepCnt();
    stop();
}
