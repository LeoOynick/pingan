#include"common.h"
#include"adclaim.h"

void adclaim(int *page)
{
	int num = 0;
	int state = 0;
	int state1 = 0;
	char licensenum[7];
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawadclaim();
	
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
		
		else if(mouse_press(280,420,360,480) == 2)   //违章管理
		{
			if (num == 0)
		    {
			    MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(280,420,360,480,11,11,8);
				puthz(303,430,"违章",16,20,8);
				puthz(303,450,"管理",16,20,8);
			    num = 3;
		    }
			continue;
		}
		else if(mouse_press(280,420,360,480) == 1)
		{
			MouseS = 0;
			*page = 21;
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
		
		else if(mouse_press(540,60,630,80) == 2)   //退出登录
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 5;
			}	
		}
		else if(mouse_press(540,60,630,80) == 1)
		{
			MouseS = 0;
			delay(1000);
			*page = 0;
			return;
		}
		
		else if(mouse_press(490,105,550,135) == 2)		//确认
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(490,105,550,135,15,8,1);
				puthz(505,113,"确认",16,18,15);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(490,105,550,135) == 1)
		{
			MouseS = 0;
		    check(licensenum);
			drawcheck();
			state = 1;
		}
		
		else if(mouse_press(190,380,250,410) == 2 && state == 1)		//通过
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(190,380,250,410,15,8,1);
				puthz(205,388,"通过",16,18,15);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(190,380,250,410) == 1 && state == 1)
		{
			MouseS = 0;
			pass(licensenum,1);
			puthz(280,390,"提交成功！",16,20,RED);
			delay(800);
			*page = 22;
			return;
		}
		else if(mouse_press(390,380,450,410) == 2 && state == 1)		//拒绝
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(390,380,450,410,15,8,1);
				puthz(405,388,"拒绝",16,18,15);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(390,380,450,410) == 1 && state == 1)
		{
			MouseS = 0;
			pass(licensenum,2);
			puthz(280,390,"提交成功！",16,20,RED);
			delay(800);
			*page = 22;
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
					button(280,420,360,480,3,3,1);
				    puthz(303,430,"违章",16,20,15);
					puthz(303,450,"管理",16,20,15);
				}	
				else if(num == 4 && state1 == 0)
				{
					button(300,100,470,140,15,15,1);
				}
				else if(num == 6)
				{
					button(490,105,550,135,7,7,1);
					puthz(505,113,"确认",16,18,1);
				}
				else if(num == 7 && state == 1)
				{
					button(190,380,250,410,7,7,1);
					puthz(205,388,"通过",16,18,1);
				}
				else if(num == 8 && state == 1)
				{
					button(390,380,450,410,7,7,1);
					puthz(405,388,"拒绝",16,18,1);
				}
				num = 0;
			}
			continue;
		}
	}
}

void drawadclaim()
{
	setbkcolor(LIGHTCYAN);
	puthz(560,60,"退出登录",16,18,8);
	setcolor(8);
	arc(550,67,100,440,7);
	line(550,63,550,58);
	setlinestyle(0,4,3);
	setfillstyle(1,3);
	bar(0,420,440,480);
	bar(520,420,640,480);
		
	puthz(150,20,"用户理赔审批",48,56,1);
	puthz(140,110,"输入车牌",24,28,1);
	setfillstyle(1,15);
	bar(260,100,470,140);
	puthz(270,110,"鄂",24,28,1);
	setfillstyle(1,7);
	bar(490,105,550,135);
	puthz(505,113,"确认",16,18,1);
	setcolor(8);
	puthz(463,430,"理赔",16,20,8);
	puthz(463,450,"审批",16,20,8);
	setcolor(15);
	puthz(143,430,"订单",16,20,15);
	puthz(143,450,"查询",16,20,15);
	puthz(303,430,"违章",16,20,15);
	puthz(303,450,"管理",16,20,15);

	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}

void drawcheck()
{
	setfillstyle(1,7);
	bar(190,380,250,410);
	bar(390,380,450,410);
	puthz(205,388,"通过",16,18,1);
	puthz(405,388,"拒绝",16,18,1);
}

