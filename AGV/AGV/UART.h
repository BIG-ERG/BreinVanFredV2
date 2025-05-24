#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED


void initUsartReceive(void);
void flushUsart2Buffer(void);

int receiveByte();

extern unsigned int serialOntvangen[4];
void receiveCommand();


#endif // UART_H_INCLUDED
