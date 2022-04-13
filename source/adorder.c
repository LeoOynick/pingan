#include"common.h"
#include"adorder.h"

void adorder(int *page)
{
	int num = 0;
	int state = 0;
	char licensenum[7] = "\0";
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draworder();
	
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
			    num = 2;
		    }
			continue;
		}
		else if(mouse_press(280,420,360,480) == 1)
		{
			MouseS = 0;
			*page = 21;
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
			if (num == 0 && state == 0)
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
				state = 1;
			else
				state = 0;
			continue;
		}		
		
		else if(mouse_press(90,380,150,410) == 2)		//保单
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(90,380,150,410,15,8,1);
				puthz(105,388,"保单",16,18,15);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(90,380,150,410) == 1)
		{
			MouseS = 0;
		    ad_insurance(licensenum);
		}
		
		else if(mouse_press(190,380,250,410) == 2)		//停车
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(190,380,250,410,15,8,1);
				puthz(205,388,"停车",16,18,15);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(190,380,250,410) == 1)
		{
			MouseS = 0;
		    
			
		}
		
		else if(mouse_press(290,380,350,410) == 2)		//服务
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(290,380,350,410,15,8,1);
				puthz(305,388,"服务",16,18,15);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(290,380,350,410) == 1)
		{
			MouseS = 0;
		    
			
		}
		
		else if(mouse_press(390,380,450,410) == 2)		//年检
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(390,380,450,410,15,8,1);
				puthz(405,388,"年检",16,18,15);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(390,380,450,410) == 1)
		{
			MouseS = 0;
		    
			
		}
		
		else if(mouse_press(490,380,550,410) == 2)		//救援
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(490,380,550,410,15,8,1);
				puthz(505,388,"救援",16,18,15);
				num = 9;
			}
			continue;
		}
		else if (mouse_press(490,380,550,410) == 1)
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
				num = 10;
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
					button(280,420,360,480,3,3,1);
				    puthz(303,430,"违章",16,20,15);
					puthz(303,450,"管理",16,20,15);
				}	
				else if(num == 3)
				{
					button(440,420,520,480,3,3,1);
					puthz(463,430,"理赔",16,20,15);
					puthz(463,450,"审批",16,20,15);
				}	
				else if(num == 4 && state == 0)
				{
					button(300,100,470,140,15,15,1);
				}
				else if(num == 5)
				{
					button(90,380,150,410,7,7,1);
					puthz(105,388,"保单",16,18,1);
				}
				else if(num == 6)
				{
					button(190,380,250,410,7,7,1);
					puthz(205,388,"停车",16,18,1);
				}
				else if(num == 7)
				{
					button(290,380,350,410,7,7,1);
					puthz(305,388,"服务",16,18,1);
				}
				else if(num == 8)
				{
					button(390,380,450,410,7,7,1);
					puthz(405,388,"年检",16,18,1);
				}
				else if(num == 9)
				{
					button(490,380,550,410,7,7,1);
					puthz(505,388,"救援",16,18,1);
				}
				num = 0;
			}
			continue;
		}
	}
}

void draworder()
{
	setbkcolor(LIGHTCYAN);
	puthz(560,60,"退出登录",16,18,8);
	setcolor(8);
	arc(550,67,100,440,7);
	line(550,63,550,58);
	setlinestyle(0,4,3);
	setfillstyle(1,3);
	bar(0,420,120,480);
	bar(200,420,640,480);
		
	puthz(150,20,"用户订单查询",48,56,1);
	puthz(140,110,"输入车牌",24,28,1);
	setfillstyle(1,15);
	bar(260,100,470,140);
	puthz(270,110,"鄂",24,28,1);
	setfillstyle(1,7);
	bar(90,380,150,410);
	bar(190,380,250,410);
	bar(290,380,350,410);
	bar(390,380,450,410);
	bar(490,380,550,410);
	puthz(105,388,"保单",16,18,1);
	puthz(205,388,"停车",16,18,1);
	puthz(305,388,"服务",16,18,1);
	puthz(405,388,"年检",16,18,1);
	puthz(505,388,"救援",16,18,1);
		
	setcolor(8);
	puthz(143,430,"订单",16,20,8);
	puthz(143,450,"查询",16,20,8);
	setcolor(15);
	puthz(303,430,"违章",16,20,15);
	puthz(303,450,"管理",16,20,15);
	puthz(463,430,"理赔",16,20,15);
	puthz(463,450,"审批",16,20,15);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}

