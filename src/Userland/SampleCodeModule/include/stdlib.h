#ifndef STDLIB_H
#define STDLIB_H

#include <stdint.h>


void printf(char * fmt, ...);
void putChar(char c);
void putDec(int i);
char getChar();
char * decToStr(int num, char * buffer);
void scanAndPrint(char * buffer);
int strCmp(char * a, char * b);
void clearBuffer(char * buffer);
int abs(int n);

#endif