#include"common.h"

void measure()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	
	puthz(200,20,"车损测算",48,56,1);
	puthz(20,90,"车辆信息",24,28,1);
	puthz(520,95,"切换车辆",16,18,8);
	setcolor(8);
	line(500,100,515,100);
	line(515,100,510,95);
	line(500,105,515,105);
	line(500,105,505,110);
	setfillstyle(1,15);
	bar(20,120,620,160);
	
	puthz(20,180,"选择损坏部位",24,28,1);
	setlinestyle(0,4,3);
	setcolor(15);
	rectangle(80,210,560,290);
	line(80,250,560,250);
	line(240,210,240,290);
	line(400,210,400,290);
	puthz(90,220,"车胎",24,28,1);
	puthz(250,220,"引擎盖",24,28,1);
	puthz(410,220,"保险杠",24,28,1);
	puthz(90,260,"车灯",24,28,1);
	puthz(250,260,"后视镜",24,28,1);
	puthz(410,260,"车门",24,28,1);
	fillellipse(200,230,5,5);
	fillellipse(360,230,5,5);
	fillellipse(520,230,5,5);
	fillellipse(200,270,5,5);
	fillellipse(360,270,5,5);
	fillellipse(520,270,5,5);
	puthz(100,320,"预计维修费用为：",24,28,1);
	puthz(400,325,"元",16,18,8);
	
	setfillstyle(1,12);
	bar(180,400,260,430);
	setfillstyle(1,14);
	bar(380,400,460,430);
	puthz(195,405,"测算",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}