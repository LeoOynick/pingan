#include "common.h"
#include "commonfunc.h"


void button (int x1,int y1,int x2,int y2,int framecolor,int fillcolor,int framewidth){
	clrmous(MouseX, MouseY); //防止画图函数与鼠标重叠
	delay(10);
	setcolor(framecolor);
	setlinestyle(SOLID_LINE, 0, framewidth); //width = "1" or "3" pixel
	setfillstyle(1, fillcolor);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);
}

/*********************************************
FUNCTION:input
DESCRIPTION：flag = 1时正常显示输入信息
			 flag = 2时输入信息以"*"号遮盖
INPUT:id,x1,y1,charnum,color
RETURN:无
***********************************************/
void input(char* id, int x1, int y1, int charnum, int color, int flag)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色，输入模式
{
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(8);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, flag);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while(bioskey(1))
		getch();//删掉之前键盘乱按的无用字符
	while (1)
	{
		t = bioskey(0); 
		if (t != '\n' && t != '\r' && t != ' ' && t != 033)//Esc
		{
			if (t != '\b' && i < charnum)
			{
				*(id + i) = t;
				*(id + i + 1) = '\0';
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
				if(flag == 1)
					outtextxy(x1 + 8 + i * 18, y1 + 3, "*");//输出 ‘*’
				else
					outtextxy(x1 + 8 + i * 18, y1, id + i);//输出t字符(16)
				i++;
				line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
			}
			else if (t == '\b' && i > 0)//退格键
			{
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
				bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
				i--;//减少一个字数
				line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
				*(id + i) = '\0';
			}
		}
		else
		{
			bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
			break;
		}
	}
}

void coverhz(int x, int y, int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 110, y + 30);
}

void show_tickcross(int x1, int y1, int x2,int y2, int flag)	//flag == 1 show tick, else cross,xy base on cross.
{
	if(flag == 1)
	{	
		setlinestyle(SOLID_LINE, 0, 3); 
		setcolor(11);
		line(x1,y1,x2,y2); 
		line(x2,y1,x1,y2);
		
		setcolor(GREEN);
		line(x1 + 24 -26, y1 + 9 +2 , x1 + 33 -26, y1 + 19 +2 );
		line(x1 + 33 -26, y1 + 19 +2, x1 + 43 -26, y1 - 3 +2);
	}
	else
	{
		setcolor(11);
		setlinestyle(SOLID_LINE, 0, 3); 
		/*line(x1 + 24, y1 + 9, x1 + 33, y1 + 19);	//ori
		line(x1 + 33, y1 + 19, x1 + 43, y1 - 3);
		line(x1 + 20 - 22, y1 +	7, x1 + 29 -22, y1 + 17);
		line(x1 + 28 -22, y1 + 17, x1 + 39 -22 , y1 - 5);*/
		line(x1 + 24 -26, y1 + 9 +2 , x1 + 33 -26, y1 + 19 +2 );
		line(x1 + 33 -26, y1 + 19 +2, x1 + 43 -26, y1 - 3 +2);
		
		setcolor(RED);
		line(x1,y1,x2,y2); 
		line(x2,y1,x1,y2);// x2 y1 x1 y2
	}
}

void captcha (char* str){ //5 digits

	char a,i,j;
	srand(time(NULL));
	
	for (i = 0; i < 5; i++)
	{
		j = rand() % 3;
		if( j == 0 )
		{
			a = rand() % 26 + 97;
			str[i] = a;
		}
		else if( j == 1 )
		{
			a = rand() % 26 + 65;
			str[i] = a;
		}
		else
		{
			a = rand() % 10 + 48; // 0-9
			str[i] = a;
		}
	}
	str[5] = '\0';
	
}

int check_captcha(char* str1, char* str2,int x, int y) //return 1 for match else return 0
{
	if(strcmp(str1,str2) != 0)
	{
		puthz(x,y,"输入错误",16,17,RED);
		
	}
	else if (strcmp(str1,str2) == 0)	//match and display tick
	{
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3); 
		line(x + 24, y + 9, x + 33, y + 19);
		line(x + 33, y + 19, x + 43, y - 3);
		return 1;
	}

		puthz(x,y,"输入错误",16,17,RED);
	
	return 0;
}

