#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

//INIT
void initUsart(void);

//TRANSMIT
void sendByte(int byte);
void sendCommand(int command, int parameter, int snelheid, int acceleratie);

//RECEIVE
void flushUsart2Buffer(void);
extern unsigned int serialData;
extern volatile int stopRequest;

extern unsigned int serialData;

#endif // UART_H_INCLUDED
