#ifndef _COMMONFUNC_H_
#define _COMMONFUNC_H_

void button (int x1,int y1,int x2,int y2,int framecolor,int fillcolor,int framewidth);
//画按钮函数

void input(char* id, int x1, int y1, int charnum, int color, int flag);
//输入的字符串，输入的xy，输入的字符限制，输入框的颜色，输入模式

void captcha (char* str); 
//5位验证码

#endif