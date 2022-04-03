#include"common.h"
#include"moreinfo.h"

void moreinfo(int *page)
{
	int num=0;
	char seatnum[5];		//座位数量
	int state1 = 0;					//判断是否有字符输入
	int state2 = 0;
	int state3 = 0;
	
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
			/**page = 20;*/
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
		    *page = 19;
			return;
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
	puthz(200,130,"奥迪",24,28,8);
	//fillellipse(290,140,5,5);
	puthz(300,130,"宝马",24,28,8);
	//fillellipse(390,140,5,5);
	puthz(400,130,"奔驰",24,28,8);
	//fillellipse(490,140,5,5);
	puthz(500,130,"比亚迪",24,28,8);
	puthz(25,190,"使用性质",24,28,8);
	//fillellipse(190,200,5,5);
	puthz(200,190,"营运",24,28,8);
	//fillellipse(390,200,5,5);
	puthz(400,190,"非营运",24,28,8);
	puthz(25,250,"座位数量",24,28,8);
	bar(140,240,620,280);
	
	setfillstyle(1,GREEN);
	bar(180,400,260,430);
	setfillstyle(1,4);
	bar(380,400,460,430);
	puthz(195,405,"提交",24,28,1);
	puthz(395,405,"返回",24,28,1);
	
	setlinestyle(0,4,3);
	setfillstyle(1,LIGHTGRAY);
    bar(610,0,640,30);
    setcolor(1);
    line(610,0,640,30);
    line(640,0,610,30);
}