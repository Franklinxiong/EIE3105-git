/*
 * Lab1B.cpp
 *
 * Created: 29/9/2023 8:46:24 am
 * Author : 21097015D
 */ 

#include <avr/io.h>

int count = 0;
int main(void)
{
	DDRD = 0xFF;
	DDRB = 0X00;
    /* Replace with your application code */
    while (1) 
    {
	//if(PINB & (1<<PINB0)){//For 1B2
		//count = ~count;
	//}
		if(PINB & (1<<PINB0)){// count == 0 when 1B2
			PORTD = 0x04;
		}else{
			PORTD = 0x00;
		}
		
    }
}

