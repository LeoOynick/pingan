#include"common.h"
#include"home.h"

void home(int *page,User *u)
{
	int num = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawhome(u);
	
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
		
		else if(mouse_press(115,95,205,205) == 2)   //买车险
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(115,95,205,205,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(135,185,"买车险",16,18,1);
				line(120,100,200,100);
				line(120,100,120,150);
				line(200,100,200,150);
				line(120,150,160,180);
				line(200,150,160,180);
				line(140,130,150,150);
				line(150,150,190,120);
			    num = 2;
		    }
			continue;
		}
		else if(mouse_press(115,95,205,205) == 1)
		{
			MouseS = 0;
			*page = 9;
			return;
		}
		
		else if(mouse_press(275,95,365,205) == 2)   //查保单
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(275,95,365,205,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(295,185,"查保单",16,18,1);
				line(280,100,280,180);
				line(360,100,360,180);
				line(280,100,360,100);
				line(280,180,320,160);
				line(360,180,320,160);
				circle(310,130,15);
				line(320,140,340,160);
			    num = 3;
		    }
			continue;
		}
		else if(mouse_press(275,95,365,205) == 1)
		{
			MouseS = 0;
			*page = 10;
			return;
		}
		
		else if(mouse_press(435,95,525,205) == 2)   //办理赔
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(435,95,525,205,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(455,185,"办理赔",16,18,1);
				line(440,100,520,100);
				line(440,100,440,180);
				line(440,180,480,180);
				line(520,100,520,140);
				line(480,180,520,140);
				line(465,130,495,130);
				line(465,145,495,145);
				line(480,130,480,160);
				line(480,130,470,120);
				line(480,130,490,120);
			    num = 4;
		    }
			continue;
		}
		else if(mouse_press(435,95,525,205) == 1)
		{
			MouseS = 0;
			*page = 11;
			return;
		}
		
		else if(mouse_press(115,255,205,365) == 2)   //查违章
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(115,255,205,365,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(135,345,"查违章",16,18,1);
				circle(160,300,40);
				line(200,340,190,330);
				line(140,300,180,300);
				line(140,290,180,290);
				line(140,310,180,310);
				line(180,310,170,320);
				line(160,280,160,325);
			    num = 5;
		    }
			continue;
		}
		else if(mouse_press(115,255,205,365) == 1)
		{
			MouseS = 0;
			*page = 12;
			return;
		}
		
		else if(mouse_press(275,255,365,365) == 2)   //预约停车
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(275,255,365,365,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(285,345,"预约停车",16,18,1);
				arc(320,300,0,180,40);
				line(320,340,280,300);
				line(320,340,360,300);
				line(310,300,330,300);
				line(310,280,330,280);
				arc(330,290,270,450,10);
				line(310,280,310,320);
			    num = 6;
		    }
		    continue;
		}
		else if(mouse_press(275,255,365,365) == 1)
		{
			MouseS = 0;
			*page = 13;
			return;
		}
		
		else if(mouse_press(435,255,525,365) == 2)   //车损测算
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(435,255,525,365,11,15,1);
				setcolor(1);
				setlinestyle(0,4,3);
				puthz(445,345,"车损测算",16,18,1);
				rectangle(440,260,520,340);
				line(450,330,510,270);
				line(465,270,465,300);
				line(450,285,480,285);
				line(495,300,510,300);
				line(485,320,510,320);
			    num = 7;
		    }
			continue;
		}
		else if(mouse_press(435,255,525,365) == 1)
		{
			MouseS = 0;
			*page = 14;
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
			    num = 8;
		    }
			continue;
		}
		else if(mouse_press(280,420,360,480) == 1)
		{
			*page = 7;
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
			    num = 9;
		    }
			continue;
		}
		else if(mouse_press(440,420,520,480) == 1)
		{
			MouseS = 0;
			*page = 8;
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
					puthz(135,185,"买车险",16,18,8);
					line(120,100,200,100);
					line(120,100,120,150);
					line(200,100,200,150);
					line(120,150,160,180);
					line(200,150,160,180);
					line(140,130,150,150);
					line(150,150,190,120);
				}
				else if(num == 3)
				{
					button(275,95,365,205,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
				    puthz(295,185,"查保单",16,18,8);
				    line(280,100,280,180);
				    line(360,100,360,180);
				    line(280,100,360,100);
				    line(280,180,320,160);
				    line(360,180,320,160);
				    circle(310,130,15);
				    line(320,140,340,160);
				}
				else if(num == 4)
				{
					button(435,95,525,205,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
					puthz(455,185,"办理赔",16,18,8);
					line(440,100,520,100);
					line(440,100,440,180);
					line(440,180,480,180);
					line(520,100,520,140);
					line(480,180,520,140);
					line(465,130,495,130);
					line(465,145,495,145);
					line(480,130,480,160);
					line(480,130,470,120);
					line(480,130,490,120);
				}
				else if(num == 5)
				{
					button(115,255,205,365,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
					puthz(135,345,"查违章",16,18,8);
					circle(160,300,40);
					line(200,340,190,330);
					line(140,300,180,300);
					line(140,290,180,290);
					line(140,310,180,310);
					line(180,310,170,320);
					line(160,280,160,325);
				}
				else if(num == 6)
				{
					button(275,255,365,365,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
					puthz(285,345,"预约停车",16,18,8);
					arc(320,300,0,180,40);
					line(320,340,280,300);
					line(320,340,360,300);
					line(310,300,330,300);
					line(310,280,330,280);
					arc(330,290,270,450,10);
					line(310,280,310,320);
				}
				else if(num == 7)
				{
					button(435,255,525,365,11,11,1);
				    setcolor(8);
				    setlinestyle(0,4,3);
					puthz(445,345,"车损测算",16,18,8);
					rectangle(440,260,520,340);
					line(450,330,510,270);
					line(465,270,465,300);
					line(450,285,480,285);
					line(495,300,510,300);
					line(485,320,510,320);
				}
				else if(num == 8)
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
				else if(num == 9)
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

void drawhome(User *u)
{
	setbkcolor(LIGHTCYAN);
	setfillstyle(1,3);
	bar(0,0,654,50);
	bar(0,420,120,480);
	bar(200,420,640,480);
	setfillstyle(1,15);
	fillellipse(25,25,24,24);
	setlinestyle(0,4,3);
	setcolor(9);
	circle(25,15,15);
	arc(25,72,60,120,40);
	
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
	
    setcolor(8);
	puthz(135,185,"买车险",16,18,8);   //买车险
	line(120,100,200,100);
	line(120,100,120,150);
	line(200,100,200,150);
	line(120,150,160,180);
	line(200,150,160,180);
	line(140,130,150,150);
	line(150,150,190,120);
	
	puthz(295,185,"查保单",16,18,8);   //查保单
	line(280,100,280,180);
	line(360,100,360,180);
	line(280,100,360,100);
	line(280,180,320,160);
	line(360,180,320,160);
	circle(310,130,15);
	line(320,140,340,160);
	
	puthz(455,185,"办理赔",16,18,8);   //办理赔
	line(440,100,520,100);
	line(440,100,440,180);
	line(440,180,480,180);
	line(520,100,520,140);
	line(480,180,520,140);
	line(465,130,495,130);
	line(465,145,495,145);
	line(480,130,480,160);
	line(480,130,470,120);
	line(480,130,490,120);
	
	puthz(135,345,"查违章",16,18,8);   //查违章
	circle(160,300,40);
	line(200,340,190,330);
	line(140,300,180,300);
	line(140,290,180,290);
	line(140,310,180,310);
	line(180,310,170,320);
	line(160,280,160,325);
	
	puthz(285,345,"预约停车",16,18,8);   //预约停车
	arc(320,300,0,180,40);
	line(320,340,280,300);
	line(320,340,360,300);
	line(310,300,330,300);
	line(310,280,330,280);
	arc(330,290,270,450,10);
	line(310,280,310,320);
	
	puthz(445,345,"车损测算",16,18,8);   //车损测算
	rectangle(440,260,520,340);
	line(450,330,510,270);
	line(465,270,465,300);
	line(450,285,480,285);
	line(495,300,510,300);
	line(485,320,510,320);
	
	setcolor(8);
	line(148,457,172,457);
	line(152,453,168,453);
	line(148,457,148,441);
	line(172,457,172,441);
	line(148,441,160,433);
	line(172,441,160,433);
	puthz(143,460,"首页",16,20,8);
	setcolor(15);
	arc(320,445,0,180,9);
	line(320,460,311,445);
	line(320,460,329,445);
	circle(320,445,4);
	puthz(303,460,"服务",16,20,15);
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
