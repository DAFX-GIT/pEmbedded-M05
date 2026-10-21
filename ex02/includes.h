#define BAUD 115200UL
#include <avr/io.h>
#include <util/delay.h>

void		adc_init();
uint16_t 	adc_read(uint8_t channel);

void		uart_init(void);
void		uart_tx(char c);
void		uart_print_hex(uint8_t value);
void		uart_print_u16(uint16_t value);