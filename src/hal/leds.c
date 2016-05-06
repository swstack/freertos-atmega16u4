#include "leds.h"

// Global state
led_state led_state_green = OFF;
led_state led_state_yellow = OFF;
led_state led_state_red = OFF;

#define PIN_ON_BOARD_GREEN      DDD5
#define PIN_ON_BOARD_RED        DDB0
#define PIN_ON_BOARD_YELLOW     DDC7

#define PIN_GPIO_GREEN          PORTB4
#define PIN_GPIO_RED            PORTB6
#define PIN_GPIO_YELLOW         PORTD6


/************************************************
  LED Init functions
*************************************************/

void init_gpio_leds() {
  // Configure GPIO LED pins to output

  DDRD |= (1 << DDD6);
  DDRB |= (1 << DDB6);
  DDRB |= (1 << DDB4);
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
  uint8_t yelval = PIND & _BV(PD6);
  if (yelval == 0) {
    set_gpio_yellow(ON);
  } else {
    set_gpio_yellow(OFF);
  }
}

void toggle_gpio_red() {
  uint8_t redval = PINB & _BV(PB4);
  if (redval == 0) {
    set_gpio_red(ON);
  } else {
    set_gpio_red(OFF);
  }
}

void toggle_gpio_green() {
  uint8_t redval = PINB & _BV(PB4);
  if (redval == 0) {
    set_gpio_green(ON);
  } else {
    set_gpio_green(OFF);
  }
}


void toggle_on_board_yellow() {
  // Toggle the state of the yellow on-board LED

  if (led_state_yellow == ON) {
    set_on_board_yellow(OFF);
  } else {
    set_on_board_yellow(ON);
  }
}

void toggle_on_board_green() {
  // Toggle the state of the green on-board LED

  if (led_state_green == ON) {
    set_on_board_green(OFF);
  } else {
    set_on_board_green(ON);
  }
}

void toggle_on_board_red() {
  // Toggle the state of the red on-board LED

  if (led_state_red == ON) {
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
  led_state_yellow = state;
}

void set_on_board_green(led_state state) {
  // Set the green on-board LED to state {ON or OFF}

  if (state == ON) {
    PORTD &= ~(1 << PORTD5);  // Set low
  } else {
    PORTD |= (1 << PORTD5);  // Set high
  }
  led_state_green = state;
}

void set_on_board_red(led_state state) {
  // Set the red on-board LED to state {ON or OFF}

  if (state == ON) {
    PORTB &= ~(1 << PORTB0);  // Set low
  } else {
    PORTB |= (1 << PORTB0);  // Set high
  }
  led_state_red = state;
}

void set_gpio_red(led_state state) {
  if (state == ON) {
    PORTB |= (1 << PORTB4);
  } else {
    PORTB &= ~(1 << PORTB4);
  }
}

void set_gpio_green(led_state state) {
  if (state == ON) {
    PORTB |= (1 << PORTB6);
  } else {
    PORTB &= ~(1 << PORTB6);
  }
}

void set_gpio_yellow(led_state state) {
  if (state == ON) {
    PORTD |= (1 << PORTD6);
  } else {
    PORTD &= ~(1 << PORTD6);
  }
}

void flash_on_board_leds() {
  // Flash all of the on-board LEDs for 1 second

  set_on_board_red(ON);
  set_on_board_green(ON);
  set_on_board_yellow(ON);
  _delay_ms(1000);
  set_on_board_red(OFF);
  set_on_board_green(OFF);
  set_on_board_yellow(OFF);
}
