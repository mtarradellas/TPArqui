#include "stdint.h"
#include <SYSCall.h>
#include <stdarg.h>
#include <stdlib.h>

char buffer[BUFFER_SIZE] = {0};

void printf(char * fmt, ...) {
	va_list args;
	va_start(args, fmt);

	int aux;
	char * str;
	while(*fmt) {
		if (*fmt != '%') {
			putChar(*fmt);
		}
		else {
			switch(*fmt) {
				case 'd':
					aux = va_arg(args, int);
					putChar('0'+aux);
					break;
				case 's':
					str = va_arg(args, char *);
					while(*str){
						putChar(*str);
						str++;
					}
					break;
				case 'c':
					aux = va_arg(args, char);
					putChar(aux);
					break;
			}
		}
		fmt++;
	}
	va_end(args);
}

void putChar(char c) {
	Color white = {255, 255, 255};
	systemCall((uint64_t)WRITE, (uint64_t)CHARACTER, (uint64_t) &c, (uint64_t) &white, 0, 0);
}

void putDec(int i) {
	char buffer[11] = {0};
	char * b = decToStr(i, buffer);
	printf(b);
}

char * decToStr(int num, char * buffer) {
    char const digit[] = "0123456789";
    char* p = buffer;
    if(num<0){
        *p++ = '-';
        num *= -1;
    }
    int shifter = num;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[num%10];
        num = num/10;
    }while(num);
    return buffer;
}

char getChar() {
	char c;
	systemCall((uint64_t)READ,(uint64_t) KEY, (uint64_t)&c, 0, 0, 0);
	return c;
}

void scanAndPrint() {

  char k;
  Color white = {255, 255, 255};

  while(((k = getChar()) != '\n')){
    if (k > 0 && k < 127) {
      systemCall((uint64_t)WRITE, (uint64_t)CHARACTER, (uint64_t)&k, (uint64_t)&white, 0, 0 );
    }
  }
}

int getHour() {
	int t;
	systemCall((uint64_t)READ, (uint64_t)TIME, (uint64_t)&t, (uint64_t)HOUR, 0, 0);
	return t;
}

int getMinute() {
	int t;
	systemCall((uint64_t)READ, (uint64_t)TIME, (uint64_t)&t, (uint64_t)MINUTE, 0, 0);
	return t;
}

int getSecond() {
	int t;
	systemCall((uint64_t)READ, (uint64_t)TIME, (uint64_t)&t, (uint64_t)SECOND, 0, 0);
	return t;
}

char * getTime() {
	char buffer[8];
	
}
