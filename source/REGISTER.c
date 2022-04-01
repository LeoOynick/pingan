#include"common.h"
#include"register.h"

void regist(int *page)
{
	int num=0;
	char inputcode[6] = { '\0' };
	char name[13] = { '\0' };		//用户名（不超过12位）	
	char password[17] = { '\0' };	//密码（不超过16位）
	char confirmpw[17] = { '\0' };	//确认密码
	char ID[19] = { '\0' };			//身份证号（18位）
	char tele[12] = { '\0' };		//电话号码（11位）
	char code[6] = { '\0' };		//验证码（5位）
	int state1 = 0;					//判断是否有字符输入
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawregist();
	
	settextstyle(0,0,2);
	captcha(code);
	outtextxy(80,407,code);
	
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
		
		else if(mouse_press(180,440,260,470) == 2)		//注册
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,440,260,470,15,10,1);
				puthz(195,445,"注册",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,440,260,470) == 1)
		{
			MouseS = 0;
			/*if(flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1 && flag5 == 1 && flag6 == 1)
			{
				puthz(120,445,"注册成功！",24,28,RED);
			}*/
			//return;
			if(check_legal_reg(name,password,confirmpw,ID,tele,code,inputcode) == 1)
			{
				delay(1000); //remove when complete check_x function
				*page = 3;
				return;
			}
		}
		
		else if(mouse_press(380,440,460,470) == 2)		//返回
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(380,440,460,470,15,12,1);
				puthz(395,445,"返回",24,28,1);
				num = 3;
			}
			continue;
		}
		else if (mouse_press(380,440,460,470) == 1)
		{
			MouseS = 0;
		    *page = 0;
			return;
		}
		
		else if(mouse_press(80,100,560,130) == 2)		//用户名
		{
			if (num == 0 && state1 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,100,560,130,8,15,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(80,100,560,130) == 1)
		{
			MouseS = 0;
		    button(80,100,560,130,8,15,1);
			name[0] = '\0';
			input(name,85,102,12,15,2);
			if(strlen(name) != 0)
				state1 = 1;
			else
				state1 = 0;
			/*if(strlen(name) >= 4 && strlen(name) <= 12)
				flag1 = 1;
			else
				flag1 = 0;*/
			continue;
		}
		
		else if(mouse_press(80,160,560,190) == 2)		//密码
		{
			if (num == 0 && state2 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,160,560,190,8,15,1);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(80,160,560,190) == 1)
		{
			MouseS = 0;
		    button(80,160,560,190,8,15,1);
			password[0] = '\0';
			input(password,85,162,16,15,1);
			if(strlen(password) != 0)
				state2 = 1;
			else
				state2 = 0;
			/*if(strlen(password) >= 4 && strlen(password) <= 16)
				flag2 = 1;
			else
				flag2 = 0;*/
			continue;
		}
		
		else if(mouse_press(80,220,560,250) == 2)		//确认密码
		{
			if (num == 0 && state3 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,220,560,250,8,15,1);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(80,220,560,250) == 1)
		{
			MouseS = 0;
		    button(80,220,560,250,8,15,1);
			confirmpw[0] = '\0';
			input(confirmpw,85,222,16,15,1);
			if(strlen(confirmpw) != 0)
				state3 = 1;
			else
				state3 = 0;
			/*if(confirmpw == password)
				flag3 = 1;
			else
				flag3 = 0;*/
			continue;
		}
		
		else if(mouse_press(80,280,560,310) == 2)		//身份证号
		{
			if (num == 0 && state4 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,280,560,310,8,15,1);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(80,280,560,310) == 1)
		{
			MouseS = 0;
		    button(80,280,560,310,8,15,1);
			ID[0] = '\0';
			input(ID,85,282,18,15,2);
			if(strlen(ID) != 0)
				state4 = 1;
			else
				state4 = 0;
			/*if(strlen(ID) == 18)
				flag4 = 1;
			else
				flag4 = 0;*/
			continue;
		}
		
		else if(mouse_press(80,340,560,370) == 2)		//电话号码
		{
			if (num == 0 && state5 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(80,340,560,370,8,15,1);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(80,340,560,370) == 1)
		{
			MouseS = 0;
		    button(80,340,560,370,8,15,1);
			tele[0] = '\0';
			input(tele,85,342,11,15,2);
			if(strlen(tele) != 0)
				state5 = 1;
			else
				state5 = 0;
			/*if(strlen(tele) == 11)
				flag5 = 1;
			else
				flag5 = 0;*/
			continue;
		}
		else if(mouse_press(160,400,560,430) == 2)		//验证码
		{
			if ((num == 0 || num == 10)&& state6 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(160,400,560,430,8,15,1);
				num = 9;
			}
			continue;
		}
		else if (mouse_press(160,400,560,430) == 1)
		{
			MouseS = 0;
		    button(160,400,560,430,8,15,1);
			inputcode[0] = '\0';
			input(inputcode,165,402,5,15,2);
			if(strlen(inputcode) != 0)
				state6 = 1;
			else
				state6 = 0;
			/*if(inputcode == code)
				flag6 = 1;
			else
				flag6 = 0;*/
			continue;
		}
		
		else if(mouse_press(80,400,160,430) == 2)		//换验证码
		{
			if (num == 0 || num == 9)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				num = 10;
			}
			continue;
		}
		else if (mouse_press(80,400,160,430) == 1)
		{
			//MouseS = 0;
			button(80,400,160,430,7,7,1);
		    settextstyle(0,0,2);
			captcha(code);
			setcolor(1);
			outtextxy(80,407,code);
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
					bar(180,440,260,470);
					puthz(195,445,"注册",24,28,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,440,460,470);
					puthz(395,445,"返回",24,28,1);
				}
				
				else if(num == 4 && state1 == 0)
				{
					button(80,100,560,130,15,15,1);
				}
				else if(num == 5 && state2 == 0)
				{
					button(80,160,560,190,15,15,1);
				}
				else if(num == 6 && state3 == 0)
				{
					button(80,220,560,250,15,15,1);
				}
				else if(num == 7 && state4 == 0)
				{
					button(80,280,560,310,15,15,1);
				}
				else if(num == 8 && state5 == 0)
				{
					button(80,340,560,370,15,15,1);
				}
				else if(num == 9 && state6 == 0)
				{
					button(160,400,560,430,15,15,1);
				}
				num=0;
			}
			continue;
		}
	}
}

