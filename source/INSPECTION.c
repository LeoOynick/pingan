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

void inspect()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	
	puthz(220,20,"年检代办",48,56,1);
	puthz(20,120,"车辆信息",24,28,1);
	puthz(520,135,"切换车辆",16,18,8);
	setcolor(8);
	line(500,140,515,140);
	line(515,140,510,135);
	line(500,145,515,145);
	line(500,145,505,150);
	setfillstyle(1,15);
	bar(20,160,620,200);
	
	puthz(20,220,"选择年检类型",24,28,1);
	setcolor(15);
	setlinestyle(0,4,3);
	rectangle(40,250,320,330);
	rectangle(320,250,600,330);
	puthz(60,270,"新车免检（免上线）",24,28,8);
	puthz(330,270,"上检测站年检（上线）",24,28,8);
	fillellipse(180,310,5,5);
	fillellipse(460,310,5,5);
	
	puthz(160,350,"共计消费：",24,28,1);
	puthz(400,355,"元",16,18,8);
	setfillstyle(1,12);
	bar(180,400,260,430);
	setfillstyle(1,14);
	bar(380,400,460,430);
	puthz(195,405,"确定",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);
	bar(625,0,640,15);
    setcolor(1);
    line(625,0,640,15);
    line(640,0,625,15);
	
	getch();
    cleardevice();
}