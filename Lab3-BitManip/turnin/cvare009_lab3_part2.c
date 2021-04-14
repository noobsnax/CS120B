/*	Author: Charles Varela
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab 3  Exercise 2
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpC = 0x00;

	//PC5-PC0 represent fuel level
	//if 1 or 2, light PC5
        if(((tmpA & 0x0D) == 0x0D) || ((tmpA & 0x0E) == 0x0E) || ((tmpA & 0x0F) == 0x0F)) {
		tmpC = 0x3F;			//0 0 111111	
	}
	//if 3 or 4, light PC5 and PC4
	else if(((tmpA & 0x0A) == 0x0A) || ((tmpA & 0x0B) == 0x0B) || ((tmpA & 0x0C) == 0x0C)) {
		tmpC = 0x3E;			// 0 0 111110
	}
	//if 5 or 6, light PC5 - PC3
	else if(((tmpA & 0x07) == 0x07) || ((tmpA & 0x08) == 0x08) || ((tmpA & 0x09) == 0x09)) {
		tmpC = 0x3C; 			// 0 0 111000
	}
	//if 7 or 9, light PC5 - PC2
	else if(((tmpA & 0x05) == 0x05) || ((tmpA & 0x06) == 0x06)) {
		tmpC = 0x38;			 // 0 0 111100
	}
	//if 10 or 12, light PC5 - PC1
	else if (((tmpA & 0x03) == 0x03) || ((tmpA & 0x04) == 0x04)) {
		tmpC = 0x70; 			//0 1 110000
	} 
	//if 13 to 15, light PC5-PC0
	else if(((tmpA & 0x01) == 0x01) || ((tmpA & 0x02) == 0x02)){
		tmpC = 0x60;			 //0 1 100000
	//if level is < 4, light PC6

	} else {
		tmpC = 0x40;
	}			//0 1 00000

	PORTC = tmpC;
    }  	
    return 1;
}
