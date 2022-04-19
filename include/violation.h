#ifndef _VIOLATION_H_
#define _VIOLATION_H_

void drawviolate(User *u, int *carid);
void violate(int *page, User *u);		//查违章界面
void search_vio(User *u, int carid);	//查询违章

#endif