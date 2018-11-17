#include "timeDriver.h"
#include "timeDriverASM.h"

unsigned long ticks = 0;

void timeHandler() {
	ticks++;
	
}

int ticksElapsed() {
	return ticks;	
}

void wait(int n) {
	int t = ticks + n;
	while (ticks < t);
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