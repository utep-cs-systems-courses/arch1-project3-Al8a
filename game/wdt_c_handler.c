#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd.h"
#include "led.h"
#include "square.h"




short redrawScreen = 0;


void wdt_c_handler()
{
  static int secCount = 0;
  secCount ++;

  if (secCount >= 8) { // about 60 fps
    secCount = 0;
    redrawScreen = 1;
  }
}
