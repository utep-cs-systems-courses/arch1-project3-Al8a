#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd.h"
#include "led.h"
#include "square.h"
#include "switches.h"
#include "buzzer_notes.h"
#include "state_machines.h"
#include "buzzer.h"



short redrawScreen = 0;

int sw1_press_state = 0;
int sw2_press_state = 0;
int sw3_press_state = 0;
int sw4_press_state = 0;
int current_switch = 0;


void wdt_c_handler()
{
  static int second_count = 0;
  static int second_count_2 = 0;

  
  second_count_2++;
  if((second_count_2 % 51 == 0) && sw1_press_state == 1 ){
    current_switch = SW1; 
    update_state(current_switch);
    second_count_2 = 0;
  }

  if((second_count_2 % 32 == 0) && sw2_press_state == 1 ){
    current_switch = SW2; 
    update_state(current_switch);
    second_count_2 = 0;
  }

  if((second_count_2 % 63 == 0) && sw3_press_state == 1 ){
    current_switch = SW3; 
    update_state(current_switch);
    second_count_2 = 0;
  }

  second_count++;
  if (second_count >= 8) { // about 60 fps
    second_count = 0;
    redrawScreen = 1;
  }

}
