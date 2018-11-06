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
	}
}

void read(uint64_t mode, uint64_t dest, uint64_t time) {
	int * t = (int *) dest;
	char * c = (char *) dest; /*
	if (mode == KEY) {
		c = (char*) dest;
	}
	else t = (int*) dest;
*/
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
		//case STRING:

		case CLEAR:
			break;

		case PAINT:
			break;
	}
}


void getTime(int * t, uint64_t time) {
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
