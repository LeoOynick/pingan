#include"common.h"
#include"violation.h"

void violate(int *page, User *u)
{
	int num = 0;
	int carid = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawviolate(u,&carid);
	
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
			setfillstyle(1,LIGHTCYAN);
			bar(0,170,640,378);
			search_vio(u,carid);
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
		
		else if (mouse_press(520,95,600,115) == 2)   //切换车辆
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(520,95,600,115) == 1)
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
			bar(20,120,620,160);
			show_car(u,90,122,1,&carid);
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

void drawviolate(User *u, int *carid)
{
	setbkcolor(LIGHTCYAN);
	
	puthz(240,20,"查违章",48,56,1);
	puthz(20,80,"车辆信息",24,28,1);
	puthz(520,95,"切换车辆",16,18,8);
	setcolor(8);
	line(500,100,515,100);
	line(515,100,510,95);
	line(500,105,515,105);
	line(500,105,505,110);
	setfillstyle(1,15);
	bar(20,120,620,160);
	setlinestyle(0,4,3);
	puthz(160,280, "请点击“查询”以查询违章", 24, 28, DARKGRAY);
	
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
	show_car(u,90,122,1,&carid);
}

void search_vio(User *u, int carid)
{
	int i,j;
	int set_num;
	int n = 0;
	int violate_found = 0;
	FILE *fp;
	Vio *vi = NULL;
	
	if( (fp = fopen("Database\\VioData.dat", "rb+" )) == NULL )	//open VioData.dat in fp
	{
		closegraph();
		printf("Error! Can't Open \"VioData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	set_num = ftell(fp) / sizeof(Vio);
	button(20,170,800,377,11,11,1);
	for (i = 0; i < set_num; i++)
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
		if (strcmp(u->car[carid].licensenum, vi->licensenum) == 0)
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