#include"common.h"
#include"parking.h"

void parking(int *page)
{
	int num = 0;
	char year[5];       //预约年份
	char month[3];     //预约月份
	char day[3];     //预约日期
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	
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
		
		else if(mouse_press(180,420,260,450) == 2)   //预约
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,420,260,450,15,10,1);
				puthz(195,425,"预约",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,420,260,450) == 1)
		{
			MouseS = 0;
			if(state1 == 0 && state2 == 0 && state3 == 0)
				puthz(220,185,"请选择地点！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(220,185,420,205);
			}
			if(state4 == 0 || state5 == 0 || state6 == 0)
				puthz(220,345,"请填写时间！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(220,345,420,365);
			}
			if((state1 != 0 || state2 != 0 || state3 != 0) && (state4 != 0 && state5 != 0 && state6 != 0))
			{
				setfillstyle(1,LIGHTCYAN);
				bar(220,185,420,205);
				bar(220,345,420,365);
				puthz(280,455,"预约成功！",16,20,4);
				delay(800);
				*page = 6;
				return;
			}
		}
		
		else if(mouse_press(380,420,460,450) == 2)   //返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(380,420,460,450,15,12,1);
				puthz(395,425,"返回",24,28,1);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(380,420,460,450) == 1)
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
				num = 4;
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
				num = 5;
			}
			continue;
		}
		else if (mouse_press(155,275,165,285) == 1)
		{
			MouseS = 0;
		    choose(160,280,&state1);
			single(&state2,&state2,&state3,320,280,320,280,480,280);
		}
		
		else if(mouse_press(315,275,325,285) == 2)   //高铁
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
		else if (mouse_press(315,275,325,285) == 1)
		{
			MouseS = 0;
		    choose(320,280,&state2);
			single(&state1,&state1,&state3,160,280,160,280,480,280);
		}
		
		else if(mouse_press(475,275,485,285) == 2)   //高校
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(475,275,485,285) == 1)
		{
			MouseS = 0;
		    choose(480,280,&state3);
			single(&state1,&state1,&state2,160,280,160,280,320,280);			
		}
		
		else if(mouse_press(255,300,340,340) == 2)		//年
		{
			if (num == 0 && state4 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(255,300,340,340,8,15,1);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(255,300,340,340) == 1)
		{
			MouseS = 0;
		    button(255,300,340,340,8,15,1);
			year[0] = '\0';
			input(year,255,305,4,15,2);
			if(strlen(year) != 0)
				state4 = 1;
			else
				state4 = 0;
			continue;
		}
		
		else if(mouse_press(360,300,410,340) == 2)		//月
		{
			if (num == 0 && state5 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(360,300,410,340,8,15,1);
				num = 9;
			}
			continue;
		}
		else if (mouse_press(360,300,410,340) == 1)
		{
			MouseS = 0;
		    button(360,300,410,340,8,15,1);
			month[0] = '\0';
			input(month,360,305,2,15,2);
			if(strlen(month) != 0)
				state5 = 1;
			else
				state5 = 0;
			continue;
		}
		
		else if(mouse_press(430,300,480,340) == 2)		//日
		{
			if (num == 0 && state6 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(430,300,480,340,8,15,1);
				num = 10;
			}
			continue;
		}
		else if (mouse_press(430,300,480,340) == 1)
		{
			MouseS = 0;
		    button(430,300,480,340,8,15,1);
			day[0] = '\0';
			input(day,430,305,2,15,2);
			if(strlen(day) != 0)
				state6 = 1;
			else
				state6 = 0;
			continue;
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
					setfillstyle(1,2);
					bar(180,420,260,450);
					puthz(195,425,"预约",24,28,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,420,460,450);
					puthz(395,425,"返回",24,28,1);
				}
				else if(num == 8 && state4 == 0)
				{
					button(255,300,340,340,15,15,1);
				}
				else if(num == 9 && state5 == 0)
				{
					button(360,300,410,340,15,15,1);
				}
				else if(num == 10 && state6 == 0)
				{
					button(430,300,480,340,15,15,1);
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
	puthz(200,20,"预约停车",48,56,1);
	puthz(20,90,"车辆信息",24,28,1);
	puthz(520,95,"切换车辆",16,18,8);
	setfillstyle(1,15);
	fillellipse(160,280,5,5);
	fillellipse(320,280,5,5);
	fillellipse(480,280,5,5);
	setcolor(8);
	line(500,100,515,100);
	line(515,100,510,95);
	line(500,105,515,105);
	line(500,105,505,110);
	circle(160,280,5);
	circle(320,280,5);
	circle(480,280,5);
	bar(20,120,620,160);
	
	puthz(20,180,"预约停车",24,28,1);
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
	
	puthz(140,310,"停车日期",24,28,1);
	bar(255,300,500,340);
	puthz(340,310,"年",24,28,8);
	puthz(410,310,"月",24,28,8);
	puthz(480,310,"日",24,28,8);
	
	setfillstyle(1,GREEN);
	bar(180,420,260,450);
	puthz(195,425,"预约",24,28,1);
	setfillstyle(1,4);
	bar(380,420,460,450);
	puthz(395,425,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}