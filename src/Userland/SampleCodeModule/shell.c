#include "shell.h"
#include "stdlib.h"
#include <stdint.h>
#include "timeModule.h"
#include "pongModule.h"

int on = 1;
void initShell(){

  printf("~~Welcome to lenias shell, es una cagada %d/%d~~\n\n\n", 0, 10);

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

      case ALEPUTO:
          alePuto();
          break;

      case LENIA:
          lenia();
          break;

      case SHELLSHOCK:
          shellShock();
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
  if (!strCmp("aleputo", command)) return ALEPUTO;
  if (!strCmp("lenia", command)) return LENIA;
  if (!strCmp("shellshock", command)) return SHELLSHOCK;
  if (!strCmp("exit", command)) return EXIT;
  return INVCOM;
}

void help() {
  printf("\nchupala\n");
}

void clear() {
  clearScreen();
  printf("~~Welcome to lenias shell, es una cagada~~\n\n\n");
}

void time(){
  unsigned int h = getHour();
  unsigned int m = getMinute();
  unsigned int s = getSecond();
  printf("\nLocal Time: %d:%d:%d\n", h, m, s);
}

void pong() {
  startPong();
}

void zeroDiv() {

}

void invOpCode() {

}

void alePuto() {
  printf("\nale es puto y cagon\n");
}

void lenia() {
  printf("\nlenia te amo <3\n");
}

void shellShock() {
  printf("\nbautiPuto\n");
}

void exit() {
  on = 0;
}

void invCom() {
  printf("\nque haces pelotudo\n");
}