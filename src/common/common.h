#ifndef _COMMON
#define _COMMON

#define F_CPU 16000000

#include <util/delay.h>
#include <avr/interrupt.h>

typedef enum { OFF, ON } led_state;

/*
    Init Functions
*/
void init_on_board_leds();
void init_1hz_timer_3();
void init_1000hz_timer_3();
void init_1000hz_timer_0();
void init_input_buttons();

/*
    LED Functions
*/
void set_on_board_yellow(led_state);
void set_on_board_red(led_state);
void set_on_board_green(led_state);

void toggle_on_board_green();
void toggle_on_board_yellow();
void toggle_on_board_red();

void flash_on_board_leds();

/*
    Time Functions
*/
uint32_t system_uptime();
void reset_uptime();
uint32_t uptime_ms;

#endif
