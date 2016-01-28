#include <avr/io.h>
#include <util/delay.h>

int x,s1,s2,s3,s4,num,count = 0;

void main(void)
{
	// numbers in binary
	uint8_t number[10]; 
	number[0] = ~0b00111111;
	number[1] = ~0b00000110;
	number[2] = ~0b01011011;
	number[3] = ~0b01001111;
	number[4] = ~0b01100110;
	number[5] = ~0b01101101;
	number[6] = ~0b01111101;
	number[7] = ~0b00000111;
	number[8] = ~0b01111111;
	number[9] = ~0b01101111;

	//init
	DDRC = ~0x00; 
	DDRB = ~0x00;
	PORTC = ~0x00;
	PORTB = ~0x00;
	
	while(1)
	{
		count++;
		if (count > 9999) //counter reset
		{
			count = 0;
		}
		
		num = count;
		s1 = num/1000; //thousands
		num=num%1000;
		s2 = num/100; //hundreds
		num=num%100;
		s3 = num/10; //dozens
		s4 = num%10; //units
		
		for (x = 0; x <=30; x++)
		{
			// alternately show the digits of number
			PORTC = 0b00010111; 
			PORTB = number[s1];
			_delay_ms(10);
			PORTC = 0b00011011;
			PORTB = number[s2];
			_delay_ms(10);
			PORTC =  0b00011101;
			PORTB = number[s3];
			_delay_ms(10);
			PORTC =  0b00011110;
			PORTB = number[s4];
			_delay_ms(10);
		}
	}
}
