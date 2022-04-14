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
	char scenetype[2];      //场景
	char charactertype[2];		//角色
	Date claimdate;		 	//时间
	char state[2];		//审核状态（0未审核，1通过，2拒绝）
}Claim;		//封装理赔信息

typedef struct insuranceinfo
{
	char licensenum[7];		//6位车牌号码
	char insurancetype[2];	//保险类型	//char insurancetype[4];
	Date insuranceenddate;	//保险单到期日
}Insurance;	//封装保险单信息

typedef struct parkinginfo
{
	char licensenum[7];		//6位车牌号码
	char parkplace[2];	//停车地点
	Date parkingdate;	//停车日期
}Parking;	//封装停车预约信息

typedef struct serviceinfo
{
	char licensenum[7];		//6位车牌号码
	char servicetype[2];	//服务类型
	Date servicedate;	//服务日期
}Service;	//封装服务信息

#endif
	
	