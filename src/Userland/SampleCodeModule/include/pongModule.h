/*#ifndef PONGMODULE_H
#define PONGMODULE_H

#define INITPY	500 //mitad de pantalla

#define LEFT 0
#define RIGHT 1

typedef struct player{
	int points = 0;
	int pos = INITY;
	int side;
} Player;

typedef struct ball{
	int posX;
	int posY;
	int dirX = 30;
	int dirY = 30;
} Ball;

void startPong();
Player play(Player p1, Player p2, Ball ball);
void printInitScreen(Player p1, Player p2, Ball ball);
void printWinScreen(Player player);
void updateScreen();
void printPlayer(Player player);
void printBall(Ball ball);
void printGoalScreen(Player player);
void goal(Player player);
void movePlayer(int dir);
void moveBall();
void hitBall(int x, int y);

#endif*/