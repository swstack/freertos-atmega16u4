#ifndef _task_helper_h
#define _task_helper_h

#include <FreeRTOS.h>
#include <task.h>

#define PRIORITY_CRITICAL 1
#define PRIORITY_HIGH 2
#define PRIORITY_NORMAL 3
#define PRIORITY_LOW 4

void create_task();

#endif
