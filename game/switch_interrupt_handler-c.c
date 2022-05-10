#include "switches.h"
#include <msp430.h>


int  sw1_status = 0;
int  sw2_status = 0;
int  sw3_status = 0;
int  sw4_status = 0;

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switches = ~p2val & SWITCHES;


  int prev_status_sw1 = sw1_status;
  int prev_status_sw2 = sw2_status;
  int prev_status_sw3 = sw3_status;
  int prev_status_sw4 = sw4_status;

  // Checks if button has been pressed
  sw1_status = (p2val & SW1) ? 0 : 1;
  sw2_status = (p2val & SW2) ? 0 : 1;
  sw3_status = (p2val & SW3) ? 0 : 1;
  sw4_status = (p2val & SW4) ? 0 : 1;

  // Switch Selection and reset
  if( (prev_status_sw1 != sw1_status) && sw1_status){
    sw1_press_state ^= 1;
    sw2_press_state = 0;
    sw3_press_state = 0; 
    sw4_press_state = 0;
  }
  else if( (prev_status_sw2 != sw2_status) && sw2_status){
    sw2_press_state ^= 1;
    sw1_press_state = 0; 
    sw3_press_state = 0;
    sw4_press_state = 0;
  }
  else if( (prev_status_sw3 != sw3_status) && sw3_status){
    sw3_press_state ^= 1;
    sw1_press_state = 0; 
    sw2_press_state = 0;
    sw4_press_state = 0;
  }
  else if ( (prev_status_sw4 != sw4_status) && sw4_status){
    sw4_press_state ^= 1;
    sw1_press_state = 0;
    sw2_press_state = 0; 
    sw3_press_state = 0;
  }
}