void check(char *licensenum)
{
	int i,j;
	int set_num;
	int claim_found = 0;
	int max_num = 0;
	FILE *fp;
	Claim *cl = NULL;
	
	if( (fp = fopen("Database\\ClaData.dat", "rb+" )) == NULL )	//open ClaimData.dat cl fp
	{
		closegraph();
		printf("Error! Can't Open \"ClaimData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	set_num = ftell(fp) / sizeof(Claim);
	button(20,150,800,415,11,11,1);
	
	for (i = 0; i < set_num; i++)
	{
		if( (cl = (Claim*)malloc(sizeof(Claim))) == NULL )	
		{
			closegraph();
			printf("Error - unable to allocate required memory in adclaim.c for cl");
			delay(1500);
			exit(1);
		}
		fseek(fp, i * sizeof(Claim), SEEK_SET);
		fread(cl, sizeof(Claim), 1, fp);
		if (strcmp(licensenum, cl->licensenum) == 0)
		{
			if(i != 0)	max_num = i;
		}
		free(cl);
	}
	
	if( (cl = (Claim*)malloc(sizeof(Claim))) == NULL )	
	{
		closegraph();
		printf("Error - unable to allocate required memory cl adclaim.c for cl");
		delay(1500);
		exit(1);
	}
	
	fseek(fp, max_num * sizeof(Claim), SEEK_SET);
	fread(cl, sizeof(Claim), 1, fp);
	
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 3);
	settextstyle(1,0,2);
		
	if(strlen(licensenum) == 0)
	{
		puthz(260,150,"请输入车牌！",16,18,RED);
		claim_found = 1;
	}
	if (strcmp(licensenum, cl->licensenum) == 0)
	{
		puthz(140,180,"日期：",24,28,1);
		setcolor(DARKGRAY);
		outtextxy(290,180,cl->claimdate.year);
		puthz(350, 185 , "年", 16, 17, BLUE);
		outtextxy(390, 180 , cl->claimdate.month);
		puthz(405, 185 , "月", 16, 17, BLUE);
		outtextxy(445, 180 , cl->claimdate.day);
		puthz(480, 185 , "日", 16, 17, BLUE);
		puthz(140,230,"场景：",24,28,1);
		switch(cl->scenetype[0])
		{
			case '1':
				puthz(290,230,"自己剐蹭了",24,28,1);
				claim_found = 1;
				break;
			case '2':
				puthz(290,230,"撞了别人车",24,28,1);
				claim_found = 1;
				break;
			case '3':
				puthz(290,230,"有人受伤了",24,28,1);
				claim_found = 1;
				break;
			case '4':
				puthz(290,230,"有物品损失",24,28,1);
				claim_found = 1;
				break;
			case '5':
				puthz(290,230,"车停放受损",24,28,1);
				claim_found = 1;
				break;
			case '6':
				puthz(290,230,"代驾发生事故",24,28,1);
				claim_found = 1;
				break;
		}
		puthz(140,280,"角色：",24,28,1);
		switch(cl->charactertype[0])
		{
			case '1':
				puthz(290,280,"主责方",24,28,1);
				claim_found = 1;
				break;
			case '2':
				puthz(290,280,"次责方",24,28,1);
				claim_found = 1;
				break;
			case '3':
				puthz(290,280,"无责方",24,28,1);
				claim_found = 1;
				break;
			case '4':
				puthz(290,280,"伤者",24,28,1);
				claim_found = 1;
				break;
		}
	}
	free(cl);
	cl = NULL;
	
	if(claim_found == 0)
	{
		puthz(160,260, "此车辆没有办理任何理赔", 24, 28, DARKGRAY);
	}
	
	if (cl != NULL)
	{
		free(cl);
		cl = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close ClaData");
		delay(2000);
		exit(1);				
	}
}

void pass(char *licensenum, int state)
{
	int i,j;
	int set_num;
	int max_num = 0;
	int claim_found = 0;
	char str[2];
	FILE *fp;
	Claim *cl = NULL;
	Claim *cl1= NULL;
	str[0] = '0' + state;
	str[1] = '\0';
	if( (fp = fopen("Database\\ClaData.dat", "rb+" )) == NULL )	//open ClaimData.dat cl fp
	{
		closegraph();
		printf("Error! Can't Open \"ClaimData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	set_num = ftell(fp) / sizeof(Claim);
	for (i = 0; i < set_num; i++)
	{
		if( (cl = (Claim*)malloc(sizeof(Claim))) == NULL )	
		{
			closegraph();
			printf("Error - unable to allocate required memory in adclaim.c for cl");
			delay(1500);
			exit(1);
		}
		fseek(fp, i * sizeof(Claim), SEEK_SET);
		fread(cl, sizeof(Claim), 1, fp);
		if (strcmp(licensenum, cl->licensenum) == 0)
		{
			if(i != 0)	max_num = i;
		}
		free(cl);
	}
	if( (cl = (Claim*)malloc(sizeof(Claim))) == NULL )	
	{
		closegraph();
		printf("Error - unable to allocate required memory cl adclaim.c for cl");
		delay(1500);
		exit(1);
	}
	if( (cl1 = (Claim*)malloc(sizeof(Claim))) == NULL )	
	{
		closegraph();
		printf("Error - unable to allocate required memory in adclaim.c for cl");
		delay(1500);
		exit(1);
	}
	fseek(fp, max_num * sizeof(Claim), SEEK_SET);
	fread(cl,sizeof(Claim),1,fp);
	memset(cl1,'\0',sizeof(Claim));
	strcpy(cl1->licensenum,cl->licensenum);
	strcpy(cl1->scenetype,cl->scenetype);
	strcpy(cl1->charactertype,cl->charactertype);
	strcpy(cl1->claimdate.year,cl->claimdate.year);
	strcpy(cl1->claimdate.month,cl->claimdate.month);
	strcpy(cl1->claimdate.day,cl->claimdate.day);
	strcpy(cl1->state,str);
	fseek(fp, max_num * sizeof(Claim), SEEK_SET);
	fwrite(cl1,sizeof(Claim),1,fp);	//write c to *fp->file
	
	if (cl != NULL)
	{
		free(cl);
		cl = NULL;
	}
	if (cl1 != NULL)
	{
		free(cl1);
		cl1 = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close ClaimData.dat");
		delay(3000);
		exit(1);
	}
}