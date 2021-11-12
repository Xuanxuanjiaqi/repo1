#ifndef _BSP_H_
#define _BSP_H_

/* 开关全局中断的宏 */
#define ENABLE_INT()	__set_PRIMASK(0)	/* 使能全局中断 */
#define DISABLE_INT()	__set_PRIMASK(1)	/* 禁止全局中断 */

/* 这个宏仅用于调试阶段排错 */
#define BSP_Printf		printf
//#define BSP_Printf(...)

#define EXTI9_5_ISR_MOVE_OUT		/* bsp.h 中定义此行，表示本函数移到 stam32f4xx_it.c。 避免重复定义 */

#define ERROR_HANDLER()		Error_Handler(__FILE__, __LINE__);


#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TRUE
	#define TRUE  1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

/* 定义优先级分组 */
#define NVIC_PREEMPT_PRIORITY	4

#include "bsp_timer.h"
#include "bsp_led.h"
#include "bsp_uart_fifo.h"

/* 提供给其他C文件调用的函数 */
void bsp_Init(void);
void bsp_Idle(void);

void bsp_GetCpuID(uint32_t *_id);
void Error_Handler(char *file, uint32_t line);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
