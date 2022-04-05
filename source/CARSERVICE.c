#include"common.h"
#include"carservice.h"

void carserve(int *page)
{
	int num = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int cost = 0;
	char charge[5];
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawcarserve();
	
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
		
		else if(mouse_press(180,400,260,430) == 2)   //提交
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(195,405,"提交",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			puthz(280,435,"提交成功！",16,20,RED);
			delay(800);
			*page = 7;
			return;
		}
		
		else if(mouse_press(380,400,460,430) == 2)   //返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(380,400,460,430,15,12,1);
				puthz(395,405,"返回",24,28,1);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(380,400,460,430) == 1)
		{
			MouseS = 0;
		    *page = 7;
			return;
		}
		
		else if (mouse_press(520,135,600,155) == 2)   //切换车辆
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
		else if (mouse_press(520,135,600,155) == 1)
		{
			MouseS = 0;
		    
		}
		
		else if (mouse_press(95,290,105,300) == 2)   //洗车
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
		else if (mouse_press(95,290,105,300) == 1)
		{
			delay(150);
			choose(100,295,&state1);
		}
		
		else if (mouse_press(245,290,255,300) == 2)   //加油
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
		else if (mouse_press(245,290,255,300) == 1)
		{
			delay(150);
			choose(250,295,&state2);
		}
		
		else if (mouse_press(395,290,405,300) == 2)   //保养
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
		else if (mouse_press(395,290,405,300) == 1)
		{
			delay(150);
			choose(400,295,&state3);
		}
		
		else if (mouse_press(545,290,555,300) == 2)   //挪车
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(545,290,555,300) == 1)
		{
			delay(150);
			choose(550,295,&state4);
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
					bar(180,400,260,430);
					puthz(195,405,"提交",24,28,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,400,460,430);
					puthz(395,405,"返回",24,28,1);
				}
				num = 0;
			}
			continue;
		}
		price(&state1,&state2,&state3,&state4,&state2,&state3,100,240,800,150,0,0,cost,charge,320,330);
	}
}

void drawcarserve()
{
	setbkcolor(LIGHTCYAN);
	puthz(220,20,"车辆服务",48,56,1);
	puthz(20,120,"车辆信息",24,28,1);
	puthz(520,135,"切换车辆",16,18,8);
	setfillstyle(1,15);
	bar(20,160,620,200);
	fillellipse(100,295,5,5);
	fillellipse(250,295,5,5);
	fillellipse(400,295,5,5);
	fillellipse(550,295,5,5);
	setcolor(8);
	line(500,140,515,140);
	line(515,140,510,135);
	line(500,145,515,145);
	line(500,145,505,150);
	circle(100,295,5);
	circle(250,295,5);
	circle(400,295,5);
	circle(550,295,5);
	
	puthz(20,220,"选择服务项目",24,28,1);
	setcolor(15);
	setlinestyle(0,4,3);
	rectangle(20,250,170,310);
	rectangle(170,250,320,310);
	rectangle(320,250,470,310);
	rectangle(470,250,620,310);
	puthz(70,260,"洗车",24,28,8);
	puthz(220,260,"加油",24,28,8);
	puthz(370,260,"保养",24,28,8);
	puthz(520,260,"挪车",24,28,8);
	
	puthz(160,330,"共计消费：",24,28,1);
	puthz(400,335,"元",16,18,8);
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(195,405,"提交",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}