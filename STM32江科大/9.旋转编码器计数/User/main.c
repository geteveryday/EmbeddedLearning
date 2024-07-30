#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Encoder.h"
#include "Delay.h"


int main(void)
{
	//旋转编码器中断初始化
	Encoder_Init();
	//初始化LED
	OLED_Init();
	OLED_ShowString(1,1,"welcome!");
	while(1)
	{
		OLED_ShowSignedNum(1,9,count,5);
		count=0;
		Delay_ms(1000);
	}
}
