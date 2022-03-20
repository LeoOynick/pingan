#include"common.h"

/*void main()
{
	int func = 0;
	int unum = 0;
	int cnum = -1;

	int driver =VGA,mode =VGAHI;
	initgraph(&driver,&mode,"c:\\borlandc\\bgi");
	cleardevice();
	mouseinit();
	while (1)
	{
		switch (func)
		{
			case 0:		//初始选择界面
				start(&func);				//改变func的值进入其他界面
				memset(&u,'\0',sizeof(USER));		//进入无登录状态
				break;
			case 1:		//退出按钮
				delay(1000);
				closegraph();
				exit(1);
			case 2:		//用户登录界面
				user_login(&func,&u,&unum,&cnum);
				break;
			case 3:		//用户注册界面
				user_register(&func);
				break;
			case 4:		//忘记密码界面
				user_forget(&func);
				break;
			case 5:		//管理员登录界面
				admin_login(&func);
				break;
			case 6:		//服务界面
				main_service(&func,&u,&unum);
				break;
			case 7:		//查询界面
				main_inquiry(&func,&u);
				break;
			case 8:		//个人中心界面
				main_user(&func,&u,&unum,&cnum);
				break;
			case 10:		//违章信息主页
				admin_p1(&func);
				break;
			case 11:		//用户信息主页
				admin_p2(&func);
				break;
			case 12:		//历史订单主页
				admin_p3(&func);
				break;
		}
	}
}*/