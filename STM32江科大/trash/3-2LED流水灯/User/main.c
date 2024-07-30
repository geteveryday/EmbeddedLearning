#include "stm32f10x.h"                  // Device header
#include "Delay.h"



int main(void)
{
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    GPIO_InitTypeDef GPIO_Initstructure;
    //GPIO_Mode_Out_PP推挽模式（高低模式都能驱动）   GPIO_Mode_Out_OD开漏输出（低电平有驱动能力，高电平为高阻态）
    GPIO_Initstructure.GPIO_Mode= GPIO_Mode_Out_PP;
  
    GPIO_Initstructure.GPIO_Pin=GPIO_Pin_All;
    GPIO_Initstructure.GPIO_Speed= GPIO_Speed_50MHz;
    
    
    
    GPIO_Init(GPIOA,&GPIO_Initstructure);
    
    //GPIO_ResetBits(GPIOA,GPIO_Pin_0);
    //GPIO_SetBits(GPIOA,GPIO_Pin_0);
    //GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
    //置为低电平  Bit_RESET
    //GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
    #if 0
    while(1)
    {
       GPIO_Write(GPIOA,~0x0001);
       Delay_ms(500);
        GPIO_Write(GPIOA,~0x0002);
       Delay_ms(500);
        GPIO_Write(GPIOA,~0x0004);
       Delay_ms(500);
        GPIO_Write(GPIOA,~0x0008);
       Delay_ms(500);
        GPIO_Write(GPIOA,~0x00010);
       Delay_ms(500);
        GPIO_Write(GPIOA,~0x00020);
       Delay_ms(500);
        GPIO_Write(GPIOA,~0x00040);
       Delay_ms(500);
        GPIO_Write(GPIOA,~0x00080);
       Delay_ms(500);
    }
    #else
	//使用指针偏移实现
	int write=0x01;
	while(1)
	{
		GPIO_Write(GPIOA,~write);
		Delay_ms(1000);
		write<<=1;
		if(write>=0x80) write=0x01;
	}
	#endif
}
