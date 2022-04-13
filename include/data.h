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
	char licensenum[7];		//6位车牌号码
	char viotype[5];		//处罚类型
	char viomoney[5];		//罚款金额（待用）
	Date viotime;			//违章日期
}Vio;		//封装违章信息

typedef struct claiminfo
{
	char licensenum[7];		//6位，车牌号
	char scenetype[2];      
	char charactertype[2];
	Date claimdate;		 	//订单时间
	char state[2];
}Claim;		//封装信息

typedef struct insuranceinfo
{
	char licensenum[7];		//6位车牌号码
	char insurancetype[2];	//3种保险类型 //char insurancetype[4];
	Date insuranceenddate;	//保险单到期日
}Insurance;	//封装保险单信息

#endif
	
	