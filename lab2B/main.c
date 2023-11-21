/*
 * Lab2B.c
 *
 * Created: 5/10/2023 下午5:52:44
 * Author : 86152
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
	TCCR2B = 0x07;//1024 perscalar
	//cycle = 16Mhz/1024
	TCCR2A = 0x02;//CTC mode for timer2
	int i;
	for(i = 0;i<=scalar; i++){
		OCR2A = 255;//256 perscalar
		while((TIFR2&0x02) == 0);
		TCCR2A = 0;
		TIFR2 = 0x02;//clear flag
	}
	OCR2A = 0x00;
	TCCR2B = 0x00;
}


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		int a = 0;
		DDRB=0xFF;
		DDRC=0xFF;
		PORTB=0X21;//1
		PORTC=0x10;
		delay_nom(61*5);
		//delay_CTC(61*5);
		PORTB=0x11;//2
		PORTC=0x10;
		delay_nom(61);
		//delay_CTC(61);
		PORTB=0x09;//3
		PORTC=0x10;
		delay_nom(61);
		//delay_CTC(61);
		PORTB=0x0B;//4
		PORTC=0x10;
		delay_nom(61);
		//delay_CTC(61);
		PORTB=0x0C;//5
		PORTC=0x20;
		delay_nom(61*5);
		//delay_CTC(61*5);
		PORTB=0x0A;//6
		while(a<=30){
			PORTC=0x20;
			delay_nom(1);
			//delay_CTC(1);
			PORTC=0x00;
			delay_nom(1);
			//delay_CTC(1);
			a ++;
		}
		//delay_nom(61);
		//delay_CTC(61);
		PORTB=0x09;//7
		PORTC=0x10;
		delay_nom(61);
		//delay_CTC(61);
		PORTB=0x19;//8
		PORTC=0x10;
		delay_nom(61);
		//delay_CTC(61);
		
		
    }
}

