#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"HZ.H"

void moreinfo()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	puthz(220,20,"更多信息",48,56,1);
	
	puthz(25,130,"品牌型号",24,28,8);
	fillellipse(190,140,5,5);
	puthz(200,130,"奥迪",24,28,8);
	fillellipse(290,140,5,5);
	puthz(300,130,"宝马",24,28,8);
	fillellipse(390,140,5,5);
	puthz(400,130,"奔驰",24,28,8);
	fillellipse(490,140,5,5);
	puthz(500,130,"比亚迪",24,28,8);
	puthz(25,190,"使用性质",24,28,8);
	fillellipse(190,200,5,5);
	puthz(200,190,"营运",24,28,8);
	fillellipse(390,200,5,5);
	puthz(400,190,"非营运",24,28,8);
	puthz(25,250,"座位数量",24,28,8);
	bar(140,240,620,280);
	
	setfillstyle(1,12);
	bar(180,400,260,430);
	setfillstyle(1,14);
	bar(380,400,460,430);
	puthz(195,405,"提交",24,28,1);
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