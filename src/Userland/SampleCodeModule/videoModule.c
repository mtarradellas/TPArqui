//#include "videoModule.h"
#include "SYSCall.h"
#include "stdint.h"

void clearScreen() {
	systemCall((uint64_t)WRITE, (uint64_t)CLEAR, 0, 0, 0, 0);
}

void deleteChar() {
	char d = '\b';
	systemCall((uint64_t)WRITE, (uint64_t)CHARACTER,(uint64_t) &d, 0, 0, 0);
}