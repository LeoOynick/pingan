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
	int i;
	if (strlen(str) != 6 )
	{
		puthz(x, y, "车牌有误", 16, 17, RED);
		return 0;
	}
	else if(str[0] < 'A' || str[0] > 'Z')
	{
		puthz(x, y, "第一位为大写字母", 16, 17, RED);
		return 0;
	}
	else
	{
		for (i = 0; i < 6; i++)
		{
			if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z'))
			{
				continue;
			}
			else
			{
				puthz(x, y, "格式不正确", 16, 17, RED);
				return 0;
			}
		}
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3); 
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 1;
	}
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
		return 0;
	}
	else if (strlen(month) != 2)
	{
		puthz(x, y, "月份为两位", 16, 17, RED);
		return 0;
	}
	else if (strlen(date) != 2)
	{
		puthz(x, y, "日期为两位", 16, 17, RED);
		return 0;
	}
	else
	{
		if (atoi(year) > local->tm_year + 1900 
			|| (atoi(year) == local->tm_year + 1900 && atoi(month) > local->tm_mon + 1)
			|| (atoi(year) == local->tm_year + 1900 && atoi(month) == local->tm_mon + 1 && atoi(date) > local->tm_mday))
		{
			puthz(x, y, "不能超出当前时间", 16, 17, RED);
			return 0;
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
				return 0;
			}
		}
		if(legal_date(atoi(year),atoi(month),atoi(date),x,y) == 0)
		{
			return 0;
		}
		setcolor(GREEN);
		setlinestyle(SOLID_LINE, 0, 3); 
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 1;
	}
}

int legal_date(int year, int month, int date, int x, int y)
{
	if(month < 1 || month > 12)
	{
		puthz(x, y, "日期不合法", 16, 17, RED);
		return 0;
	}
	else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (date < 1 || date > 31))
	{
		puthz(x, y, "日期不合法", 16, 17, RED);
		return 0;
	}
	else if((month == 4 || month == 6 || month == 9 || month == 11) && (date < 1 || date > 30))
	{
		puthz(x, y, "日期不合法", 16, 17, RED);
		return 0;
	}
	else
	{
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if(date < 1 || date > 29)
			{
				puthz(x, y, "日期不合法", 16, 17, RED);
				return 0;
			}
		}
		else
		{
			if(date < 1 || date > 28)
			{
				puthz(x, y, "日期不合法", 16, 17, RED);
				return 0;
			}
		}
	}
	return 1;
}

int show_car(User* u, int x,int y,int flag, int *state)	//显示车辆信息
{
	int i;
	int j = 0;
	int a = 0;
	int carnum = 0;
	settextstyle(1, HORIZ_DIR, 2);
	setlinestyle(SOLID_LINE,0,3);
	
	for(i = 0; i < 3; i++)
	{
		setcolor(DARKGRAY);
		if(strlen(u->car[i].licensenum) != 0)
		{
			while(strlen(u->car[*state].licensenum) == 0 && a < 3)
			{
				if(*state < 2)
				{
					*state ++;
				}
				else
				{
					*state = 0;
				}
				a++;
			}
				
			carnum++;
			if(flag == 2)
			{
				switch(u->car[i].type[0])
				{
					case '1':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "红旗", 24, 25, DARKGRAY);
						break;
					case '2':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "奥迪", 24, 25, DARKGRAY);
						break;
					case '3':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "宝马", 24, 25, DARKGRAY);
						break;
					case '4':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "奔驰", 24, 25, DARKGRAY);
						break;
				}
			}
			else if (flag != 2 && carnum == 1)
			{
				switch(u->car[*state].type[0])
				{
					case '1':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "红旗", 24, 25, DARKGRAY);
						break;
					case '2':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "奥迪", 24, 25, DARKGRAY);
						break;
					case '3':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "宝马", 24, 25, DARKGRAY);
						break;
					case '4':
						puthz(x + 2, y + 5 + (3 + 31 * flag) * i, "奔驰", 24, 25, DARKGRAY);
						break;	
				}
			}
			if(flag == 2)
			{
				switch(u->car[i].nature[0])
				{
					case '1':
						puthz(x + 150, y + 8 + (3 + 31 * flag) * i, "营运",16,17,DARKGRAY);
						break;
					case '2':
						puthz(x + 150, y + 8 + (3 + 31 * flag) * i, "非营运",16,17,DARKGRAY);
						break;
				}
			}
			else
			{
				if(carnum == 1)
				{
					switch(u->car[*state].nature[0])
					{
						case '1':
							puthz(x + 150, y + 8 + (3 + 31 * flag) * i, "营运",16,17,DARKGRAY);
							break;
						case '2':
							puthz(x + 150, y + 8 + (3 + 31 * flag) * i, "非营运",16,17,DARKGRAY);
							break;
					}
				}
			}
			if(flag == 2)
			{
				puthz(x + 65, y + 8 + (3 + 31 * flag) * i, "使用性质", 16, 18, DARKGRAY);
				puthz(x + 220, y + 5 + (3 + 31 * flag) * i, "车牌号码", 24, 25, DARKGRAY);
				puthz(x + 330, y + 5 + (3 + 31 * flag) * i, "鄂", 24, 25, DARKGRAY);
				outtextxy(x + 357, y + 2 + (3 + 31 * flag) * i, u->car[i].licensenum);
			}
			else
			{
				if(carnum == 1)
				{
					puthz(x + 65, y + 8 + (3 + 31 * flag) * i, "使用性质", 16, 18, DARKGRAY);
					puthz(x + 220, y + 5 + (3 + 31 * flag) * i, "车牌号码", 24, 25, DARKGRAY);
					puthz(x + 330, y + 5 + (3 + 31 * flag) * i, "鄂", 24, 25, DARKGRAY);
					outtextxy(x + 357, y + 2 + (3 + 31 * flag) * i, u->car[*state].licensenum);
				}
			}
			if(flag ==2)
			{ 
				setcolor(LIGHTGRAY);
				for( j = 0 ; j < carnum ; j++)
				{
					rectangle(x, y + (3 + 31 * flag) * i, x + 490, y + (3 + 31 * flag) * (i + 1));
				}
				puthz(122 -40, 205 + 65 * i, "注册日期", 24, 25, WHITE);
				outtextxy(290-40, 205 + 65 * i, u->car[i].regdate.year);
				puthz(350-40, 205 + 65 * i, "年", 24, 25, WHITE);
				outtextxy(387-40, 205 + 65 * i, u->car[i].regdate.month);
				puthz(430-40, 205 + 65 * i, "月", 24, 25, WHITE);
				outtextxy(467-40, 205 + 65 * i, u->car[i].regdate.day);
				puthz(510-40, 205 + 65 * i, "日", 24, 25, WHITE);
			}
		}
	}
	if( carnum < 3 && flag == 2)
	{
		bar(20 ,160 + 90* j,620,200 + 90* j);
		setcolor(8);
		line(185 ,180 + 90* j,215,180 + 90* j);
		line(200 ,165 + 90* j,200,195 + 90* j);
		puthz(280 ,170 + 90* j,"立即添加车辆",24,28,8);	
	}
	return carnum;
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
			
			for(j = 2 ; j > -1 ; j--)
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