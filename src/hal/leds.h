#ifndef _leds_h
#define _leds_h

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

typedef enum { OFF, ON } led_state;

/************************************************
  LED Init functions
*************************************************/

void init_gpio_leds();
void init_on_board_leds();

/************************************************
  LED Toggle Functions (Flip state)
*************************************************/

void toggle_gpio_yellow();
void toggle_gpio_red();
void toggle_gpio_green();
void toggle_on_board_yellow();
void toggle_on_board_green();
void toggle_on_board_red();

/************************************************
  LED Set Functions
*************************************************/

void set_on_board_yellow(led_state state);
void set_on_board_green(led_state state);
void set_on_board_red(led_state state);
void set_gpio_red(led_state state);
void set_gpio_green(led_state state);
void set_gpio_yellow(led_state state);

/************************************************
  Other Function
*************************************************/

void flash_all_leds();

#endif
