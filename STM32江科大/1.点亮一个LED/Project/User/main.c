#include "stm32f10x.h"                  // Device header
int main(void)
{
	//让GPIOA端口的时钟启动
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//使用GPIO_InitTypeDef结构体设置GPIOA的初始状态
	GPIO_InitTypeDef Init_GPIOA;
	
	//设置GPIOA的工作模式
	Init_GPIOA.GPIO_Mode=GPIO_Mode_Out_PP;//设置为推完输出0x10
	
	//设置工作的引脚
	Init_GPIOA.GPIO_Pin=GPIO_Pin_4;
	
	//设置引脚的速度--响应速度
	Init_GPIOA.GPIO_Speed=GPIO_Speed_10MHz;
	
	//初始化GPIO
	GPIO_Init(GPIOA,&Init_GPIOA);
#if 0
	//将引脚设置为低电平 --Led亮  （此时Led灯近端口端为负极）
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
#elif 0
//将引脚设置为高电平 --Led熄灭，将Led正负极反装，亮
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
#elif 1
//将GPIOA4设置为高电平   ---Bit_RESET=0，Bit_SET=1；
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
#elif 0
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,0);
#endif
	while(1)
	{
		
	}
	
}