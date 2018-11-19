#ifndef TIMEDriver_h
#define TIMEDriver_h

void timeHandler();
static int ticksElapsed();
void wait(int n);
unsigned int getHour();
unsigned int getMinute();
unsigned int getSecond();

#endif