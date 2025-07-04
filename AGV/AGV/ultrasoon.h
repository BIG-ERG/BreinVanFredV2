#ifndef ULTRASOON_H_INCLUDED
#define ULTRASOON_H_INCLUDED

#include "main.h"

#define Pin_Trig_Left PL4
#define Pin_Trig_Right PL5
#define Pin_echo    PL1

void init_timer5(void);
void init_pins_ultrasoon(void);
void init_ultrasoon(void);

extern volatile int distance_right;
extern volatile int distance_left;

#endif // ULTRASOON_H_INCLUDED
