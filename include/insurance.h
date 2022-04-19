#ifndef _INSURANCE_H_
#define _INSURANCE_H_

void drawinsure(User *u,int *state);
void insure(int *page,User *u);			//买保单界面
void write_insurancedata(User* u, int carid, int state1, int state2, int state3);

#endif