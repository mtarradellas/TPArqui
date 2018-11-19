#include "timeDriver.h"
#include "timeDriverASM.h"
#include "videoDriver.h"

static unsigned long ticks = 0;
Color w ={255, 255, 255};


void timeHandler() {
	ticks++;
	/*Color w = {255, 255, 255};
	printChar((ticks%10) + 48, w);*/
}

static unsigned long ticksElapsed() {
	unsigned long t = ticks;
	return t;	
}

void wait(int n) {
	_sti();
	unsigned long t = ticksElapsed() + n;
	while(ticksElapsed() < t);
}

unsigned int getHour() {
	unsigned int t = _getHour();
	return t;
}

unsigned int getMinute() {
	unsigned int t = _getMinute();
	return t;
}

unsigned int getSecond() {
	unsigned int t = _getSecond();
	return t;
}