#define F_CPU   16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int i = 0;

ISR(INT4_vect) { // Interrupt 4 (Switch 4) 
	PORTA = 0b10101010;
	_delay_ms(100);
	PORTA = ~PORTA;
	_delay_ms(100);
    PORTA = ~PORTA;
	_delay_ms(100);
    PORTA = ~PORTA;
	_delay_ms(100);
}

ISR(INT5_vect) { // Interrupt 5 (Switch 5)  on and off
	PORTA = 0xff;
	_delay_ms(100);
	PORTA = ~PORTA;
	_delay_ms(100);
	PORTA = ~PORTA;
	_delay_ms(100);
	PORTA = ~PORTA;
	_delay_ms(100);
	PORTA = ~PORTA;
	_delay_ms(100);
}

ISR(INT6_vect) { // Interrupt 6 (Switch 6) lights off from the end
	PORTA = 0xff;
	_delay_ms(200);
	PORTA = PORTA & 0x7E;
	_delay_ms(200);
	PORTA = PORTA & 0x3C;
	_delay_ms(200);
	PORTA = PORTA & 0x18;
	_delay_ms(200);
	PORTA = PORTA & 0x00;
	_delay_ms(200);
	PORTA = PORTA | 0x18;
	_delay_ms(200);
	PORTA = PORTA | 0x3C;
	_delay_ms(200);
	PORTA = PORTA | 0x7E;
	_delay_ms(200);
	PORTA = PORTA | 0xff;
	_delay_ms(200);
}

SIGNAL(INT7_vect) { // Switch 7 siren at the falling edge
	for(i=0 ; i < 10 ; i++){
        PORTA = 0b01100000;
        _delay_ms(100);
        PORTA = 0b00000110;
        _delay_ms(100);
	}
}

int main(void) {
	DDRA = 0xff; 
	PORTA = 0x00;

	EICRB = 0b10111111;// 4 5 6 rising edge, 7 falling edge 
	
	EIMSK = 0xF0;// PE4-7 : Interrupt enable

	sei(); // global interrupt enbled

	while (1) {	
		PORTA = PORTA | 0X80;
		_delay_ms(50);
		PORTA = PORTA | 0X40;
		_delay_ms(50);
		PORTA = PORTA | 0X20;
		_delay_ms(50);
		PORTA = PORTA | 0X10;
		_delay_ms(50);
		PORTA = PORTA | ~0Xf7;
		_delay_ms(50);
		PORTA = PORTA | 0X04;
		_delay_ms(50);
		PORTA = PORTA | 0X02;
		_delay_ms(50);
		PORTA = PORTA | 0X01;
		_delay_ms(50);
		PORTA = PORTA | 0X00;
		_delay_ms(50);


		PORTA = PORTA & 0XfE; 
		_delay_ms(50);
		PORTA = PORTA & 0XfC;
		_delay_ms(50);
		PORTA = PORTA & 0Xf8;
		_delay_ms(50);
		PORTA = PORTA&~0X0F;
		_delay_ms(50);
		PORTA = PORTA & 0Xe0;
		_delay_ms(50);
		PORTA = PORTA & 0Xc0;
		_delay_ms(50);
		PORTA = PORTA & 0X80;
		_delay_ms(50);
		PORTA = PORTA & 0X00;
		_delay_ms(50);
	}
}