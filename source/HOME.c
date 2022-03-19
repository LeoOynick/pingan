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

void home()
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
	
	puthz(135,185,"买车险",16,18,15);
	puthz(295,185,"查保单",16,18,15);
	puthz(455,185,"办理赔",16,18,15);
	puthz(135,345,"查违章",16,18,15);
	puthz(277,345,"停车·缴费",16,18,15);
	puthz(445,345,"车损测算",16,18,15);
	
	line(120,100,200,100);
	line(120,100,120,150);
	line(200,100,200,150);
	line(120,150,160,180);
	line(200,150,160,180);
	line(140,130,150,150);
	line(150,150,190,120);   //买车险;
	
	line(280,100,280,180);
	line(360,100,360,180);
	line(280,100,360,100);
	line(280,180,320,160);
	line(360,180,320,160);
	circle(310,130,15);
	line(320,140,340,160);   //查保单;
	
	line(440,100,520,100);
	line(440,100,440,180);
	line(440,180,480,180);
	line(520,100,520,140);
	line(480,180,520,140);
	line(465,130,495,130);
	line(465,145,495,145);
	line(480,130,480,160);
	line(480,130,470,120);
	line(480,130,490,120);   //办理赔;
	
	circle(160,300,40);
	line(200,340,190,330);
	line(140,300,180,300);
	line(140,290,180,290);
	line(140,310,180,310);
	line(180,310,170,320);
	line(160,280,160,325);   //查违章;
	
	arc(320,300,0,180,40);
	line(320,340,280,300);
	line(320,340,360,300);
	line(310,300,330,300);
	line(310,280,330,280);
	arc(330,290,270,450,10);
	line(310,280,310,320);   //停车·缴费;
	
	rectangle(440,260,520,340);
	line(450,330,510,270);
	line(465,270,465,300);
	line(450,285,480,285);
	line(495,300,510,300);
	line(485,320,510,320);   //车损测算;
	
	bar(440,430,520,480);
	bar(280,430,360,480);
	setcolor(15);
	line(120,480,120,420);
	line(120,420,0,420);
	line(200,480,200,420);
	line(200,420,640,420);
	line(148,457,172,457);
	line(152,453,168,453);
	line(148,457,148,441);
	line(172,457,172,441);
	line(148,441,160,433);
	line(172,441,160,433);
	puthz(143,460,"首页",16,20,15);
	setcolor(LIGHTGRAY);
	arc(320,445,0,180,9);
	line(320,460,311,445);
	line(320,460,329,445);
	circle(320,445,4);
	puthz(303,460,"服务",16,20,LIGHTGRAY);
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