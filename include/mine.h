#ifndef _MINE_H_
#define _MINE_H_

void mine(int *page, User *u, int *usernum, int *carnum);
void drawmine(User *u, int * usernum, int *carnum, int *buttonpos);
void del_cardata(int* usernum,int flag);

#endif