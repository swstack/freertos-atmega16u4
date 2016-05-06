#include <stdlib.h>
#include <stdbool.h>
#include <leds.h>
#include <avr_config.h>
#include <task_helper.h>

/************************************************
  Tasks
*************************************************/

void task_blink_green_led(void *pvParameters __attribute__((unused))) {
  for (;;) {
    toggle_on_board_green();
    vTaskDelay(1);
  }
}

void task_blink_red_led(void *pvParameters __attribute__((unused))) {
  for (;;) {
    toggle_on_board_red();
    vTaskDelay(5);
  }
}

void task_blink_yellow_led(void *pvParameters __attribute__((unused))) {
  for (;;) {
    vTaskDelay(5);
  }
}

void task_count_green_led(void *pvParameters __attribute__((unused))) {
  for (;;) {
    vTaskDelay(5);
  }
}

void task_jitter_led(void *pvParameters __attribute__((unused))) {
  for (;;) {
    vTaskDelay(5);
  }
}

void task_hough_transform(void *pvParameters __attribute__((unused))) {
  for (;;) {
    vTaskDelay(5);
  }
}


/************************************************
  Main
*************************************************/

int main() {
  // Main loop

  init_on_board_leds();
  flash_on_board_leds();

  create_task(task_blink_green_led, PRIORITY_NORMAL);
  create_task(task_blink_red_led, PRIORITY_NORMAL);

  vTaskStartScheduler();

  return 0;
}
