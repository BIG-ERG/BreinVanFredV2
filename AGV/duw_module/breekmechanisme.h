
#ifndef BREEKMECHANISME_H_INCLUDED
#define BREEKMECHANISME_H_INCLUDED


#define led2 PC4 // pin 33
#define ddr_led2 DDRC
#define port_led2 PORTC
#define endswitch PC2 //pin 35
#define DDR_switch DDRC
#define PIN_switch PINC
#define PORT_switch PORTC
void initinterface();
void interfacerun();

#endif // BREEKMECHANISME_H_INCLUDED

