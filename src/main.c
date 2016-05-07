#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include <leds.h>
#include <avr_config.h>
#include <task_helper.h>
#include <VirtualSerial.h>
#include <hough.h>

uint32_t uptime_ms;
uint16_t timer_ms;

bool one_in_four() {
   int random_int = (rand() % 4) + 1;
   if (random_int == 4) {
     return true;
   } else {
     return false;
   }
}


/************************************************
  Tasks
*************************************************/

void task_blink_green_led(void *args) {
  /* Blink Green LED Task (executes every 100ms)
   *
   * This task toggles the green LED connected to a GPIO pin
   */

  for (;;) {
    toggle_gpio_green();
    vTaskDelay(100);
  }
}

void task_blink_red_led(void *args) {
  /* Blink Red LED Task (executes every 100ms)
   *
   * This task toggles the red LED connected to a GPIO pin
   */

  for (;;) {
    toggle_gpio_red();
    vTaskDelay(100);
  }
}

void task_blink_yellow_led(void *args) {
  /* Blink Yellow LED Task (executes every 100ms)
   *
   * This task toggles the yellow LED connected to a GPIO pin
   */

  for (;;) {
    toggle_gpio_yellow();
    vTaskDelay(100);
  }
}

void task_jitter_led(void *args) {
  /* Jitter Yellow LED Task (executes every 25ms)
   *
   * This task runs a hough transform on a 6x6 pixel image
   */

  for (;;) {
    if (one_in_four() == true) {
      set_on_board_yellow(ON);
      _delay_ms(5);
      set_on_board_yellow(OFF);
    }

    vTaskDelay(25);
  }
}

void task_hough_transform(void *args) {
  /* Hough Transform Task (executes every 100ms)
   *
   * This task runs a hough transform on a 6x6 pixel image
   */

  for (;;) {
    set_on_board_green(ON);
    houghTransform((uint16_t)&image_red, (uint16_t)&image_green, (uint16_t)&image_blue);
    set_on_board_green(OFF);
    vTaskDelay(1000);
  }
}

void task_virtual_serial(void *args) {
  /* Virtual Serial Task (executes every 30ms)
   *
   * This task handles the virtual serial input/output buffer
   */

  for (;;) {
    USB_Mainloop_Handler();
    vTaskDelay(30);
  }
}

/************************************************
  Main
*************************************************/

void init_uptime_ms_timer() {
  /* Setup a 1000hz timer to keep track of system uptime in milliseconds
   */

  TCCR3A = 0;
  TCCR3B = (1 << CS30) | (1 << CS31) | (1 << WGM32);
  OCR3A = 250;
  TIMSK3 = (1 << OCIE3A);
}

void initial_prompt() {
  /* Block the program until a user presses any key
   */

  while(1) {
    USB_Mainloop_Handler();
    printf("Press any key to continue...\r\n");
    if (fgetc(stdin) != -1) {
      return;
    }
    _delay_ms(1000);
  }
}

void init() {
  /* Initialize the entire system
   *    - Configure pins
   *    - Setup libraries
   *    - Enable interrupts
   */

  init_uptime_ms_timer();
  init_on_board_leds();
  init_gpio_leds();
  SetupHardware();
  sei();
}

int main() {
  // Main loop

  init();
  flash_all_leds();
  // initial_prompt();
  uptime_ms = 0;

  // WTF: Board crashes unless hough transform task created first...
  create_task(task_hough_transform, PRIORITY_NORMAL);

  // Rest of tasks
  create_task(task_blink_red_led, PRIORITY_NORMAL);
  create_task(task_blink_green_led, PRIORITY_NORMAL);
  create_task(task_blink_yellow_led, PRIORITY_NORMAL);
  create_task(task_jitter_led, PRIORITY_NORMAL);
  // create_task(task_virtual_serial, PRIORITY_CRITICAL);

  vTaskStartScheduler();

  return 0;

}

ISR(TIMER3_COMPA_vect) {
  uptime_ms++;
}
