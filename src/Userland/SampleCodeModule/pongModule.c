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
	Player p2;
	Ball ball;

	p1->pos = yResolution/2;
	p1->side = 0;
	p1->points = 0;

	p2->pos = yResolution/2;
	p2->side = 1;
	p2->points = 0;

	ball->posX = xResolution/2;
	ball->posY = yResolution/2;
	ball->dirX = 10;
	ball->dirY = 17;

	char c;

	printInitScreen(ball, p1, p2);

	while(c = getChar() != '\n' && c != '\b'){
		if (c == '\b') {
			clearScreen();
			return;
		}
	}

	int exitStatus = play(ball, p1, p2);

	if (exitStatus == 0) {
		clearScreen();
		return;
	}
	//printWinScreen(exitStatus);
	clearScreen();
	return;
}

int play(Ball ball, Player p1, Player p2) {
	int playing = 1;
	int exitStatus = 0;
	while (playing) {
		wait(2);
		char command = getChar();
		if (command == '\b') {
			playing = 0;
		}
		act(command, p1, p2);
		int goal = moveBall(ball, p1, p2);
		if (goal) {
			scoreGoal(goal, ball, p1, p2);
		}
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

int moveBall(Ball ball, Player p1, Player p2) {
	int goal = 0;
	printBall(black, ball);
	if (onEdge(ball)) {
		ball->dirY = -ball->dirY;
	}
	if (onGoal(ball)) {
		goal = 1;
	}
	if (onPlayer(ball, p1, p2)) {
		ball->dirX = -ball->dirX;
	}
	ball->posX += ball->dirX;
	ball->posY += ball->dirY;
	printBall(white, ball);
	return goal;
}

int onPlayer(Ball ball, Player p1, Player p2) {
	int touchRightX = 0;
	int touchLeftX = 0;
	int touchRightY = 0;
	int touchLeftY = 0;
	if (ball->posX + ball->dirX + 10 >= xResolution-30) {
		touchRightX = 1;
	}
	else if (ball->posX + ball->dirX - 10 <= 30) {
		touchLeftX = 1;
	}
	if (touchRightX) {
		if (ball->posY + ball->dirY <= p2->pos + 70 && ball->posY + ball->dirY >= p2->pos - 70) {
			return 1;
		}
		return 0;
	}
	else if (touchLeftX) {
		if (ball->posY + ball->dirY <= p1->pos + 70 && ball->posY + ball->dirY >= p1->pos - 70) {
			return 1;
		}
		return 0;
	}
	return 0;
}

int onGoal(Ball ball) {
	if (ball->posX + ball->dirX + 10 >= xResolution-2){
		return 2;
	}
	if (ball->posX + ball->dirX - 10 <= 2){
		return 1;
	}
	return 0;
}

void scoreGoal(int goal, Ball ball, Player p1, Player p2) {
	if (goal == 1) {
		p1->points = p1->points + 1;
	} else {
		p2->points = p2->points + 1;
	}
	p1->pos = yResolution/2;
	p2->pos = yResolution/2;
	ball->posX = xResolution/2;
	ball->posY = yResolution/2;
	ball->dirX = 10;
	ball->dirY = 17;
	printGoalScreen(goal, ball, p1, p2);
	return;
}

void printGoalScreen(int goal, Ball ball, Player p1, Player p2) {
	printInitScreen(ball, p1, p2);
}

int onEdge(Ball ball) {
	if (ball->posY + ball->dirY + 10 >= yResolution-2 || ball->posY + ball->dirY - 10 <= 2){
		return 1;
	}
	return 0;
}

void movePlayer(Player p, int step) {
	int xPos = p->side == 0? 30 : xResolution-30;
	int yPos = step < 0 ? (p->pos + 70) - abs(step/2) : (p->pos - 70) + abs(step/2);
	drawRectangle(black, xPos, yPos, 4, abs(step/2));
	yPos = step > 0 ? (p->pos + 70) - abs(step/2) + step : (p->pos - 70) + abs(step/2) + step;
	drawRectangle(white, xPos, yPos, 4, abs(step/2));
	p->pos = p->pos + step;

}

void printInitScreen(Ball ball, Player p1, Player p2) {
	clearScreen();
	printFrame();
	printPlayer(white, p1);
	printPlayer(white, p2);
	printBall(white, ball);
}

void printPlayer(Color color, Player p) {
	int xPos = p->side == 0? 30 : xResolution-30;
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

