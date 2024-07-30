#include "stm32f10x.h"                  // Device header
#include "tool.h"
#include "Delay.h"


//初始化引脚为推挽输出
void LEDInit_Pin(GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStruct.GPIO_Pin=Pin;
	GPIO_Init(GPIOx,&GPIO_InitStruct);
	GPIO_SetBits(GPIOx,Pin);
}
//初始化引脚为浮空输入
void KEYInit_Pin(GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct;	
	//GPIO_InitStruct.GPIO_Mode= GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Mode= GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_InitStruct.GPIO_Pin=Pin;
	GPIO_Init(GPIOx,&GPIO_InitStruct);
}


//判断按键是否按下
isKEY PushKEY(GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,Pin)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOx,Pin)==0)
		Delay_ms(20);
		return ON;
	}
 return OFF;
}
//判断按键按下返回数据
void ONAndOFF(GPIO_TypeDef* GPIOx,uint16_t Pin,bool* Pin_OFF_ON)
{
	isKEY key=PushKEY(GPIOx,Pin);
	if(key==ON)
	{
		//按键按下一次，就取反
		if((*Pin_OFF_ON)==true)
		{
			(*Pin_OFF_ON)=false;
			Delay_ms(20);
		}
		else
		{
			(*Pin_OFF_ON)=true;
			Delay_ms(20);
		}
	}
}
