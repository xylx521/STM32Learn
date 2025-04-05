#include "stm32f10x.h"                  // Device header


void Light_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //GPIOB时钟使能
	GPIO_InitTypeDef GPIO_InitStructure; //结构体初始化
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//输出模式,上拉输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	//输出端口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//输出速率
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t LightSenSor_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
}
