/*#include"common.h"
#include"moreinfo.h"

void moreinfo(int *page)
{
	int num=0;
	char seatnum[5];		//座位数量
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	int state7 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawmoreinfo();
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(610,0,640,30) == 2)		//退出
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
		
		else if(mouse_press(180,370,260,400) == 2)		//提交
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,370,260,400,15,10,1);
				puthz(195,375,"提交",24,24,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,370,260,400) == 1)
		{
			MouseS = 0;
			if(state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0)
				puthz(25,160,"请选择型号！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(25,160,200,185);
			}
			if(state5 == 0 && state6 == 0)
				puthz(25,220,"请选择使用性质！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(25,220,200,240);
			}
			if(state7 == 0)
				puthz(140,285,"请填写座位数量！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(140,285,300,310);
			}
			if((state1 != 0 || state2 != 0 || state3 != 0 || state4 != 0) && (state5 != 0 || state6 != 0) && state7 != 0)
			{
				puthz(280,435,"提交成功！",16,20,4);
				delay(800);
				*page = 8;
				return;
			}			
		}
		
		else if(mouse_press(380,370,460,400) == 2)		//返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(380,370,460,400,15,12,1);
				puthz(395,375,"返回",24,28,1);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(380,370,460,400) == 1)
		{
			MouseS = 0;
		    *page = 19;
			return;
		}
		
		else if (mouse_press(185,135,195,145) == 2)   //红旗
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
		else if (mouse_press(185,135,195,145) == 1)
		{
			delay(150);
			choose(190,140,&state1);
			single(&state2,&state3,&state4,290,140,390,140,490,140);
		}
		
		else if (mouse_press(285,135,295,145) == 2)   //奥迪
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
		else if (mouse_press(285,135,295,145) == 1)
		{
			delay(150);
			choose(290,140,&state2);
			single(&state1,&state3,&state4,190,140,390,140,490,140);
		}
		
		else if (mouse_press(385,135,395,145) == 2)   //宝马
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
		else if (mouse_press(385,135,395,145) == 1)
		{
			delay(150);
			choose(390,140,&state3);
			single(&state1,&state2,&state4,190,140,290,140,490,140);
		}
		
		else if (mouse_press(485,135,495,145) == 2)   //奔驰
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
		else if (mouse_press(485,135,495,145) == 1)
		{
			delay(150);
			choose(490,140,&state3);
			single(&state1,&state2,&state3,190,140,290,140,390,140);
		}
		
		else if (mouse_press(185,195,195,205) == 2)   //营运
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
		else if (mouse_press(185,195,195,205) == 1)
		{
			delay(150);
			choose(190,200,&state5);
			single(&state6,&state6,&state6,390,200,390,200,390,200);
		}
		
		else if (mouse_press(385,195,395,205) == 2)   //非营运
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 9;
			}
			continue;
		}
		else if (mouse_press(385,195,395,205) == 1)
		{
			delay(150);
			choose(390,200,&state6);
			single(&state5,&state5,&state5,190,200,190,200,190,200);
		}
		
		else if(mouse_press(290,240,500,280) == 2)		//座位数量
		{
			if (num == 0 && state7 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(290,240,500,280,8,15,1);
				num = 10;
			}
			continue;
		}
		else if (mouse_press(290,240,500,280) == 1)
		{
			MouseS = 0;
		    button(290,240,500,280,8,15,1);
			seatnum[0] = '\0';
			input(seatnum,340,245,4,15,2);
			if(strlen(seatnum) != 0)
				state7 = 1;
			else
				state7 = 0;
			continue;
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
					bar(180,370,260,400);
					puthz(195,375,"提交",24,24,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,370,460,400);
					puthz(395,375,"返回",24,28,1);
				}
				else if(num == 10 && state7 == 0)
				{
					button(290,240,500,280,15,15,1);
				}
				num=0;
			}
			continue;
		}
	}
}

void drawmoreinfo()
{
	setbkcolor(LIGHTCYAN);
	puthz(220,20,"更多信息",48,56,1);
	setfillstyle(1,15);
	puthz(25,130,"品牌型号",24,28,8);
	fillellipse(190,140,5,5);
	fillellipse(290,140,5,5);
	fillellipse(390,140,5,5);
	fillellipse(490,140,5,5);
	fillellipse(190,200,5,5);
	fillellipse(390,200,5,5);
	setcolor(8);
	circle(190,140,5);
	circle(290,140,5);
	circle(390,140,5);
	circle(490,140,5);
	circle(190,200,5);
	circle(390,200,5);
	puthz(200,130,"红旗",24,28,8);
	puthz(300,130,"奥迪",24,28,8);
	puthz(400,130,"宝马",24,28,8);
	puthz(500,130,"奔驰",24,28,8);
	puthz(25,190,"使用性质",24,28,8);
	puthz(200,190,"营运",24,28,8);
	puthz(400,190,"非营运",24,28,8);
	puthz(140,250,"座位数量",24,28,8);
	bar(290,240,500,280);
	
	setfillstyle(1,GREEN);
	bar(180,370,260,400);
	setfillstyle(1,4);
	bar(380,370,460,400);
	puthz(195,375,"提交",24,28,1);
	puthz(395,375,"返回",24,28,1);
	
	setlinestyle(0,4,3);
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}



void write_cardata2(int type, int nature, char* seatnum)
{
	FILE *fp ;
	Car *c = NULL;
	
	if( (fp = fopen("Database\\CarData.dat", "rb+" )) == NULL )	//open cardata.dat in fp
	{
		printf("Error! Can't Open \"CarData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	if( (c = (Car*)malloc(sizeof(Car))) == NULL )	//allocate memory for c
	{
		printf("Error - unable to allocate required memory");
		delay(1500);
		exit(1);
	}
	
	memset(c,'\0',sizeof(Car));
	
	c->type = type;								//copy licensenum to C.licensenum
	c->nature = nature; 
	stpcpy(c->seatnum,seatnum);
	fseek(fp,0,SEEK_END);
	fwrite(c,sizeof(Car),1,fp);				//write c to *fp->file
	
	if (c != NULL)
	{
		free(c);
		c = NULL;
	}
	
	if (fclose(fp) != 0)
	{
		printf("\n cannot close CarData.dat");
		delay(3000);
		exit(1);
	}
	
}*/