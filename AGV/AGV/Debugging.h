#ifndef DEBUGGING_H_INCLUDED
#define DEBUGGING_H_INCLUDED

///serial com for debugging
void initSerialCom(unsigned int ubrr);
void SerialComTransmit(unsigned char data);
void Serialprint(const char *s);
#endif // DEBUGGING_H_INCLUDED
