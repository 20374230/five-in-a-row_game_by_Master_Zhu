#pragma once
#include <conio.h>
#include<iostream>
#include"game.h"
void setbackground(int x,int y){
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(RED);
	fillrectangle(x-80,y+40,x+80,y-40);
	settextstyle(25,0,L"Times New Roman");
	setbkmode(TRANSPARENT);
	outtextxy(x,y,L"start");}
void start(int x,int y){
while (1) {
		m = GetMouseMsg();
		if (m.x >= x-80 && m.x <= x+80 && m.y >=y-40 && m.y <= y+40) {
			setlinecolor(BLUE);
			rectangle(x-90,y+50,x+90,y-50);
			if (m.uMsg == WM_LBUTTONDOWN) {	break;	
				
			}
		}
		else {	
			setlinecolor(WHITE);
			rectangle(x-90,y+50,x+90,y-50);
		}
	}
}


