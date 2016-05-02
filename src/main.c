#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>
#include <common.h>
#include <FreeRTOS.h>

/************************************************
  Main
*************************************************/

void task_blink_green_led( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;) // A Task shall never return or exit.
  {
    toggle_on_board_green();
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }

}

void task_blink_red_led( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;) // A Task shall never return or exit.
  {
    toggle_on_board_red();
    vTaskDelay(5);  // one tick delay (15ms) in between reads for stability
  }

}


int main() {
  // Main loop
  //

  init_on_board_leds();
  flash_on_board_leds();

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


  vTaskStartScheduler();

  return 0;
}
