#ifndef LED_INCLUDED
#define LED_INCLUDED

#define LED_RED BIT6               // P1.6  P1.0 used by LCD
#define LEDS (LED_RED)

void led_init();
void led_red_on();
void led_red_off();

#endif
