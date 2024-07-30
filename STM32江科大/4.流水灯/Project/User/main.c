#include "stm32f10x.h"
#include "Delay.h"
//流水灯

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	int value=0x01;
	while(1)
	{
		GPIO_Write(GPIOA,~value);
		Delay_ms(300);
		value<<=1;
		if(value>0x80)
		{
			value=0x01;
		}
	}
	
}
