#include"common.h"
#include"mine.h"

void mine(int *page, User *u, int *usernum, int *carnum)
{
	int num = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawmine(u,usernum,carnum);
	
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
		else if(strlen(u->car[0].licensenum) == 0 && strlen(u->car[1].licensenum) == 0 
				&& strlen(u->car[2].licensenum) == 0 &&(mouse_press(20,160+ 90* 0,620,200+ 90* 0) == 2))   //添加车辆
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 4;
			}	
		}
		else if(strlen(u->car[0].licensenum) == 0 && strlen(u->car[1].licensenum) == 0 
				&& strlen(u->car[2].licensenum) == 0 && (mouse_press(20,160+ 90* 0,620,200+ 90* 0) == 1))
		{
				MouseS = 0;
				*page = 19;
				return;
		}
		else if(strlen(u->car[0].licensenum) != 0 && strlen(u->car[1].licensenum) == 0 
				&&(mouse_press(20,160+ 90* 1,620,200+ 90* 1) == 2))   //添加车辆 
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 4;
			}	
		}
		else if(strlen(u->car[0].licensenum) != 0 && strlen(u->car[1].licensenum) == 0 
				&& (mouse_press(20,160+ 90* 1,620,200+ 90* 1) == 1))
		{
				MouseS = 0;
				*page = 19;
				return;
		}
		else if(strlen(u->car[0].licensenum) != 0 && strlen(u->car[1].licensenum) != 0 
				&& strlen(u->car[2].licensenum) == 0 &&(mouse_press(20,160+ 90* 2,620,200+ 90* 2) == 2))   //添加车辆 //2 = rescue
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 4;
			}	
		}
		else if(strlen(u->car[0].licensenum) != 0 && strlen(u->car[1].licensenum) != 0
				&& strlen(u->car[2].licensenum) == 0&& (mouse_press(20,160+ 90* 2,620,200+ 90* 2) == 1))
		{
				MouseS = 0;
				*page = 19;
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
		else if((mouse_press(510,205,558,228) == 2) && strlen(u->car[0].licensenum) != 0) //bar(560 - 50, 202 + 3 + 65 * i, 608-50, 225+3 + 65 * i);
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(510,205,558,228, WHITE, LIGHTRED);
				puthz(568 -50, 206 + 3 + 65 * 0, "删除", 16, 18, WHITE);
				num = 7;
			}
		}
		else if((mouse_press(510,205,558,228) == 1) && strlen(u->car[0].licensenum) != 0)
		{
			MouseS = 0;
			del_cardata(usernum,1);
			output_userinfo(u,usernum,carnum);
			show_car(u,80, 170, 2);
			*page = 8;
			return;
		}
		else if((mouse_press(510,270,558,293) == 2) && strlen(u->car[1].licensenum) != 0) //bar(560 - 50, 202 + 3 + 65 * i, 608-50, 225+3 + 65 * i);
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(510,270,558,293, WHITE, LIGHTRED);
				puthz(568 -50, 206 + 3 + 65 * 1, "删除", 16, 18, WHITE);
				num = 8;
			}
		}
		else if((mouse_press(510,270,558,293) == 1) && strlen(u->car[1].licensenum) != 0)
		{
			MouseS = 0;
			del_cardata(usernum,2);
			output_userinfo(u,usernum,carnum);
			show_car(u,80, 170, 2);
			*page = 8;
			return;
		}
		else if((mouse_press(510,335,558,358) == 2) && strlen(u->car[2].licensenum) != 0) //bar(560 - 50, 202 + 3 + 65 * i, 608-50, 225+3 + 65 * i);
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(510,335,558,358, WHITE, LIGHTRED);
				puthz(568 -50, 206 + 3 + 65 * 2, "删除", 16, 18, WHITE);
				num = 9;
			}
		}
		else if(mouse_press(510,335,558,358) == 1 && strlen(u->car[2].licensenum) != 0)
		{
			MouseS = 0;
			del_cardata(usernum,3);
			output_userinfo(u,usernum,carnum);
			show_car(u,80, 170, 2);
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
				else if (num == 7 && strlen(u->car[0].licensenum) != 0)
				{
					setfillstyle(1,RED);
					bar(560 - 50, 202 + 3 + 65 * 0, 608-50, 225+3 + 65 * 0);
					puthz(568 -50, 206 + 3 + 65 * 0, "删除", 16, 18, WHITE);
				}
				else if (num == 8 && strlen(u->car[1].licensenum) != 0)
				{
					setfillstyle(1,RED);
					bar(560 - 50, 202 + 3 + 65 * 1, 608-50, 225+3 + 65 * 1);
					puthz(568 -50, 206 + 3 + 65 * 1, "删除", 16, 18, WHITE);
				}
				else if (num == 9 && strlen(u->car[2].licensenum) != 0)
				{
					setfillstyle(1,RED);
					bar(560 - 50, 202 + 3 + 65 * 2, 608-50, 225+3 + 65 * 2);
					puthz(568 -50, 206 + 3 + 65 * 2, "删除", 16, 18, WHITE);
				}
                num = 0;				
			}
			continue;
		}	
	}
}

