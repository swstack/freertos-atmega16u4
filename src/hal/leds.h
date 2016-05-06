#ifndef _LEDS
#define _LEDS

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

typedef enum { OFF, ON } led_state;

void init_on_board_leds();

void set_on_board_yellow(led_state);
void set_on_board_red(led_state);
void set_on_board_green(led_state);

void toggle_on_board_green();
void toggle_on_board_yellow();
void toggle_on_board_red();

void flash_on_board_leds();

#endif
