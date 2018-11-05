#include <stdint.h>
#include "keyboardDriver.h"
#include "naiveConsole.h"

#define READ 0
#define WRITE 1

#define KEY 0
#define TIME 1

void syscallDispatcher(uint64_t syscall, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5) {
	switch(syscall) {
		case READ:
			read(p3, (char*) p4);
			break;
		case WRITE:
			write(p1, (char*) p2, p3, p4, p5);
			break;
	}
}

void read(uint64_t mode, char * dest) {
	char *key;
	switch(mode) {
		case TIME:
			//getTime(dest);
			break;
		case KEY:
			dest = getKey();
			break;
	}
}

void write(uint64_t mode, char * c, uint64_t p2, uint64_t p3, uint64_t p4) {
	switch(mode) {
		case CHARACTER:
			printChar(*c, (Color)* p2);
			break;
		//case STRING:

		case CLEAR:

		case PAINT:
	}
}

/*
void getTime(uint64_t dest) {
	//	time driver
}
*/