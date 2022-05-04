#include <msp430.h>
#include "buzzer.h"
#include "switches.h"
#include "buzzer_notes.h"
#include "state_machines.h"
#include "lcd.h"
#include "lcdutils.h"
#include "lcddraw.h"




// GREEN HILLS ZONE
void play_song_1()
{
  static char curr_note = 0;
  // All notes of song, 0s are for break in between notes
  int notes[45] = {C5, A4, C5, 0, B4, C5, B4, B4, G4, G4, G4, 0, G4, E5, D5_SHARP, D5_SHARP, C5, B4, B4, G4, G4, G4, 0, C5, A4, C5,0, B4, C5, 0, B4, G4,0, 0, A4, A4, F4, A4, G4, A4, G4, C4, 0, C5, 0};
  int n = 45;

  if (curr_note < n){
    buzzer_set_period(notes[curr_note]);
    curr_note++;
  }else
    curr_note = 0;
}




// TETRIS THEME
void play_song_2()
{
  static char curr_note = 0;  
  int notes[37] = {G5, D5, E5_FLAT, F5, E5_FLAT, D5, C5, 0, C5, E5_FLAT, G5, F5, E5_FLAT, D5, E5_FLAT, F5, G5, E5_FLAT, C5, 0, C5, 0, 0, 0, F5, A5_FLAT, C6_SHARP, B5_FLAT, A5_FLAT, G5, F5, G5, E5_FLAT, C5, 0, C5, 0}; 
  int n = 37;

  if (curr_note < n){
    buzzer_set_period(notes[curr_note]);
    curr_note++;
  }else
    // LOOP SONG 
    curr_note = 0;
}




// OVERLOAD OPENING
void play_song_3()
{
  static char curr_note = 0;
  switch(curr_note){
  case 0:
    buzzer_set_period(C6_SHARP);
    curr_note++;
    break;
  case 1:
    buzzer_set_period(F6_SHARP);
    curr_note++;
    break;
  case 2:
    buzzer_set_period(G6_SHARP);
    curr_note++;
    break;
  case 3:
    buzzer_set_period(A6);
    curr_note++;
    break;
  case 5: 
    buzzer_set_period(C6_SHARP);
    curr_note++;
    break;
  case 7:
    buzzer_set_period(F6_SHARP);
    curr_note++;
    break;
  case 8:  
    buzzer_set_period(G6_SHARP);
    curr_note++;
    break;
  case 10:  
    buzzer_set_period(A6);
    curr_note++;
    break;
  case 14:
    buzzer_set_period(D6);
    curr_note++;
    break;
  case 15:
    buzzer_set_period(F6_SHARP);
    curr_note++;
    break;
  case 16:                              
    buzzer_set_period(G6_SHARP);
    curr_note++;
    break;
  case 18:
    buzzer_set_period(D6);
    curr_note++;
    break;
  case 20:
    buzzer_set_period(F6_SHARP);
    curr_note++;
    break;
  case 21:
    buzzer_set_period(G6_SHARP);
    curr_note++;
    break;
  case 22:
    buzzer_set_period(A6);
    curr_note++;
    break;
  case 26:                              // LOOP BACK TO BEGINNING
    buzzer_set_period(0);
    curr_note = 0;
    break;
  default:
    curr_note++;
    break;
  }
}



int switches = 0;

void update_state(int current_switch)
{

  if(current_switch == (switches & SW1)){
    play_song_1();
  }
  else buzzer_stop();

  if(current_switch == (switches & SW2)){
    display_text();
  }
  if(current_switch == (switches & SW3)){
    //draw_character();
    clearScreen(COLOR_BLUE);
  }
  if(current_switch == (switches & SW4)){
    reset_game();
    display_reset_text();
  }
 
}



void reset_game(){
  clearScreen(COLOR_BLACK);
  buzzer_stop();
}



void display_text(){
  drawString8x12(20,100, "HOWDY", COLOR_BLACK, COLOR_YELLOW);
}



void display_reset_text()
{
  clearScreen(COLOR_RED);
  fillRectangle(80,80,60,60,COLOR_ORANGE);
  drawString11x16(20,80,"GOODBYE", COLOR_BLACK, COLOR_WHITE);
  
}
