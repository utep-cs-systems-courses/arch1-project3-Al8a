/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);
  fillRectangle(60,60, 30, 30, COLOR_ORANGE);
  drawString11x16(20,80, "hello", COLOR_GREEN, COLOR_RED);
  drawString8x12(20,100, "howdy", COLOR_GREEN, COLOR_RED);
  drawString5x7(20,130, "goose", COLOR_GREEN, COLOR_RED);
  
  int a, length = 20;
  int fCol = 50, fRow = 50;

  // 160 width
  // 120 height

  
  // Triangle
  for ( a = 0; a < length; a++){
    drawPixel(fCol + a ,fRow + a, COLOR_RED);
    drawPixel(fCol + a,fRow, COLOR_BLUE);
    drawPixel(fCol+length,fRow+a,COLOR_WHITE);
  
    if(a % 2 == 1){
      for(int v = 0; v < a; v++){
	drawPixel(fCol + a, fRow + v, COLOR_PURPLE);
	drawPixel((fRow + length) - v , (fCol +length) - a , COLOR_BLACK);
      }
    }
  }
  
  // Asteriks 
  int sCol = 50, sRow = 100;
  int s;
 
  for(s = 0; s < length; s++){
    drawPixel(sCol+s, sRow+s, COLOR_BLACK);             // diagonal
    drawPixel((sCol+(length/2)),sRow + s, COLOR_BLACK); // middle line
    drawPixel(sCol+s, (sRow+(length/2)),COLOR_BLACK);   // horizontal line
    drawPixel((sCol+length)-s, sRow+s,COLOR_BLACK);     // Other diagonal
  }
}
