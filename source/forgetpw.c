#include"common.h"
#include"forgetpw.h"

void forget(int *page)
{
	int num=0;
	char inputcode[6] = { '\0' };
	char str[6] = { '\0' };
	char name[13] = { '\0' };   //用户名（不超过12位）	
	char password[17] = { '\0' };   //重置密码（不超过16位）
	char confirmpw[17] = { '\0' };   //确认密码
	char ID[19] = { '\0' };   //身份证号（18位）
	char tele[12] = { '\0' };   //电话号码（11位）
	char code[6] = { '\0' };   //验证码（5位）
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	int state6 = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawforget();
	
	settextstyle(0,0,2);
	captcha(code);
	outtextxy(80,407,code);
	
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
		
		else if(mouse_press(180,440,260,470) == 2)   //完成
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,440,260,470,15,10,1);
				puthz(195,445,"完成",24,28,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,440,260,470) == 1)
		{
			//MouseS = 0;
			if(verify_forgotpw_info(name,password,confirmpw,ID,tele,code,inputcode))
			{
				delay(1500);
				*page = 3;
				return;
			}
			else
			{
				continue;
			}
			
		}
		
		else if(mouse_press(380,440,460,470) == 2)   //返回
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
		
		else if(mouse_press(80,100,560,130) == 2)   //用户名
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
			continue;
		}
		
		else if(mouse_press(80,160,560,190) == 2)   //重置密码
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
			continue;
		}
		
		else if(mouse_press(80,220,560,250) == 2)   //确认密码
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
			continue;
		}
		
		else if(mouse_press(80,280,560,310) == 2)   //身份证号
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
			continue;
		}
		
		else if(mouse_press(80,340,560,370) == 2)   //电话号码
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
					puthz(195,445,"完成",24,28,1);
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

void drawforget()
{
	
	setfillstyle(1,15);
	setbkcolor(11);
	bar(80,100,560,130);
    bar(80,160,560,190);
    bar(80,220,560,250);
	bar(80,280,560,310);
    bar(80,340,560,370);
    bar(160,400,560,430);
	setfillstyle(1,7);
	bar(80,400,160,430);
	puthz(80,80,"用户名",16,20,1);
	puthz(80,140,"重置密码",16,20,1);
    puthz(80,200,"确认密码",16,20,1);
    puthz(80,260,"身份证号",16,20,1);
    puthz(80,320,"电话号码",16,20,1);
    puthz(80,380,"验证码",16,20,1);
	
	setfillstyle(1,2);
	bar(180,440,260,470);
	setfillstyle(1,4);
	bar(380,440,460,470);
	puthz(195,445,"完成",24,28,1);
	puthz(395,445,"返回",24,28,1);
	puthz(200,20,"忘记密码",48,56,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
	setlinestyle(0,4,3);
    line(610,0,640,30);
    line(640,0,610,30);
}

int verify_forgotpw_info(char* name, char* password, char* confirmpw, 
					char* ID, char* tele, char* code, char* inputcode)
{
	int inputed = 0;
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
		
		/*coverhz(350,68,11);
		coverhz(355,68,11);*/
		coverhz(430,68,11);
		if(inputed == 1)
		{
			break;
		}
		else if(inputed == 0)
		{
			if(!check_samename(name,2))	//账号不存在
			{
				puthz(430, 80, "账号不存在", 16, 17, RED);
				show_tickcross(592,105,607,125,0);
				/*setlinestyle(SOLID_LINE, 0, 3);
				setcolor(11);
				line(566 + 24, 130-23 + 9, 566 + 33, 130-23 + 19);
				line(566 + 33, 130-23 + 19, 566 + 43, 130-23 - 3);
				setcolor(RED);
				line(592,105,607,125);
				line(607,105,592,125);*/
				/*format_name = check_username_dig (name,566,130-23);	//若符合格式则为 1
				format_pw = check_pw_dig (password,566,190-23);
				format_Cpw = check_comfirmpw(password,confirmpw,566,250-23);
				format_ID = check_id(ID,566,310-23);
				format_tele = check_tele_dig(tele,566,370-23);
				format_code = check_captcha(code,inputcode,566,430-23);*/
				
				break;
				
			}
			else if(check_samename(name,2))
			{
				
				show_tickcross(592,105,607,125,1);
				/*setlinestyle(SOLID_LINE, 0, 3); 
				setcolor(11);
				line(592,105,607,125);
				line(607,105,592,125);
				
				setcolor(GREEN);
				line(566 + 24, 130-23 + 9, 566 + 33, 130-23 + 19);
				line(566 + 33, 130-23 + 19, 566 + 43, 130-23 - 3);*/
				
				//format_name = check_username_dig (name,566,130-23);	//若符合格式则为 1
				format_pw = check_pw_dig (password,566,190-23);
				format_Cpw = check_comfirmpw(password,confirmpw,566,250-23);
				format_ID = check_id(ID,566,310-23);
				format_tele = check_tele_dig(tele,566,370-23);
				format_code = check_captcha(code,inputcode,566,430-23);
			
				
				if(format_pw != 1 || format_Cpw != 1 
					|| format_tele != 1 || format_code != 1 ||format_ID != 1)	
				{
					break;
				}
				else if(format_pw == 1 && format_Cpw == 1 
					&& format_tele == 1 && format_code == 1 &&format_ID == 1)
				{
					
					if(change_userpw(name,password,confirmpw,ID,tele))
					{
						button(70,70,800,800,LIGHTCYAN,LIGHTCYAN,3);	//覆盖输入框
						button(200,200,430,300,CYAN,LIGHTGRAY,3);				
						puthz(256,238, "重置成功！", 24, 28, BLUE);
						return 1;
					}
					else
					{
						break;
					}
					
				}
			}
			
		}
	}
	return 0;
}

