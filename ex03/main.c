#include "includes.h"

int main () {
	adc_init();
	uart_init();

	while (1) {
		_delay_ms(20);
		int16_t raw = raw_to_celsius(adc_read_temp_raw());
		if (raw < 0) {uart_tx('-'); raw = -raw;}
		uart_print_u16(raw);
		uart_tx('\r');
		uart_tx('\n');
	}
}
