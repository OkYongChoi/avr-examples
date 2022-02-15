#define F_CPU   16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRA = 0xff;
	PORTA = 0x00;

	DDRE = 0x0f; 
	PORTE = 0xf0; 

	while (1) {
		if (PINE == 0x80) { // on and off
			PORTA = 0x00;
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

		if (PINE == 0x40) { // light moves from side to side
			PORTA = 0b10000001;
			_delay_ms(100);
			PORTA = 0b01000010;
			_delay_ms(100);
			PORTA = 0b00100100;
			_delay_ms(100);
			PORTA = 0b00011000;
			_delay_ms(100);
			PORTA = 0b00100100;
			_delay_ms(100);
			PORTA = 0b01000010;
			_delay_ms(100);
			PORTA = 0b10000001;
			_delay_ms(100);
		}

		if (PINE == 0x20) { // light shift to the right
            PORTA = 0x00;
			_delay_ms(100);
			PORTA = 0b11000000;
			_delay_ms(100);
			PORTA = 0b11000000 >> 2;
			_delay_ms(100);
			PORTA = 0b11000000 >> 4;
			_delay_ms(100);
			PORTA = 0b11000000 >> 6;
			_delay_ms(100);
			PORTA = 0b11000000 >> 8;
		}
		if (PINE == 0x10) { // lights up randomly
			PORTA = rand();
			_delay_ms(100);
        }
	}
}
