#define BAUD 115200UL
#include <avr/io.h>
#include <util/delay.h>

void		adc_init();
uint16_t 	adc_read(uint8_t channel);
uint16_t	adc_read_temp_raw(void);
int16_t		raw_to_celsius(uint16_t raw);

void light_diodes(uint8_t pot);

void		uart_init(void);
void		uart_tx(char c);
void		uart_print_hex(uint8_t value);
void		uart_print_u16(uint16_t value);

void		init_rgb();
void		wheel(uint8_t pos) ;