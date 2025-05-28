#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED


#include "UART.h"
#include "main.h"

#include <avr/io.h>
#include <avr/interrupt.h>

//INIT
void initUsart(void);

//TRANSMIT
void sendByte(int byte);
void sendCommand(int command, int parameter, int snelheid, int acceleratie);

//RECEIVE
void flushUsart2Buffer(void);
int receiveByte(void);
extern unsigned int serialOntvangen[4];
void receiveCommand(void){


#endif // UART_H_INCLUDED
