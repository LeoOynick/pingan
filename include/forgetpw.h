#ifndef _FORGETPW_H_
#define _FORGETPW_H_

void forget(int *page);
void drawforget();
int verify_forgotpw_info(char* name, char* password, char* confirmpw, 
					char* ID, char* tele, char* code, char* inputcode);
int change_userpw(char* name, char* password, char* confirmpw, 
					char* ID, char* tele);

#endif