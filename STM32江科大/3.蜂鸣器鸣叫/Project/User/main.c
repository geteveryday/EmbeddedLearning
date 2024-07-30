#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	/*蜂鸣器介绍,三个引脚，一个VCC 一个GND 一个I/O ，I/O接端口
	触发方式根据说明
	*/
	//初始化时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//初始化GPIO
		//初始化GPIO结构体
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	while(1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		Delay_ms(200);
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		Delay_ms(200);
	}
	
}