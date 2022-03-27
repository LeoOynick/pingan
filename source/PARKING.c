#include"common.h"
#include"parking.h"

void parking(int *page)
{
	int num = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawparking();
	
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
		
		else if(mouse_press(280,420,360,450) == 2)   //返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(280,420,360,450,15,12,1);
				puthz(295,425,"返回",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(280,420,360,450) == 1)
		{
			MouseS = 0;
		    *page = 6;
			return;
		}
		
		else if (mouse_press(520,95,600,115) == 2)   //切换车辆
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
		else if (mouse_press(520,95,600,115) == 1)
		{
			MouseS = 0;
		    //*page = 6;
			return;
		}
		
		else if(mouse_press(155,275,165,285) == 2)   //机场
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(155,275,165,285) == 1)
		{
			MouseS = 0;
		    choose(160,280,state1);
		}
		
		else if(mouse_press(315,275,325,285) == 2)   //高铁
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(315,275,325,285) == 1)
		{
			MouseS = 0;
		    choose(320,280,state2);
		}
		
		else if(mouse_press(475,275,485,285) == 2)   //高校
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(475,275,485,285) == 1)
		{
			MouseS = 0;
		    choose(480,280,state3);
		}
		
		else if(mouse_press(570,240,610,260) == 2)   //预约
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(570,240,610,260,15,8,3);
				puthz(575,242,"预约",16,18,15);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(570,240,610,260) == 1)
		{
			MouseS = 0;
		    
		}
		
		else if(mouse_press(570,350,610,370) == 2)   //缴费
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(570,350,610,370,15,8,3);
				puthz(575,352,"预约",16,18,15);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(570,350,610,370) == 1)
		{
			MouseS = 0;
		    
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
					bar(280,420,360,450);
					puthz(295,425,"返回",24,28,1);
				}
				else if(num == 7)
				{
					setfillstyle(1,7);
					bar(570,240,610,260);
					puthz(575,242,"预约",16,18,1);
				}
				else if(num == 8)
				{
					setfillstyle(1,7);
					bar(570,350,610,370);
					puthz(575,352,"缴费",16,18,1);
				}
				num = 0;
			}
			continue;
		}
	}
}

void drawparking()
{
	setbkcolor(LIGHTCYAN);
	puthz(200,20,"停车·缴费",48,56,1);
	puthz(20,90,"车辆信息",24,28,1);
	puthz(520,95,"切换车辆",16,18,8);
	setcolor(8);
	line(500,100,515,100);
	line(515,100,510,95);
	line(500,105,515,105);
	line(500,105,505,110);
	setfillstyle(1,15);
	bar(20,120,620,160);
	puthz(20,180,"预约停车",24,28,1);
	puthz(140,185,"（两天内有效）",16,18,1);
	setcolor(15);
	setlinestyle(0,4,3);
	rectangle(80,210,240,290);
	rectangle(240,210,400,290);
	rectangle(400,210,560,290);
	puthz(90,220,"机场",24,28,1);
	puthz(250,220,"高铁",24,28,1);
	puthz(410,220,"高校",24,28,1);
	puthz(110,250,"武汉天河机场",16,18,8);
	puthz(275,250,"武汉火车站",16,18,8);
	puthz(430,250,"华中科技大学",16,18,8);
	fillellipse(160,280,5,5);
	fillellipse(320,280,5,5);
	fillellipse(480,280,5,5);
	
	puthz(20,310,"缴停车费",24,28,1);
	rectangle(80,340,240,380);
	rectangle(240,340,400,380);
	rectangle(400,340,560,380);
	setfillstyle(1,7);
	bar(570,240,610,260);
	puthz(575,242,"预约",16,18,1);
	bar(570,350,610,370);
	puthz(575,352,"缴费",16,18,1);
	
	setfillstyle(1,4);
	bar(280,420,360,450);
	puthz(295,425,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}