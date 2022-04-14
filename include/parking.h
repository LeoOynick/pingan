#ifndef _PARKING_H_
#define _PARKING_H_

void parking(int *page, User *u);
void drawparking(User *u, int *carid);
void write_parkingdata(User *u, int carid, int place1,int place2, int place3,
					char* year, char* month, char* day);
#endif 