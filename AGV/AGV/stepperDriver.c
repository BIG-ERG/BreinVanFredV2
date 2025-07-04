/*
step instelling: sixteen steps (MS1 hoog, MS2 hoog, MS3 hoog)
stepper right: digital pin 11
voorlopig geen enable/disable pin voor driver board
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "stepperDriver.h"

void initPinsStepper (void){
	// Config pins as output
	DDR_STEP_R |= (1<<STEPPER_RIGHT);
	DDR_STEP_L |= (1<<STEPPER_LEFT);
	DDR_DIR_R |= (1<<DIRECTION_R);
	DDR_DIR_L |= (1<<DIRECTION_L);

	// Output low
	PORT_STEP_R &= ~(1<<STEPPER_RIGHT);
	PORT_STEP_L &= ~(1<<STEPPER_LEFT);
	PORT_DIR_R |= (1<<DIRECTION_R);
	PORT_DIR_L &= ~(1<<DIRECTION_L);
}

void disableStepper(void){
        TCCR3A = (0<<WGM31) | (0<<WGM30) | (0<<COM3A1) | (0<<COM3A0);
        TCCR3B = (0<<WGM33) | (0<<WGM32) | (0<<CS32) | (1<<CS31) | (0<<CS30);
        TCCR4A = (0<<WGM41) | (0<<WGM40) | (0<<COM4A1) | (0<<COM4A0);
        TCCR4B = (0<<WGM43) | (0<<WGM42) | (0<<CS42) | (1<<CS41) | (0<<CS40);
}

//stepper right
void initTimer3Stepper(void){
    // Use mode 14, prescaler = 256
    TCCR3A = (1<<WGM31) | (0<<WGM30) | (1<<COM3A1) | (0<<COM3A0);
    TCCR3B = (1<<WGM33) | (1<<WGM32) | (0<<CS32) | (1<<CS31) | (0<<CS30);

	//define top value
    OCR3A = STEPVALUE;
    sei();
}

//stepper left
void initTimer4Stepper(void){
    // Use mode 14, prescaler = 256
    TCCR4A = (1<<WGM41) | (0<<WGM40) | (1<<COM4A1) | (0<<COM4A0);
    TCCR4B = (1<<WGM43) | (1<<WGM42) | (0<<CS42) | (1<<CS41) | (0<<CS40);

	//define top value
    OCR4A = STEPVALUE;
    sei();
}


void initStepper(void){
    initTimer4Stepper();
    initTimer3Stepper();
    initPinsStepper();
}

void speedStepperRight(int PWMRight){
    ICR3 = PWMRight;
}

void speedStepperLeft(int PWMLeft){
    ICR4 = PWMLeft;
}

void toggleStepperDirectionRight(void){
    static int state = 0;
    if(state == 0){
        PORT_DIR_R &= ~(1<<DIRECTION_R);
        state = 1;
    }
    else{
        PORT_DIR_R |= (1<<DIRECTION_R);
        state = 0;
    }
}

void toggleStepperDirectionLeft(void){
    static int state = 0;
    if(state == 0){
        PORT_DIR_L |= (1<<DIRECTION_L);
        state = 1;
    }
    else{
        PORT_DIR_L &= ~(1<<DIRECTION_L);
        state = 0;
    }
}


volatile unsigned int stepCounterLeft = 0;
ISR(TIMER4_OVF_vect){
    stepCounterLeft++;
}

volatile unsigned int stepCounterRight = 0;
ISR(TIMER3_OVF_vect){
    stepCounterRight++;
}

void clearStepCnt(void){
    stepCounterLeft = 0;
    stepCounterRight = 0;
}

//these two functions should help improve performance
void enableStepCnt(void){
    TIMSK4 |= (1<<TOIE4);
    TIMSK3 |= (1<<TOIE3);
}

void disableStepCnt(void){
    TIMSK4 &= ~(1<<TOIE4);
    TIMSK3 &= ~(1<<TOIE3);
}

void stepperBackward(void){
    PORT_DIR_R &= ~(1<<DIRECTION_R);
	PORT_DIR_L |= (1<<DIRECTION_L);
}

void stepperForward(void){
    PORT_DIR_R |= (1<<DIRECTION_R);
	PORT_DIR_L &= ~(1<<DIRECTION_L);
}
