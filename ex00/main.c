#include "includes.h"

int main () {
	adc_init();
	uart_init();

	while (1) {
		_delay_ms(20);
		uart_print_hex(adc_read8(0));
		uart_tx('\r');
		uart_tx('\n');
	}
}
