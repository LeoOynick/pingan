#ifndef _CLAIM_H_
#define _CLAIM_H_

void drawclaim(User *u, int *carid);
int whichscenes(int state1 ,int state2 ,int state3 , int state4 ,int state5 ,int state6);
int whichcharacter(int state7,int state8,int state9,int state10);
void write_claimdata(User *u,int carid,int scene,int character);
void claim(int *page,User *u);

#endif

