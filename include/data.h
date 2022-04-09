#ifndef _DATA_H_
#define _DATA_H_

typedef struct datetime
{
	char year[5];			//年
	char month[5];			//月
	char day[3];			//日
	char hour[3];			//时
	char min[3];			//分
}Date;		//时间

typedef struct carinfo
{
	char licensenum[7];		//6位车牌号码
	char type[2];			//车辆品牌型号
	char nature[2];			//车辆使用性质
	Date regdate;			//车辆注册日期
}Car;

typedef struct userinfo
{
	char name[13];			//4-12位用户名称
	char password[17];		//4-16位密码
	char ID[19];			//18位身份证号码
	char tele[12];			//11位电话号码
	Car  car[3];			//每个用户最多三台车辆
}User;		//封装用户信息

typedef struct vioinfo
{
	char name[13];			//4-12位用户名称
	char licensenum[7];		//6位车牌号码
	char viotype[5];		//处罚类型
	char viomoney[5];		//罚款金额（待用）
	Date viotime;			//违章日期
}Vio;		//封装违章信息

typedef struct orderinfo
{
	char name[13];          //4-12位，用户名
	char licensenum[7];		//6位，车牌号
	char ordertype[3];      //订单类型
	char ordertele[12];		//订单电话
	Date ordertime;		 	//订单时间
}Order;		//封装订单信息

typedef struct insuranceinfo
{
	char name[13];			//4-12位用户名称
	char licensenum[7];		//6位车牌号码
	char insurancetype[4];	//3种保险类型
	Date insuranceenddate;	//保险单到期日
}Insurance;	//封装保险单信息

#endif
	
	