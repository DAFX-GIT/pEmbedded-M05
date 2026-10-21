#include "includes.h"



int main () {
	adc_init();
	init_rgb();
	while (1) {
		wheel((uint8_t) (adc_read(0) >> 2));
	}
}