void ad_insurance(char *licensenum)
{
	int i,j;
	int set_num;
	int insurance_found = 0;
	FILE *fp;
	Insurance *in = NULL;
	
	if( (fp = fopen("Database\\InsData.dat", "rb+" )) == NULL )	//open InsuranceData.dat in fp
	{
		closegraph();
		printf("Error! Can't Open \"InsuranceData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	set_num = ftell(fp) / sizeof(Insurance);
	button(20,150,800,375,11,11,1);
	for (i = 0; i < set_num; i++)
	{
		if( (in = (Insurance*)malloc(sizeof(Insurance))) == NULL )	//allocate memory for u
		{
			closegraph();
			printf("Error - unable to allocate required memory in policy.c for in");
			delay(1500);
			exit(1);
		}
		
		fseek(fp, i * sizeof(Insurance), SEEK_SET);
		fread(in, sizeof(Insurance), 1, fp);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 0, 3);
		settextstyle(1,0,2);
		
		if(strlen(licensenum) == 0)
		{
			puthz(260,150,"请输入车牌！",16,18,RED);
			insurance_found = 1;
		}
		if (strcmp(licensenum, in->licensenum) == 0)
		{
			switch(in->insurancetype[0])
			{
				case '1':
					puthz(50,210,"基本险",24,28,1);
					puthz(150, 215 ,"保额", 16, 17, BLUE);
					setcolor(DARKGRAY);
					outtextxy(200,210,"2.0");
					puthz(240, 215 , "万元", 16, 17, BLUE);
					puthz(300, 215 , "保障期至", 16, 17, BLUE);
					outtextxy(380, 210, in->insuranceenddate.year);
					puthz(440, 215 , "年", 16, 17, BLUE);
					outtextxy(480, 210 , in->insuranceenddate.month);
					puthz(505, 215 , "月", 16, 17, BLUE);
					outtextxy(535, 210 , in->insuranceenddate.day);
					puthz(570, 215 , "日", 16, 17, BLUE);
					settextstyle(1,0,1);
					setcolor(WHITE);
					rectangle(40, 200 , 40 + 560, 200 + (3 + 31 * 1.5 ) * (0 + 1));
					insurance_found = 1;
					break;
				case '2':
					puthz(50,260,"商业险",24,28,1);
					puthz(150, 265 ,"保额", 16, 17, BLUE);
					setcolor(DARKGRAY);
					outtextxy(200,260,"1.0");
					puthz(240, 265 , "万元", 16, 17, BLUE);
					puthz(300, 265 , "保障期至", 16, 17, BLUE);
					outtextxy(380, 260, in->insuranceenddate.year);
					puthz(440, 265 , "年", 16, 17, BLUE);
					outtextxy(480, 260 , in->insuranceenddate.month);
					puthz(505, 265 , "月", 16, 17, BLUE);
					outtextxy(535, 260 , in->insuranceenddate.day);
					puthz(570, 265 , "日", 16, 17, BLUE);
					settextstyle(1,0,1);
					setcolor(WHITE);
					rectangle(40, 200 + (3 + 31 * 1.5 ) * 1 , 40 + 560, 200 + (3 + 31 * 1.5 ) * 2);
					insurance_found = 1;
					break;
				case '3':
					puthz(50,310,"交强险",24,28,1);
					puthz(150, 315 ,"保额", 16, 17, BLUE);
					setcolor(DARKGRAY);
					outtextxy(200,310,"1.5");
					puthz(240, 315 , "万元", 16, 17, BLUE);
					puthz(300, 315 , "保障期至", 16, 17, BLUE);
					outtextxy(380, 310, in->insuranceenddate.year);
					puthz(440, 315 , "年", 16, 17, BLUE);
					outtextxy(480, 310 , in->insuranceenddate.month);
					puthz(505, 315 , "月", 16, 17, BLUE);
					outtextxy(535, 310 , in->insuranceenddate.day);
					puthz(570, 315 , "日", 16, 17, BLUE);
					settextstyle(1,0,1);
					setcolor(WHITE);
					rectangle(40, 200 + (3 + 31 * 1.5 ) * 2 , 40 + 560, 200 + (3 + 31 * 1.5 ) * 3);
					insurance_found = 1;
					break;
			}
		}
		free(in);
		in = NULL;
	}
	if(insurance_found == 0)
	{
		puthz(160,260, "此车辆没有购买任何保险", 24, 28, DARKGRAY);
	}
	
	if (in != NULL)
	{
		free(in);
		in = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close PolData");
		delay(2000);
		exit(1);				
	}
}