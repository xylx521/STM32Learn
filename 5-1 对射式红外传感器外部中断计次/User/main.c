#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Countsensor.h"

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Countsensor_Init(); //红外计数传感器初始化
	
	
	/*OLED显示*/
	
	OLED_ShowString(1, 1, "Count:");	//1行1列显示字符串Count:
	
	while (1)
	{
		OLED_ShowNum(1, 7, Countsensor_Get(), 5);
	}
}

