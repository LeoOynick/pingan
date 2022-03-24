#ifndef _REGISTER_H_
#define _REGISTER_H_

void regist(int *page);
void drawregist();
int check_legal_reg(char* name, char* password, char* confirmpw, 
					char* ID, char* tele, char* code, char* inputcode);

#endif