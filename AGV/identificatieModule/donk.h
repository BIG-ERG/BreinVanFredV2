#ifndef DONK_H_INCLUDED
#define DONK_H_INCLUDED

#define DDR_IR  DDRD
#define PORT_IR PORTD
#define PIN_IR  PIND
#define IR      PD1 //pin 30

void initDonkInterrupt(void);
extern unsigned int aantalGedectecteerd;

#endif // DONK_H_INCLUDED
