#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd.h"
#include "led.h"
#include "square.h"



void game_loop()
{
  clearScreen(LCD_BG);
  generate_squares();

  while (1) {
    if (redrawScreen) {
      redrawScreen = 0;
      draw_screen();
    }

    led_red_off();        // P1OUT &= LED
    or_sr(0x10);	  /**< CPU OFF */
    led_red_on();         // P1OUT |= LED
  }
}



void draw_screen()
{
  redraw_squares();
}
