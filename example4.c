#define F_CPU 16000000UL
 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
 
int n = 156;
/* Since it operates at 16MHZ, which is a ctc mode with a division ratio of 256,
 16000000/(2*256) = 31250, 1/31250 = 0.000032,
  and multiplying this by 200, the OCR2A value, is 0.0064 seconds. 
  To make 1 second, you need to count 156 times (156*0.0064 = 0.9984), 
  so the initial value of n is 156. */
int now = 0;

void ctcmode() {
   DDRA = 0XFF;
   PORTA = 0X00;
   TCCR0A |=0X08; // 1024 CTC mode
   TCCR0A |=0X00; // normal port operation
   TCCR0A |=0X04; // prescaler 256
   TIMSK0 = 0x02; // Allow output compare interrupt
 
   TCNT0 = 0X00; // Set the counting register TCNT0 to 0.   
   OCR0A = 199; // Substitute 200-1 into OCR2A
}
 
ISR(TIMER0_COMP_vect) { // Timer Compare Interrupt
    n--; 
    if(n==0) {
        if(now==0) {
       		PORTA = 0xff;
            _delay_ms(100);

            PORTA = 0x00;
            _delay_ms(100);
        
            PORTA = 0xff;
            _delay_ms(100);

            PORTA = 0x00;
            _delay_ms(100);
        
            PORTA = 0b10000001;
            _delay_ms(100);

            PORTA = 0b01000010;
            _delay_ms(100);
        
            PORTA = 0b00100100;
            _delay_ms(100);

            PORTA = 0b00011000;
            _delay_ms(100);

        
            PORTA = 0xff;
            _delay_ms(100);

            PORTA = 0x00;
            _delay_ms(100);
        
            PORTA = 0xff;
            _delay_ms(100);

            PORTA = 0x00;
            _delay_ms(100);
            
            now = 1;
        }
        else {
            now = 0;
        }
        n=156;
    }
}

int main(void) {
    ctcmode(); // Call the ctcmode function
    sei(); // allow interruption
    while(1){}
}
