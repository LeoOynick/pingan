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

int check_captcha(char* str1, char* str2,int x, int y) //return 0 for match else return 1
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
		return 0;
	}

		puthz(x,y,"输入错误",16,17,RED);
	
	return 1;
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