int check_samename(char* name, int flag)	//flag 1--用户已被注册, 2--账号存在, 3--不输出
{
	int i;
	int set_num;
	FILE *fp = NULL;
	User *u = NULL;
	
	if( (fp = fopen("Database\\UserData.dat", "rb+" )) == NULL )	//open userdata.dat in fp
	{
		printf("Error! Can't Open \"UserData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp,0,SEEK_END);
	set_num = ftell(fp) / sizeof(User);	// total / sizeof User
	
	for(i = 0; i < set_num ; i++)
	{
		if( (u = (User*)malloc(sizeof(User))) == NULL )	//allocate memory for u
		{
			printf("Error - unable to allocate required memory");
			delay(1500);
			exit(1);
		}
		
		fseek(fp, i * sizeof(User), SEEK_SET);	//指向每隔一个User大小的
		fread(u, sizeof(User), 1, fp);			//读取一个u
		
		if( strcmp(name,u->name) == 0) 
		{
			switch(flag)
			{
				case 1:
					puthz(350,80,"用户已被注册",16 ,17 ,RED);
					
					show_tickcross(592,105,607,125,0);
					/*setcolor(LIGHTCYAN);
					setlinestyle(SOLID_LINE, 0, 3); 
					line(566 + 24, 130-23 + 9, 566 + 33, 130-23 + 19);
					line(566 + 33, 130-23 + 19, 566 + 43, 130-23 - 3);
					
					setcolor(RED);
					line(592,105,607,125);
					line(607,105,592,125);*/
					break;
					
				case 2:
					puthz(430, 80, "账号存在", 16, 17, GREEN);
					break;
					
				case 3:		//不输出
					break;
					
				default:
					printf("check flag of \"check_samename\" function");
					delay(1500);
					exit(1);
			}
			
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 1;
			
		}
		free(u);
		u = NULL; 
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 0;	
}

int check_license_dig(char* str, int x, int y)
{
	if(strlen(str) == 6)
	{
		show_tickcross(592,105,607,125,1);
		return 1;
	}
	else
	{
		puthz(x,y,"车牌有误",16,17,RED);
		
	}
	return 0;
}

int judge_samecar(char* new_car) 
{
	int i,j;
	int set_num;
	FILE* fp;
	User * u = NULL;
	
	if( (fp = fopen("Database\\UserData.dat", "rb+" )) == NULL )	//open Userdata.dat in fp
	{
		printf("Error! Can't Open \"UserData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	set_num = ftell(fp) / sizeof(User);
	
	for (i = 0; i < set_num; i++)
	{
		if( (u = (User*)malloc(sizeof(User))) == NULL )	//allocate memory for u
		{
			printf("Error - unable to allocate required memory");
			delay(1500);
			exit(1);
		}
		
		fseek(fp, i * sizeof(User), SEEK_SET);
		fread(u, sizeof(User), 1, fp);
		
		for(j = 0; j < 2; j++)
		{
			if (strcmp(u->car[j].licensenum, new_car) == 0)
			{
				puthz(547, 270, "车牌号已存在", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database.");
					delay(3000);
					exit(1);
				}
				return 0;
			}
		}
		/*if (strcmp(u->car[0].licensenum, new_car) == 0 || strcmp(u->car[1].licensenum, new_car) == 0 || 
			strcmp(u->car[2].licensenum, new_car) == 0 )
		{
			puthz(547, 270, "车牌号已存在", 16, 17, RED);
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 0;
		}*/
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 1;
}


int check_date(char* year, char* month, char* date, int x, int y)
{
	struct tm *local;
    time_t t;
	int i;
	char str[9]={ '\0' };
	t=time(NULL);
	local=localtime(&t);
	strcat(str, year);
	strcat(str, month);
	strcat(str, date);
	if (strlen(year) != 4)
	{
		puthz(x, y, "年份为四位", 16, 17, RED);
		return 1;
	}
	else if (strlen(month) != 2)
	{
		puthz(x, y, "月份为两位", 16, 17, RED);
		return 1;
	}
	else if (strlen(date) != 2)
	{
		puthz(x, y, "日期为两位", 16, 17, RED);
		return 1;
	}
	else
	{
		if (atoi(year) > local->tm_year + 1900 
			|| (atoi(year) == local->tm_year + 1900 && atoi(month) > local->tm_mon + 1)
			|| (atoi(year) == local->tm_year + 1900 && atoi(month) == local->tm_mon + 1 && atoi(date) > local->tm_mday))
		{
			puthz(x, y, "不能超出当前时间", 16, 17, RED);
			return 1;
		}	
		for (i = 0; i < 8; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x, y, "格式不正确", 16, 17, RED);
				return 1;
			}
		}
		if (atoi(month) < 1 || atoi(month) > 12 || atoi(date) < 1 || atoi(date) > 31)
		{
			puthz(x, y, "格式不正确", 16, 17, RED);
			return 1;
		}
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3); 
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
}


int output_userinfo(User *us, int *usernum, int *carnum)
{
	int i,j;
	int set_num;
	FILE *fp;
	User *u = NULL;
	
	if( (fp = fopen("Database\\UserData.dat", "rb+" )) == NULL )	//open userdata.dat in fp
	{
		printf("Error! Can't Open \"UserData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	fseek(fp,0,SEEK_END);
	set_num = ftell(fp) / sizeof(User);// total / sizeof User
	
	for(i = 0; i < set_num ; i++)
	{
		if( (u = (User*)malloc(sizeof(User))) == NULL )	//allocate memory for u
		{
			printf("Error - unable to allocate required memory");
			delay(1500);
			exit(1);
		}
		
		fseek(fp, i * sizeof(User), SEEK_SET);	//指向每隔一个User大小的
		fread(u, sizeof(User), 1, fp);			//读取一个u
		
		if(strcmp(us->name,u->name) == 0)
		{
			memset(us,'\0',sizeof(User));              //先重置us
			strcpy(us->name,u->name); 
			strcpy(us->password,u->password); 
			strcpy(us->ID,u->ID); 
			strcpy(us->tele,u->tele);
			
			for(j=2;j>-1;j--)
			{
				if(strlen(u->car[j].licensenum) == 0)
				{
					*carnum = j;
				}
				else
				{
					strcpy(us->car[j].licensenum,u->car[j].licensenum); 
					strcpy(us->car[j].type,u->car[j].type);
					strcpy(us->car[j].nature,u->car[j].nature);
					strcpy(us->car[j].regdate.year,u->car[j].regdate.year);
					strcpy(us->car[j].regdate.month,u->car[j].regdate.month);
					strcpy(us->car[j].regdate.day,u->car[j].regdate.day);
				}
			}
			
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database");
				delay(2000);
				exit(1);				
			}
			*usernum = i;
			return 1;		//outputted
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(2000);
		exit(1);				
	}
	return 0;	//output error
}

void judgeinput(char* str,int* state,int x,int y) //判断是否有输入
{
	if(strlen(str) == 0)
	{
		puthz(x,y,"未输入！",16,17,RED);
		*state = 1;
	}
}

int check_username_dig(char* str,int x,int y) //4-12位用户名
{
	if(strlen(str) >=4 && strlen(str) <=12)
	{
		show_tickcross(592,105,607,125,1);
		/*setlinestyle(SOLID_LINE, 0, 3); 
		setcolor(LIGHTCYAN);
		line(592,105,607,125);
		line(607,105,592,125);
		
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3); 
		line(x + 24, y + 9, x + 33, y + 19);
		line(x + 33, y + 19, x + 43, y - 3);*/
		return 1;
	}
	else if(strlen(str) < 4)
	{
		puthz(x,y,"检查长度",16,17,RED);
		/*setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1,HORIZ_DIR,2);
		outtextxy(x+72,y-5,">4!");*/
	}
	return 0;
}

int check_comfirmpw(char* str1,char* str2,int x,int y)
{
	if(strcmp(str1,str2) == 0) //same
	{
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3); 
		line(x + 24, y + 9, x + 33, y + 19);
		line(x + 33, y + 19, x + 43, y - 3);
		
		return 1;
	}
	else
	{
		puthz(x,y,"检查密码",16,17,RED);	
	}
	return 0;
}

int check_pw_dig(char* str,int x,int y)
{
	if(strlen(str) >=4 && strlen(str) <=16)
	{
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3); 
		line(x + 24, y + 9, x + 33, y + 19);
		line(x + 33, y + 19, x + 43, y - 3);
		
		return 1;
	}
	else if(strlen(str) < 4)
	{
		puthz(x,y,"检查长度",16,17,RED);
		/*setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1,HORIZ_DIR,1);
		outtextxy(x+53,y-5,">4!");*/
	}
	return 0;
}

int check_tele_dig(char* str,int x,int y)
{
	int i;
	if(strlen(str) != 11)
	{
		puthz(x,y,"检查长度",16,17,RED);
		return 0;
	}
	else
	{
		for(i=0;i<11;i++)
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x,y,"检查格式",16,17,RED);
				return 0;
			}
		}
	}
	setcolor(GREEN);
	setlinestyle(SOLID_LINE, 0, 3); 
	line(x + 24, y + 9, x + 33, y + 19);
	line(x + 33, y + 19, x + 43, y - 3);
	
	return 1;
}

int check_id(char* str,int x,int y)
{
	int i;
	if(strlen(str) != 18)
	{
		puthz(x,y,"检查长度",16,17,RED);
		return 0;
	}
	else
	{
		for(i=0;i<17;i++)
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x,y,"检查格式",16,17,RED);
				return 0;
			}
		}
		if(str[17] =='X' || (str[17] >= '0' && str[17] <= '9') )
		{
			setcolor(GREEN);
			setlinestyle(SOLID_LINE, 0, 3); 
			line(x + 24, y + 9, x + 33, y + 19);
			line(x + 33, y + 19, x + 43, y - 3);
			return 1;
		}
		else
		{
			puthz(x,y,"检查格式",16,17,RED);
			return 0;
		}
	}
}

