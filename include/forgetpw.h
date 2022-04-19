#ifndef _FORGETPW_H_
#define _FORGETPW_H_

void forget(int *page);	//忘记密码界面
void drawforget();
int verify_forgotpw_info(char* name, char* password, char* confirmpw, 
					char* ID, char* tele, char* code, char* inputcode);		//检查输入资料格式
int change_userpw(char* name, char* password, char* confirmpw, 
					char* ID, char* tele);									//修改密码

#endif