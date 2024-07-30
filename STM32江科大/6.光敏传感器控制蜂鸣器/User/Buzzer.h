#ifndef __BUZZER_H
#define __BUZZER_H
#include "stm32f10x.h"
#include "Delay.h"
//初始化引脚
void GPIO_Pin_BuzzerInit(GPIO_TypeDef* GPIOx,uint16_t Pin);
//初始化光敏电阻
void GPIO_Pin_LDRInit(GPIO_TypeDef* GPIOx,uint16_t Pin);
//开始蜂鸣
void StartBuzzer(GPIO_TypeDef* GPIOx,uint16_t Pin);
//停止蜂鸣
void stopBuzzer(GPIO_TypeDef* GPIOx,uint16_t Pin);
//光敏电阻设置蜂鸣器
void LDR_Set_Buzzer(GPIO_TypeDef*GPIOBuzzer,uint16_t PinBuzzer,GPIO_TypeDef*GPIOLDR,uint16_t PinLDR);
#endif
