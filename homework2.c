#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void init()
{	
	//leds
	DDRB = 0xFF;                        
	PORTB = 0; 
	DDRC &= ~(_BV(PD2));                
	PORTC |= _BV(PD2);
	DDRD = 0xFF;
	PORTD = 0;

	// Interruption on INT0
	GICR |= _BV(INT0);
	MCUCR |= _BV(ISC01) | _BV(ISC00);
	sei();
}

ISR(INT0_vect) //interruption
{
	PORTB++;
}

int main(void)
{
	init();
	while (1)
	{
		PORTD++;
		_delay_ms(500);
	}
}