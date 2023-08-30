#include<easyx.h>
#include<graphics.h>
#include<Windows.h>
#define __TEXT(quote) quote 
#pragma once
#include<iostream>
#include<string>
MOUSEMSG m ;
using namespace std;
int restart;int ches[21][21];
void black(){
setfillcolor(BLACK);fillrectangle(780,100,1260,10);setbkmode(TRANSPARENT);
outtextxy(820,50,L"white turn");};
void white(){
setfillcolor(BLACK);fillrectangle(780,100,1260,10);setbkmode(TRANSPARENT);
outtextxy(820,50,L"black turn");}
class temp{public:
int x,y,color;
temp(int c){color=c;}
void dele(int &n){setlinecolor(WHITE);
	if(color==2){white();circle(x,y,16);setfillcolor(WHITE);fillcircle(x,y,16);ches[(x-100)/30][(y-10)/30]=0;n=0;}
	else{black(); circle(x,y,16);ches[(x-100)/30][(y-10)/30]=0;n=1;}};
}twh(1),tbl(2);
class bottom{
protected:
int height;
int width;
int color;
int x,y;int p;
string name;
public:
	bottom(int h,int w,int c,int x,int y,string s):height(h),width(w),color(c),x(x),y(y),name(s){};
	void draw(int &p){if(p){
	setfillcolor(color);
	fillrectangle(x-width/2,y+height/2,x+width/2,y-height/2);
	settextstyle(25,0,L"Times New Roman");
	setbkmode(TRANSPARENT);
	wstring widstr; 
    widstr = std::wstring(name.begin(), name.end());
	outtextxy(x-50,y,(LPWSTR)widstr.c_str());
	p=0;
	}}
	void rdraw(){
		setfillcolor(GREEN);
	fillrectangle(x-width/2,y+height/2,x+width/2,y-height/2);
	settextstyle(25,0,L"Times New Roman");
	setbkmode(TRANSPARENT);
	wstring widstr; 
    widstr = std::wstring(name.begin(), name.end());
	outtextxy(x-50,y,(LPWSTR)widstr.c_str());	};

	virtual int func()=0;
};
class restart:public bottom{
public:	
	restart(int h,int w,int c,int x,int y,string s):bottom(h, w, c, x, y,s){};
	virtual int func(){
			if(m.x >=x-width/2 && m.x <x+width/2 && m.y >=y-height/2&& m.y <= y+height/2){
			rdraw();
			p=1;
		}
		else draw(p);
	if (m.uMsg == WM_LBUTTONDOWN) {	if(m.x >=x-width/2 && m.x <x+width/2 && m.y >=y-height/2&& m.y <= y+height/2){return 1;}};
	return 0;};}Restart(100,200,RED,880,170,"restart");
class exit:public bottom{
public:
	exit(int h,int w,int c,int x,int y,string s):bottom(h, w, c, x, y,s){};
	virtual int func(){
			if(m.x >=x-width/2 && m.x <x+width/2 && m.y >=y-height/2&& m.y <= y+height/2){
			rdraw();
			p=1;
		}
		else draw(p);
	if (m.uMsg == WM_LBUTTONDOWN) {	if(m.x >=x-width/2 && m.x <x+width/2 && m.y >=y-height/2&& m.y <= y+height/2){return 1;}};
	return 0;};}Exit(100,200,RED,880,300,"exit");
class withdraw:public bottom{
public:	
	withdraw(int h,int w,int c,int x,int y,string s):bottom(h, w, c, x, y,s){};
virtual int func(){
			if(m.x >=x-width/2 && m.x <x+width/2 && m.y >=y-height/2&& m.y <= y+height/2){
			rdraw();
			p=1;
		}
		else draw(p);
	if (m.uMsg == WM_LBUTTONDOWN) {	if(m.x >=x-width/2 && m.x <x+width/2 && m.y >=y-height/2&& m.y <= y+height/2){return 1;}};
	return 0;};}Withdraw(100,200,RED,880,430,"withdraw");
