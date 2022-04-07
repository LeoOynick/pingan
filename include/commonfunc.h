#ifndef _COMMONFUNC_H_
#define _COMMONFUNC_H_

void button (int x1,int y1,int x2,int y2,int framecolor,int fillcolor,int framewidth);
//画按钮函数

void input (char* id, int x1, int y1, int charnum, int color, int flag);
//输入的字符串，输入的xy，输入的字符限制，输入框的颜色，输入模式

void coverhz (int x, int y, int color);
//遮盖字符

void show_tickcross(int x1, int y1, int x2,int y2, int flag);
//flag == 1 show tick, else cross,xy base on cross.

void captcha (char* str);
//5位验证码

int check_captcha (char* str1, char* str2,int x, int y);
//判断验证码是否正确

int check_samename(char* name, int flag);
//flag 1--用户已被注册, 2--账号存在, 3--不输出

int output_userinfo(User *us);


void judgeinput (char* str,int* state,int x,int y);
//判断是否有输入

int check_username_dig (char* str,int x,int y);
//判断用户名称长度

int check_comfirmpw (char* str1,char* str2,int x,int y);
//判断确认密码是否与密码一致

int check_pw_dig (char* str,int x,int y);
//判断密码长度

int check_tele_dig (char* str,int x,int y);
//判断电话号码长度

int check_id (char* str,int x,int y);
//判断身份证格式

void choose(int x,int y,int *state);
//进行项目勾选

void single(int *state1, int *state2, int *state3, int x1, int y1, int x2, int y2, int x3, int y3);
//实现单选（选择其中一项时其他几项清零）

void price(int *state1, int *state2, int *state3, int *state4, int *state5, int *state6,
			int cost1, int cost2, int cost3, int cost4, int cost5, int cost6, int cost, char *charge, int x, int y);
//勾选之后显示价格
#endif