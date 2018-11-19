#include "shell.h"
#include "stdlib.h"
#include <stdint.h>
#include "timeModule.h"
#include "videoModule.h"
#include "pongModule.h"

void initShell(){

  printf("~~Welcome to lenias shell, es una cagada %d/%d~~\n\n\n", 0, 10);
  int on = 1;

  char command[MAXLEN];
  while (on){

    printf("$> ");
    clearBuffer(command);
    scanAndPrint(command);
    int com = getCommand(command);

    switch(com) {
      case HELP:
          help();
          break;

      case CLEAR:
          clear();
          break;

      case TIME:
          time();
          break;

      case PONG:
          pong();
          break;

      case ZERODIV:
          zeroDiv();
          break;

      case INVOPCODE:
          invOpCode();
          break;

      case LENIA:
          lenia();
          break;

      case EXIT:
          exit();
          break;

      case INVCOM:
          invCom();
    }
  }
   printf("\n\n killme");
}

int getCommand(char * command) {
  if (!strCmp("help", command)) return HELP;
  if (!strCmp("clear", command)) return CLEAR;
  if (!strCmp("time", command)) return TIME;
  if (!strCmp("pong", command)) return PONG;
  if (!strCmp("zerodiv", command)) return ZERODIV;
  if (!strCmp("invopcode", command)) return INVOPCODE;
  if (!strCmp("lenia", command)) return LENIA;
  if (!strCmp("exit", command)) return EXIT;
  return INVCOM;
}

void help() {
  printf("\n********  Help Menu  ********\n");
  printf("  * clear     :       Clears screen\n");
  printf("  * pong      :       Iniciates pong when user presses 'enter' which will run until\n"); 
  printf("                      end of game or until user presses 'backspace' to leave\n");
  printf("  * invopcode :       Executes Invalid OP Code Interruption\n");
  printf("  * zerodiv   :       Executes Zero Division Interruption\n");
  printf("  * exit      :       Exits shell\n");
  printf("  * lenia     :       IMPRIME BOLA\n");
  printf("  * time      :       Displays current time\n");

  printf("\n  Any other command will be taken as invalid\n\n");

}

void clear() {
  clearScreen();
  printf("~~Welcome tooo Lenia's Shell~~\n\n\n");
}

void time(){
  unsigned int h = getHour();
  unsigned int m = getMinute();
  unsigned int s = getSecond();
  printf("\nLocal Time: %d:%d:%d\n", h, m, s);
}

void pong() {
  startPong();
  clear();
}

void zeroDiv() {

}

void invOpCode() {

}

void lenia() {
  Color b = {0, 0, 255};
  printf("\nlenia te amo <3\n");
  wait(10);
  printf("\n<<<<<<<<<<<<<<<<<<<<<<3333333333333333\n");
  /*drawBall(100, 150, 200);
  drawBall(150, 150, 400);
  //drawRectangle(512, 260, 30, 60);
  
  int x;
  int y;
  getSize(&x, &y);
  printf("\nX res: %d\nY res: %d\n", x, y);
  drawBall(50, x/2, y/2);*/
}


void exit() {
  //on = 0;
}

void invCom() {
  printf("\nInvalid command\n");
}