#include <msp430.h>
#include <libTimer.h>
#include "led.h"
#include "lcd.h"
#include "buzzer.h"
#include "switches.h"
#include "square.h"
#include "state_machines.h"
#include "lcdutils.h"


void main()
{
  led_init();
  configureClocks();
  buzzer_init();
  lcd_init();
  switch_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	                /**< GIE (enable interrupts) */
  game_loop();  
  update_state();
}



/* Switch on S2 */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	      /* single handler for all switches */
  }
}