void choose(int x,int y,int *state)	
{
	delay(150);
	if(*state == 0)
	{
		clrmous(MouseX, MouseY);
		delay(10);
		setfillstyle(1,RED);
		fillellipse(x,y,3,3);
		*state = 1;
	}
	else if(*state == 1)
	{
		clrmous(MouseX, MouseY);
		delay(10);
		setfillstyle(1,15);
		fillellipse(x,y,5,5);
		setcolor(8);
		circle(x,y,5);
		*state = 0;
	}
}

void single(int *state1, int *state2, int *state3, int *state4, int *state5, int x1, int y1,
			int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5)
{
	if(*state1 == 1)
		choose(x1,y1,state1);
	if(*state2 == 1)
		choose(x2,y2,state2);
	if(*state3 == 1)
		choose(x3,y3,state3);
	if(*state4 == 1)
		choose(x4,y4,state4);
	if(*state5 == 1)
		choose(x5,y5,state5);
}

void price(int *state1, int *state2, int *state3, int *state4, int *state5, int *state6, 
			int cost1, int cost2, int cost3, int cost4, int cost5, int cost6, int cost, char *charge, int x, int y)
{
	cost = *state1 * cost1 + *state2 * cost2 + *state3 * cost3 +  *state4 * cost4 + *state5 * cost5 + *state6 * cost6;
	itoa(cost,charge,10);
	setfillstyle(1,LIGHTCYAN);
	bar(x-5,y-5,x+45,y+20);
	setcolor(8);
	settextstyle(1,0,1);
	outtextxy(x,y,charge);	
}