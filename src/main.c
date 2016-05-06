#include <stdlib.h>
#include <stdbool.h>
#include <leds.h>
#include <avr_config.h>
#include <FreeRTOS.h>

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

/************************************************
  Main
*************************************************/
void create_task() {

}

void create_tasks() {
  xTaskCreate(
    task_blink_green_led
    ,  (const portCHAR *)"Blink Green LED"  // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 1 being the highest, and 4 being the lowest.
    ,  NULL );

    xTaskCreate(
      task_blink_red_led
      ,  (const portCHAR *)"Blink Red LED"  // A name just for humans
      ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
      ,  NULL
      ,  2  // Priority, with 1 being the highest, and 4 being the lowest.
      ,  NULL );
}

int main() {
  // Main loop

  init_on_board_leds();
  flash_on_board_leds();
  create_tasks();
  vTaskStartScheduler();

  return 0;
}