int change_userpw(char* name, char* password, char* confirmpw, 
					char* ID, char* tele)
{
	int i;
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
		
		if(strcmp(name,u->name) == 0) 			//用户名匹配
		{
			if(strcmp(ID,u->ID) != 0) 
			{
				//coverhz(430,260,11);
				puthz(430, 260, "证件不匹配", 16, 17, RED);
				
				
				/*setcolor(LIGHTCYAN);
				setlinestyle(SOLID_LINE, 0, 3); 
				line(566 + 24, 130-23 + 9, 566 + 33, 130-23 + 19);
				line(566 + 33, 130-23 + 19, 566 + 43, 130-23 - 3);
					
				setcolor(RED);
				line(592,105,607,125);
				line(607,105,592,125);*/
				show_tickcross(592,285,607,305,0);
				/*setcolor(RED);
				line(592,285,607,305);
				line(607,285,592,305);*/
			}
			else if(strcmp(ID,u->ID) == 0)
			{
				coverhz(430,250,11);
				show_tickcross(592,285,607,305,1);
				/*setcolor(11);
				line(592,105,607,125);
				line(607,105,592,125);
				check_id(ID,566,310-23);*/
			}
			
			if(strcmp(tele,u->tele) != 0)
			{
				//coverhz(566,310-23,11);
				puthz(430, 320, "电话不匹配", 16, 17, RED);
				
				show_tickcross(592,345,607,365,0);
				/*setcolor(RED);
				line(592,345,607,365);
				line(607,345,592,365);*/
			}
			else if (strcmp(tele,u->tele) == 0)
			{
				coverhz(430,310,11);
				show_tickcross(592,345,607,365,1);
				/*setcolor(11);
				line(592,125,607,145);
				line(607,125,592,145);
				check_tele_dig(tele,566,370-23);*/
			}
			
			if((strcmp(ID,u->ID) == 0) && (strcmp(tele,u->tele) == 0))
			{
				if(strcmp(password,confirmpw) == 0)
				{
					u->password[0] = '\0';
					strcpy(u->password, password);
					fseek(fp, i * sizeof(User), SEEK_SET);
					fwrite(u, sizeof(User), 1, fp);
					
					if (u != NULL)
					{
						free(u);
						u = NULL;
					}
					if (fclose(fp) != 0)
					{
						printf("\n cannot close Database");
						exit(1);
					}
					//delay(2000);
					return 1;
				}
			}
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
		exit(1);
	}
	return 0;
}			