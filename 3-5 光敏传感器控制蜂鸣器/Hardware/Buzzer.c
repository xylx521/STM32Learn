#include "stm32f10x.h"                  // Device header

//Buzzer初始化程序
void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //GPIOB时钟使能
	GPIO_InitTypeDef GPIO_InitStructure; //结构体初始化
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	//输出端口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//输出速率
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

//Buzzer鸣响程序
void Buzzer_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

//Buzzer鸣响程序
void Buzzer_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

//Buzzer取反
void Buzzer_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	}
}


