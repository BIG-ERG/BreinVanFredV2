#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

/// --- Defines --- ///
// -- Display --- //
#define DDR_DIO     DDRL
#define PIN_DIO     PL7
#define PORT_DIO    PORTL
#define REG_DIO     PINL

#define DDR_CLK     DDRL
#define PIN_CLK     PL6
#define PORT_CLK    PORTL
#define NORMAL_BRIGHTNESS 7
/// --- Functions --- ///
void display_start(void);
void display_stop(void);
void display_sendbyte(unsigned char data);
void display_brightness(unsigned char brightness);
void display_digits(unsigned char digits[4]);
void display_number(int number);
void display_letter(unsigned int letter, unsigned char position);
void display_init(void);

void display_mode(char mode);
void display_direction(char dir);
void display_cfg(void);
void display_fol(void);
void display_cnt(void);
void display_turn(void);
void display_dist(void);
void display_pac(void);
void display_left(void);
void display_rght(void);
void display_go(void);
void display_end(void);
void display_srch(void);
void display_txt_stop(void);

#endif // DISPLAY_H_INCLUDED
