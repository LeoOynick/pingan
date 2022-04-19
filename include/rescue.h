#ifndef _RESCUE_H_
#define _RESCUE_H__H_

void rescue(int* page, User* u);		//救援界面
void drawrescue(User* u, int* carid);
void write_rescuedata(User *u, int carid, int rescue1,int rescue2,int rescue3,int rescue4);

#endif