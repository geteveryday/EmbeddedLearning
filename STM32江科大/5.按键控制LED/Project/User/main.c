#include "stm32f10x.h"
#include "Delay.h"
#include "tool.h"


//按键控制LED

int main(void)
{
	//初始化端口
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//初始化LED引脚
	LEDInit_Pin(GPIOA,GPIO_Pin_0);
	LEDInit_Pin(GPIOA,GPIO_Pin_1);
	KEYInit_Pin(GPIOB,GPIO_Pin_0);
	KEYInit_Pin(GPIOB,GPIO_Pin_1);
	//初始化灯信号，最开始为熄灭
	bool pin1=false,pin2=false;
	
	while(1)
	{
		ONAndOFF(GPIOB,GPIO_Pin_0,&pin1);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)pin1);
		ONAndOFF(GPIOB,GPIO_Pin_1,&pin2);
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,(BitAction)pin2);
	}
}
