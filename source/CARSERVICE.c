#include"common.h"
#include"carservice.h"

void carserve(int *page, User *u)
{
	int num = 0;
	int carid = 0;		//showcar中第几架车辆
	int state1 = 0;		//判断内容输入状态的参数
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int cost = 0;		//总金额
	char charge[5];
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawcarserve(u,&carid);
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(610,0,640,30) == 2)			//退出
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
		
		else if(mouse_press(180,400,260,430) == 2)	//提交
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(195,405,"提交",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			if(state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0)
				puthz(220,225,"请选择项目！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(220,225,420,245);
			}
			if((state1 != 0 || state2 != 0 || state3 != 0 || state4 != 0)
				&& (strlen(u->car[carid].licensenum)!= 0))
			{
				write_servicedata(u,carid,state1,state2,state3,state4);
				puthz(280,435,"提交成功！",16,20,RED);
				delay(800);
				*page = 7;
				return;
			}
		}
		
		else if(mouse_press(380,400,460,430) == 2)	//返回
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
		    *page = 7;
			return;
		}
		
		else if (mouse_press(520,135,600,155) == 2)	//切换车辆
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
		else if (mouse_press(520,135,600,155) == 1)
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
			bar(20,160,620,200);
			show_car(u,90,162,1,&carid);
		}
		
		else if (mouse_press(95,290,105,300) == 2)	//洗车
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(95,290,105,300) == 1)
		{
			delay(150);
			choose(100,295,&state1);
		}
		
		else if (mouse_press(245,290,255,300) == 2)	//加油
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(245,290,255,300) == 1)
		{
			delay(150);
			choose(250,295,&state2);
		}
		
		else if (mouse_press(395,290,405,300) == 2)	//保养
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(395,290,405,300) == 1)
		{
			delay(150);
			choose(400,295,&state3);
		}
		
		else if (mouse_press(545,290,555,300) == 2)	//挪车
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(545,290,555,300) == 1)
		{
			delay(150);
			choose(550,295,&state4);
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
					puthz(195,405,"提交",24,28,1);
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
		if(state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0)
		{
			setfillstyle(1,LIGHTCYAN);
			bar(320,330,390,360);
		}
		else
			price(&state1,&state2,&state3,&state4,&state2,&state3,100,240,800,150,0,0,cost,charge,320,330);
	}
}

void drawcarserve(User *u,int *carid)
{
	setbkcolor(LIGHTCYAN);
	puthz(220,20,"车辆服务",48,56,1);
	puthz(20,120,"车辆信息",24,28,1);
	puthz(520,135,"切换车辆",16,18,8);
	setfillstyle(1,15);
	bar(20,160,620,200);
	fillellipse(100,295,5,5);
	fillellipse(250,295,5,5);
	fillellipse(400,295,5,5);
	fillellipse(550,295,5,5);
	setcolor(8);
	line(500,140,515,140);
	line(515,140,510,135);
	line(500,145,515,145);
	line(500,145,505,150);
	circle(100,295,5);
	circle(250,295,5);
	circle(400,295,5);
	circle(550,295,5);
	
	puthz(20,220,"选择服务项目",24,28,1);
	setcolor(15);
	setlinestyle(0,4,3);
	rectangle(20,250,170,310);
	rectangle(170,250,320,310);
	rectangle(320,250,470,310);
	rectangle(470,250,620,310);
	puthz(70,260,"洗车",24,28,8);
	puthz(220,260,"加油",24,28,8);
	puthz(370,260,"保养",24,28,8);
	puthz(520,260,"挪车",24,28,8);
	
	puthz(160,330,"共计消费：",24,28,1);
	puthz(400,335,"元",16,18,8);
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(195,405,"提交",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
	
	show_car(u,90,162,1,carid);		//输出车辆资料
}

void write_servicedata(User *u, int carid, int service1,int service2,int service3,int service4)
{
	FILE *fp;
	Service *s;
	struct tm *local;
    time_t t;
	int i;
	char str[5];
	t=time(NULL);
    local=localtime(&t);
	
	if( (fp = fopen("Database\\ServData.dat", "wb+" )) == NULL )	//open ServData.dat in fp
	{
		closegraph();
		printf("Error! Can't Open \"ServData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	if( (s = (Service*)malloc(sizeof(Service))) == NULL )	//allocate memory for s
	{
		printf("Error - unable to allocate required memory for service");
		delay(1500);
		exit(1);
	}
	
	memset(s,'\0',sizeof(Service));
	strcpy(s->licensenum, u->car[carid].licensenum);
	local=localtime(&t);
	itoa(local->tm_year + 1900, str, 10);
	strcpy(s->servicedate.year, str);
	itoa(local->tm_mon + 1, str, 10);
	strcpy(s->servicedate.month, str);
	itoa(local->tm_mday, str, 10);
	strcpy(s->servicedate.day, str);
	
	for(i = 0; i < 4; i++)
	{
		if(service1 != 0)
		{
			s->servicetype[0] = '1';
			service1 = 0;
		}
		else if(service2 != 0)
		{
			s->servicetype[0] = '2';
			service2 = 0;
		}
		else if(service3 != 0)
		{
			s->servicetype[0] = '3';
			service3 = 0;
		}
		else if(service4 != 0)
		{
			s->servicetype[0] = '4';
			service4 = 0;
		}
		if(s->servicetype[0] != '0')
		{
			fseek(fp, 0, SEEK_END);				//跳转至文件末尾
			fwrite(s, sizeof(Service), 1, fp);	//把车险信息写入文件
			s->servicetype[0] = '0';
		}
	}
	
	if (s != NULL)
	{
		free(s);
		s = NULL;
	}
	
	if (fclose(fp) != 0)
	{
		printf("\n cannot close ServData.dat");
		delay(3000);
		exit(1);
	}
	
}
	