#include "../includes.h"

const uint8_t ledBits[4] = {PB0, PB1, PB2, PB4}; // store all led in an array

void light_diodes(uint8_t pot) {
	for (uint8_t i = 0; i < 4; i++) {
		if ((uint16_t)pot * 4 >= 255U * (i + 1))
			PORTB |=  (1 << ledBits[i]);
		else 
			PORTB &= ~(1 << ledBits[i]);
	}
}