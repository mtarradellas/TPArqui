#include "timeDriver.h"
#include "timeDriverASM.h"

unsigned long ticks = 0;

void timeHandler() {
	ticks++;
}

int ticksElapsed() {
	return ticks;	
}

int getHour() {
	int * t = _getHour();
	return *t;
}

int getMinute() {
	int * t = _getMinute();
	return *t;
}

int getSecond() {
	int * t = _getSecond();
	return *t;
}