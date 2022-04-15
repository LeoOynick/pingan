#include"common.h"
#include"policy.h"

void policy(int *page,User *u)
{
	int num = 0;
	int carid = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawpolicy(u,&carid);
	
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
		
		else if(mouse_press(180,400,260,430) == 2)   //查询
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(195,405,"查询",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			search_insurance(u,carid);
		}
		
		else if(mouse_press(380,400,460,430) == 2)   //返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(380,400,460,430,15,12,1);
				puthz(395,405,"返回",24,28,1);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(380,400,460,430) == 1)
		{
			MouseS = 0;
		    *page = 6;
			return;
		}
		
		else if (mouse_press(520,135-10,600,155-10) == 2)   //切换车辆
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(520,135-10,600,155-10) == 1)
		{
			delay(130);
			if(carid < 2)
			{
				carid += 1;
			}
			else
			{
				carid = 0;
			}
			setfillstyle(1,15);
			bar(20,160-10,620,200-10);
			show_car(u,90,162-10,1,&carid);
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
					setfillstyle(1,2);
					bar(180,400,260,430);
					puthz(195,405,"查询",24,28,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,400,460,430);
					puthz(395,405,"返回",24,28,1);
				}
				num = 0;
			}
			continue;
		}
	}
}

void drawpolicy(User *u, int* state)
{
	setbkcolor(LIGHTCYAN);
	
	puthz(240,20,"查保单",48,56,1);
	puthz(20,120-10,"车辆信息",24,28,1);
	puthz(520,135-10,"切换车辆",16,18,8);
	setcolor(8);
	line(500,140-10,515,140-10);
	line(515,140-10,510,135-10);
	line(500,145-10,515,145-10);
	line(500,145-10,505,150-10);
	setfillstyle(1,15);
	bar(20,160-10,620,200-10);
	setlinestyle(0,4,3);
	//setcolor(15);
	//rectangle(80,240-10,560,320-10);
	puthz(160,280, "请点击“查询”以查询保单", 24, 28, DARKGRAY);
	
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(195,405,"查询",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
	
	show_car(u,90,162-10,1,state);
}

void search_insurance(User *u, int carid)
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
	button(20,205,800,390,11,11,1);
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
		
		if (strcmp(u->car[carid].licensenum, in->licensenum) == 0)
		{
			switch(in->insurancetype[0])
			{
				case '1':
					button(380,230,570,265,11,11,1);
					puthz(50,230,"基本险",24,28,1);
					puthz(150, 235 ,"保额", 16, 17, BLUE);
					setcolor(DARKGRAY);
					outtextxy(200,230,"2.0");
					puthz(240, 235 , "万元", 16, 17, BLUE);
					puthz(300, 235 , "保障期至", 16, 17, BLUE);
					outtextxy(380, 230, in->insuranceenddate.year);
					puthz(440, 235 , "年", 16, 17, BLUE);
					outtextxy(480, 230 , in->insuranceenddate.month);
					puthz(505, 235 , "月", 16, 17, BLUE);
					outtextxy(535, 230 , in->insuranceenddate.day);
					puthz(570, 235 , "日", 16, 17, BLUE);
					settextstyle(1,0,1);
					setcolor(WHITE);
					setlinestyle(SOLID_LINE, 0, 3);
					rectangle(40, 220 , 40 + 560, 220 + (3 + 31 * 1.5 ) * (0 + 1));
					insurance_found = 1;
					break;
				case '2':
					button(380,280,570,315,11,11,1);
					puthz(50,280,"商业险",24,28,1);
					puthz(150, 285 ,"保额", 16, 17, BLUE);
					setcolor(DARKGRAY);
					outtextxy(200,280,"1.0");
					puthz(240, 285 , "万元", 16, 17, BLUE);
					puthz(300, 285 , "保障期至", 16, 17, BLUE);
					outtextxy(380, 280, in->insuranceenddate.year);
					puthz(440, 285 , "年", 16, 17, BLUE);
					outtextxy(480, 280 , in->insuranceenddate.month);
					puthz(505, 285 , "月", 16, 17, BLUE);
					outtextxy(535, 280 , in->insuranceenddate.day);
					puthz(570, 285 , "日", 16, 17, BLUE);
					settextstyle(1,0,1);
					setcolor(WHITE);
					setlinestyle(SOLID_LINE, 0, 3);
					rectangle(40, 220 + (3 + 31 * 1.5 ) * 1 , 40 + 560, 220 + (3 + 31 * 1.5 ) * 2);
					insurance_found = 1;
					break;
				case '3':
					button(380,330,570,365,11,11,1);
					puthz(50,330,"交强险",24,28,1);
					puthz(150, 335 ,"保额", 16, 17, BLUE);
					setcolor(DARKGRAY);
					outtextxy(200,330,"1.5");
					puthz(240, 335 , "万元", 16, 17, BLUE);
					puthz(300, 335 , "保障期至", 16, 17, BLUE);
					outtextxy(380, 330, in->insuranceenddate.year);
					puthz(440, 335 , "年", 16, 17, BLUE);
					outtextxy(480, 330 , in->insuranceenddate.month);
					puthz(505, 335 , "月", 16, 17, BLUE);
					outtextxy(535, 330 , in->insuranceenddate.day);
					puthz(570, 335 , "日", 16, 17, BLUE);
					settextstyle(1,0,1);
					setcolor(WHITE);
					setlinestyle(SOLID_LINE, 0, 3);
					rectangle(40, 220 + (3 + 31 * 1.5 ) * 2 , 40 + 560, 220 + (3 + 31 * 1.5 ) * 3);
					insurance_found = 1;
					break;
			}
		}
		free(in);
		in = NULL;
	}
	if(insurance_found == 0)
	{
		puthz(160,280, "此车辆没有购买任何保险", 24, 28, DARKGRAY);
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