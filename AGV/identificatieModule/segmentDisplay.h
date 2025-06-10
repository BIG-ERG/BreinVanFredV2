#ifndef SEGMENTDISPLAY_H_INCLUDED
#define SEGMENTDISPLAY_H_INCLUDED

/// --- Defines --- ///
// -- Display --- //
#define DDR_DIO     DDRL
#define PIN_DIO     PL7
#define PORT_DIO    PORTL
#define REG_DIO     PINL

#define DDR_CLK     DDRL
#define PIN_CLK     PL5
#define PORT_CLK    PORTL
#define NORMAL_BRIGHTNESS 7
/// --- Functions --- ///
void display_start(void);
void display_stop(void);
void display_sendbyte(unsigned char data);
void display_brightness(unsigned char brightness);
void display_number(int number);
void display_letter(unsigned int letter, unsigned char position);
void display_init(void);
void display_txt_stop(void);

#endif // SEGMENTDISPLAY_H_INCLUDED
