#ifndef STDLIB_H
#define STDLIB_H

#include <stdint.h>

typedef struct Color{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
} Color;

void printf(char * fmt, ...);
void putChar(char c);
void putDec(int i);
char getChar();
char * decToStr(int num, char * buffer);
void scanAndPrint(char * buffer);
int strCmp(char * a, char * b);
void clearBuffer(char * buffer);
void wait(int n);

#endif