#include"common.h"

void drawservice()
{
	setbkcolor(LIGHTCYAN);
	setfillstyle(1,3);
	bar(0,0,654,50);
	bar(0,420,280,480);
	bar(360,420,640,480);
	setfillstyle(1,15);
	fillellipse(25,25,24,24);
	setlinestyle(0,4,3);
	setcolor(9);
	circle(25,15,15);
	arc(25,72,60,120,40);
    setcolor(8);
	
	puthz(125,185,"车辆服务",16,18,8);   //车辆服务
	line(120,170,200,170);
	line(120,170,120,140);
	line(200,170,200,140);
	line(120,140,130,140);
	line(200,140,190,140);
	line(130,140,145,120);
	line(190,140,175,120);
	line(145,120,175,120);
	circle(130,155,3);
	circle(190,155,3);
	line(130,168,130,175);
	line(190,168,190,175);
	
	puthz(445,185,"年检代办",16,18,8);   //年检代办
	line(440,100,520,100);
	line(440,100,440,150);
	line(520,100,520,150);
	line(440,150,480,180);
	line(520,150,480,180);
	puthz(465,115,"检",32,28,8);
	
	puthz(125,345,"道路救援",16,18,8);   //道路救援
	line(120,340,200,340);
	line(120,340,160,270);
	line(200,340,160,270);
	setfillstyle(1,8);
	bar(158,290,162,320);
	fillellipse(160,330,2,2);
	
	puthz(445,345,"服务地图",16,18,8);   //服务地图
	circle(480,295,5);
	arc(480,295,330,570,12);
	line(480,315,470,301);
	line(480,315,490,301);
	line(470,301,440,315);
	line(490,301,520,315);
	line(440,315,480,335);
	line(520,315,480,335);
	
	arc(320,445,0,180,9);
	line(320,460,311,445);
	line(320,460,329,445);
	circle(320,445,4);
	puthz(303,460,"服务",16,20,8);
	setcolor(15);
	line(148,457,172,457);
	line(152,453,168,453);
	line(148,457,148,441);
	line(172,457,172,441);
	line(148,441,160,433);
	line(172,441,160,433);
	puthz(143,460,"首页",16,20,15);
	circle(480,445,12);
	line(480,440,480,444);
	line(474,440,474,444);
	puthz(463,460,"我的",16,20,15);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}

void main()
{
	int num = 0;
	
	int gdriver=VGA;
    int gmode=VGAHI;
    initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	
	mouseinit();
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawservice();
	
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
		
		else if(mouse_press(115,95,205,205) == 2)   //车辆服务
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(115,95,205,205,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(125,185,"车辆服务",16,18,1);
				line(120,170,200,170);
				line(120,170,120,140);
				line(200,170,200,140);
				line(120,140,130,140);
				line(200,140,190,140);
				line(130,140,145,120);
				line(190,140,175,120);
				line(145,120,175,120);
				circle(130,155,3);
				circle(190,155,3);
				line(130,168,130,175);
				line(190,168,190,175);
			    num = 2;
		    }
			continue;
		}
		else if(mouse_press(115,95,205,205) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		
		else if(mouse_press(435,95,525,205) == 2)   //年检代办
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(435,95,525,205,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(445,185,"年检代办",16,18,1);
				line(440,100,520,100);
				line(440,100,440,150);
				line(520,100,520,150);
				line(440,150,480,180);
				line(520,150,480,180);
				puthz(465,115,"检",32,28,1);
			    num = 3;
		    }
			continue;
		}
		else if(mouse_press(435,95,525,205) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		
		else if(mouse_press(115,255,205,365) == 2)   //道路救援
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(115,255,205,365,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(125,345,"道路救援",16,18,1);
				line(120,340,200,340);
				line(120,340,160,270);
				line(200,340,160,270);
				setfillstyle(1,1);
				bar(158,290,162,320);
				fillellipse(160,330,2,2);
			    num = 4;
		    }
			continue;
		}
		else if(mouse_press(115,255,205,365) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		
		else if(mouse_press(435,255,525,365) == 2)   //服务地图
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(435,255,525,365,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(445,345,"服务地图",16,18,1);
				circle(480,295,5);
				arc(480,295,330,570,12);
				line(480,315,470,301);
				line(480,315,490,301);
				line(470,301,440,315);
				line(490,301,520,315);
				line(440,315,480,335);
				line(520,315,480,335);
			    num = 5;
		    }
			continue;
		}
		else if(mouse_press(435,255,525,365) == 1)
		{
			MouseS = 0;
			//*func = 2;
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
			    num = 6;
		    }
			continue;
		}
		else if(mouse_press(120,420,400,480) == 1)
		{
			MouseS = 0;
			//*func = 2;
			return;
		}
		
		else if(mouse_press(440,420,520,480) == 2)   //我的
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(440,420,520,480,11,11,8);
				setcolor(8);
				setlinestyle(0,4,3);
				circle(480,445,12);
				line(483,440,483,444);
				line(477,440,477,444);
				puthz(463,460,"我的",16,20,8);
			    num = 7;
		    }
			continue;
		}
		else if(mouse_press(440,420,520,480) == 1)
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
					button(115,95,205,205,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
				    puthz(125,185,"车辆服务",16,18,8);
					line(120,170,200,170);
					line(120,170,120,140);
					line(200,170,200,140);
					line(120,140,130,140);
					line(200,140,190,140);
					line(130,140,145,120);
					line(190,140,175,120);
					line(145,120,175,120);
					circle(130,155,3);
					circle(190,155,3);
					line(130,168,130,175);
					line(190,168,190,175);
				}
				else if(num == 3)
				{
					button(435,95,525,205,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
					puthz(445,185,"年检代办",16,18,8);
					line(440,100,520,100);
					line(440,100,440,150);
					line(520,100,520,150);
					line(440,150,480,180);
					line(520,150,480,180);
					puthz(465,115,"检",32,28,8);
				}
				else if(num == 4)
				{
					button(115,255,205,365,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
					puthz(125,345,"道路救援",16,18,8);
					line(120,340,200,340);
					line(120,340,160,270);
					line(200,340,160,270);
					setfillstyle(1,8);
					bar(158,290,162,320);
					fillellipse(160,330,2,2);
				}
				else if(num == 5)
				{
					button(435,255,525,365,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
					puthz(445,345,"服务地图",16,18,8);
					circle(480,295,5);
					arc(480,295,330,570,12);
					line(480,315,470,301);
					line(480,315,490,301);
					line(470,301,440,315);
					line(490,301,520,315);
					line(440,315,480,335);
					line(520,315,480,335);
				}
				else if(num == 6)
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
				else if(num == 7)
				{
					button(440,420,520,480,3,3,1);
				    setcolor(15);
				    setlinestyle(0,4,3);
				    circle(480,445,12);
				    line(480,440,480,444);
					line(474,440,474,444);
				    puthz(463,460,"我的",16,20,15);
				}	
				num = 0;
			}
			continue;
		}
	}
}