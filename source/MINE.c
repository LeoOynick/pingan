#include"common.h"

void mine()
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
	
	bar(120,430,200,480);
	bar(280,430,360,480);
	line(440,480,440,420);
	line(440,420,0,420);
	line(520,480,520,420);
	line(520,420,640,420);
	setcolor(LIGHTGRAY);
	arc(320,445,0,180,9);
	line(320,460,311,445);
	line(320,460,329,445);
	circle(320,445,4);
	puthz(303,460,"服务",16,20,LIGHTGRAY);
	line(148,457,172,457);
	line(152,453,168,453);
	line(148,457,148,441);
	line(172,457,172,441);
	line(148,441,160,433);
	line(172,441,160,433);
	puthz(143,460,"首页",16,20,LIGHTGRAY);
	setcolor(15);
	circle(480,445,12);
	line(483,440,483,444);
	line(477,440,477,444);
	puthz(463,460,"我的",16,20,15);
	
	puthz(20,120,"我的爱车",24,28,1);
	puthz(520,135,"车辆管理",16,18,15);
	line(600,142,595,137);
	line(600,142,595,147);
	setfillstyle(1,15);
	bar(20,160,620,200);
	setcolor(8);
	line(185,180,215,180);
	line(200,165,200,195);
	puthz(280,170,"立即添加车辆",24,28,8);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}