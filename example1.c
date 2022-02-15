#define F_CPU   16000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{

	DDRA = 0xff; 
	PORTA = 0x00;

	_delay_ms(200); 



	while (1)
	{
		
		PORTA = PORTA | 0X80; // 왼쪽으로 불빛 이동
		_delay_ms(200);
		PORTA = PORTA | 0X40;
		_delay_ms(200);
		PORTA = PORTA | 0X20;
		_delay_ms(200);
		PORTA = PORTA | 0X10;
		_delay_ms(200);
		PORTA = PORTA | ~0Xf7;
		_delay_ms(200);
		PORTA = PORTA | 0X04;
		_delay_ms(200);
		PORTA = PORTA | 0X02;
		_delay_ms(200);
		PORTA = PORTA | 0X01;
		_delay_ms(200);
		PORTA = PORTA | 0X00;
		_delay_ms(200);


	
		PORTA = PORTA & 0XfE; // move the light to the right
		_delay_ms(200);
		PORTA = PORTA & 0XfC;
		_delay_ms(200);
		PORTA = PORTA & 0Xf8;
		_delay_ms(200);
		PORTA = PORTA&~0X0F;
		_delay_ms(200);
		PORTA = PORTA & 0Xe0;
		_delay_ms(200);
		PORTA = PORTA & 0Xc0;
		_delay_ms(200);
		PORTA = PORTA & 0X80;
		_delay_ms(200);
		PORTA = PORTA & 0X00;
		_delay_ms(200);



	}

}
