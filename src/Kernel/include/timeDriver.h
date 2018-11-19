#ifndef TIMEDriver_h
#define TIMEDriver_h

void timeHandler();
static unsigned long ticksElapsed();
unsigned int getHour();
unsigned int getMinute();
unsigned int getSecond();
void wait(int n);
#endif