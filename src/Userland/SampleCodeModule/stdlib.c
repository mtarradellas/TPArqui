#include "SYSCall.h"
#include <stdio.h>
#include <stdarg.h>

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
					aux = va_arg(va_arg, char);
					putChar(aux);
			}
	}	

}