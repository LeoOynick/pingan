#include"common.h"

void drawstart()
{
   

   setbkcolor(LIGHTCYAN);
   setfillstyle(1,YELLOW);
   bar(400,160,560,220);
   bar(400,260,560,320);
   bar(400,360,560,420);
   puthz(420,180,"用户注册",24,28,1);
   puthz(420,280,"用户登录",24,28,1);
   puthz(410,380,"管理员登录",24,28,1);
   puthz(220,40,"欢迎进入",48,56,1);
   puthz(140,80, "平安好车主系统",48,56,1);
   puthz(105,360,"用车就上好车主！",24,28,5);
   puthz(180,440,"车服务·车保险·车生活",24,28,6);

   setcolor(RED);
   arc(200,200,-30,210,60);
   line(200,320,148,230);
   line(200,320,252,230);
   circle(180,220,5);
   circle(220,220,5);
   arc(180,220,180,360,10);
   arc(220,220,180,360,10);
   line(190,220,210,220);
   line(170,220,160,220);
   line(240,220,230,220);
   arc(180,220,90,180,20);
   arc(220,220,0,90,20);
   arc(200,200,0,180,20);
   setfillstyle(1,4);
   floodfill(180,220,4);
   floodfill(220,220,4);
   floodfill(200,240,4);
   
   setfillstyle(1,LIGHTGRAY);
   bar(610,0,640,30);
   setcolor(1);
   line(610,0,640,30);
   line(640,0,610,30);
}

void start()
{
	int num = 0;
	
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	mouseinit();
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawstart();
	
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
			delay(1000);
			closegraph();
			exit(1);
		}
		
		if(mouse_press(400,160,560,220) == 2)   //用户注册
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(400,160,560,220,15,LIGHTGREEN,3);
				puthz(420,180,"用户注册",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(400,160,560,220) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		
		else if(mouse_press(400,260,560,320) == 2)   //用户登录
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(400,260,560,320,15,LIGHTGREEN,3);
				puthz(420,280,"用户登录",24,28,1);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(400,260,560,320) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		
		else if(mouse_press(400,360,560,420) == 2)   //管理员登录
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(400,360,560,420,15,LIGHTGREEN,3);
				puthz(410,380,"管理员登录",24,28,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(400,360,560,420) == 1)
		{
			MouseS = 0;
			//*func = 2;
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
					setfillstyle(1,YELLOW);
					bar(400,160,560,220);
					puthz(420,180,"用户注册",24,28,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,YELLOW);
					bar(400,260,560,320);
					puthz(420,280,"用户登录",24,28,1);
				}
				else if(num == 4)
				{
					setfillstyle(1,YELLOW);
					bar(400,360,560,420);
					puthz(410,380,"管理员登录",24,28,1);
				}
				num = 0;
			}
			continue;
		}
		
	}
}