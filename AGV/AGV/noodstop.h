#ifndef NOODSTOP_H_INCLUDED
#define NOODSTOP_H_INCLUDED

#include "main.h"

#define NOODKNOP PD0
#define DDR_NOOD DDRD
#define PORT_NOOD PORTD
#define PIN_NOOD PIND
#define start PA6 // pin 28
#define DDR_knop DDRA
#define PIN_knop PINA
#define PORT_knop PORTA

void initNoodstop(void);
void SAFETYFIRST(void);

#endif // NOODSTOP_H_INCLUDED
