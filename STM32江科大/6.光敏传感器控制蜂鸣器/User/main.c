#include "stm32f10x.h"                  // Device header
#include "Buzzer.h"


//光敏电阻-亮时，输出高电平

int main(void)
{
	//初始化端口
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//初始化蜂鸣器引脚
    GPIO_Pin_BuzzerInit(GPIOA,GPIO_Pin_7);
	//初始化光敏电阻引脚
	GPIO_Pin_LDRInit(GPIOA,GPIO_Pin_4);
	
	while(1)
	{
		LDR_Set_Buzzer(GPIOA,GPIO_Pin_7,GPIOA,GPIO_Pin_4);
		Delay_ms(200);
	}
}
