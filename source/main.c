#include "main.h"
#include "common.h"

void main()
{
	int page = 0;
	int usernum = 0;
	int carnum = -1;	// -1 means no car
	User u;
	int gdriver =VGA,gmode =VGAHI;
	
	initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	memset(&u,'\0',sizeof(User));
	mouseinit();
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	
	while(1)
	{
		switch(page)
		{	
			case(0):   //初始界面
				start(&page);
				memset(&u,'\0',sizeof(User));
				break;
				
			case(1):   //关闭按钮
				delay(1000);
			    closegraph();
			    exit(1);
				
			case(2):   //用户注册
				regist(&page);
				break;
				
			case(3):   //用户登录
				enter(&page,&u,&usernum,&carnum);
				break;
				
			case(4):   //管理员登录
				administ(&page);
				break;
				
			case(5):   //忘记密码
			    forget(&page);
				break;
				
			case(6):   //主页
				home(&page,&u);
				break;
				
			case(7):   //服务
				service(&page,&u);
				break;
				
			case(8):   //我的
				mine(&page,&u);
				break;
				
			case(9):   //买车险
				insure(&page);
				break;
				
			case(10):   //查保单
				policy(&page);
				break;
				
			case(11):   //办理赔
				claim(&page);
				break;
				
			case(12):   //查违章
				violate(&page);
				break;
				
			case(13):   //停车·缴费
				parking(&page);
				break;
				
			case(14):   //车损测算
				measure(&page);
				break;
			
			case(15):   //车辆服务
				carserve(&page);
				break;
				
			case(16):   //年检代办
				inspect(&page);
				break;
				
			case(17):   //道路救援
				rescue(&page);
				break;
				
			case(18):   //服务地图
				map(&page);
				break;
				
			case(19):   //添加车辆
				binding(&page);
				break;

			case(20):   //订单查询
				adorder(&page);
				break;
			
			case(21):   //违章管理
				advio(&page);
				break;
				
			case(22):   //理赔审批
				adclaim(&page);
				break;
		}
	}
}