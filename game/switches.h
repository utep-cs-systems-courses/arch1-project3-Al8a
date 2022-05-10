#ifndef SWITCHES_INCLUDED
#define SWITCHES_INCLUDED

#define SW1 1
#define SW2 2
#define SW3 4
#define SW4 8
#define SWITCHES 15

void switch_init();
extern void switch_interrupt_handler();
extern char switch_update_interrupt_sense();

extern int switches;
extern int current_switch;

extern int sw1_press_state;
extern int sw2_press_state;
extern int sw3_press_state;
extern int sw4_press_state;

extern int sw1_status;
extern int sw2_status;
extern int sw3_status;
extern int sw4_status;


#endif

