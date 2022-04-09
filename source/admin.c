#include"common.h"
#include"admin.h"

void administ(int *page)
{
	int num=0;
	char password[20] = { '\0' };   //密码（不超过16位）
	int state = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawadminist();
	
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
		
		else if(mouse_press(180,400,260,430) == 2)   //登录
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(195,405,"登录",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			*page = 20;
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
		    *page = 0;
			return;
		}
		
		else if(mouse_press(80,240,560,270) == 2)   //管理员密码
		{
			if (num == 0 && state == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,240,560,270,8,15,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(80,240,560,270) == 1)
		{
			MouseS = 0;
		    button(80,240,560,270,8,15,1);
			password[0] = '\0';
			input(password,85,242,16,15,1);
			if(strlen(password) != 0)
				state = 1;
			else
				state = 0;
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
					bar(180,400,260,430);
					puthz(195,405,"登录",24,28,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,400,460,430);
					puthz(395,405,"返回",24,28,1);
				}
				else if(num == 4 && state == 0)
				{
					button(80,240,560,270,15,15,1);
				}
				num=0;
			}
			continue;
		}
	}
}

void drawadminist()
{
	setbkcolor(LIGHTCYAN);
	setlinestyle(0,4,3);
    
	setfillstyle(1,15);
    bar(80,240,560,270);
	
	setfillstyle(1,2);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	
	setcolor(1);
	puthz(80,220,"请输入管理员密码",16,20,1);
	puthz(195,405,"登录",24,28,1);
	puthz(395,405,"返回",24,28,1);
	puthz(180,50,"管理员登录",48,56,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}
