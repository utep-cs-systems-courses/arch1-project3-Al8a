#ifndef BUZZER_INCLUDED
#define BUZZER_INCLUDED


typedef enum BuzzerState{ BUZZER_PLAYING, BUZZER_OFF } BuzzerState;

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_stop();
void buzzer_timer_interrupt();

#endif
