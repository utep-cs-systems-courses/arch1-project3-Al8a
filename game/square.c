#include <stdlib.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "square.h"
#include "lcd.h"
#include "switches.h"
#include "buzzer.h"
#include "buzzer_notes.h"


#define SQUARE_SIZE 4

extern int switches;

static Square *squares;
//static SquareState square_state = SQUARES_IDLE;

void generate_squares()
{
  squares = calloc(SQUARE_COUNT, sizeof(Square));
  unsigned short colors[] = { COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_PURPLE, COLOR_BROWN, COLOR_YELLOW };

  unsigned short spacing = (screenWidth - (SQUARE_SIZE * SQUARE_COUNT)) / (SQUARE_COUNT + 1);

  for (char i = 0; i < SQUARE_COUNT; ++i) {
    squares[i].x = spacing * (i + 1) + SQUARE_SIZE * i;
    squares[i].y = (screenHeight / 2) - (SQUARE_SIZE / 2);

    squares[i].vel_x = 1 * (i + 1);
    squares[i].vel_y = 1 * (i + 1);
    squares[i].color = colors[i];
  }
}



static void pre_update()
{
  for (char i = 0; i < SQUARE_COUNT; ++i) {
    fillRectangle(squares[i].x, squares[i].y, SQUARE_SIZE, SQUARE_SIZE, LCD_BG);
  }
}



static void update_square(Square *square)
{
  // Apply velocity
  square->x += square->vel_x;
  square->y += square->vel_y;

  
  //  Wall collisions
  if (square->x + SQUARE_SIZE > screenWidth) {
    square->x = screenWidth - SQUARE_SIZE;
    square->vel_x *= -1;                         // Flip direction
  }
  else if (square->x < 0) {
    square->x = 0;
    square->vel_x *= -1;                         // Flip direction
  }

  if (square->y + SQUARE_SIZE > screenHeight) {
    square->y = screenHeight - SQUARE_SIZE;
    square->vel_y *= -1;                         // Flip direction
  }
  else if (square->y < 0) {
    square->y = 0;
    square->vel_y *= -1;                         // Flip direction
  }
}



static void update_squares()
{
  for (char i = 0; i < SQUARE_COUNT; ++i) {
    update_square(squares + i);
  }

}



static void post_update()
{
  for (char i = 0; i < SQUARE_COUNT; ++i) {
    fillRectangle(squares[i].x, squares[i].y, SQUARE_SIZE, SQUARE_SIZE, squares[i].color);
  }
}



void redraw_squares()
{
  pre_update();     // Remove old ball
  update_squares(); // Update position
  post_update();    // Draw at new positions
}
