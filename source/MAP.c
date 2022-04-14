#include"common.h"
#include"map.h"
#include"putbmp.h"

void map(int *page)
{
	int num=0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawmap();
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(610,0,640,30) == 2)   //退出
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,RED);
				bar(610,0,640,30);
			    setcolor(15);
				setlinestyle(0,4,3);
			    line(610,0,640,30);
				line(640,0,610,30);
			    num = 1;
		    }
			continue;
		}
		else if(mouse_press(610,0,640,30) == 1)
		{
			*page = 1;
			return;
		}
		
		else if(mouse_press(280,430,360,460) == 2)   //返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(280,430,360,460,15,12,1);
				puthz(295,435,"返回",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(280,430,360,460) == 1)
		{
			MouseS = 0;
		    *page = 7;
			return;
		}
		
		else
		{
			if(num != 0)
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				delay(10);
				if(num == 1)
				{
					setfillstyle(1,LIGHTGRAY);
					bar(610,0,640,30);
					setcolor(1);
					setlinestyle(0,4,3);
					line(610,0,640,30);
					line(640,0,610,30);
				}
				else if(num == 2)
				{
					setfillstyle(1,4);
					bar(280,430,360,460);
					puthz(295,435,"返回",24,28,1);
				}
				num = 0;
			}
			continue;
		}
	}
}


void drawmap()
{
	setbkcolor(LIGHTCYAN);
	puthz(220,20,"服务地图",48,56,1);
	setfillstyle(1,15);
	bar(20,70,620,420);
	setfillstyle(1,LIGHTGREEN);
	bar(20,70,200,170);
	setfillstyle(1,LIGHTCYAN);
	bar(440,195,620,295);
	setfillstyle(1,LIGHTGRAY);
	bar(230,320,410,420);
	bar(230,195,410,295);
	bar(230,70,410,170);	
	bar(20,195,200,295);
	bar(20,320,200,420);
	bar(440,70,620,170);
	bar(440,320,620,420);
	puthz(280,230,"科技楼",24,28,1);
	puthz(490,105,"教学楼",24,28,1);
	puthz(70,355,"加油站",24,28,1);
	puthz(490,355,"修理厂",24,28,1);
	puthz(70,230,"图书馆",24,28,1);
	puthz(280,355,"校史馆",24,28,1);
	puthz(280,105,"停车场",24,28,1);
	puthz(70,105,"喻家山",24,28,1);
	puthz(490,230,"喻家湖",24,28,1);
	puthz(285,175,"喻园大道",16,18,1);
	puthz(288,300,"启明路",16,18,1);
	
	setfillstyle(1,4);
	bar(280,430,360,460);
	puthz(295,435,"返回",24,28,1);
	
	setlinestyle(0,4,3);
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
	
	setfillstyle(1,4);
	bar(280,430,360,460);
	puthz(295,435,"返回",24,28,1);
	//putbmp(30,62,"c:\\pingan\\bmp\\petrol.bmp");
}