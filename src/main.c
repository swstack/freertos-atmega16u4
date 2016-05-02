#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>
#include <common.h>

/************************************************
  Main
*************************************************/


int main() {
  // Main loop
  //

  init_on_board_leds();
  flash_on_board_leds();

  return 0;
}
