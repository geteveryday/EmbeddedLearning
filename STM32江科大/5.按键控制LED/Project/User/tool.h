#ifndef __TOOL_H
#define __TOOL_H
#include "stdbool.h"
typedef enum
{
	OFF=0,
	ON=1
}isKEY;


//初始化引脚为推挽输出
void LEDInit_Pin(GPIO_TypeDef* GPIOx,uint16_t Pin);
//初始化引脚为浮空输入
void KEYInit_Pin(GPIO_TypeDef* GPIOx,uint16_t Pin);
//判断按键是否按下
isKEY PushKEY(GPIO_TypeDef* GPIOx,uint16_t Pin);
//判断按键按下返回数据
void ONAndOFF(GPIO_TypeDef* GPIOx,uint16_t Pin,bool* Pin_OFF_ON);
#endif
