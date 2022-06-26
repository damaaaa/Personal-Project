/*
 */

#include <avr/io.h>
#include "hcsr04.h"
#include "uart.h"

int main(void)
{

    // Insert code
    uint8_t distance;

    hcsr04_init();
    uart_init();

    while(1)
    {
        trigger_ultrasonic();
        _delay_ms(1000);
        distance = get_distance();
        uart_print_string("distance(cm) = ");
        uart_print_8bit_num(distance);
        uart_string_transmit("\r\n");
    }


    return 0;
}

ISR(PCINT0_vect)
{
    sbi(PCIFR, PCIF0);  //PCINT0 flag clear
    if((PORTB & ECHO) == 1)
    {
        //Clock select : 16MHz / 8 = 2MHz Timer start
        TCNT0 = 0;
        cbi(TCCR0B, CS02);
        sbi(TCCR0B, CS01);
        cbi(TCCR0B, CS00);
    }
    else if((PORTB & ECHO) == 0)
    {
        duration = TCNT0 * 0.5; //1 tick에 0.5us
        cbi(TCCR0B, CS02 | CS01 | CS00);    //Timer stop
    }
}
