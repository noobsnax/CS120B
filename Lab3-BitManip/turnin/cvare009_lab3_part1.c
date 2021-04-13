/*	Author: Charles Varela
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 1
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA, tmpB;
	unsigned char cnt, i = 0x00;	
    /* Insert your solution below */
    while (1) {
	cnt = 0;
	tmpA = PINA;
	tmpB = PINB;
	for(i=0;i<8;i++){
		if((tmpA >> i & 0x01) == 0x01)
			cnt++;
		if((tmpB >> i & 0x01) == 0x01)
			cnt++;			
	}
	PORTC = cnt;
    }  	
    return 1;
}
