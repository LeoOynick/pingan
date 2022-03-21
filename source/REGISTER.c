#include"common.h"
#include"register.h"

void regist(int *page)
{
	int num=0;
	char str[6] = { '\0' };
	char name[15] = { '\0' };   //用户名（不超过12位）	
	char password[20] = { '\0' };   //密码（不超过16位）
	char confirm[20] = { '\0' };   //确认密码
	char ID[20] = { '\0' };   //身份证号（18位）
	char tele[12] = { '\0' };   //电话号码（11位）
	char code[6] = { '\0' };   //验证码（5位）
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawregist();
	
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
		
		else if(mouse_press(180,440,260,470) == 2)   //注册
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,440,260,470,15,10,1);
				puthz(195,445,"注册",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,440,260,470) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		
		else if(mouse_press(380,440,460,470) == 2)   //返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(380,440,460,470,15,12,1);
				puthz(395,445,"返回",24,28,1);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(380,440,460,470) == 1)
		{
			MouseS = 0;
		    *page = 0;
			return;
		}
		
		else if(mouse_press(80,100,560,130) == 2)   //用户名
		{
			if (num == 0 && state1 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,100,560,130,8,15,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(80,100,560,130) == 1)
		{
			MouseS = 0;
		    button(80,100,560,130,8,15,1);
			name[0] = '\0';
			input(name,85,102,12,15,2);
			if(strlen(name) != 0)
				state1 = 1;
			else
				state1 = 0;
			continue;
		}
		
		else if(mouse_press(80,160,560,190) == 2)   //密码
		{
			if (num == 0 && state2 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,160,560,190,8,15,1);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(80,160,560,190) == 1)
		{
			MouseS = 0;
		    button(80,160,560,190,8,15,1);
			password[0] = '\0';
			input(password,85,162,16,15,1);
			if(strlen(password) != 0)
				state2 = 1;
			else
				state2 = 0;
			continue;
		}
		
		else if(mouse_press(80,220,560,250) == 2)   //确认密码
		{
			if (num == 0 && state3 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,220,560,250,8,15,1);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(80,220,560,250) == 1)
		{
			MouseS = 0;
		    button(80,220,560,250,8,15,1);
			confirm[0] = '\0';
			input(confirm,85,222,16,15,1);
			if(strlen(confirm) != 0)
				state3 = 1;
			else
				state3 = 0;
			continue;
		}
		
		else if(mouse_press(80,280,560,310) == 2)   //身份证号
		{
			if (num == 0 && state4 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,280,560,310,8,15,1);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(80,280,560,310) == 1)
		{
			MouseS = 0;
		    button(80,280,560,310,8,15,1);
			ID[0] = '\0';
			input(ID,85,282,16,15,2);
			if(strlen(ID) != 0)
				state4 = 1;
			else
				state4 = 0;
			continue;
		}
		
		else if(mouse_press(80,340,560,370) == 2)   //电话号码
		{
			if (num == 0 && state5 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,340,560,370,8,15,1);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(80,340,560,370) == 1)
		{
			MouseS = 0;
		    button(80,340,560,370,8,15,1);
			tele[0] = '\0';
			input(tele,85,342,16,15,2);
			if(strlen(tele) != 0)
				state5 = 1;
			else
				state5 = 0;
			continue;
		}
		
		else if(mouse_press(160,400,560,430) == 2)   //验证码
		{
			if ((num == 0 || num == 10)&& state6 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(160,400,560,430,8,15,1);
				num = 9;
			}
			continue;
		}
		else if (mouse_press(160,400,560,430) == 1)
		{
			MouseS = 0;
		    button(160,400,560,430,8,15,1);
			code[0] = '\0';
			input(code,165,402,16,15,2);
			if(strlen(code) != 0)
				state6 = 1;
			else
				state6 = 0;
			continue;
		}
		
		else if(mouse_press(80,400,160,430) == 2)   //换验证码
		{
			if (num == 0 || num == 9)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 10;
			}
			continue;
		}
		else if (mouse_press(80,400,160,430) == 1)
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
					setfillstyle(1,2);
					bar(180,440,260,470);
					puthz(195,445,"注册",24,28,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,440,460,470);
					puthz(395,445,"返回",24,28,1);
				}
				
				else if(num == 4 && state1 == 0)
				{
					button(80,100,560,130,15,15,1);
				}
				else if(num == 5 && state2 == 0)
				{
					button(80,160,560,190,15,15,1);
				}
				else if(num == 6 && state3 == 0)
				{
					button(80,220,560,250,15,15,1);
				}
				else if(num == 7 && state4 == 0)
				{
					button(80,280,560,310,15,15,1);
				}
				else if(num == 8 && state5 == 0)
				{
					button(80,340,560,370,15,15,1);
				}
				else if(num == 9 && state6 == 0)
				{
					button(160,400,560,430,15,15,1);
				}
				num=0;
			}
			continue;
		}
	}
}

void drawregist()
{
	setbkcolor(11);
	setfillstyle(1,15);
	bar(80,100,560,130);
    bar(80,160,560,190);
    bar(80,220,560,250);
	bar(80,280,560,310);
    bar(80,340,560,370);
    bar(160,400,560,430);
	setfillstyle(1,7);
	bar(80,400,160,430);
	puthz(80,80,"用户名",16,20,1);
    puthz(80,140,"密码",16,20,1);
    puthz(80,200,"确认密码",16,20,1);
    puthz(80,260,"身份证号",16,20,1);
    puthz(80,320, "电话号码",16,20,1);
    puthz(80,380,"验证码",16,20,1);
	
	setfillstyle(1,2);
	bar(180,440,260,470);
	setfillstyle(1,4);
	bar(380,440,460,470);
	puthz(195,445,"注册",24,28,1);
	puthz(395,445,"返回",24,28,1);
	puthz(200,20,"用户注册",48,56,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}
