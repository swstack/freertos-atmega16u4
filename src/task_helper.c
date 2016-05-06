#include "task_helper.h"

void create_task(TaskFunction_t task, int priority) {
  xTaskCreate(
    task,                     // The task function
    (const portCHAR *)"",     // Name for humans
    128,                      // Stack size
    NULL,                     // Task parameters
    priority,                 // Priority, with 1 being the highest, and 4 being the lowest.
    NULL );
}
