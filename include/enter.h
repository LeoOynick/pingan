#ifndef _ENTER_H_
#define _ENTER_H_
#include"data.h"

void enter(int *page,User *u);
void drawenter();
int verify_login(char *name, char *password, char *code, char *inputcode);
int verify_user(char *name, char *password);

#endif