#ifndef __MAIN_H
#define __MAIN_H

#include "bsp.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define START_TASK_PRI		2
#define START_STACK_SIZE	128
TaskHandle_t StartHandler;
void start_task(void * parameter);

#define LED_TASK_PRI		3
#define LED_STACK_SIZE		128
TaskHandle_t LedHandler;
void led_task(void * parameter);

#define UART_TASK_PRI		4
#define UART_STACK_SIZE		256
TaskHandle_t UartHandler;
void uart_task(void * parameter);

#define FLOAT_TASK_PRI		5
#define FLOAT_STACK_SIZE	256
TaskHandle_t FloatHandler;
void float_task(void * parameter);

#endif
