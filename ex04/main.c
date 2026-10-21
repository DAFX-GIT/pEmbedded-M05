#include "includes.h"



int main () {
	DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB4); //D1 D2 D3 D4 en sortie → LED
	adc_init();
	init_rgb();

	while (1) {
		uint8_t pot = (uint8_t) (adc_read(0) >> 2);
		wheel(pot);
		light_diodes(pot);
	}
}
