#include <avr/io.h>
#include <util/delay.h>

uint8_t Scan()
{
	int row,col;

	PORTC |= 0X0F;
	for(col = 0; col < 3;col++) // iterate col
	{
		DDRC&=~(0X7F);
		DDRC|=(0X40>>col);

		for(row = 0; row < 4; row++) // if col live than find row
		{
			if(!(PINC & (0X08>>row)))
			{
				return (row*3+col+1);
			}
		}
	}
	return 0;
}

void main()
{
	uint8_t key;
	DDRB = 0xFF;
	while(1)
	{
		key=Scan();
		switch(key)
		{
			case 0:
			PORTB = ~0b00000001;
			break;
			case 1:
			PORTB = ~0b00000010;
			break;
			case 2:
			PORTB = ~0b00000100;
			break;
			case 3:
			PORTB = ~0b00001000;
			break;
			case 4:
			PORTB = ~0b00010000;
			break;
			case 5:
			PORTB = ~0b00100000;
			break;
			case 6:
			PORTB = ~0b01000000;
			break;
			case 7:
			PORTB = ~0b10000000;
			break;
		}
	}
}




