#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

void initUsartSend(void);
void sendByte(int byte);
void sendCommand(int command, int parameter, int snelheid, int acceleratie);

#endif // UART_H_INCLUDED
