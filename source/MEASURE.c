#include"common.h"
#include"measure.h"

void measure(int *page)
{
	int num = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	int cost = 0;
	char charge[5];
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawmeasure();
	
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
		
		else if(mouse_press(180,400,260,430) == 2)   //测算
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(195,405,"测算",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			if(state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0 && state5 == 0 && state6 == 0)
			{
				setfillstyle(1,LIGHTCYAN);
				bar(340,300,390,340);
				puthz(220,165,"请选择损坏部位！",16,18,RED);
			}
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(220,165,400,185);
				price(&state1,&state2,&state3,&state4,&state5,&state6,1000,1500,600,800,800,3000,cost,charge,340,300);
			}
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
		    *page = 6;
			return;
		}
		
		else if (mouse_press(195,205,205,215) == 2)   //车胎
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
		else if (mouse_press(195,205,205,215) == 1)
		{
			delay(150);
			choose(200,210,&state1);
		}
		
		else if (mouse_press(355,205,365,215) == 2)   //引擎盖
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
		else if (mouse_press(355,205,365,215) == 1)
		{
			delay(150);
			choose(360,210,&state2);
		}
		
		else if (mouse_press(515,205,525,215) == 2)   //保险杠
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
		else if (mouse_press(515,205,525,215) == 1)
		{
			delay(150);
			choose(520,210,&state3);
		}
		
		else if (mouse_press(195,245,205,255) == 2)   //车灯
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
		else if (mouse_press(195,245,205,255) == 1)
		{
			delay(150);
			choose(200,250,&state4);
		}
		
		else if (mouse_press(355,245,365,255) == 2)   //后视镜
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
		else if (mouse_press(355,245,365,255) == 1)
		{
			delay(150);
			choose(360,250,&state5);
		}
		
		else if (mouse_press(515,245,525,255) == 2)   //车门
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 9;
			}
			continue;
		}
		else if (mouse_press(515,245,525,255) == 1)
		{
			delay(150);
			choose(520,250,&state6);
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
					puthz(195,405,"测算",24,28,1);
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
	}
}


void drawmeasure()
{
	setbkcolor(LIGHTCYAN);
	puthz(200,20,"车损测算",48,56,1);
	puthz(20,160,"选择损坏部位",24,28,1);
	setfillstyle(1,15);
	fillellipse(200,210,5,5);
	fillellipse(360,210,5,5);
	fillellipse(520,210,5,5);
	fillellipse(200,250,5,5);
	fillellipse(360,250,5,5);
	fillellipse(520,250,5,5);
	setcolor(8);
	circle(200,210,5);
	circle(360,210,5);
	circle(520,210,5);
	circle(200,250,5);
	circle(360,250,5);
	circle(520,250,5);
	setlinestyle(0,4,3);
	setcolor(15);
	rectangle(80,190,560,270);
	line(80,230,560,230);
	line(240,190,240,270);
	line(400,190,400,270);
	puthz(90,200,"车胎",24,28,1);
	puthz(250,200,"引擎盖",24,28,1);
	puthz(410,200,"保险杠",24,28,1);
	puthz(90,240,"车灯",24,28,1);
	puthz(250,240,"后视镜",24,28,1);
	puthz(410,240,"车门",24,28,1);
	puthz(100,300,"预计维修费用为：",24,28,1);
	puthz(400,305,"元",24,28,1);
	puthz(120,330,"注：预计维修费用仅供参考。",16,18,8);
	
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(195,405,"测算",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}