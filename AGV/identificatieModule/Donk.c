#include "donk.h"
#include "main.h"
#include "metaalDetector.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DDR_IR  DDRE
#define PORT_IR PORTE
#define PIN_IR  PINE
#define IR_R     PE4
#define IR_L     PE5

void initDonkInterrupt(void){
    DDR_IR &= ~(1<<IR_R);
    PORT_IR |= (1<<IR_R);

    DDR_IR &= ~(1<<IR_L);
    PORT_IR |= (1<<IR_L);
}

 int aantalGedectecteerd = -2;

int irDetect(void){
    static int buttonstate1 = 0;
        if((PIN_IR & (1<<IR_R))){
            if(buttonstate1 ==0){
                aantalGedectecteerd++;
                if(detectMetaalLinks()==1){
                    aantalGedectecteerd+=100;
                }
                buttonstate1 = 1;
                _delay_ms(10);
                return 1;
            }
        }
        else{
            if(buttonstate1 == 1){
            buttonstate1 = 0;
            _delay_ms(10);
            return 0;
            }
        }

        static int buttonstate2 = 0;
        if((PIN_IR & (1<<IR_L))){
            if(buttonstate2 ==0){
                aantalGedectecteerd++;
                if(detectMetaalRechts()==1){
                    aantalGedectecteerd+=100;
                }
                buttonstate2 = 1;
                _delay_ms(10);
                return 1;
            }
        }
        else{
            if(buttonstate2 == 1){
            buttonstate2 = 0;
            _delay_ms(10);
            return 0;
            }
        }
}
