#include <avr/io.h>
#include "main.h"
#include "knipperLicht.h"

#define LVR PC1
#define LVL PC5
#define LAR PC3
#define LAL PC7
#define PORTLED PORTC
#define DDRLED  DDRC
void initKnipperLicht(void){
    DDRLED |= (1<<LVR);
    DDRLED |= (1<<LVL);
    DDRLED |= (1<<LAR);
    DDRLED |= (1<<LAL);
}

void toggleKnipperRechts(void){
    static int state = 0;
    if(state == 0){
        PORTLED |= (1<<LVR);
        PORTLED |= (1<<LAR);
        state = 1;
    }
    else{
        PORTLED &= ~(1<<LVR);
        PORTLED &= ~(1<<LAR);
        state = 0;
    }
}

void toggleKnipperLinks(void){
    static int state = 0;
    if(state == 0){
        PORTLED |= (1<<LVL);
        PORTLED |= (1<<LAL);
        state = 1;
    }
    else{
        PORTLED &= ~(1<<LVL);
        PORTLED &= ~(1<<LAL);
        state = 0;
    }
}

void toggleKnipperNood(void){
    static int state = 0;
    if(state == 0){
        PORTLED |= (1<<LVL);
        PORTLED |= (1<<LAL);
        PORTLED |= (1<<LVR);
        PORTLED |= (1<<LAR);
        state = 1;
    }
    else{
        PORTLED &= ~(1<<LVL);
        PORTLED &= ~(1<<LAL);
        PORTLED &= ~(1<<LVR);
        PORTLED &= ~(1<<LAR);
        state = 0;
    }
}

