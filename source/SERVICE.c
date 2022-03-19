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

void service()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(CYAN);
	setlinestyle(0,4,3);
	fillellipse(25,25,24,24);
	setcolor(9);
	circle(25,15,15);
	arc(25,72,60,120,40);
    setcolor(15);
    line(0,50,640,50);
	
	puthz(125,185,"车辆服务",16,18,8);
	line(120,170,200,170);
	line(120,170,120,140);
	line(200,170,200,140);
	line(120,140,130,140);
	line(200,140,190,140);
	line(130,140,145,120);
	line(190,140,175,120);
	line(145,120,175,120);
	circle(130,155,3);
	circle(190,155,3);
	line(130,168,130,175);
	line(190,168,190,175);
	
	puthz(445,185,"年检代办",16,18,8);
	line(440,100,520,100);
	line(440,100,440,150);
	line(520,100,520,150);
	line(440,150,480,180);
	line(520,150,480,180);
	puthz(465,115,"检",32,28,15);
	
	puthz(125,345,"道路救援",16,18,8);
	line(120,340,200,340);
	line(120,340,160,270);
	line(200,340,160,270);
	bar(158,290,162,320);
	fillellipse(160,330,2,2);
	
	puthz(445,345,"服务地图",16,18,8);
	circle(480,295,5);
	arc(480,295,330,570,12);
	line(480,315,470,301);
	line(480,315,490,301);
	line(470,301,440,315);
	line(490,301,520,315);
	line(440,315,480,335);
	line(520,315,480,335);
	
	bar(440,430,520,480);
	bar(120,430,200,480);
	line(280,480,280,420);
	line(280,420,0,420);
	line(360,480,360,420);
	line(360,420,640,420);
	arc(320,445,0,180,9);
	line(320,460,311,445);
	line(320,460,329,445);
	circle(320,445,4);
	puthz(303,460,"服务",16,20,15);
	setcolor(LIGHTGRAY);
	line(148,457,172,457);
	line(152,453,168,453);
	line(148,457,148,441);
	line(172,457,172,441);
	line(148,441,160,433);
	line(172,441,160,433);
	puthz(143,460,"首页",16,20,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	circle(480,445,12);
	line(480,440,480,444);
	line(474,440,474,444);
	puthz(463,460,"我的",16,20,LIGHTGRAY);
	
	setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTGRAY);
	bar(625,0,640,15);
    setcolor(1);
    line(625,0,640,15);
    line(640,0,625,15);
	
	getch();
    cleardevice();
}