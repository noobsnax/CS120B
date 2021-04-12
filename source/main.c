/*	Author: Charles Varela
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 2  Exercise 2
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
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmpA = 0x00; 
   /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	if(tmpA == 0x00){
		PORTC = 0x04; //all spaces are empty
	} 
	else if(tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08) {
		PORTC = 0x03; //three spots are available
	}
	else if(tmpA == 0x03 || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x09 || tmpA == 0x0A || tmpA == 0x0C) {
		PORTC = 0x02; //two spots are available
    	}
	else if (tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D || tmpA == 0x0E) {
		PORTC = 0x01; //one spot is available
	}	
	else {
		PORTC = 0x00; //no parking available
	 }
	
	}
     return 1;
}	
