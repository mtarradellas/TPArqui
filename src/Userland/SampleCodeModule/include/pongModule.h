#ifndef PONGMODULE_H
#define PONGMODULE_H

#define LEFT 0
#define RIGHT 1

#define P1UP 119
#define P1DOWN 115

#define P2UP 11
#define P2DOWN 10

#define UP -15
#define DOWN 15

#include "videoModule.h"

typedef struct player{
	int points;
	int pos;
	int side;
} PlayerStruct;

typedef struct ball{
	int posX;
	int posY;
	int dirX;
	int dirY;
} BallStruct;

typedef PlayerStruct * Player;
typedef BallStruct * Ball;

void startPong();
int play(Player p1, Player p2, Ball ball);
void printInitScreen(Player p1, Player p2, Ball ball);
//void printWinScreen(int player);
//void updateScreen();
void printPlayer(Color color, Player player);
void printBall(Color color, Ball ball);
//void printGoalScreen(Player player);
//void printExitScreen();
void printFrame();
//void goal(Player player);
void movePlayer(Player p, int step);
//void moveBall();
//void hitBall(int x, int y);
void act(char com, Player p1, Player p2);
#endif