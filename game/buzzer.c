#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"

BuzzerState buzzer_state = BUZZER_OFF;

void buzzer_init()
{
  timerAUpmode();                     // Used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;                      // Enable output to speaker (P2.6)
}



void buzzer_set_period(short cycles) // Buzzer clock = 2Mhz
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;                // One half cycle
}


buzzer_timer_interrupt()
{
}



void buzzer_stop()
{
  buzzer_set_period(0);
  buzzer_state = BUZZER_OFF;
}


