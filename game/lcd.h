#ifndef LCD_INCLUDED
#define LCD_INCLUDED

#define LCD_BG COLOR_WHITE

void wdt_c_handler();
void game_loop();
void draw_screen();
void exit_game_loop();

extern short redrawScreen;

#endif

