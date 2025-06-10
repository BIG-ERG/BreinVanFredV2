#ifndef METAALDETECTOR_H_INCLUDED
#define METAALDETECTOR_H_INCLUDED

///metaal detector Rechts
void initMetaalDetectorRechts(void);
void initAdcRechts(void);
int detectMetaalRechts(void);

///metaal detector links
void initMetaalDetectorLinks(void);
void initAdcLinks(void);
int detectMetaalLinks(void);

///serial communication (for debugging)
///uart
void initSerialCom(unsigned int ubrr);
void SerialComTransmit(unsigned char data);
void Serialprint(const char *s);

#endif // METAALDETECTOR_H_INCLUDED
