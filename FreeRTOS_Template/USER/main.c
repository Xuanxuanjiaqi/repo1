#include "main.h"

int main(int argc,char *argv[])
{
	bsp_Init();
	bsp_StartAutoTimer(0,495);
	
	taskENTER_CRITICAL();
	xTaskCreate((TaskFunction_t	)start_task,
				(char *			)"start_task",
				(uint16_t 		)START_STACK_SIZE,
				(void *			)NULL,
				(UBaseType_t	)START_TASK_PRI,
				(TaskHandle_t * )&StartHandler);
	vTaskStartScheduler();
	taskEXIT_CRITICAL();
	while(1){}
}

void start_task(void * parameter)
{
	taskENTER_CRITICAL();
	xTaskCreate((TaskFunction_t	)led_task,
				(char *			)"led_task",
				(uint16_t 		)LED_STACK_SIZE,
				(void *			)NULL,
				(UBaseType_t	)LED_TASK_PRI,
				(TaskHandle_t * )&LedHandler);
				
	xTaskCreate((TaskFunction_t	)uart_task,
				(char *			)"uart_task",
				(uint16_t 		)UART_STACK_SIZE,
				(void *			)NULL,
				(UBaseType_t	)UART_TASK_PRI,
				(TaskHandle_t * )&UartHandler);
				
	xTaskCreate((TaskFunction_t	)float_task,
				(char *			)"float_task",
				(uint16_t 		)FLOAT_STACK_SIZE,
				(void *			)NULL,
				(UBaseType_t	)FLOAT_TASK_PRI,
				(TaskHandle_t * )&FloatHandler);
	//删除起始任务
	vTaskDelete(NULL);
	taskEXIT_CRITICAL();
}

void led_task(void * parameter)
{
	while(1)
	{
		if(bsp_CheckTimer(0))
		{
			bsp_LedToggle(1);
			bsp_LedToggle(2);
		}
		vTaskDelay(5);
	}
}

void uart_task(void * parameter)
{
	while(1)
	{
		printf("uart_task is runing....\r\n");
		vTaskDelay(1000);
	}
}

void float_task(void * parameter)
{
	float f1 = 0.1f;
	float f2 = 0.001f;
	while(1)
	{
		printf("f1 + f2 = %f\r\n",f1 + f2);
		f1 += 0.1f;
		vTaskDelay(500);
	}
}
