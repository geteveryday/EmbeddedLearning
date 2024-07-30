#include "stm32f10x.h"                  // Device header
#include "OLED.h"


int main(void)
{
	OLED_Init();
	OLED_ShowChar(1,1,'A');
	OLED_ShowString(1,3,"afjaof");
	OLED_ShowNum(2,2,222,3);
	
	while(1)
	{
		
	}
}
