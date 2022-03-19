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

void claim()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	
	puthz(240,20,"办理赔",48,56,1);
	puthz(20,90,"车辆信息",24,28,1);
	puthz(520,95,"切换车辆",16,18,8);
	setcolor(8);
	line(500,100,515,100);
	line(515,100,510,95);
	line(500,105,515,105);
	line(500,105,505,110);
	setfillstyle(1,15);
	bar(20,120,620,160);
	
	puthz(20,180,"场景选择",24,28,1);
	setcolor(15);
	setlinestyle(0,4,3);
	rectangle(20,210,620,290);
	puthz(30,220,"自己剐蹭了",24,28,8);
	puthz(230,220,"撞了别人车",24,28,8);
	puthz(430,220,"有人受伤了",24,28,8);
	puthz(30,260,"有物品损失",24,28,8);
	puthz(230,260,"车停放受损",24,28,8);
	puthz(430,260,"代驾发生事故",24,28,8);
	fillellipse(180,230,5,5);
	fillellipse(380,230,5,5);
	fillellipse(580,230,5,5);
	fillellipse(180,270,5,5);
	fillellipse(380,270,5,5);
	fillellipse(600,270,5,5);
	
	puthz(20,310,"角色选择",24,28,1);
	rectangle(20,340,620,380);
	puthz(30,350,"主责方",24,28,8);
	puthz(180,350,"次责方",24,28,8);
	puthz(330,350,"无责方",24,28,8);
	puthz(480,350,"伤者",24,28,8);
	fillellipse(120,360,5,5);
	fillellipse(270,360,5,5);
	fillellipse(420,360,5,5);
	fillellipse(540,360,5,5);
	
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