#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f4xx_hal.h"

/* ���ⲿ���õĺ������� */
void bsp_InitLed(void);
void bsp_LedOn(uint8_t _no);
void bsp_LedOff(uint8_t _no);
void bsp_LedToggle(uint8_t _no);
uint8_t bsp_IsLedOn(uint8_t _no);

#endif

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
