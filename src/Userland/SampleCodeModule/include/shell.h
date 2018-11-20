#ifndef SHELL_H
#define SHELL_H

#define INVCOM 0
#define HELP   1
#define CLEAR   2
#define TIME   3
#define PONG   4
#define ZERODIV   5
#define INVOPCODE   6
#define ALEPUTO   7
#define LENIA   8
#define SHELLSHOCK   9
#define EXIT   10

#define MAXLEN 256

void initShell();
int getCommand(char * command);
void help();
void clear();
void time();
void pong();
void zeroDiv();
void invOpCode();
void aleDuto();
void lenia();
void shellShock();
void exit();
void invCom();

#endif