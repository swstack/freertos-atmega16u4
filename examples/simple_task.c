#include <FreeRTOS.h>
#include <task.h>


void simple_task(void *args) {
  // Task runs every 100 ticks

  for(;;) {
    // Task body
    vTaskDelay(100);  // 100 ticks
  }
}

int main() {

  xTaskCreate(
    simple_task,                         // The task function
    (const portCHAR *)"Simple Task",     // Name for humans
    128,                                 // Stack size (words)
    NULL,                                // Task parameters
    2,                                   // Priority (1 high, 4 low)
    NULL);

  vTaskStartScheduler();

  return 0;

}
