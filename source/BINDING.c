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
		
		else if(mouse_press(180,400,260,430) == 2)		//下一步
		{
			if (num == 0)
			{
				MouseS = 1;
				clrmous(MouseX, MouseY);
				delay(10);
				button(180,400,260,430,15,10,1);
				puthz(185,405,"下一步",24,24,1);
				num = 2;
			}
			continue;
		}
		else if (mouse_press(180,400,260,430) == 1)
		{
			MouseS = 0;
			*page = 20;
			return;
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
		    *page = 0;
			return;
		}
		
		else if(mouse_press(275,120,480,160) == 2)		//车牌号码
		{
			if (num == 0 && state1 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(275,120,480,160,8,15,1);
				num = 4;
			}
			continue;
		}
		else if (mouse_press(275,120,480,160) == 1)
		{
			MouseS = 0;
		    button(275,120,480,160,8,15,1);
			licensenum[0] = '\0';
			input(licensenum,280,122,11,15,2);
			if(strlen(licensenum) != 0)
				state1 = 1;
			else
				state1 = 0;
			continue;
		}
		
		else if(mouse_press(275,180,480,220) == 2)		//车架号码
		{
			if (num == 0 && state2 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(275,180,480,220,8,15,1);
				num = 5;
			}
			continue;
		}
		else if (mouse_press(275,180,480,220) == 1)
		{
			MouseS = 0;
		    button(275,180,480,220,8,15,1);
			caridnum[0] = '\0';
			input(caridnum,280,182,11,15,2);
			if(strlen(caridnum) != 0)
				state2 = 1;
			else
				state2 = 0;
			continue;
		}
		
		else if(mouse_press(275,240,480,280) == 2)		//发动机号
		{
			if (num == 0 && state3 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(275,240,480,280,8,15,1);
				num = 6;
			}
			continue;
		}
		else if (mouse_press(275,240,480,280) == 1)
		{
			MouseS = 0;
		    button(275,240,480,280,8,15,1);
			enginenum[0] = '\0';
			input(enginenum,280,242,11,15,2);
			if(strlen(enginenum) != 0)
				state3 = 1;
			else
				state3 = 0;
			continue;
		}
		
		else if(mouse_press(275,300,320,340) == 2)		//年
		{
			if (num == 0 && state4 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(275,300,320,340,8,15,1);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(275,300,320,340) == 1)
		{
			MouseS = 0;
		    button(275,300,320,340,8,15,1);
			year[0] = '\0';
			input(year,280,302,11,15,2);
			if(strlen(year) != 0)
				state4 = 1;
			else
				state4 = 0;
			continue;
		}
		
		else if(mouse_press(360,300,380,340) == 2)		//月
		{
			if (num == 0 && state5 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(360,300,380,340,8,15,1);
				num = 7;
			}
			continue;
		}
		else if (mouse_press(360,300,380,340) == 1)
		{
			MouseS = 0;
		    button(360,300,380,340,8,15,1);
			month[0] = '\0';
			input(month,360,302,11,15,2);
			if(strlen(month) != 0)
				state5 = 1;
			else
				state5 = 0;
			continue;
		}
		
		else if(mouse_press(420,300,440,340) == 2)		//日
		{
			if (num == 0 && state6 == 0)
			{
				MouseS = 2;
				clrmous(MouseX, MouseY);
				delay(10);
				button(420,300,440,340,8,15,1);
				num = 8;
			}
			continue;
		}
		else if (mouse_press(420,300,440,340) == 1)
		{
			MouseS = 0;
		    button(420,300,440,340,8,15,1);
			day[0] = '\0';
			input(day,360,302,11,15,2);
			if(strlen(day) != 0)
				state6 = 1;
			else
				state6 = 0;
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
					bar(180,400,260,430);
					puthz(185,405,"下一步",24,24,1);
				}
				else if(num == 3)
				{
					setfillstyle(1,4);
					bar(380,400,460,430);
					puthz(395,405,"返回",24,28,1);
				}
				
				else if(num == 4 && state1 == 0)
				{
					button(275,120,480,160,15,15,1);
				}
				else if(num == 5 && state2 == 0)
				{
					button(275,180,480,220,15,15,1);
				}
				else if(num == 6 && state3 == 0)
				{
					button(275,240,480,280,15,15,1);
				}
				else if(num == 7 && state4 == 0)
				{
					button(275,300,320,340,15,15,1);
				}
				else if(num == 8 && state5 == 0)
				{
					button(360,300,380,340,15,15,1);
				}
				else if(num == 9 && state6 == 0)
				{
					button(420,300,440,340,15,15,1);
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
	puthz(20,100,"请参照行驶证填写车辆信息",16,18,4);
	setfillstyle(1,15);
	bar(275,120,480,160);
	puthz(160,130,"车牌号码",24,28,8);
	puthz(280,130,"鄂",24,28,8);
	bar(275,180,480,220);
	puthz(160,190,"车架号码",24,28,8);
	bar(275,240,480,280);
	puthz(160,250,"发动机号",24,28,8);
	bar(275,300,480,340);
	puthz(160,310,"注册日期",24,28,8);
	puthz(340,310,"年",24,28,8);
	puthz(400,310,"月",24,28,8);
	puthz(460,310,"日",24,28,8);
	
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	puthz(185,405,"下一步",24,24,1);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(395,405,"返回",24,28,1);
	
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}