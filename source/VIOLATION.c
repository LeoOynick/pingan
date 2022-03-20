#include"common.h"

void violate()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	
	puthz(240,20,"查违章",48,56,1);
	puthz(20,120,"车辆信息",24,28,1);
	puthz(520,135,"切换车辆",16,18,8);
	setcolor(8);
	line(500,140,515,140);
	line(515,140,510,135);
	line(500,145,515,145);
	line(500,145,505,150);
	setfillstyle(1,15);
	bar(20,160,620,200);
	setlinestyle(0,4,3);
	setcolor(15);
	rectangle(80,210,240,250);
	rectangle(240,210,400,250);
	rectangle(400,210,560,250);
	puthz(130,220,"日期",24,28,1);
	puthz(270,220,"违章类型",24,28,1);
	puthz(450,220,"处罚",24,28,1);
	
	setfillstyle(1,14);
	bar(280,400,360,430);
	puthz(295,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}