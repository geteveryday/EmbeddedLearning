#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Encoder.h"
extern int count;



int main(void)
{
	//初始化LED灯
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);	
	
	//初始化OLED
	OLED_Init();
	//初始化编码器
	init_Device();
	OLED_ShowString(1,1,"COUNT:");
	while(1)
	{
		OLED_ShowSignedNum(1,7,count,5);
		if(count<10)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_0);
			GPIO_SetBits(GPIOA,GPIO_Pin_1);
			GPIO_SetBits(GPIOA,GPIO_Pin_2);
		}
		else if(count<20)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_0);
			GPIO_ResetBits(GPIOA,GPIO_Pin_1);
			GPIO_SetBits(GPIOA,GPIO_Pin_2);
		}
		else
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_0);
			GPIO_ResetBits(GPIOA,GPIO_Pin_1);
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);
		}
	}
}