class chess{
	int color;
public:
	chess(int clo){color=clo;}
int setchess(int x,int y,int&n){if(ches[(x-100)/30][(y-10)/30]==0){
	if(n==1){twh.x=x;twh.y=y;white();circle(x,y,16);ches[(x-100)/30][(y-10)/30]=1;n=0;return 0;}
	else{tbl.x=x;tbl.y=y;black(); circle(x,y,16);setfillcolor(BLACK);fillcircle(x,y,16);ches[(x-100)/30][(y-10)/30]=2;n=1;return 0;}
}
 return 1;
}
int judgex(int x,int y,int n){int i=x,k=0;
	for(i=x;i>=0;i--)if(ches[i][y]==n)k++;else break;
	for(i=x;i<=21;i++)if(ches[i][y]==n)k++;else break;
	if(k>5)return 1;
	return 0;
} 
int judgey(int x,int y,int n){
int i=y,k=0;
for(i=y;i>=0;i--)if(ches[x][i]==n)k++;else break;
	for(i=y;i<=21;i++)if(ches[x][i]==n)k++;else break;
	if(k>5)return 1;
	return 0;} 
int judgexx(int x,int y,int n){
int i=x,j=y,k=0;
	for(i=x,j=y;i>=0&&j>=0;i--,j--)if(ches[i][j]==n)k++;else break;
	for(i=x,j=y;i<=21&&j<=21;i++,j++)if(ches[i][j]==n)k++;else break;
	if(k>5)return 1;
	return 0;} 
int judgeyy(int x,int y,int n){
int i=x,j=y,k=0;
	for(i=x,j=y;i>=0&&j<=21;i--,j++)if(ches[i][j]==n)k++;else break;
	for(i=x,j=y;i<=21&&j>=0;i++,j--)if(ches[i][j]==n)k++;else break;
	if(k>5)return 1;
	return 0;
} 
int judge(int xx,int yy){int x=(xx-100)/30,y=(yy-10)/30;
int k=judgex(x,y,color)+
judgey(x,y,color)+
judgexx(x,y,color)+
judgeyy(x,y,color);
return k;
}
}wh(1),bl(2);
void drawbroad(int x,int y){
	setlinecolor(BLACK);
	int i;
	for(i=100;i<=x-300;i+=30){
		line(i,10,i,y-60);}
	for(i=10;i<=y-40;i+=30){
		line(100,i,x-300,i);}
};
struct point{
int x;
int y;
}point[2100];
void search(int x,int y,int &xx,int &yy,int j){
	long long int min=12310000,k;
	
	for(j--;j>=0;j--){
		k=(point[j].x-x)*(point[j].x-x)+(point[j].y-y)*(point[j].y-y);
	if(min>k)
	{xx=point[j].x;yy=point[j].y;min=k;}}
};
int setpoint(int x,int y){
int i,k,j=0;
	for(i=100;i<=x-300;i+=30)for(k=10;k<=y-40;k+=30){
		point[j].x=i,point[j].y=k;j++;
	}
return j;
};
void game(){int x,y,as=0,bs=0,n=0;

	int j=setpoint(1000,640),p=1;
	Restart.draw(p);
		p=1;
	Exit.draw(p);
	p=1;Withdraw.draw(p);
		white();
	memset(&m,0,sizeof(m));
	while (1) {my:
		m = GetMouseMsg();
	
		if(Restart.func()){restart =1;break;}
		if(Exit.func()){exit(0);};
		if(Withdraw.func()){if(n)tbl.dele(n);else twh.dele(n);};
			if (m.uMsg == WM_LBUTTONDOWN) {	setlinecolor(BLACK);
			if(m.x >= x-80 && m.x <= x+80 && m.y >=y-40 && m.y <= y+40)
			if(n)if(wh.setchess(x,y,n))goto my;else {wh.setchess(x,y,n);if(wh.judge(x,y)){restart =1;setfillcolor(BLACK);fillrectangle(0,200,800,120);setbkmode(TRANSPARENT);outtextxy(220,150,L"white wins!   click restart to restart");
			while(1){
	m=GetMouseMsg();
	if(Exit.func())exit(0);
	if(Restart.func())break;
	}break;}}
			else if(bl.setchess(x,y,n))goto my;else {bl.setchess(x,y,n);if(bl.judge(x,y)){restart =1;setfillcolor(BLACK);fillrectangle(0,200,800,120);setbkmode(TRANSPARENT);outtextxy(220,150,L"black wins!   click restart to restart");	
			while(1){
	m=GetMouseMsg();
	if(Exit.func())exit(0);
	if(Restart.func())break;
	}break;}}
			}drawbroad(1000,640);	
			search(m.x,m.y,x,y,j);
			if(as!=x||bs!=y){setlinecolor(BLACK);
				circle(x,y,15);
				setlinecolor(WHITE);
			circle(as,bs,15);
			as=x;bs=y;
			}	
	}
	Restart.draw(p=1);
	p=1;
		Exit.draw(p);
	
}
void play(){restart:
flushall();FlushMouseMsgBuffer();
memset(ches,0,sizeof(ches));
	setbkcolor(WHITE);
	cleardevice();
	drawbroad(1000,640);
	setpoint(1000,640);
	game();
	
	if(restart)goto restart;
};