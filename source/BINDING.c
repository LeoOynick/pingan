#include"common.h"
#include"binding.h"

void binding()
{
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	setbkcolor(LIGHTCYAN);
	
	puthz(220,20,"绑定车辆",48,56,1);
	puthz(20,100,"请参照行驶证填写车辆信息",16,18,4);
	setfillstyle(1,15);
	bar(140,120,620,160);
	puthz(25,130,"车牌号码",24,28,8);
	puthz(145,130,"鄂",24,28,8);
	setcolor(8);
	bar(140,180,620,220);
	puthz(25,190,"车架号码",24,28,8);
	bar(140,240,620,280);
	puthz(25,250,"发动机号",24,28,8);
	bar(140,300,620,340);
	puthz(25,310,"注册日期",24,28,8);
	//line(280,300,280,340);
	//line(320,300,320,340);
	puthz(290,310,"年",24,28,8);
	//line(430,300,430,340);
	//line(470,300,470,340);
	puthz(440,310,"月",24,28,8);
	//line(580,300,580,340);
	puthz(590,310,"日",24,28,8);
	
	setfillstyle(1,12);
	bar(180,400,260,430);
	puthz(185,405,"下一步",24,24,1);
	setfillstyle(1,14);
	bar(380,400,460,430);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}