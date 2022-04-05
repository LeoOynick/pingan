#ifndef _ENTER_H_
#define _ENTER_H_

void enter(int *page);
void drawenter();
int verify_login(char *name, char *password, char *code, char *inputcode);
int verify_user(char *name, char *password);

#endif