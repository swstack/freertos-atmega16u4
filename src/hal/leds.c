#include "leds.h"

// Global state
led_state led_state_on_board_green = OFF;
led_state led_state_on_board_yellow = OFF;
led_state led_state_on_board_red = OFF;

led_state led_state_gpio_green = OFF;
led_state led_state_gpio_yellow = OFF;
led_state led_state_gpio_red = OFF;


/************************************************
  LED Init functions
*************************************************/

void init_gpio_leds() {
  // Configure GPIO LED pins to output

  DDRD |= (1 << DDD6);  // yellow
  DDRB |= (1 << DDB6);  // green
  DDRB |= (1 << DDB4);  // red
}

void init_on_board_leds() {
  // Configure on-board LED pins to output

  DDRC |= (1 << DDC7);  // yellow
  DDRD |= (1 << DDD5);  // green
  DDRB |= (1 << DDB0);  // red
}

/************************************************
  LED Toggle Functions (Flip state)
*************************************************/

void toggle_gpio_yellow() {
  if (led_state_gpio_yellow == OFF) {
    set_gpio_yellow(ON);
  } else {
    set_gpio_yellow(OFF);
  }
}

void toggle_gpio_red() {
  if (led_state_gpio_red == OFF) {
    set_gpio_red(ON);
  } else {
    set_gpio_red(OFF);
  }
}

void toggle_gpio_green() {
  if (led_state_gpio_green == OFF) {
    set_gpio_green(ON);
  } else {
    set_gpio_green(OFF);
  }
}


void toggle_on_board_yellow() {
  // Toggle the state of the yellow on-board LED

  if (led_state_on_board_yellow == ON) {
    set_on_board_yellow(OFF);
  } else {
    set_on_board_yellow(ON);
  }
}

void toggle_on_board_green() {
  // Toggle the state of the green on-board LED

  if (led_state_on_board_green == ON) {
    set_on_board_green(OFF);
  } else {
    set_on_board_green(ON);
  }
}

void toggle_on_board_red() {
  // Toggle the state of the red on-board LED

  if (led_state_on_board_red == ON) {
    set_on_board_red(OFF);
  } else {
    set_on_board_red(ON);
  }
}

/************************************************
  LED Set Functions
*************************************************/

void set_on_board_yellow(led_state state) {
  // Set the yellow on-board LED to state {ON or OFF}

  if (state == ON) {
    PORTC |= (1 << PORTC7);  // Set high
  } else {
    PORTC &= ~(1 << PORTC7);  // Set low
  }
  led_state_on_board_yellow = state;
}

void set_on_board_green(led_state state) {
  // Set the green on-board LED to state {ON or OFF}

  if (state == ON) {
    PORTD &= ~(1 << PORTD5);  // Set low
  } else {
    PORTD |= (1 << PORTD5);  // Set high
  }
  led_state_on_board_green = state;
}

void set_on_board_red(led_state state) {
  // Set the red on-board LED to state {ON or OFF}

  if (state == ON) {
    PORTB &= ~(1 << PORTB0);  // Set low
  } else {
    PORTB |= (1 << PORTB0);  // Set high
  }
  led_state_on_board_red = state;
}

void set_gpio_red(led_state state) {
  if (state == ON) {
    PORTB |= (1 << PORTB4);
  } else {
    PORTB &= ~(1 << PORTB4);
  }
  led_state_gpio_red = state;
}

void set_gpio_green(led_state state) {
  if (state == ON) {
    PORTB |= (1 << PORTB6);
  } else {
    PORTB &= ~(1 << PORTB6);
  }
  led_state_gpio_green = state;
}

void set_gpio_yellow(led_state state) {
  if (state == ON) {
    PORTD |= (1 << PORTD6);
  } else {
    PORTD &= ~(1 << PORTD6);
  }
  led_state_gpio_yellow = state;
}

void flash_all_leds() {
  // Flash all of the on-board LEDs for 1 second

  set_on_board_red(ON);
  set_on_board_green(ON);
  set_on_board_yellow(ON);
  set_gpio_yellow(ON);
  set_gpio_red(ON);
  set_gpio_green(ON);
  _delay_ms(1000);
  set_on_board_red(OFF);
  set_on_board_green(OFF);
  set_on_board_yellow(OFF);
  set_gpio_yellow(OFF);
  set_gpio_red(OFF);
  set_gpio_green(OFF);
}
