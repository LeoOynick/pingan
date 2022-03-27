#include"common.h"
#include"violation.h"

void violate(int *page)
{
	int num = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawpolicy();
	
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
		
		else if(mouse_press(280,400,360,430) == 2)   //返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(280,400,360,430,15,12,1);
				puthz(295,405,"返回",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(280,400,360,430) == 1)
		{
			MouseS = 0;
		    *page = 6;
			return;
		}
		
		else if (mouse_press(520,135,600,155) == 2)   //切换车辆
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(520,135,600,155) == 1)
		{
			MouseS = 0;
		    //*page = 6;
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
					bar(280,400,360,430);
					puthz(295,405,"返回",24,28,1);
				}
				num = 0;
			}
			continue;
		}
	}
}

void drawviolate()
{
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
	
	setfillstyle(1,4);
	bar(280,400,360,430);
	puthz(295,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}