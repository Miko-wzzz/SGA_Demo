#ifndef __DRV_PWM_H_
#define __DRV_PWM_H_

#include "drv_hal_conf.h"

typedef struct
{
	TIM_HandleTypeDef 	tPWMHandle;		/* STM32�ڲ�PWM�豸��� */
	TIM_OC_InitTypeDef	tPWMChannel;	/* STM32�ڲ�PWMͨ����� */
	uint32_t			ulFreq;			/* Ƶ�� */
	uint8_t				ulChannel;		/* ͨ�� */
	tagGPIO_T			tGPIO;
}tagPWM_T;

void Drv_PWM_DutyfactorSet(tagPWM_T *_tPWM,float _fDuty);
void Drv_PWM_Init(tagPWM_T *_tPWM, uint8_t _ucNum);

#endif
