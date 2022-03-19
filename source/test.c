#include <common.h>

void main(){
	int gdriver=VGA, gmode=VGAHI;
	
	char user[5] = "\0";
	int status = 0;
	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	cleardevice();
	
	mouseinit();
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	

	setbkcolor(CYAN);
	
	
	setfillstyle(1,WHITE);
	bar(80,160,560,190);
	button(80,160,560,190,WHITE,WHITE,1);
	button(600,10,620,30,WHITE,WHITE,1);
	setcolor(RED);
	line(605,15,615,25);
	line(615,15,605,25);
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if(mouse_press(600,10,620,30)==1)
		{
			delay(1000);
			closegraph();
			exit(1);
		}
		else if (mouse_press(80,160,560,190)==2)
		{
			status = 1;
			MouseS=2;
			clrmous(MouseX, MouseY);
			delay(10);
			button(80,160,560,190,GREEN,WHITE,1);
		}
		else if (mouse_press(80,160,560,190)==1)
		{
			MouseS=0;
			button(80,160,560,190,GREEN,LIGHTGRAY,1);
			input(user, 80, 160, 12, LIGHTGRAY, 2);
		}
		else
		{
			if(status != 0){
				MouseS = 0;
				if(status == 1){
					button(80,160,560,190,WHITE,WHITE,1);
					status = 0;
				}
			}
		}
		
		
	}
	
}