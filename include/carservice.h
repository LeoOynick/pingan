#ifndef _CARSERVICE_H_
#define _CARSERVICE_H_

void carserve(int *page, User *u);	//车辆服务界面
void drawcarserve(User *u, int *carid);
void write_servicedata(User *u, int carid, int service1,int service2,int service3,int service4);


#endif