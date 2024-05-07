#include <reg51.h>
sbit IR_SENSOR = P1^0;

sbit BUZZER = P1^1;

#define DELAY_TIME 10

unsigned int timer = 0;

void delay_ms(unsigned int time) {
  while (time--) {
    TMOD &= 0xF0;
    TH0 = 0xFF;
    TL0 = 0x00;
    TR0 = 1;
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
  }
}

void main() {
  while (1) {
    if (IR_SENSOR == 1) {
      timer++;
      if (timer >= (2000 / DELAY_TIME)) {
        BUZZER = 0;
        
      }
    } else {
      timer = 0;
      BUZZER = 1;
     
    }
    delay_ms(DELAY_TIME);
  }
}
