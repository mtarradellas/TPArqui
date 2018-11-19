#ifndef VIDEOMODULE_H
#define VIDEOMODULE_H

#include <stdint.h>

typedef struct Color{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
} Color;

void clearScreen();
void deleteChar();
void drawBall(Color color, int radio, int x, int y);
void drawRectangle(Color color, int x, int y, int b, int h);
void getSize(int * x, int * y);

#endif