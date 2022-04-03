#include"common.h"
#include"enter.h"

void enter(int *page)
{
	int num=0;
	char inputcode[6] = { '\0' };
	char str[6] = { '\0' };
	char name[15] = { '\0' };   //用户名（不超过12位）	
	char password[20] = { '\0' };   //密码（不超过16位）
	char code[6] = { '\0' };   //验证码（5位）
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawenter();
	
	settextstyle(0,0,2);
	captcha(code);
	outtextxy(80,318,code);
	
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
			*page = 6;
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
		
		else if(mouse_press(280,360,350,380) == 2)   //忘记密码
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
		else if (mouse_press(280,360,350,380) == 1)
		{
			MouseS = 0;
		    *page = 5;
			return;
		}

        else if(mouse_press(80,170,560,200) == 2)   //用户名
		{
			if (num == 0 && state1 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,170,560,200,8,15,1);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(80,170,560,200) == 1)
		{
			MouseS = 0;
		    button(80,170,560,200,8,15,1);
			name[0] = '\0';
			input(name,85,172,12,15,2);
			if(strlen(name) != 0)
				state1 = 1;
			else
				state1 = 0;
			continue;
		}
		
		else if(mouse_press(80,240,560,270) == 2)   //密码
		{
			if (num == 0 && state2 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,240,560,270,8,15,1);
				num = 6;
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
				state2 = 1;
			else
				state2 = 0;
			continue;
		}
		
		else if(mouse_press(160,310,560,340) == 2)   //验证码
		{
			if ((num == 0 || num == 8)&& state3 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(160,310,560,340,8,15,1);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(160,310,560,340) == 1)
		{
			MouseS = 0;
		    button(160,310,560,340,8,15,1);
			inputcode[0] = '\0';
			input(inputcode,165,312,5,15,2);
			if(strlen(inputcode) != 0)
				state3 = 1;
			else
				state3 = 0;
			continue;
		}
		
		else if(mouse_press(80,310,160,340) == 2)   //换验证码
		{
			if (num == 0 || num == 7)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(80,310,160,340) == 1)
		{
			//MouseS = 0;
			button(80,310,160,340,7,7,1);
			settextstyle(0,0,2);
			captcha(code);
			setcolor(1);
			outtextxy(80,318,code);
		    
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
				else if(num == 5 && state1 == 0)
				{
					button(80,170,560,200,15,15,1);
				}
				else if(num == 6 && state2 == 0)
				{
					button(80,240,560,270,15,15,1);
				}
				else if(num == 7 && state3 == 0)
				{
					button(160,310,560,340,15,15,1);
				}
				num=0;
			}
			continue;
		}
	}
}

void drawenter()
{
	setbkcolor(LIGHTCYAN);
	setlinestyle(0,4,3);
    setfillstyle(1,15);
	bar(80,170,560,200);
    bar(80,240,560,270);
    bar(160,310,560,340);
	setfillstyle(1,LIGHTGRAY);
	bar(80,310,160,340);
	puthz(80,150,"用户名",16,20,1);
    puthz(80,220,"密码",16,20,1);
    puthz(80,290,"验证码",16,20,1);
	
	setfillstyle(1,2);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(195,405,"登录",24,28,1);
	puthz(395,405,"返回",24,28,1);
	puthz(280,360,"忘记密码",16,18,DARKGRAY);
	puthz(200,50,"用户登录",48,56,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}
