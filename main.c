//stable button & led pattern with external interrupt 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
unsigned char press_no;

int main(void)
{

	DDRB=0x0F;				//Define as output

	sei();							//Global interrupt enabled
	GICR=(1<<INT0);		//External Interrupt 0 (local interrupt) Enabled
	MCUCR=(1<<ISC01)|(1<<ISC00);	//Interrupt On Rising Edge

	while (1)				//infinite loop
	{
		///////////Led patterns according to number of button pressed////
		switch(press_no)
		{
			case 0:
					PORTB=0X00;
					break;
			case 1:
					PORTB=0X01;
					break;
			case 2:
					PORTB=0X02;
					break;
			case 3:
					PORTB=0X04;
					break;
			case 4:
					PORTB=0X08;
					break;
			case 5:
					PORTB=0X00;
					press_no=0;
					break;
		}
	}
}


ISR(INT0_vect)		//This ISR will be executed when button goes high from low
{
	press_no++;			//increment your data by 1
}




