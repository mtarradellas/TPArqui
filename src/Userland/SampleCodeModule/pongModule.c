#include "pongModule.h"
#include "videoModule.h"
#include "stdlib.h"
#include "timeModule.h"


int xResolution;
int yResolution;

Color white = {255, 255, 255};
Color black = {0, 0, 0};

void startPong() {
	getSize(&xResolution, &yResolution);	
	Player p1;
	p1->points = 0;
	p1->pos = yResolution/2;
	p1->side = 0;
	Player p2;
	p2->points = 0;
	p2->pos = yResolution/2;
	p2->side = 1;
	Ball ball;
	ball->posX = xResolution/2;
	ball->posY = yResolution/2;
	ball->dirX = 2;
	ball->dirY = 1;
	char c;

	printInitScreen(p1, p2, ball);

	while(c = getChar() != '\n' && c != '\b');
	if (c == '\b') {
		clearScreen();
		return;
	}

	int exitStatus = play(p1, p2, ball);

	if (exitStatus == 0) {
		clearScreen();
		return;
	}
	//printWinScreen(exitStatus);
	clearScreen();
	return;
}

int play(Player p1, Player p2, Ball ball) {
	int playing = 1;
	int exitStatus = 0;
	while (playing) {
		wait(1);
		char command = getChar();
		if (command == '\b') {
			playing = 0;
		}
		act(command, p1, p2);
		printBall(black, ball);
		ball->posX += ball->dirX;
		ball->posY += ball->dirY;
		printBall(white, ball);
	}
	return exitStatus;
return 1;
}

void act(char command, Player p1, Player p2) {
	switch(command) {
		case P1UP:
			movePlayer(p1, UP);
			break;
		case P1DOWN:
			movePlayer(p1, DOWN);
			break;
		case P2UP:
			movePlayer(p2, UP);
			break;
		case P2DOWN:
			movePlayer(p2, DOWN);
			break;
	}
}

void movePlayer(Player p, int step) {
	int xPos = p->side == 0? 20 : xResolution-20;
	int yPos = step < 0 ? (p->pos + 70) - abs(step/2) : (p->pos - 70) + abs(step/2);
	drawRectangle(black, xPos, yPos, 4, abs(step/2));
	yPos = step > 0 ? (p->pos + 70) - abs(step/2) + step : (p->pos - 70) + abs(step/2) + step;
	drawRectangle(white, xPos, yPos, 4, abs(step/2));
	p->pos = p->pos + step;

}

void printInitScreen(Player p1, Player p2, Ball ball) {
	clearScreen();
	printFrame();
	printPlayer(white, p1);
	printPlayer(white, p2);
	printBall(white, ball);
}

void printPlayer(Color color, Player p) {
	int xPos = p->side == 0? 20 : xResolution-20;
	int yPos = p->pos;
	drawRectangle(color, xPos, yPos, 4, 70);
}

void printBall(Color color, Ball b) {
	drawBall(color, 10, b->posX, b->posY);
}

void printFrame() {
	drawRectangle(white, xResolution/2, 2, (xResolution/2 )-2, 0);
	drawRectangle(white, xResolution/2, yResolution-2, (xResolution/2 )-2, 0);
	drawRectangle(white, 2, yResolution/2, 1, (yResolution/2)-2);
	drawRectangle(white, xResolution-2, yResolution/2, 1, (yResolution/2)-2);
}

