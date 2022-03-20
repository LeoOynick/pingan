#include"common.h"

void policy()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	setlinestyle(0,4,3);
	
	puthz(240,20,"查保单",48,56,1);
	rectangle(80,80,560,200);
	rectangle(80,200,560,320);
	puthz(90,90,"车牌：鄂",24,28,1);
	puthz(90,130,"保额：",24,28,1);
	puthz(260,130,"万元",24,28,1);
	puthz(90,170,"保障期至：",24,28,1);
	puthz(90,210,"车牌：鄂",24,28,1);
	puthz(90,250,"保额：",24,28,1);
	puthz(260,250,"万元",24,28,1);
	puthz(90,290,"保障期至：",24,28,1);
	setcolor(8);
	settextstyle(1,0,1);
	//outtextxy(240,170,"2023");
	puthz(300,170,"年",24,28,1);
	puthz(300,290,"年",24,28,1);
	//outtextxy(340,170,"4");
	puthz(360,170,"月",24,28,1);
	puthz(360,290,"月",24,28,1);
	//outtextxy(400,170,"23");
	puthz(430,170,"日",24,28,1);
	puthz(430,290,"日",24,28,1);
	
	setfillstyle(1,14);
	bar(280,400,360,430);
	puthz(295,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}