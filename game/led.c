#include <msp430.h>
#include "libTimer.h"
#include "led.h"



void led_init(void)
{
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
}



void led_red_on(void)
{
  P1OUT |= LED_RED;             // SET LED
}



void led_red_off(void)
{
  P1OUT &= ~LED_RED;            // CLEAR LED
}
