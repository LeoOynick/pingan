#ifndef _ADVIO_H_
#define _ADVIO_H_

void advio(int *page);
void drawvio();
void drawadd();
void write_violatedata(char *licensenum, int type1,int type2, int type3, int type4,
					char* year, char* month, char* day, char* fine, char* point);
void refer_violatedata(char *licensenum);

#endif 