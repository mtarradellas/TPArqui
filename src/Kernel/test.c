#include "videoDriver.h"

void paramT();
void param(int a, int b, int c, int d, int e, int f, int g);
void paramTest(int a, int b, int c, int d, int e, int f, int g);

void paramT() {
	param(1, 2, 3, 4, 5, 6, 7);
}

void paramTest(int a, int b, int c, int d, int e, int f, int g){
	Color w = {255, 255, 255};
	printChar(g + 48, w);
}