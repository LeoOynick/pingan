#include"common.h"
#include"insurance.h"

void insure(int *page, User *u)
{
	int num = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int cost = 0;
	int carid = 0;
	char charge[5];
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawinsure(u,&carid);
	
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
			if(state1 == 0 && state2 == 0 && state3 == 0)
			{
				setfillstyle(1,LIGHTCYAN);
				bar(270,435,370,455);
				puthz(270,435,"请选择保险！",16,20,RED);
			}
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(270,435,390,455);
				puthz(280,435,"购买成功！",16,20,RED);
				delay(800);
				*page = 6;
				return;
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
			delay(130);
			if(carid < 2)
			{
				carid += 1;
			}
			else
			{
				carid = 0;
			}
			setfillstyle(1,15);
			bar(20,160,620,200);
			show_car(u,78,162,1,&carid);
		}
		
		else if (mouse_press(535,235,545,245) == 2)   //基本险
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
		else if (mouse_press(535,235,545,245) == 1)
		{
			delay(150);
			choose(540,240,&state1);
		}
		
		else if (mouse_press(535,275,545,285) == 2)   //商业险
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
		else if (mouse_press(535,275,545,285) == 1)
		{
			delay(150);
			choose(540,280,&state2);
		}
		
		else if (mouse_press(535,315,545,325) == 2)   //交强险
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
		else if (mouse_press(535,315,545,325) == 1)
		{
			delay(150);
			choose(540,320,&state3);
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
		if(state1 == 0 && state2 == 0 && state3 == 0)
		{
			setfillstyle(1,LIGHTCYAN);
			bar(150,350,195,395);
		}
		else
			price(&state1,&state2,&state3,&state1,&state2,&state3,1000,800,1200,0,0,0,cost,charge,150,350);	
	}
}

void drawinsure(User *u,int *state)
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
	fillellipse(540,240,5,5);
	fillellipse(540,280,5,5);
	fillellipse(540,320,5,5);
	circle(540,240,5);
	circle(540,280,5);
	circle(540,320,5);
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
	puthz(200,230,"保额",24,28,1);
	puthz(200,270,"保额",24,28,1);
	puthz(200,310,"保额",24,28,1);
	settextstyle(1,0,1);
	outtextxy(280,230,"2.00");
	outtextxy(280,270,"1.00");
	outtextxy(280,310,"1.50");
	puthz(320,230,"万元",24,28,1);
	puthz(320,270,"万元",24,28,1);
	puthz(320,310,"万元",24,28,1);
	puthz(390,233,"价格",16,18,8);
	puthz(390,273,"价格",16,18,8);
	puthz(390,313,"价格",16,18,8);
	outtextxy(430,230,"1000");
	outtextxy(430,270,"800");
	outtextxy(430,310,"1200");
	puthz(480,233,"元",16,18,8);
	puthz(480,273,"元",16,18,8);
	puthz(480,313,"元",16,18,8);
	puthz(80,350,"总计",24,28,1);
	puthz(200,350,"元",24,28,1);
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
	
	show_car(u,78,162,1,state);
}