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

uint16_t adc_read_temp_raw(void)
{
    // Internal 1.1V reference + channel 8 (temperature sensor), ADLAR = 0
    ADMUX = (1 << REFS1) | (1 << REFS0) | (1 << MUX3);
    _delay_ms(2);                         // let the reference settle

    // Throw away the first conversion after switching reference
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));

    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

int16_t raw_to_celsius(uint16_t raw)
{
    // raw - 352: distance from the 25 °C reference
	//  the sensor changes by about 128 LSB over 100 °C (352 → 480 between 25 °C and 125 °C):
	// slope = 128 LSB / 100 °C = 1.28 LSB per °C
	// To go from LSB to °C, you divide by 1.28, which is the same as multiplying by 100/128. Simplified, that fraction is 25/32:
	// + 25 because we started with the distance from that reference point. 
    return (int16_t)(((int32_t)raw - 352) * 25 / 32 + 25);
}