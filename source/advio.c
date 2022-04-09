#include"common.h"
#include"advio.h"

void advio(int *page)
{
	int num = 0;
	int state = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	int state7 = 0;
	int state8 = 0;
	int state9 = 0;
	int state10 = 0;
	char licensenum[7];
	char year[5];
	char month[3];
	char day[3];
	char fine[5];
	char point[3];
	
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
		
		else if(mouse_press(300,100,470,140) == 2)		//车牌号码
		{
			if (num == 0 && state1 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(300,100,470,140,8,15,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(300,100,470,140) == 1)
		{
			MouseS = 0;
		    button(300,100,470,140,8,15,1);
			licensenum[0] = '\0';
			input(licensenum,300,105,6,15,2);
			if(strlen(licensenum) != 0)
				state1 = 1;
			else
				state1 = 0;
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
		    setfillstyle(1,LIGHTCYAN);
			bar(0,150,640,378);
			state = 0;
			
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
			drawadd();
			state = 1;
			
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
		
		if(mouse_press(255,150,340,190) == 2 && state == 1)		//年
		{
			if (num == 0 && state2 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(255,150,340,190,8,15,1);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(255,150,340,190) == 1 && state == 1)
		{
			MouseS = 0;
			button(255,150,340,190,8,15,1);
			year[0] = '\0';
			input(year,255,155,4,15,2);
			if(strlen(year) != 0)
				state2 = 1;
			else
				state2 = 0;
			continue;
		}
		
		else if(mouse_press(360,150,410,190) == 2 && state == 1)		//月
		{
			if (num == 0 && state3 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(360,150,410,190,8,15,1);
				num = 9;
			}
			continue;
		}
		else if (mouse_press(360,150,410,190) == 1 && state == 1)
		{
			MouseS = 0;
			button(360,150,410,190,8,15,1);
			month[0] = '\0';
			input(month,360,155,2,15,2);
			if(strlen(month) != 0)
				state3 = 1;
			else
				state3 = 0;
			continue;
		}
		
		else if(mouse_press(430,150,480,190) == 2 && state == 1)		//日
		{
			if (num == 0 && state4 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(430,150,480,190,8,15,1);
				num = 10;
			}
			continue;
		}
		else if (mouse_press(430,150,480,190) == 1 && state == 1)
		{
			MouseS = 0;
			button(430,150,480,190,8,15,1);
			day[0] = '\0';
			input(day,430,155,2,15,2);
			if(strlen(day) != 0)
				state4 = 1;
			else
				state4 = 0;
			continue;
		}
		
		else if (mouse_press(185,215,195,225) == 2 && state == 1)   //超速
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 11;
			}
			continue;
		}
		else if (mouse_press(185,215,195,225) == 1 && state == 1)
		{
			delay(150);
			choose(190,220,&state5);
			single(&state6,&state7,&state8,&state7,&state8,290,220,390,220,490,220,390,220,490,220);
		}
		
		else if (mouse_press(285,215,295,225) == 2 && state == 1)   //超载
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 12;
			}
			continue;
		}
		else if (mouse_press(285,215,295,225) == 1 && state == 1)
		{
			delay(150);
			choose(290,220,&state6);
			single(&state5,&state7,&state8,&state7,&state8,190,220,390,220,490,220,390,220,490,220);
		}
		
		else if (mouse_press(385,215,395,225) == 2 && state == 1)   //酒驾
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 13;
			}
			continue;
		}
		else if (mouse_press(385,215,395,225) == 1 && state == 1)
		{
			delay(150);
			choose(390,220,&state7);
			single(&state5,&state6,&state8,&state6,&state8,190,220,290,220,490,220,290,220,490,220);
		}
		
		else if (mouse_press(485,215,495,225) == 2 && state == 1)   //闯红灯
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 14;
			}
			continue;
		}
		else if (mouse_press(485,215,495,225) == 1 && state == 1)
		{
			delay(150);
			choose(490,220,&state8);
			single(&state5,&state6,&state7,&state6,&state7,190,220,290,220,390,220,290,220,390,220);
		}
		
		else if(mouse_press(340,250,425,290) == 2 && state == 1)		//罚款
		{
			if (num == 0 && state9 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(340,250,425,290,8,15,1);
				num = 15;
			}
			continue;
		}
		else if (mouse_press(340,250,425,290) == 1 && state == 1)
		{
			MouseS = 0;
			button(340,250,425,290,8,15,1);
			fine[0] = '\0';
			input(fine,340,255,4,15,2);
			if(strlen(fine) != 0)
				state9 = 1;
			else
				state9 = 0;
			continue;
		}
		
		else if(mouse_press(340,300,425,340) == 2 && state == 1)		//扣分
		{
			if (num == 0 && state9 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(340,300,425,340,8,15,1);
				num = 16;
			}
			continue;
		}
		else if (mouse_press(340,300,425,340) == 1 && state == 1)
		{
			MouseS = 0;
			button(340,300,425,340,8,15,1);
			point[0] = '\0';
			input(point,340,305,4,15,2);
			if(strlen(point) != 0)
				state10 = 1;
			else
				state10 = 0;
			continue;
		}
		
		else if(mouse_press(290,345,350,375) == 2 && state == 1)		//提交
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(290,345,350,375,15,8,1);
				puthz(305,353,"提交",16,18,15);
				num = 17;
			}
			continue;
		}
		else if (mouse_press(290,345,350,375) == 1 && state == 1)
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
				else if(num == 4 && state1 == 0)
				{
					button(300,100,470,140,15,15,1);
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
				else if(num == 8 && state == 1 && state2 == 0)
				{
					button(255,150,340,190,15,15,1);
				}
				else if(num == 9 && state == 1 && state3 == 0)
				{
					button(360,150,410,190,15,15,1);
				}
				else if(num == 10 && state == 1 && state4 == 0)
				{
					button(430,150,480,190,15,15,1);
				}
				else if(num == 15 && state == 1 && state9 == 0)
				{
					button(340,250,425,290,15,15,1);
				}
				else if(num == 16 && state == 1 && state10 == 0)
				{
					button(340,300,425,340,15,15,1);
				}
				else if(num == 17 && state == 1)
				{
					button(290,345,350,375,7,7,1);
					puthz(305,353,"提交",16,18,1);
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
	puthz(140,110,"输入车牌",24,28,1);
	setfillstyle(1,15);
	bar(260,100,470,140);
	puthz(270,110,"鄂",24,28,1);
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

void drawadd()
{
	setfillstyle(1,15);
	bar(255,150,500,190);
	puthz(140,160,"违章日期",24,28,1);
	puthz(340,160,"年",24,28,1);
	puthz(410,160,"月",24,28,1);
	puthz(480,160,"日",24,28,1);
	puthz(60,210,"违章类型",24,28,1);
	fillellipse(190,220,5,5);
	fillellipse(290,220,5,5);
	fillellipse(390,220,5,5);
	fillellipse(490,220,5,5);
	setcolor(8);
	circle(190,220,5);
	circle(290,220,5);
	circle(390,220,5);
	circle(490,220,5);
	puthz(200,210,"超速",24,28,1);
	puthz(300,210,"超载",24,28,1);
	puthz(400,210,"酒驾",24,28,1);
	puthz(500,210,"闯红灯",24,28,1);
	puthz(140,260,"处罚内容",24,28,1);
	puthz(280,260,"罚款",24,28,1);
	bar(340,250,425,290);
	puthz(430,265,"元",16,18,1);
	puthz(280,310,"扣分",24,28,1);
	bar(340,300,425,340);
	puthz(430,315,"分",16,18,1);
	setfillstyle(1,7);
	bar(290,345,350,375);
	puthz(305,353,"提交",16,18,1);
}