void drawmine(User *u, int * usernum, int *carnum)
{
	int i,j;
	output_userinfo(u,usernum,carnum);
	setbkcolor(LIGHTCYAN);
	puthz(560,60,"退出登录",16,18,8);
	setcolor(8);
	arc(550,67,100,440,7);
	line(550,63,550,58);
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
	show_car(u,80, 170, 2);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
	
	if(strlen(u->car[0].licensenum) != 0)
	{
		setfillstyle(1, RED);
		bar(560 - 50, 202 + 3 + 65 * 0, 608-50, 225+3 + 65 * 0);
		puthz(568 -50, 206 + 3 + 65 * 0, "删除", 16, 18, WHITE);
		setfillstyle(1, WHITE);
	}
	if(strlen(u->car[1].licensenum) != 0)
	{
		setfillstyle(1, RED);
		bar(560 - 50, 202 + 3 + 65 * 1, 608-50, 225+3 + 65 * 1);
		puthz(568 -50, 206 + 3 + 65 * 1, "删除", 16, 18, WHITE);
		setfillstyle(1, WHITE);
	}
	if(strlen(u->car[2].licensenum) != 0)
	{
		setfillstyle(1, RED);
		bar(560 - 50, 202 + 3 + 65 * 2, 608-50, 225+3 + 65 * 2);
		puthz(568 -50, 206 + 3 + 65 * 2, "删除", 16, 18, WHITE);
	}
	if(strlen(u->car[0].licensenum) == 0 && strlen(u->car[1].licensenum) == 0 && strlen(u->car[2].licensenum) == 0)
	{
		setfillstyle(1, WHITE);
		setcolor(DARKGRAY);
		bar(20 ,160 + 90* 0,620,200 + 90* 0);
		setcolor(8);
		line(185 ,180 + 90* 0,215,180 + 90* 0);
		line(200 ,165 + 90* 0,200,195 + 90* 0);
		puthz(280 ,170 + 90* 0,"立即添加车辆",24,28,8);
	}
	else if (strlen(u->car[0].licensenum) != 0 && strlen(u->car[1].licensenum) == 0 ) // + && strlen(u->car[2].licensenum) == 0
	{
		setfillstyle(1, WHITE);
		setcolor(DARKGRAY);
		bar(20 ,160 + 90* 1,620,200 + 90* 1);
		setcolor(8);
		line(185 ,180 + 90* 1,215,180 + 90* 1);
		line(200 ,165 + 90* 1,200,195 + 90* 1);
		puthz(280 ,170 + 90* 1,"立即添加车辆",24,28,8);
	}
	else if (strlen(u->car[0].licensenum) != 0 && strlen(u->car[1].licensenum) != 0 && strlen(u->car[2].licensenum) == 0)
	{
		setfillstyle(1, WHITE);
		setcolor(DARKGRAY);
		bar(20 ,160 + 90* 2,620,200 + 90* 2);
		setcolor(8);
		line(185 ,180 + 90* 2,215,180 + 90* 2);
		line(200 ,165 + 90* 2,200,195 + 90* 2);
		puthz(280 ,170 + 90* 2,"立即添加车辆",24,28,8);
	}
	else if (strlen(u->car[0].licensenum) != 0 && strlen(u->car[1].licensenum) != 0 && strlen(u->car[2].licensenum) != 0)
	{}

}

void del_cardata(int* usernum,int flag)
{
	FILE* fp;
	Car* c = NULL;
	
	if( (fp = fopen("Database\\UserData.dat", "rb+" )) == NULL )	//open userdata.dat in fp
	{
		printf("Error! Can't Open \"UserData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	if ((c = (Car*)malloc(sizeof(Car))) == NULL)
	{
		printf("Error - unable to allocate required memory");
		delay(1500);
		exit(1);
	}
	memset(c,'\0',sizeof(Car));
	fseek(fp, (*usernum + 1) * sizeof(User) + (flag - 4) * sizeof(Car) , SEEK_SET);//跳转用户第一个空余车辆位置
	fwrite(c, sizeof(Car), 1, fp);//把用户信息写入文件
	if (c != NULL)
	{
		free(c);
		c = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(3000);
		exit(1);
	}
}
