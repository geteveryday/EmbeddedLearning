#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "CountSensor.h"

int main(void)
{
	//开启端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//初始化LED
	OLED_Init();
	CountSenSor_Init();
	OLED_ShowString(1,1,"COUNT:");
	while(1)
	{
		OLED_ShowNum(1,7,getCount(),5);
	}
}
