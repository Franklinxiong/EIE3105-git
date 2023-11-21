/*
 * Lab1A.c
 *
 * Created: 22/9/2023 8:50:28 am
 * Author : 21097015D
 */ 

#include <avr/io.h>

//void delay1s(void){
//	unsigned int a = 0;
	//for(a=0;a<421500;a++);
//}
int main(void)
{
    /* Replace with your application code */
	DDRD = 0xFF;
	//DDRB = 0xFF;
    while (1) 
    {
	if((PINB & (1<< PINB0)) == (1 << PINB0)){
		unsigned long a = 0;
		PORTD = 0x55;
		for(a=0;a<421500;a++);
		//delay1s(1);
		PORTD = 0xAA;
		for(a=0;a<421500;a++);
		//delay1s(1);
		}else{
		PORTD = 0x00;
    }
}

