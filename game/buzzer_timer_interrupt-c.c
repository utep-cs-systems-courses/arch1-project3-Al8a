#include "buzzer.h"
#include "switches.h"
#include "led.h"
#include "state_machines.h"


extern BuzzerState buzzer_state;

void buzzer_timer_interrupt()
{
  switch(buzzer_state){
  case BUZZER_OFF:
    return;
  case BUZZER_PLAYING:
    play_song_2();
  }
}
