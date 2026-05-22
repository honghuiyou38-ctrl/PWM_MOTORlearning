#include "reg52.h"
#include <intrins.h>
#include <delay.h>
#include <uart.h>
#include <main.h>
#include "Timer.h"

uchar recv;
uchar TIM_count_0=0;
uchar Level=5;

void main()
{
	Timer0_INTrupt();
	EA=1;
	
  while(1)
  {		

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
