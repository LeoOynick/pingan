#include"common.h"
#include"binding.h"

void binding(int *page)
{
	int num=0;
	char licensenum[7];		//6位车牌号码
	char caridnum[6];		//5位车架号码
	char enginenum[6];		//5位发动机号
	char year[5];       //注册年份
	char month[3];     //注册月份
	char day[3];     //注册日期
	int state1 = 0;					//判断是否有字符输入
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	int state7 = 0;
	int state8 = 0;
	int state9 = 0;
	int state10 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawbinding();
	
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
		
		else if(mouse_press(180,400,260,430) == 2)		//提交
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(195,405,"提交",24,24,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			/*if(state1 == 0)
				puthz(485,135,"请填写车牌号码！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(485,135,640,165);
			}
			if(state2 == 0)
				puthz(485,195,"请填写车架号码！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(485,195,640,225);
			}
			if(state3 == 0)
				puthz(485,255,"请填写发动机号！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(485,255,640,285);
			}
			if(state4 == 0 || state5 == 0 || state6 == 0)
				puthz(505,315,"请填写日期！",16,18,4);
			else
			{
				setfillstyle(1,LIGHTCYAN);
				bar(505,315,640,345);
			}
			if(state1 != 0 && state2 != 0 && state3 != 0 && state4 != 0 && state5 != 0 && state6 != 0)
			{
				*page = 20;
				return;
			}*/
		}
		
		else if(mouse_press(380,400,460,430) == 2)		//返回
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
		    *page = 8;
			return;
		}
		
		else if(mouse_press(310,120,480,160) == 2)		//车牌号码
		{
			if (num == 0 && state1 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(310,120,480,160,8,15,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(310,120,480,160) == 1)
		{
			MouseS = 0;
		    button(310,120,480,160,8,15,1);
			licensenum[0] = '\0';
			input(licensenum,310,125,6,15,2);
			if(strlen(licensenum) != 0)
				state1 = 1;
			else
				state1 = 0;
			continue;
		}
		

		

		
		else if(mouse_press(255,180,340,220) == 2)		//年
		{
			if (num == 0 && state2 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(255,180,340,220,8,15,1);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(255,180,340,220) == 1)
		{
			MouseS = 0;
		    button(255,180,340,220,8,15,1);
			year[0] = '\0';
			input(year,255,185,4,15,2);
			if(strlen(year) != 0)
				state2 = 1;
			else
				state2 = 0;
			continue;
		}
		
		else if(mouse_press(360,180,410,220) == 2)		//月
		{
			if (num == 0 && state3 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(360,180,410,220,8,15,1);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(360,180,410,220) == 1)
		{
			MouseS = 0;
		    button(360,180,410,220,8,15,1);
			month[0] = '\0';
			input(month,360,185,2,15,2);
			if(strlen(month) != 0)
				state3 = 1;
			else
				state3 = 0;
			continue;
		}
		
		else if(mouse_press(430,180,480,220) == 2)		//日
		{
			if (num == 0 && state4 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(430,180,480,220,8,15,1);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(430,180,480,220) == 1)
		{
			MouseS = 0;
		    button(430,180,480,220,8,15,1);
			day[0] = '\0';
			input(day,430,185,2,15,2);
			if(strlen(day) != 0)
				state4 = 1;
			else
				state4 = 0;
			continue;
		}
		
		else if (mouse_press(185,255,195,265) == 2)   //红旗
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
		else if (mouse_press(185,255,195,265) == 1)
		{
			delay(150);
			choose(190,260,&state5);
			single(&state6,&state7,&state8,&state7,&state8,290,260,390,260,490,260,390,260,490,260);
		}
		
		else if (mouse_press(285,255,295,265) == 2)   //奥迪
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
		else if (mouse_press(285,255,295,265) == 1)
		{
			delay(150);
			choose(290,260,&state6);
			single(&state5,&state7,&state8,&state7,&state8,190,260,390,260,490,260,390,260,490,260);
		}
		
		else if (mouse_press(385,255,395,265) == 2)   //宝马
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 10;
			}
			continue;
		}
		else if (mouse_press(385,255,395,265) == 1)
		{
			delay(150);
			choose(390,260,&state7);
			single(&state5,&state6,&state8,&state6,&state8,190,260,290,260,490,260,290,260,490,260);
		}
		
		else if (mouse_press(485,255,495,265) == 2)   //奔驰
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
		else if (mouse_press(485,255,495,265) == 1)
		{
			delay(150);
			choose(490,260,&state8);
			single(&state5,&state6,&state7,&state6,&state7,190,260,290,260,390,260,290,260,390,260);
		}
		
		else if (mouse_press(185,315,195,325) == 2)   //营运
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
		else if (mouse_press(185,315,195,325) == 1)
		{
			delay(150);
			choose(190,320,&state9);
			single(&state10,&state10,&state10,&state10,&state10,390,320,390,320,390,320,390,320,390,320);
		}
		
		else if (mouse_press(385,315,395,325) == 2)   //非营运
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
		else if (mouse_press(385,315,395,325) == 1)
		{
			delay(150);
			choose(390,320,&state10);
			single(&state9,&state9,&state9,&state9,&state9,190,320,190,320,190,320,190,320,190,320);
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
					puthz(195,405,"提交",24,24,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,400,460,430);
					puthz(395,405,"返回",24,28,1);
				}
				
				else if(num == 4 && state1 == 0)
				{
					button(310,120,480,160,15,15,1);
				}
				
				else if(num == 5 && state2 == 0)
				{
					button(255,180,340,220,15,15,1);
				}
				else if(num == 6 && state3 == 0)
				{
					button(360,180,410,220,15,15,1);
				}
				else if(num == 7 && state4 == 0)
				{
					button(430,180,480,220,15,15,1);
				}
				num=0;
			}
			continue;
		}
	}
}

