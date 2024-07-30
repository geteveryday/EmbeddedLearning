#include "stm32f10x.h"                  // Device header
#include "Delay.h"



int main(void)
{
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    GPIO_InitTypeDef GPIO_Initstructure;
    //GPIO_Mode_Out_PP推挽模式（高低模式都能驱动）   GPIO_Mode_Out_OD开漏输出（低电平有驱动能力，高电平为高阻态）
    GPIO_Initstructure.GPIO_Mode= GPIO_Mode_Out_PP;
  
    GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0;
    GPIO_Initstructure.GPIO_Speed= GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOA,&GPIO_Initstructure);
    
    //GPIO_ResetBits(GPIOA,GPIO_Pin_0);
    //GPIO_SetBits(GPIOA,GPIO_Pin_0);
    //GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
    //置为低电平  Bit_RESET
    //GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
    
    while(1)
    {
        GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
        Delay_ms(500);
        GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
        Delay_ms(500);
    }
    
    
    
    
    
}
