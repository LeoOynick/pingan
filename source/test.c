#include <common.h>

void main(){
	int gdriver=VGA, gmode=VGAHI;
	
	char user[5] = "\0";
	
	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	cleardevice();
	
	mouseinit();
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	

	setbkcolor(CYAN);
	
	
	setfillstyle(1,WHITE);
	bar(80,160,560,190);
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if(mouse_press(600,10,620,20)==1)
		{
			delay(1000);
			closegraph();
			exit(1);
		}
		else if (mouse_press(80,160,560,190)==1)
		{
			MouseS=2;
			input(user, 80, 160, 12, BLACK, 2);
		}
		else
		{
			MouseS = 0;
		}
		
		
	}
	
}