#ifndef STDLIB_H
#define STDLIB_H

typedef struct Color{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
} Color;

void printf(char * fmt, ...);
void putChar(char c);
char getChar();
void putChar(char c);
char * decToStr(int num, char * buffer);



#endif