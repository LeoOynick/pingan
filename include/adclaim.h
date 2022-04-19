#ifndef _ADCLAIM_H_
#define _ADCLAIM_H_

void adclaim(int *page);
void drawadclaim();
void drawcheck();
void check(char *licensenum);				//输出理赔资料
void pass(char *licensenum, int state);		//审核理赔资料


#endif 