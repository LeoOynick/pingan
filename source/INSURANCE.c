#include"common.h"
#include"insurance.h"

void insure(int *page)
{
	int num = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawinsure();
	
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
		
		else if(mouse_press(180,400,260,430) == 2)   //购买
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(195,405,"购买",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			
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
		    //*page = 6;
			return;
		}
		
		else if (mouse_press(530,230,550,250) == 2)   //基本险
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
		else if (mouse_press(530,230,550,250) == 1)
		{
			delay(150);
			if(state1 == 0)
			{
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,RED);
				fillellipse(540,240,5,5);
				state1 = 1;
			}
			else
			{
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,LIGHTCYAN);
				fillellipse(540,240,7,7);
				state1 = 0;
			}
		}
		
		else if (mouse_press(530,270,550,290) == 2)   //商业险
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
		else if (mouse_press(530,270,550,290) == 1)
		{
			delay(150);
			if(state2 == 0)
			{
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,RED);
				fillellipse(540,280,5,5);
				state2 = 1;
			}
			else
			{
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,LIGHTCYAN);
				fillellipse(540,280,7,7);
				state2 = 0;
			}
		}
		
		else if (mouse_press(530,310,550,330) == 2)   //交强险
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
		else if (mouse_press(530,310,550,330) == 1)
		{
			delay(150);
			if(state3 == 0)
			{
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,RED);
				fillellipse(540,320,5,5);
				state3 = 1;
			}
			else
			{
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,LIGHTCYAN);
				fillellipse(540,320,7,7);
				state3 = 0;
			}
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
					puthz(195,405,"购买",24,28,1);
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

void drawinsure()
{
	setbkcolor(LIGHTCYAN);
	
	puthz(240,20,"买车险",48,56,1);
	puthz(20,120,"车辆信息",24,28,1);
	puthz(520,135,"切换车辆",16,18,8);
	setcolor(8);
	line(500,140,515,140);
	line(515,140,510,135);
	line(500,145,515,145);
	line(500,145,505,150);
	setfillstyle(1,15);
	bar(20,160,620,200);
	setcolor(15);
	setlinestyle(0,4,3);
	rectangle(60,220,580,260);
	rectangle(60,260,580,300);
	rectangle(60,300,580,340);
	setcolor(8);
	puthz(80,230,"基本险",24,28,1);
	puthz(80,270,"商业险",24,28,1);
	puthz(80,310,"交强险",24,28,1);
	puthz(280,230,"保额",24,28,1);
	puthz(280,270,"保额",24,28,1);
	puthz(280,310,"保额",24,28,1);
	settextstyle(1,0,1);
	outtextxy(360,230,"2.00");
	outtextxy(360,270,"1.00");
	outtextxy(360,310,"1.50");
	puthz(400,230,"万元",24,28,1);
	puthz(400,270,"万元",24,28,1);
	puthz(400,310,"万元",24,28,1);
	setlinestyle(0,4,3);
	circle(540,240,8);
	circle(540,280,8);
	circle(540,320,8);
	puthz(80,350,"总计",24,28,1);
	puthz(200,350,"万元",24,28,1);
	puthz(260,355,"（更多请关注“平安好车主”公众号）",16,18,8);
	
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(195,405,"购买",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}