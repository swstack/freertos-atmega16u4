#include "avr_config.h"

void prvSetupTimerInterrupt(void) {
  
  // Timer 0 @1000hz
	TCCR0A = 0;
	TCCR0B = (1 << CS00) | (1 << CS01) | (1 << WGM02);
	OCR0A = 250;
	TIMSK0 = (1 << OCIE0A);

}
