#ifndef _ENTER_H_
#define _ENTER_H_
#include "data.h"

void enter(int *page,User *u,int *usernum, int *carnum);					//登录界面
void drawenter();
int verify_login(char *name, char *password, char *code, char *inputcode);	//检查用户信息格式
int verify_user(char *name, char *password);								//验证用户信息

#endif