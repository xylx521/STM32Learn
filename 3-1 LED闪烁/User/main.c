#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main()
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //时钟使能
	
		GPIO_InitTypeDef GPIO_InitStructure; //结构体初始化
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		//GPIO_ResetBits(GPIOA, GPIO_Pin_0);   //置PA0为低电平，点灯
		//GPIO_SetBits(GPIOA, GPIO_Pin_0);     //置PA0为高电平，灭灯
		//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);  //写入低电平
		//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);  //写入高电平
	
	while(1)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1); 
		Delay_ms(500);
		GPIO_SetBits(GPIOA, GPIO_Pin_1); 
		Delay_ms(500);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
//		Delay_ms(100);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
//		Delay_ms(100);
	}
	
}
