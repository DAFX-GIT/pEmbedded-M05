#include "../includes.h"

void adc_init() {
	ADMUX = (1 << REFS0) | (1 << ADLAR); // AVcc and left aligned.
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADPSx set prescaler to 128. 
}

uint8_t adc_read8(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);  // keeps REFS0 and ADLAR set
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADCH;                                 // 0..255
}