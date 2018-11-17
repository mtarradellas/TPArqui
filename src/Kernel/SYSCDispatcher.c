#include <stdint.h>
#include "keyboardDriver.h"
#include "videoDriver.h"
#include "timeDriver.h"
#include "SYSCDispatcher.h"

void syscallDispatcher(uint64_t syscall, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5) {
	switch(syscall) {
		case READ:
			read(p1, p2, p3);
			break;
		case WRITE:
			write(p1, (char*) p2, (Color*) p3, p4, p5);
			break;
		case WAIT:
			wait( *( (int*) p1) );
			break;
	}
}

void read(uint64_t mode, uint64_t dest, uint64_t time) {
	unsigned int * t = (unsigned int *) dest;
	char * c = (char *) dest;
	switch(mode) {
		case TIME:
			getTime(t, time);
			break;
		case KEY:
			*c = getKey();
			break;
	}
}

void write(uint64_t mode, char * c, Color * color, uint64_t p3, uint64_t p4) {
	switch(mode) {
		case CHARACTER:
			printChar(*c, *color);
			break;
		case DRAWCHAR:
			drawChar(*c, *((int*) p3), *((int*) p4), *color);
		case CLEAR:
			clear();
			break;

		case PAINT:
			//paint(*c, *color, *((int*)p3), *((int*) p4));
			break;
	}
}


void getTime(unsigned int * t, uint64_t time) {
	switch(time) {
		case HOUR:
			*t = getHour();
			break;
		case MINUTE:
			*t = getMinute();
			break;
		case SECOND:
			*t = getSecond();
			break;
	}

}