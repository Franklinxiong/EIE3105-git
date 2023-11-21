/*
 * lab4c.c
 *
 * Created: 17/11/2023 11:17:37 am
 * Author : 26672
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
void usart_init()//initiallize
{
	UCSR0B = (1<<TXEN0|1<<RXEN0);
	UCSR0C = (1<<UCSZ01|1<<UCSZ00|1<<UCSZ02);
	UBRR0L = 0x67;
}

void usart_send(unsigned char ch)//send data to serial
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = ch;
}

void usart_receive(unsigned char recieve)//receive data and store to receieve
{
	while(!(UCSR0A & (1<<RXC0)));
	recieve = UDR0;
}

int main(void)
{
	usart_init();
	unsigned char rec;
	unsigned char cop;//used to compare with rec
	while(1)
	{
		do 
		{
			usart_send('a');
		} while (!(UCSR0A & (1<<RXC0)));//when ready to receive
		rec=UDR0;//directly read UDR0
		for(int i=0;i<=10;i++)
		{
			usart_send(rec);
		}
		cop=rec;
		rec=0x00;
		do 
		{
			rec=UDR0;//no need to call recieve function, it will stop the program
		} while (rec!=cop);
	}
}