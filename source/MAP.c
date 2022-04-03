#include"common.h"
#include"map.h"

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
	bar(20,70,620,420);
	
	setfillstyle(1,4);
	bar(280,430,360,460);
	puthz(295,435,"返回",24,28,1);
	
	setlinestyle(0,4,3);
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}