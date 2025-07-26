#include "stm32f10x.h"                  // Device header

//extern uint16_t Numb;

/*
中断初始化函数
*/
void Timer_Init(void)
{	
	//配置时钟和选择时钟模式
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_InternalClockConfig(TIM2);   //默认使用内部时钟，不写这一行也可以
	
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseIniture;
	TIM_TimeBaseIniture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseIniture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseIniture.TIM_Period = 10000 - 1;
	TIM_TimeBaseIniture.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseIniture.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseIniture);
	
	//清除一个初始标志位
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	//配置中断输出控制
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	//配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	//启动定时器
	TIM_Cmd(TIM2, ENABLE);
	
}

/*
中断函数
*/

//void TIM2_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//	{
//		
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}
//	
//}


