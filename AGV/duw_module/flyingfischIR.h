
#ifndef FLYINGFISCHIR_H_INCLUDED
#define FLYINGFISCHIR_H_INCLUDED

#define pinnummer_ir PC7 // pin 30
#define ddr_irout DDRC
#define pin_ir PINC
#define ddr_led DDRC
#define led1 PC5 // groen pin 32 PC5
#define port_led PORTC

extern int tel;
void IR_init();
void IR_RUN();

#endif // FLYINGFISCHIR_H_INCLUDED

