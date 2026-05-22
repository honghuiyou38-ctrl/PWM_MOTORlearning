#include <key.h>
#include <main.h>
#include <delay.h>


uchar Key_scan()
{
		if(KEY1==0)
		{
			Delay_xms(20);
			while(KEY1==0);
			Delay_xms(20);
			return 1;
		}
		
		if(KEY2==0)
		{
			Delay_xms(20);
			while(KEY2==0);
			Delay_xms(20);
			return 2;
		}
		
		return 0;
}