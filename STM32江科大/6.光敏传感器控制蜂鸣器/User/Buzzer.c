#include "Buzzer.h"

//初始化引脚
void GPIO_Pin_BuzzerInit(GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	//设置为高电平
	GPIO_SetBits(GPIOx,Pin);
}
//开始蜂鸣
void StartBuzzer(GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	GPIO_ResetBits(GPIOA,Pin);
	Delay_ms(300);
	GPIO_SetBits(GPIOx,Pin);
	Delay_ms(300);
	GPIO_ResetBits(GPIOA,Pin);
}
//停止蜂鸣
void stopBuzzer(GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	GPIO_SetBits(GPIOx,Pin);
}
//初始化光敏电阻
void GPIO_Pin_LDRInit(GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin=Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}
//光敏电阻设置蜂鸣器
void LDR_Set_Buzzer(GPIO_TypeDef*GPIOBuzzer,uint16_t PinBuzzer,GPIO_TypeDef*GPIOLDR,uint16_t PinLDR)
{
	if(GPIO_ReadInputDataBit(GPIOLDR,PinLDR)==0)
	{
		StartBuzzer(GPIOBuzzer,PinBuzzer);
	}
	else
	{
		stopBuzzer(GPIOBuzzer,PinBuzzer);
	}
	
	
}

