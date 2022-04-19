#ifndef _REGISTER_H_
#define _REGISTER_H_

void regist(int *page);		//注册界面
void drawregist();
int check_legal_reg(char* name, char* password, char* confirmpw, 
					char* ID, char* tele, char* code, char* inputcode);	//检查输入格式

void write_userdata(char* name, char* pw, char* ID, char* tele);		//写入用户资料


#endif