#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main()
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //GPIOA时钟使能
	
		GPIO_InitTypeDef GPIO_InitStructure; //结构体初始化
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//输出模式
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;	//输出端口
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//输出速率
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		//GPIO_ResetBits(GPIOA, GPIO_Pin_0);   //置PA0为低电平，点灯
		//GPIO_SetBits(GPIOA, GPIO_Pin_0);     //置PA0为高电平，灭灯
		//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);  //写入低电平
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);  //写入高电平
	
	while(1)
	{
//		GPIO_ResetBits(GPIOA, GPIO_Pin_0); 
//		Delay_ms(500);
//		GPIO_SetBits(GPIOA, GPIO_Pin_0); 
//		Delay_ms(500);
		
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
//		Delay_ms(100);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
//		Delay_ms(100);
		
		GPIO_Write(GPIOA, ~0x0001);	//0000 0000 0000 0001
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0002);	//0000 0000 0000 0010
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0004);	//0000 0000 0000 0100
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0008);	//0000 0000 0000 1000
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0010);	//0000 0000 0001 0000
		Delay_ms(500);
		
	}
	
}
