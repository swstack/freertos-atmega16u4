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
void task_blink_green_led(void *args) {
  for (;;) {
    toggle_on_board_green();
    vTaskDelay(100);
  }
}

void task_blink_red_led(void *args) {
  for (;;) {
    toggle_gpio_red();
    vTaskDelay(100);
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
    vTaskDelay(30);
  }
}


/************************************************
  Main
*************************************************/

void init() {
  init_on_board_leds();
  init_gpio_leds();
  SetupHardware();
  sei();
}


int main() {
  // Main loop

  init();
  flash_on_board_leds();

  create_task(task_blink_green_led, PRIORITY_NORMAL);
  create_task(task_blink_red_led, PRIORITY_NORMAL);
  create_task(task_virtual_serial, PRIORITY_LOW);

  vTaskStartScheduler();

  return 0;
}
