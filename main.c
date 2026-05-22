#include "reg52.h"
#include <intrins.h>
#include <delay.h>
#include <uart.h>
#include <main.h>
#include "Timer.h"
#include <IIC.h>
#include "oled.h"

uchar recv;
uchar TIM_count_0=0;
uchar Level=0;
uchar keynum;

void main()
{
	OLED_Init();
	OLED_Clear();
	OLED_ShowString(26,0,"MotorB Test",16);
	OLED_ShowString(0,2,"Level:",16);
	Timer0_INTrupt();
	EA=1;
	
  while(1)
  {		
		keynum=key_scan();
		
		if(keynum==1)
		{
			Level++;
			if(Level>10)
			Level=0;
		}
		
		if(keynum==2)
		{
			if(Level>0)
			Level--;
		}
		OLED_ShowNum(48,2,Level,2,16);
	}
 
}

void TIM_Routine() interrupt 1
{
	TH0=0xDC;
	TL0=0x00;
	TIM_count_0++;
	TIM_count_0=TIM_count_0%10;
	if(TIM_count_0<Level)
	{
		PWM_IO=1;
	}
	else
	{
		PWM_IO=0;
	}
	
	
}
