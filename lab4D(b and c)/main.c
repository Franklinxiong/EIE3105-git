/*
 * Lab4E.c
 *
 * Created: 19/11/2023 8:40:39 pm
 * Author : 26672
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
void usart_init()//initiallize
{
	UCSR0B = (1<<TXEN0|1<<RXEN0|1<<RXCIE0);
	UCSR0C = (1<<UCSZ01|1<<UCSZ00|1<<UCSZ02);
	UBRR0L = 0x67;
}

void usart_send(unsigned char ch)//send data to serial
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = ch;
}

unsigned char cop;
unsigned char rec;

int main(void)
{
    usart_init();
	sei();
	while(1)
	{
		usart_send('a');
	}
}
ISR(USART_RX_vect)
{
	rec = UDR0;
	for(int i=0;i<10;i++)
	{
		usart_send(rec);
	}
	cop = rec;
	rec = 0x00;
	do 
	{
		rec = UDR0;	
	} while (cop != rec);
}

