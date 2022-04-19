#ifndef _BINDING_H_
#define _BINDING_H_
#include "data.h"

void drawbinding();		//绑定车辆界面
void binding(int *page,User *u, int *usernum, int *carnum);
int check_legal_addcar(char* licensenum, char* year, char* month, char* day, 
						int type, int nature, int *usernum, int *carnum);
void write_cardata(char* licensenum, char* year, char* month, char* day,
					char* choice_str_type, char* choice_str_nature, int *usernum, int *carnum);


#endif
