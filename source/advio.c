#include"common.h"
#include"advio.h"

void advio(int *page)
{
	int num = 0;
	int state = 0;
	char licensenum[7];
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawvio();
	
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
		else if(mouse_press(610,0,640,30) == 1) //exit
		{
			*page = 1;
			return;
		}
		
		else if(mouse_press(120,420,200,480) == 2)   //订单查询
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(120,420,200,480,11,11,8);
				puthz(143,430,"订单",16,20,8);
				puthz(143,450,"查询",16,20,8);
			    num = 2;
		    }
			continue;
		}
		else if(mouse_press(120,420,200,480) == 1)
		{
			MouseS = 0;
			*page = 20;
			return;
		}
		
		else if(mouse_press(440,420,520,480) == 2)   //理赔审批
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(440,420,520,480,11,11,8);
				puthz(463,430,"理赔",16,20,8);
				puthz(463,450,"审批",16,20,8);
			    num = 3;
		    }
			continue;
		}
		else if(mouse_press(440,420,520,480) == 1)
		{
			MouseS = 0;
			*page = 22;
			return;
		}
		
		else if(mouse_press(280,100,440,140) == 2)		//车牌号码
		{
			if (num == 0 && state == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(280,100,440,140,8,15,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(280,100,440,140) == 1)
		{
			MouseS = 0;
		    button(280,100,440,140,8,15,1);
			licensenum[0] = '\0';
			input(licensenum,280,105,6,15,2);
			if(strlen(licensenum) != 0)
				state = 1;
			else
				state = 0;
			continue;
		}		
		
		else if(mouse_press(190,380,250,410) == 2)		//查询
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(190,380,250,410,15,8,1);
				puthz(205,388,"查询",16,18,15);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(190,380,250,410) == 1)
		{
			MouseS = 0;
		    
			
		}
		
		else if(mouse_press(390,380,450,410) == 2)		//添加
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(390,380,450,410,15,8,1);
				puthz(405,388,"添加",16,18,15);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(390,380,450,410) == 1)
		{
			MouseS = 0;
		    
			
		}
		
		else if(mouse_press(540,60,630,80) == 2)   //退出登录
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 7;
			}	
		}
		else if(mouse_press(540,60,630,80) == 1)
		{
			MouseS = 0;
			delay(1000);
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
					button(120,420,280,480,3,3,1);
				    puthz(143,430,"订单",16,20,15);
					puthz(143,450,"查询",16,20,15);
				}	
				else if(num == 3)
				{
					button(440,420,520,480,3,3,1);
					puthz(463,430,"理赔",16,20,15);
					puthz(463,450,"审批",16,20,15);
				}	
				else if(num == 4 && state == 0)
				{
					button(280,100,440,140,15,15,1);
				}
				else if(num == 5)
				{
					button(190,380,250,410,7,7,1);
					puthz(205,388,"查询",16,18,1);
				}
				else if(num == 6)
				{
					button(390,380,450,410,7,7,1);
					puthz(405,388,"添加",16,18,1);
				}
				num = 0;
			}
			continue;
		}
	}
}

void drawvio()
{
	setbkcolor(LIGHTCYAN);
	puthz(560,60,"退出登录",16,18,8);
	setcolor(8);
	arc(550,67,100,440,7);
	line(550,63,550,58);
	setlinestyle(0,4,3);
	setfillstyle(1,3);
	bar(0,420,280,480);
	bar(360,420,640,480);
		
	puthz(150,20,"用户违章管理",48,56,1);
	puthz(110,110,"输入车牌",24,28,1);
	setfillstyle(1,15);
	bar(240,100,440,140);
	puthz(250,110,"鄂",24,28,1);
	setfillstyle(1,7);
	bar(190,380,250,410);
	bar(390,380,450,410);
	puthz(205,388,"查询",16,18,1);
	puthz(405,388,"添加",16,18,1);	
		
	setcolor(8);
	puthz(303,430,"违章",16,20,8);
	puthz(303,450,"管理",16,20,8);
	setcolor(15);
	puthz(143,430,"订单",16,20,15);
	puthz(143,450,"查询",16,20,15);
	puthz(463,430,"理赔",16,20,15);
	puthz(463,450,"审批",16,20,15);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}