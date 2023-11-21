/*
 * Lab2A.cpp
 *
 * Created: 29/9/2023 9:28:22 am
 * Author : 21097015D
 */ 

#include <avr/io.h>
void delay_nom(int scaler){
	int i;
	for(i = 0;i<=scaler; i++){
	TCNT0 = 0x00;
	TCCR0B = 0x05;//1024 perscalar
	// a cycle should be 16Mhz/1024=6.4*10^-5s
	while((TIFR0&1) == 0);
	TIFR0 = 0x01;//clear tov0
	TCCR0B = 0x00;//turn off timer 0
	//delay 256*6.4*10^-5s
	}
}

void delay_CTC(int scalar){
	TCCR2B = 0x07;//perscalar 1024
	//cycle = 16Mhz/1024
	TCCR2A = 0x02;//CTC mode for timer2
	int i;
	for(i = 0;i<=scalar; i++){
		OCR2A = 255;//256 perscalars
		while((TIFR2&0x02) == 0);
		TCCR2A = 0;
		TIFR2 = 0x02;//clear flag
	}
	OCR2A = 0x00;
	TCCR2B = 0x00;
}

int main(void)
{
	DDRB = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		PORTB = 0xFF;
		delay_CTC(61);
		PORTB = 0x00;
		delay_CTC(61);
    }
}

