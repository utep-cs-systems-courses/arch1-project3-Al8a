#ifndef SQUARES_INCLUDED
#define SQUARES_INCLUDED


#define SQUARE_COUNT 6


typedef struct square_struct {
  short x, y;
  short vel_x, vel_y;
  unsigned short color;
} Square;


typedef enum square_state_enum { SQUARE_NORMAL, SQUARE_CONVERGE } SquareState;

void generate_squares();
void redraw_squares();

void square_handle_interrupts();

#endif
