#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
#include "Timer.h"


uint16_t Numb;
int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Timer_Init();		//定时器初始化
	
	/*OLED显示*/
	
	OLED_ShowString(1, 1, "Numb:");	//1行1列显示字符串Numb:
	OLED_ShowString(2, 1, "Counter:");	//2行1列显示字符串Numb:
	while(1)
		{
			
			OLED_ShowNum(1, 6, Numb, 5);//显示Numb的值
			OLED_ShowNum(2, 9, TIM_GetCounter(TIM2), 6);//显示计数器的值
			
		}

}


void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Numb++;
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
	
}
