#include "stm32f10x.h"                  // Device header

int16_t Encoder_count;

void Encoder_Init(void)
{
	//配置GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//配置AFIO，中断引脚选择。AFIO外设的库函数在GPIO的库函数里面
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);//中断引脚选择
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	
	//配置EXTI，边沿检测及控制
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line0 | EXTI_Line1;					//接的PB0和PB1
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//下降沿触发，PB0和PB1设置的上拉输入，默认高电平。
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	//配置NVIC，中断管理
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //优先级分组。分组方式，芯片只能用一种
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
	
}	


//返回计数值函数
int16_t Encoder_Get(void)
{
	int16_t Temp;
	Temp = Encoder_count;
	Encoder_count = 0;
	return Temp;
}


//中断函数执行程序
void EXTI0_IRQHandler(void)		//该函数名在启动文件里面找，不是随便取名的。所以也不需要包含在.h文件里
{
	if(EXTI_GetFlagStatus(EXTI_Line0) == SET)//获取标志位
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)  //PB0低电平
		{
			if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)	//PB0的下降沿触发中断，此时检测另一相PB0的电平，目的是判断旋转方向
				{
					Encoder_count --;
				}
		}
		
		EXTI_ClearFlag(EXTI_Line0); //执行完必须清除标志位，不然会一直在中断程序里
	}
}
void EXTI1_IRQHandler(void)		//该函数名在启动文件里面找，不是随便取名的。所以也不需要包含在.h文件里
{
	if(EXTI_GetFlagStatus(EXTI_Line1) == SET)//获取标志位
	{
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)  //PB1低电平
		{
			if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) //PB1的下降沿触发中断，此时检测另一相PB0的电平，目的是判断旋转方向
				{
					Encoder_count ++;
				}
		}
		EXTI_ClearFlag(EXTI_Line1); //执行完必须清除标志位，不然会一直在中断程序里
	}
}
