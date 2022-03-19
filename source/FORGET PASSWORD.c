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

void forget()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(11);
	bar(80,100,560,130);
    bar(80,160,560,190);
    bar(80,220,560,250);
	bar(80,280,560,310);
    bar(80,340,560,370);
    bar(160,400,560,430);
	setfillstyle(1,7);
	bar(80,400,160,430);
	puthz(80,80,"用户名",16,20,1);
    puthz(80,140,"身份证号",16,20,1);
    puthz(80,200,"重置密码",16,20,1);
    puthz(80,260,"确认密码",16,20,1);
    puthz(80,320, "电话号码",16,20,1);
    puthz(80,380,"验证码",16,20,1);
	
	
	setfillstyle(1,2);
	bar(180,440,260,470);
	setfillstyle(1,14);
	bar(380,440,460,470);
	puthz(195,445,"完成",24,28,1);
	puthz(395,445,"返回",24,28,1);
	
	puthz(200,20,"忘记密码",48,56,1);
	
	setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);
	bar(625,0,640,15);
    setcolor(1);
    line(625,0,640,15);
    line(640,0,625,15);
	
	getch();
    cleardevice();
}