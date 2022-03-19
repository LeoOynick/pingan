#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"HZ.H"
#include"mouse.h"

void drawregist()
{
	setbkcolor(11);
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
	setfillstyle(1,14);
	bar(380,440,460,470);
	puthz(195,445,"注册",24,28,8);
	puthz(395,445,"返回",24,28,8);
	
	puthz(200,20,"用户注册",48,56,1);
	
	setfillstyle(1,LIGHTGRAY);
   bar(610,0,640,30);
   setcolor(1);
   line(610,0,640,30);
   line(640,0,610,30);
}

void main()
{
	int num=0;
	char str[5] = { '\0' };
	
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	mouseinit();
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawregist();
	
	while(1)
    {
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(180,440,260,470) == 2)
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,LIGHTGREEN);
				bar(180,440,260,470);
				setcolor(15);
				rectangle(180,440,260,470);
				puthz(195,445,"注册",24,28,1);
				num = 1;
			}
			continue;
		}
		else if (mouse_press(180,440,260,470) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		else if(mouse_press(380,440,460,470) == 2)
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,LIGHTGREEN);
				bar(380,440,460,470);
				setcolor(15);
				rectangle(380,440,460,470);
				puthz(395,445,"返回",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(380,440,460,470) == 1)
		{
			MouseS = 0;
		    //*func = 2;
			return;
		}
		else if(mouse_press(610,0,640,30) == 2)
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
			    setfillstyle(1,RED);
			    bar(610,0,640,30);
			    setcolor(15);
			    line(610,0,640,30);
				line(640,0,610,30);
			    num = 3;
		    }
		continue;
		}
		else if(mouse_press(610,0,640,30) == 1)
		{
			delay(1000);
			closegraph();
			exit(1);
		}
		else if(mouse_press(80,100,560,130) == 2)
		{
			if (num == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				setfillstyle(1,LIGHTGRAY);
				bar(80,100,560,130);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(80,100,560,130) == 1)
		{
			MouseS = 0;
		    //*func = 2;
			return;
		}
	}
}