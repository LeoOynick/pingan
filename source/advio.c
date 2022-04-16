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
	int state_date = 0;
	char licensenum[7] = "\0";
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
			if(strlen(licensenum) == 0)
				puthz(260,150,"请输入车牌！",16,18,RED);
			else
				refer_violatedata(licensenum);
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
			setfillstyle(1,LIGHTCYAN);
			bar(0,150,640,378);
			if(strlen(licensenum) == 0)
				puthz(260,150,"请输入车牌！",16,18,RED);
			else
			{
				drawadd();
				state = 1;
			}
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
		
		else if(mouse_press(255,150,340,190) == 2 && state == 1)		//年
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
			if(state2 == 0 || state3 == 0 || state4 == 0)
				puthz(510,165,"请输入日期！",16,18,RED);
			else
			{
				setfillstyle(1,11);
				bar(510,165,640,210);
				if(check_date(year,month,day,510,165)) state_date = 1;
			}
			if(state5 == 0 && state6 == 0 && state7 == 0 && state8 == 0)
				puthz(520,240,"请选择类型！",16,18,RED);
			else
			{
				setfillstyle(1,11);
				bar(520,240,640,260);
			}
			if(state9 == 0)
			{
				setfillstyle(1,11);
				bar(470,265,640,295);
				puthz(470,265,"请填写罚款金额！",16,18,RED);
			}
			else if(strlen(fine) != 4)
			{
				setfillstyle(1,11);
				bar(470,265,640,295);
				puthz(470,265,"金额为四位",16,18,RED);
			}
			else
			{
				setfillstyle(1,11);
				bar(470,265,640,295);
			}
			if(state10 == 0)
			{
				setfillstyle(1,11);
				bar(470,315,640,345);
				puthz(470,315,"请填写扣分分数！",16,18,RED);
			}
			else if(strlen(point) != 2)
			{
				setfillstyle(1,11);
				bar(470,315,640,345);
				puthz(470,315,"分数为两位",16,18,RED);
			}
			else
			{
				setfillstyle(1,11);
				bar(470,315,640,345);
			}
			if(state_date == 1 && (state5 != 0 || state6 != 0 || state7 != 0 || state8 != 0)
				&& strlen(fine) == 4 && strlen(point) == 2)
			{
				write_violatedata(licensenum,state5,state6,state7,state8,year,month,day,fine,point);
				puthz(280,388,"提交成功！",16,20,4);
				delay(800);
				*page = 21;
				return;
			}
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
	setfillstyle(1,11);
	bar(0,145,640,377);
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

void write_violatedata(char *licensenum, int type1,int type2, int type3, int type4,
					char* year, char* month, char* day, char* fine, char* point)
{
	FILE *fp;
	Vio *v;
	int type = 0;
	char violate_str_type[2];
	
	
	if( (fp = fopen("Database\\VioData.dat", "rb+" )) == NULL )	//open VioData.dat in fp
	{
		closegraph();
		printf("Error! Can't Open \"VioData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	if( (v = (Vio*)malloc(sizeof(Vio))) == NULL )	//allocate memory for v
	{
		printf("Error - unable to allocate required memory for violate");
		delay(1500);
		exit(1);
	}
	
	if(type1 == 1)
	{
		type = 1;
	}
	else if(type2 == 1)
	{
		type = 2;
	}
	else if(type3 == 1)
	{
		type = 3;
	}
	else if(type4 == 1)
	{
		type = 4;
	}
	violate_str_type[0] = '0' + type;
	violate_str_type[1] = '\0';
	
	strcpy(v->licensenum, licensenum);		//copy licensenum to C.licensenum
	strcpy(v->viotype,violate_str_type);
	strcpy(v->viodate.year,year);
	strcpy(v->viodate.month,month);
	strcpy(v->viodate.day,day);
	strcpy(v->viomoney,fine);
	strcpy(v->viopoint,point);
	
	fseek(fp,0,SEEK_END);			
	fwrite(v,sizeof(Vio),1,fp);	//write c to *fp->file
	
	if (v != NULL)
	{
		free(v);
		v = NULL;
	}
	
	if (fclose(fp) != 0)
	{
		printf("\n cannot close VioData.dat");
		delay(3000);
		exit(1);
	}
}

void refer_violatedata(char *licensenum)
{
	int i,j;
	int set_num;
	int n = 0;
	int violate_found = 0;
	FILE *fp;
	Vio *vi = NULL;
	
	setfillstyle(1,LIGHTCYAN);
	bar(0,150,640,378);
	if( (fp = fopen("Database\\VioData.dat", "rb+" )) == NULL )	//open VioData.dat in fp
	{
		closegraph();
		printf("Error! Can't Open \"VioData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	set_num = ftell(fp) / sizeof(Vio);
	button(20,145,800,377,11,11,1);
	for (i = set_num - 1;i >= 0;i--)
	{
		if( (vi = (Vio*)malloc(sizeof(Vio))) == NULL )	
		{
			closegraph();
			printf("Error - unable to allocate required memory in advio.c for in");
			delay(1500);
			exit(1);
		}
		fseek(fp, i * sizeof(Vio), SEEK_SET);
		fread(vi, sizeof(Vio), 1, fp);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 0, 3);
		settextstyle(1,0,2);
	
		if (strcmp(licensenum, vi->licensenum) == 0)
		{
			rectangle(20,170 + 50 * n,620,220 + 50 * n);
			setcolor(DARKGRAY);
			outtextxy(30,180 + 50 * n,vi->viodate.year);
			puthz(90, 185 + 50 * n , "年", 16, 17, BLUE);
			outtextxy(115, 180 + 50 * n , vi->viodate.month);
			puthz(145, 185 + 50 * n , "月", 16, 17, BLUE);
			outtextxy(170, 180 + 50 * n , vi->viodate.day);
			puthz(200, 185 + 50 * n , "日", 16, 17, BLUE);
			switch(vi->viotype[0])
			{
				case '1':
					puthz(260,180 + 50 * n,"超速",24,28,1);
					violate_found = 1;
					break;
				case '2':
					puthz(260,180 + 50 * n,"超载",24,28,1);
					violate_found = 1;
					break;
				case '3':
					puthz(260,180 + 50 * n,"酒驾",24,28,1);
					violate_found = 1;
					break;
				case '4':
					puthz(260,180 + 50 * n,"闯红灯",24,28,1);
					violate_found = 1;
					break;
			}
			puthz(360,185 + 50 * n,"罚款",16,18,1);
			outtextxy(400,180 + 50 * n,vi->viomoney);
			puthz(460,185 + 50 * n,"元",16,18,1);
			puthz(510,185 + 50 * n,"扣分",16,18,1);
			outtextxy(550,180 + 50 * n,vi->viopoint);
			puthz(580,185 + 50 * n,"分",16,18,1);
		}
		free(vi);
		vi = NULL;
		n++;
		if(n >= 3)	break;
	}
	
	if(violate_found == 0)
	{
		puthz(160,260, "此车辆没有任何违章记录", 24, 28, DARKGRAY);
	}
	
	if (vi != NULL)
	{
		free(vi);
		vi = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close VioData");
		delay(2000);
		exit(1);				
	}
}