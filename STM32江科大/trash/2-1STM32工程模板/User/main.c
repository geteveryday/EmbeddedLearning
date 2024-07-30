#include "stm32f10x.h"                  // Device header

int main(void)
{
    /*RCC->APB2ENR=0x00000010;
    GPIOC->CRH=0x00300000;
    GPIOC->ODR=0x00002000;
    */
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructute;
    GPIO_InitStructute.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_InitStructute.GPIO_Pin=GPIO_Pin_13;
    GPIO_InitStructute.GPIO_Speed=  GPIO_Speed_50MHz;
    GPIO_Init(GPIOC,&GPIO_InitStructute);
    //设置高电平
    //GPIO_SetBits(GPIOC,GPIO_Pin_13);
    //设置低电平
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);
    while(1)
    {
        
    }
   
}