void drawbinding()
{	
	setbkcolor(LIGHTCYAN);
	
	puthz(220,20,"绑定车辆",48,56,1);
	setfillstyle(1,15);
	bar(275,120,480,160);
	puthz(160,130,"车牌号码",24,28,8);
	puthz(280,130,"鄂",24,28,8);
	puthz(60,250,"品牌型号",24,28,8);
	fillellipse(190,260,5,5);
	fillellipse(290,260,5,5);
	fillellipse(390,260,5,5);
	fillellipse(490,260,5,5);
	fillellipse(190,320,5,5);
	fillellipse(390,320,5,5);
	setcolor(8);
	circle(190,260,5);
	circle(290,260,5);
	circle(390,260,5);
	circle(490,260,5);
	circle(190,320,5);
	circle(390,320,5);
	puthz(200,250,"红旗",24,28,8);
	puthz(300,250,"奥迪",24,28,8);
	puthz(400,250,"宝马",24,28,8);
	puthz(500,250,"奔驰",24,28,8);
	puthz(60,310,"使用性质",24,28,8);
	puthz(200,310,"营运",24,28,8);
	puthz(400,310,"非营运",24,28,8);
	bar(255,180,500,220);
	puthz(140,190,"注册日期",24,28,8);
	puthz(340,190,"年",24,28,8);
	puthz(410,190,"月",24,28,8);
	puthz(480,190,"日",24,28,8);
		
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	puthz(195,405,"提交",24,24,1);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(395,405,"返回",24,28,1);
	
	setlinestyle(0,4,3);
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}

/*
int check_legal_bin(char* licensenum, char* caridnum, char* enginenum, 
					char* year, char* month, char* day)
{
	int i;
	int inputed = 0;	//判断是否有输入
	int format_licensenum = 0;   //判断输入字符是否符合要求
	int format_caridnum = 0;
	int format_enginenum = 0;
	int format_year = 0;
	int format_month = 0;
	int format_day = 0;
	
	while(1)
	{
		coverhz(485,135,11);	//覆盖文字
		coverhz(485,195,11);
		coverhz(485,255,11);
		coverhz(505,315,11);
	
		judgeinput(licensenum,&inputed,485,135);	//判断格式是否符合要求
		judgeinput(caridnum,&inputed,485,195);
		judgeinput(enginenum,&inputed,485,255);
		judgeinput(year,&inputed,505,315);
		judgeinput(month,&inputed,505,315);
		judgeinput(day,&inputed,505,315);
		
		if(inputed == 1)
		{
			break;
		}
		else if(inputed == 0)
		{
			format_name = check_username_dig (name,566,130-23);	//若符合格式则为 1
			format_pw = check_pw_dig (password,566,190-23);
			format_Cpw = check_comfirmpw(password,confirmpw,566,250-23);
			format_ID = check_id(ID,566,310-23);
			format_tele = check_tele_dig(tele,566,370-23);
			format_code = check_captcha(code,inputcode,566,430-23);
			
			if(check_samename(name,1))	//检查重名
			{
				break;
			}
			else
			{
				coverhz(350,68,11);
				if(format_name != 1 || format_pw != 1 || format_Cpw != 1 
					|| format_tele != 1 || format_code != 1 ||format_ID != 1)	
				{
					break;
				}
				else if(format_name == 1 && format_pw == 1 && format_Cpw == 1 
					&& format_tele == 1 && format_code == 1 &&format_ID == 1)
				{
					write_userdata(name,password,ID,tele);
					button(70,70,800,800,LIGHTCYAN,LIGHTCYAN,3);	//覆盖输入框
					button(200,200,430,300,CYAN,LIGHTGRAY,3);				
					puthz(256,238, "注册成功！", 24, 28, BLUE);
					return 1;
				}
			}
			
		}
	}
	return 0;
}

void write_cardata(char* licensenum, char* caridnum, char* enginenum, char* year, char* month, char* day)
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
	
	stpcpy(c->licensenum,licensenum);			//copy licensenum to C.licensenum
	stpcpy(c->caridnum,caridnum); 
	stpcpy(c->enginenum,enginenum);
	stpcpy(c->regdate.year,year);
	stpcpy(c->regdate.month,month);
	stpcpy(c->regdate.day,day);
	fseek(fp,0,SEEK_END);
	fwrite(c,sizeof(Car),1,fp);	//write c to *fp->file
	
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