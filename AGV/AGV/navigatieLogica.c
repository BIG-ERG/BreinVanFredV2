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
    //while agv binnen het pad is
    while((distance_right<30)||(distance_left<30)){
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
    //stop driving
    stop();
}

void linksom(void){
    enableStepCnt();
    clearStepCnt();
    while(stepCounterLeft<4100){      //agv rijdt ietsjes verder buiten het pad
        vooruit();
    }
    clearStepCnt();
    toggleStepperDirectionRight();
    while(stepCounterLeft<2200){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionRight();
    clearStepCnt();
    while(stepCounterLeft<(5500)){    //agv rijdt naar volgende pad
        vooruit();
    }
    toggleStepperDirectionRight();      //agv draati 90 graden
    clearStepCnt();
    while(stepCounterLeft<(2200)){
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
}

void rechtsom(void){
    enableStepCnt();
    clearStepCnt();
    while(stepCounterLeft<4100){      //agv rijdt ietsjes verder buiten het pad
        vooruit();
    }
    clearStepCnt();
    toggleStepperDirectionLeft();
    while(stepCounterLeft<2200){   //agv draait 90 graden
        vooruit();
    }
    toggleStepperDirectionLeft();
    clearStepCnt();
    while(stepCounterLeft<(5500)){    //agv rijdt naar volgende pad
        vooruit();
    }
    toggleStepperDirectionLeft();      //agv draati 90 graden
    clearStepCnt();
    while(stepCounterLeft<(2200)){
        vooruit();
    }
    toggleStepperDirectionLeft();
    disableStepCnt();
    vooruit();
    while(distance_left>15){           //agv is in het volgende pad
        vooruit();
    }
    stop();
}
