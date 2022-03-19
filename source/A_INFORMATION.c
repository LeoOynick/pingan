#include<string.h>
#include<graphics.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"HZ.H"
#include"mouse.h"
//#include"mouse.h"

void a_info()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	setlinestyle(0,4,3);
	
	puthz(150,20,"用户信息管理",48,56,1);
	puthz(150,80,"输入车牌",24,28,1);
	bar(150,110,420,150);
	puthz(160,120,"鄂",24,28,1);
	setfillstyle(1,7);
	bar(440,117,490,143);
	puthz(450,122,"查询",16,18,1);
	
	puthz(80,160,"违章查询",24,28,1);
	rectangle(80,190,240,230);
	rectangle(240,190,400,230);
	rectangle(400,190,560,230);
	puthz(130,200,"日期",24,28,1);
	puthz(270,200,"违章类型",24,28,1);
	puthz(450,200,"处罚",24,28,1);
	
	puthz(80,320,"保单查询",24,28,1);
	rectangle(80,350,560,430);
	puthz(90,360,"保额：",24,28,1);
	puthz(260,360,"万元",24,28,1);
	puthz(90,400,"保障期至：",24,28,1);
	puthz(300,400,"年",24,28,1);
	puthz(360,400,"月",24,28,1);
	puthz(430,400,"日",24,28,1);
	
	setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);
	bar(625,0,640,15);
    setcolor(1);
    line(625,0,640,15);
    line(640,0,625,15);
	
	getch();
    cleardevice();
}