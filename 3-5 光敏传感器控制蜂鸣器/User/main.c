#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LightSenSor.h"
#include "Buzzer.h"

int main()
{
	Buzzer_Init();
	Light_Init();
	
	while(1)
	{
	if(LightSenSor_Get() == 1)
	{
		Buzzer_ON();
	}
	else
	{
		Buzzer_OFF();
	}
		
	}
	
}
