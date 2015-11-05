/*
 * GccApplication1.c
 *
 * Created: 2015-11-05 08:48:41
 *  Author: Administrator
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0x00;
	PORTB = 0b0000001;
	
	while(1)
    {
		/*
		if (!(PINB & 0x01))
	{
		for(int i = 0; i <= 7; i++)
		{
			PORTA = 1 << i;
			_delay_ms(100);
		}	
		for(int i = 7; i >= 0; i--)
		{
			PORTA = 1 << i;
			_delay_ms(100);
		}	
	}
	else
	{
		PORTA = 0b11111111;
		
	}
	*/
		if (!(PINB & 0x01))
		{
			int x = 0;
			
			while(x < 1000)
			{
				x+=1;
				PORTA = 0b00000000;
				_delay_us(x);
				PORTA = 0b11111111;
				_delay_us(1000 - x);
			
			}
			x = 0;
			while(x < 1000)
			{
				x+=1;
				PORTA = 0b11111111;
				_delay_us(x);
				PORTA = 0b00000000;
				_delay_us(1000 - x);
			
			}
		}
		else
		{
			PORTA = 0b11111111;
			
		}
		
		
    }
}