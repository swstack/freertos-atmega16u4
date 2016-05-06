#ifndef avr_config_h
#define avr_config_h

#include <avr/io.h>
#include <avr/wdt.h>
#include "FreeRTOS.h"
#include "task.h"

// SS: Custom tick rate (1000hz)
#define configTICK_RATE_HZ		( (TickType_t)( 128000 >> 7  ) )

// System tick timer (1ms)
void prvSetupTimerInterrupt(void);

#endif // avr_config_h
