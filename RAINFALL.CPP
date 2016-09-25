#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
void fall(int &x,int &y,int speed=1)
{
gotoxy(x,y);
cout<<' ';
y+=speed;
gotoxy(x,y);
cout<<"|";
if(y>=45)
{	clrscr();
	y=0;}
}
void main()
{
randomize();
int x[100],y[100],t=0;
time_t first,second;
for(int i=0;i<30;i++)
{	x[i]=random(75)+5;
	y[i]=random(40)+5;
}
clrscr();
first=time(0);
while(!kbhit())
{
second=time(0);
if((difftime(second,first))==2)
{
	clrscr();
	t++;
	first=time(0);
}
fall(x[t],y[t]);
fall(x[t+10],y[t+10],random(3)+1);
fall(x[t+20],y[t+20],2);
delay(50);
if(t==10)
	t=0;
}
}