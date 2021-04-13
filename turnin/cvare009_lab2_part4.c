/*	Author: Charles Varela
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned char tmpA = 0x00; 
	unsigned char tmpB = 0x00; 
	unsigned char tmpC = 0x00; 
	unsigned char tmpD = 0x00; 
	unsigned char tmpFinal = 0x00; 
	
	unsigned short totalW = 0x0000; 
   /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	totalW = tmpA + tmpB + tmpC;
	
	if(totalW > 0x008C){ //0000 0000 1000 1100 (140 dec)
		tmpD = 0x01; //0000 0001 //if exceeds 140, PD0 = 1
	} 
	else
	{
		tmpD = 0x00; //0000 0000
	}	
	if (tmpA > tmpC){
		if((tmpA - tmpC) > 0x50){ //0101 0000 (50dec)
			tmpD = tmpD >> 2;	
		}
	}
	else
	{	
		if((tmpC - tmpA) > 0x50){
			tmpD = tmpD >> 2;	
		}
	}
	tmpFinal = (totalW & 0x00FC) | tmpD; //sets tmpF to totalW, MSB 6 digits 0000 0000 xxxx xx00
						//forces D0 to hold value of tmpD
	PORTD = tmpFinal;
    }
     return 1;
}	
