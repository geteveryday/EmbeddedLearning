#include "stm32f10x.h"                  // Device header
#include "OLED.h"


int main(void)
{
	//初始化LED
	OLED_Init();
	OLED_ShowString(1,1,"welcome!");
	while(1)
	{
		
	}
}
