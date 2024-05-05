/*
 * blinky.c
 *
 * Created: 05/05/2024 00:58:09
 * Author : kami
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(void)
{
	PORTB = (1<<PB5|1<<PB4); // PB5 high and DDRB5 low gives us input with pullup. also start off with output PB4 high
	DDRB = (1<<DDB4|1<<DDB3|1<<DDB2|1<<DDB1|1<<DDB0); // define direction of pins PB4 to PB0 as output. everything else input with pullup
    unsigned char direction;
    
    while (1) {
	    if(direction) {
		    PORTB = (PORTB << 1); // shift bits left in PORTB left
		    if(PORTB == 0b00010000) {
			    direction = 0;
		    }
		    } else {
		    PORTB = (PORTB >> 1); // shift bits in PORTB right
		    if(PORTB == 0b00000001) {
			    direction = 1;
		    }
	    }
	    _delay_ms(BLINK_DELAY_MS);
		}
}

