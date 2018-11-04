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
			read(p3, p4);
			break;
		case WRITE:
			write(p1, p2, p3, p4, p5);
			break;
	}
}

void read(uint64_t mode, uint64_t dest) {
	char *key;
	switch(mode) {
		case TIME:
			//getTime(dest);
			break;
		case KEY:
			key = (char *) dest;
			*key = getKey();
			break;
	}
}

void write(uint64_t mode, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4) {

}

/*
void getTime(uint64_t dest) {
	//	time driver
}
*/