void drawregist()
{
	setbkcolor(11);
	setlinestyle(0,4,3);
	setfillstyle(1,15);
	bar(80,100,560,130);
    bar(80,160,560,190);
    bar(80,220,560,250);
	bar(80,280,560,310);
    bar(80,340,560,370);
    bar(160,400,560,430);
	setfillstyle(1,7);
	bar(80,400,160,430);
	puthz(80,80,"用户名",16,20,1);
	puthz(135,80,"（",16,18,8);
	settextstyle(1,0,1);
	outtextxy(155,75,"4-12");
	puthz(205,80,"个字符）",16,18,8);
    puthz(80,140,"密码",16,20,1);
	puthz(115,140,"（",16,18,8);
	outtextxy(135,135,"4-16");
	puthz(185,140,"个字符）",16,18,8);
    puthz(80,200,"确认密码",16,20,1);
    puthz(80,260,"身份证号",16,20,1);
    puthz(80,320, "电话号码",16,20,1);
    puthz(80,380,"验证码",16,20,1);
	
	setfillstyle(1,2);
	bar(180,440,260,470);
	setfillstyle(1,4);
	bar(380,440,460,470);
	puthz(195,445,"注册",24,28,1);
	puthz(395,445,"返回",24,28,1);
	puthz(200,20,"用户注册",48,56,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}

int check_legal_reg(char* name, char* password, char* confirmpw, 
					char* ID, char* tele, char* code, char* inputcode)
{
	int i;
	int inputed = 0;	//判断是否有输入
	int format_name = 0;   //判断输入字符是否符合要求
	int format_pw = 0;
	int format_Cpw = 0;
	int format_ID = 0;
	int format_tele = 0;
	int format_code = 0;
	
	while(1)
	{
		coverhz(566,130-23,11);	//覆盖文字
		coverhz(566,190-23,11);
		coverhz(566,250-23,11);
		coverhz(566,310-23,11);
		coverhz(566,370-23,11);
		coverhz(566,430-23,11);
	
		judgeinput(name,&inputed,566,130-23);	//判断格式是否符合要求
		judgeinput(password,&inputed,566,190-23);
		judgeinput(confirmpw,&inputed,566,250-23);
		judgeinput(ID,&inputed,566,310-23);
		judgeinput(tele,&inputed,566,370-23);
		judgeinput(inputcode,&inputed,566,430-23);
		
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
			
			if(!check_samename(name,1))	//检查重名
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
					//button(								//差输出形式
					//puthz
					return 1;
				}
			}
			
		}
	}
	return 0;
}

void write_userdata(char* name, char* pw, char* ID, char* tele)
{
	FILE *fp = NULL;
	User *u = NULL;
	
	if( (fp = fopen("Database\\UserData.dat", "rb+" )) == NULL )	//open userdata.dat in fp
	{
		printf("Error! Can't Open \"UserData.dat\" File");
		delay(1500);
		exit(1);
	}
	
	if( (u = (User*)malloc(sizeof(User))) == NULL )	//allocate memory for u
	{
		printf("Error - unable to allocate required memory");
		delay(1500);
		exit(1);
	}
	
	stpcpy(u->name,name);			//copy name to U.name
	stpcpy(u->password,pw); 
	stpcpy(u->ID,ID);
	stpcpy(u->tele,tele);
	fseek(fp,0,SEEK_END);
	fwrite(u,sizeof(User),1,fp);	//write u to *fp->file
	
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	
	if (fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(3000);
		exit(1);
	}
	
}
	