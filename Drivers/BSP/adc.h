#ifndef __ADC_H
#define __ADC_H

#include "sys.h"


/* ADC3温度传感器通道 定义 */
#define ADC_ADCX                            ADC1 
#define ADC_TEMPSENSOR_CHX                  ADC_CHANNEL_16
#define ADC_ADCX_CHY_CLK_ENABLE()           do{ __HAL_RCC_ADC1_CLK_ENABLE(); }while(0)          /* ADC1 时钟使能 */

/* 函数声明 */
void adc_temperature_init(void);    /* 初始化ADC内部温度传感器 */
int16_t adc_get_temperature(void);  /* 获取内部温度传感器温度值 */

#endif 

