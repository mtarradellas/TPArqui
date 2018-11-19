#include "timeDriver.h"
#include "timeDriverASM.h"
#include "videoDriver.h"

static unsigned long ticks = 0;
Color w ={255, 255, 255};


void timeHandler() {
	ticks++;
	//printChar((ticks%10)+48, w);
	/*Color w = {255, 255, 255};
	printChar((ticks%10) + 48, w);*/
}

static int ticksElapsed() {
	return ticks;	
}




void wait(int n) {
	printChar('A', w);
	int t = ticksElapsed() + 10;
	while(ticksElapsed() < t);
	//printChar((ticksElapsed()%10)+48, w);
	/*while ( (current = ticksElapsed()) <= end ) {
		printChar(current + 48, w);
		printChar(' ', w);
		printChar(end + 48, w);
		printChar(' ', w);

		int i= 0;
		for (; i<1000000; i++);
	}*/
	//for(int i = 0; i<100000000; i++);
	//printChar((ticksElapsed()%10)+48, w);

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