#include"common.h"
#include"mine.h"

void mine(int *page, User *u, int *usernum, int *carnum)
{
	int num = 0;
	int buttonpos = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawmine(u,usernum,carnum,&buttonpos);
	
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
		
		else if(mouse_press(120,420,200,480) == 2)   //首页
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(120,420,200,480,11,11,8);
				setcolor(8);
				setlinestyle(0,4,3);
				line(148,457,172,457);
				line(152,453,168,453);
				line(148,457,148,441);
				line(172,457,172,441);
				line(148,441,160,433);
				line(172,441,160,433);
				puthz(143,460,"首页",16,20,8);
			    num = 2;
		    }
			continue;
		}
		else if(mouse_press(120,420,200,480) == 1)
		{
			MouseS = 0;
			*page = 6;
			return;
		}
		
		else if(mouse_press(280,420,360,480) == 2)   //服务
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(280,420,360,480,11,11,8);
				setcolor(8);
				setlinestyle(0,4,3);
				arc(320,445,0,180,9);
				line(320,460,311,445);
				line(320,460,329,445);
				circle(320,445,4);
				puthz(303,460,"服务",16,20,8);
			    num = 3;
		    }
			continue;
		}
		else if(mouse_press(280,420,360,480) == 1)
		{
			MouseS = 0;
			*page = 7;
			return;
		}
		
		else if(mouse_press(20,160+ 90* buttonpos,620,200+ 90* buttonpos) == 2)   //添加车辆
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 4;
			}	
		}
		else if(mouse_press(20,160+ 90* buttonpos,620,200+ 90* buttonpos) == 1)
		{
			/*if(*carnum == -1)
			{
				button(0,0,900,900,LIGHTCYAN,LIGHTCYAN,3);	//覆盖
				button(200,200-20,430,300-20,CYAN,LIGHTGRAY,3);				
				puthz(235,238-20, "绑定已达上限", 24, 28, BLUE);
				delay(1500);
				*page = 8;
				return;
				//puthz(280, 200, "绑定已达上限", 32, 34, RED);
			}
			else
			{*/

				MouseS = 0;
				*page = 19;
				return;
			//}
		}
		
		else if(mouse_press(520,135,600,155) == 2)   //车辆管理
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 5;
			}	
		}
		else if(mouse_press(520,135,600,155) == 1)
		{
			MouseS = 0;
			//*page = 2;
			return;
		}
		
		else if(mouse_press(540,60,630,80) == 2)   //退出登录
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 6;
			}	
		}
		else if(mouse_press(540,60,630,80) == 1)
		{
			MouseS = 0;
			delay(500);
			*page = 0;
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
					button(120,420,200,480,3,3,1);
				    setcolor(15);
				    setlinestyle(0,4,3);
				    line(148,457,172,457);
					line(152,453,168,453);
					line(148,457,148,441);
					line(172,457,172,441);
					line(148,441,160,433);
					line(172,441,160,433);
					puthz(143,460,"首页",16,20,15);
				}	
				else if(num == 3)
				{
					button(280,420,360,480,3,3,1);
				    setcolor(15);
				    setlinestyle(0,4,3);
				    arc(320,445,0,180,9);
				    line(320,460,311,445);
				    line(320,460,329,445);
				    circle(320,445,4);
				    puthz(303,460,"服务",16,20,15);
				}
                num = 0;				
			}
			continue;
		}	
	}
}

void drawmine(User *u, int * usernum, int *carnum, int *buttonpos)
{
	output_userinfo(u,usernum,carnum);
	setbkcolor(LIGHTCYAN);
	setfillstyle(1,3);
	bar(0,0,654,50);
	bar(0,420,440,480);
	bar(520,420,640,480);
	setfillstyle(1,15);
	fillellipse(25,25,24,24);
	
	if(strlen(u->name) == 0)
	{
		outtextxy(60,24,"error");
	}	
	else
	{
		puthz(60, 17, "您好，", 16, 18, WHITE);
		setcolor(WHITE);
		settextstyle(3, HORIZ_DIR, 2); //2,3
		outtextxy(110, 10, u->name);
	}
	
	puthz(560,60,"退出登录",16,18,8);
	setcolor(8);
	arc(550,67,100,440,7);
	line(550,63,550,58);
	
	setlinestyle(0,4,3);
	setcolor(9);
	circle(25,15,15);
	arc(25,72,60,120,40);
	
	setcolor(15);
	arc(320,445,0,180,9);
	line(320,460,311,445);
	line(320,460,329,445);
	circle(320,445,4);
	puthz(303,460,"服务",16,20,15);
	line(148,457,172,457);
	line(152,453,168,453);
	line(148,457,148,441);
	line(172,457,172,441);
	line(148,441,160,433);
	line(172,441,160,433);
	puthz(143,460,"首页",16,20,15);
	setcolor(8);
	circle(480,445,12);
	line(483,440,483,444);
	line(477,440,477,444);
	puthz(463,460,"我的",16,20,8);
	
	puthz(20,120-10,"我的爱车",24,28,1);
	puthz(520,135-20,"车辆管理",16,18,8);
	line(600,142-20,595,137-20);
	line(600,142-20,595,147-20);
	
	/*setfillstyle(1,15);
	bar(20,160,620,200);
	setcolor(8);
	line(185,180,215,180);
	line(200,165,200,195);
	puthz(280,170,"立即添加车辆",24,28,8);*/
	
	*buttonpos = show_car(u,80, 170, 2);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}
