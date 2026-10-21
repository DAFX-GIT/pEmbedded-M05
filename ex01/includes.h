#define BAUD 115200UL
#include <avr/io.h>
#include <util/delay.h>

void		adc_init();
uint8_t 	adc_read8(uint8_t channel);

void		uart_init(void);
void		uart_tx(char c);
void		uart_print_hex(uint8_t value);