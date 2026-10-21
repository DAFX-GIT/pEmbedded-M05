#include "../includes.h"

void adc_init() {
	ADMUX = (1 << REFS0); // AVcc.
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADPSx set prescaler to 128. 
}

uint16_t adc_read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);  // keeps REFS0 and ADLAR set
    ADCSRA |= (1 << ADSC); // start conversion voltage to 10bit value 
    while (ADCSRA & (1 << ADSC)); // wait till conversion is done 
    return ADC;
}
