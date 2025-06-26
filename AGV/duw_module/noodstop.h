
#ifndef NOODSTOP_H_INCLUDED
#define NOODSTOP_H_INCLUDED

#define NOODKNOP PD0
#define DDR_NOOD DDRD
#define PORT_NOOD PORTD
#define PIN_NOOD PIND
#define startknop PC3 // pin 34
#define DDR_start DDRC
#define PIN_start PINC
#define PORT_start PORTC
#define NOODLAMP PC6// pin 31
#define DDRlAMP DDRC
#define PORTLAMP PORTC



void initNoodstop(void);
void initStartKnop(void);

#endif // NOODSTOP_H_INCLUDED

