#include "shell.h"
#include "stdlib.h"

void initializeShell(){

  printf("~~Welcome to lenias shell, es una cagada~~\n\n\n");

  char command[MAXLENGTH];
  int on = 1;
  while (on){

    printf("$> ");
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
    }

    

  }
   printf("\n\n killme");
}
