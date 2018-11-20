#ifndef PONGMODULE_H
#define PONGMODULE_H

#define LEFT 0
#define RIGHT 1

#define P1UP 119
#define P1DOWN 115

#define P2UP 11
#define P2DOWN 10

#define UP -45
#define DOWN 45

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
int play(Ball ball, Player p1, Player p2);
void printInitScreen(Ball ball, Player p1, Player p2);
//void printWinScreen(int player);
//void updateScreen();
void printPlayer(Color color, Player player);
void printBall(Color color, Ball ball);
void printGoalScreen(int goal, Ball ball, Player p1, Player p2);
//void printExitScreen();
void printFrame();
void movePlayer(Player p, int step);
int moveBall(Ball ball, Player p1, Player p2);
int onEdge(Ball ball);
int onGoal(Ball ball);
int onPlayer(Ball ball, Player p1, Player p2);
void scoreGoal(int goal, Ball ball, Player p1, Player p2);
//void hitBall(int x, int y);
void act(char com, Player p1, Player p2);
#endif