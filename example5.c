#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

char go;
char back;

ISR(INT4_vect) { // duty 50%
    back=0;
    _delay_ms(200);
    go=128;
}

ISR(INT5_vect) { // duty 20%
    go=51;
    _delay_ms(200);
    back=0;
}

ISR(INT6_vect) { // reverse rotation
    go=0;
    _delay_ms(200);
    back=0xff;
}

ISR(INT7_vect) { // stop
    back=0;
    go=0;  
}

int main(void) {
   
    DDRB = 0xff;  
    DDRD = 0xff;

    PORTD = 0xff;
    DDRA = 0xff;

    EICRB = 0xff; // interrupt
    EIMSK = 0xf0;

    TCCR1A = 0b10100101; // fast pwm mode , 8bit
    TCCR1B = 0b00000100; // prescaler 256
    TCCR1C = 0x0;

    OCR1B = 0x00ff;

    back = 0;
    go = 0xff; // rotate normally

    while(1) {
       cli();
       OCR1A = back;
       OCR1B = go;
       sei();
    }
}