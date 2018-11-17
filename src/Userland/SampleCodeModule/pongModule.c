/*#include "pongModule.h"
#include "videoModule.h"
#include "stdlib.h"
#include "timeModule.h"

void startPong() {
	Player p1;
	Player p2;
	Ball ball;
	printInitScreen(p1, p2, ball);
	while(c = getChar() != '\n' && c != '\b');
	if (c == '\b') return;
	Player winner = play(p1, p2, ball);
	printWinScreen(winner);
	return;
}

void printInitScreen(p1, p2, ball) {
	
}

Player play(Player p1, Player p2, Ball ball) {
	int playing = 0;
	while (playing) {
		wait(50);
		char command = getChar();
		act(command);


	}
}*/