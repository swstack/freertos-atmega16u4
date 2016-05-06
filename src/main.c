#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include <leds.h>
#include <avr_config.h>
#include <task_helper.h>
#include <VirtualSerial.h>

/************************************************
  Tasks
*************************************************/
void set_led_red(led_state state) {
  if (state == ON) {
    PORTB |= (1 << PORTB4);
  } else {
    PORTB &= ~(1 << PORTB4);
  }
}

void task_blink_green_led(void *args) {
  for (;;) {
    toggle_on_board_green();
    vTaskDelay(11);
  }
}

void task_blink_red_led(void *args) {
  for (;;) {

    uint8_t redval = PINB & _BV(PB4);
    if (redval == 0) {
      set_led_red(ON);
    } else {
      set_led_red(OFF);
    }

    vTaskDelay(100);
    // vTaskDelay(pdMS_TO_TICKS(100));
  }
}

void task_blink_yellow_led(void *args) {
  for (;;) {
    vTaskDelay(5);
  }
}

void task_count_green_led(void *args) {
  for (;;) {
    vTaskDelay(5);
  }
}

void task_jitter_led(void *args) {
  for (;;) {
    vTaskDelay(5);
  }
}

void task_hough_transform(void *args) {
  for (;;) {
    vTaskDelay(5);
  }
}

void task_virtual_serial(void *args) {
  for (;;) {
    USB_Mainloop_Handler();
    vTaskDelay(1);  // Every 30ms
  }
}


/************************************************
  Main
*************************************************/
void init_leds() {
  init_on_board_leds();
  DDRD |= (1 << DDD6);
  DDRB |= (1 << DDB6);
  DDRB |= (1 << DDB4);
}


void init() {
  init_on_board_leds();
  init_leds();
  SetupHardware();
  sei();
}


int main() {
  // Main loop

  init();
  flash_on_board_leds();

  // create_task(task_blink_green_led, PRIORITY_NORMAL);
  create_task(task_blink_red_led, PRIORITY_NORMAL);
  // create_task(task_virtual_serial, PRIORITY_LOW);

  vTaskStartScheduler();

  return 0;
}
