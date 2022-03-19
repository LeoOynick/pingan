#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"HZ.H"

void enter()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
    setcolor(1);
	bar(80,170,560,200);
    bar(80,240,560,270);
    bar(160,310,560,340);
	setfillstyle(1,LIGHTGRAY);
	bar(80,310,160,340);
	puthz(80,150,"用户名",16,20,1);
    puthz(80,220,"密码",16,20,1);
    puthz(80,290,"验证码",16,20,1);
	
	setfillstyle(1,2);
	bar(180,400,260,430);
	setfillstyle(1,14);
	bar(380,400,460,430);
	puthz(195,405,"登录",24,28,1);
	puthz(395,405,"返回",24,28,1);
	puthz(280,360,"忘记密码",16,18,DARKGRAY);
	puthz(200,50,"用户登录",48,56,1);
	
	setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);
	bar(625,0,640,15);
    setcolor(1);
    line(625,0,640,15);
    line(640,0,625,15);
	
	getch();
    cleardevice();
}