/*
 * Lab4b.c
 *
 * Created: 17/11/2023 8:56:35 am
 * Author : 26672
 */ 

#include <avr/io.h>


void usart_init(){
	UCSR0B = (1<<TXEN0|1<<RXEN0);
	UCSR0C = (1<<UCSZ01|1<<UCSZ00|1<<UCSZ02);
	UBRR0L = 0x67;
}

void usart_send(unsigned char ch){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = ch; 
}

/*void usart_receive(){
	while(!(UCSR0A & (1<<RXC0)));
	ch = UDR0;
}*/

void ready()
{
    /* Replace with your application code */
	//unsigned char str[4] = "Bye!";
	unsigned char we[14] = "We Are Ready!";
	unsigned char i = 0;
	while(i<=14){
	usart_send(we[i++]);
	}
	/*i = 0;	
	while(a<=5){
		while(i<=4){
		usart_send(str[i++]);
			}
	a++;
	}*/
}

void b(){
	unsigned char str[4] = "Bye!";
	unsigned char b = 0;
	while(b<=4){
		usart_send(str[b++]);
	}
}

int main(void){
	usart_init();
	ready();
	unsigned char hi;
	while(!(UCSR0A&(1<<RXC0)));
	hi = UDR0;
	if(hi == 'h')
	{
		while(!(UCSR0A&(1<<RXC0)));
			hi = UDR0;
		if(hi == 'i')
		{
			b();
			b();
			b();
			b();
			b();
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
	return 0;
}
