#include "reg52.h"
#include "Timer.h"

void Timer0_INTrupt()
{
	TMOD&=0xF0;
	TMOD|=0x01;
	TH0=0xDC;
	TL0=0x00;
	TF0=0;
	TR0=1;
	ET0=1;
}

void Timer1_INTrupt()
{
	TMOD&=0x0F;
	TMOD|=0x10;
	TH1=0xDC;
	TL1=0x00;
	TF1=0;
	TR1=1;
	ET1=1;
}