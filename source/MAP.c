#include"common.h"

void map()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	puthz(220,20,"服务地图",48,56,1);
	bar(20,70,620,420);
	
	setfillstyle(1,14);
	bar(280,430,360,460);
	puthz(295,435,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}