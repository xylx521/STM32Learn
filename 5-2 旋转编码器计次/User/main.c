#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"


int16_t Numb = 0;
int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Encoder_Init();		//旋转编码器初始化
	
	/*OLED显示*/
	
	OLED_ShowString(1, 1, "Numb:");	//1行1列显示字符串Numb:
	
	while (1)
	{
		Numb += Encoder_Get();
		OLED_ShowSignedNum(1, 6 , Numb, 6);
	}
}

