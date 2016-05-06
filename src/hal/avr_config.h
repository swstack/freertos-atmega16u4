/* avr_config.h
 *
 * More or less the same file as FreeRTOSVariant.h from:
 *   - https://github.com/feilipu/Arduino_FreeRTOS_Library
 */

#ifndef avr_config_h
#define avr_config_h

#include <avr/io.h>
#include <avr/wdt.h>

#include "FreeRTOS.h"
#include "task.h"

// System Tick - Scheduler timer
// Use the Watchdog timer, and choose the rate at which scheduler interrupts will occur.

#define portUSE_WDTO WDTO_15MS	// portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick

/* Watchdog period options: 	WDTO_15MS
								WDTO_30MS
								WDTO_60MS
								WDTO_120MS
								WDTO_250MS
								WDTO_500MS
*/
//	xxx Watchdog Timer is 128kHz nominal, but 120 kHz at 5V DC and 25 degrees is actually more accurate, from data sheet.
#define configTICK_RATE_HZ		( (TickType_t)( (uint32_t)128000 >> (portUSE_WDTO + 11) ) )  // 2^11 = 2048 WDT scaler for 128kHz Timer

/*-----------------------------------------------------------*/

void initVariant(void) __attribute__((flatten));

void vApplicationIdleHook( void ) __attribute__((flatten));

void vApplicationMallocFailedHook( void );
void vApplicationStackOverflowHook( TaskHandle_t xTask, portCHAR *pcTaskName );

/*-----------------------------------------------------------*/

#endif // avr_config_h
