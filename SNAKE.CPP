#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
int col_arr[1000],row_arr[1000];
inline int legal(int x,int y)
{
return((x<77)&&(x>2)&&(y<47)&&(y>2));
}

void layout()
{       textcolor(LIGHTGREEN);
	clrscr();
	for(int i=2;i<78;i++)
	{
		gotoxy(i,2);
		cout<<char(177);
		gotoxy(i,47);
		cout<<char(177);
	}
	for(int j=3;j<48;j++)
	{
		gotoxy(2,j);
		cout<<char(177);
		gotoxy(77,j);
		cout<<char(177);
	}
}
void fixfood(int &x,int &y)
{
x=random(74)+3;
y=random(43)+4;
gotoxy(x,y);
textcolor(LIGHTRED);
cprintf("@");
}
void gameover(int x)
{
clrscr();
cout<<"GAME OVER\nYOU ATE "<<x<<" FOODS.";
getch();
}
int checktail(int x,int y,int a,int b)
{
for(int i=(a-b);i<a;i++)
{
	if((x==row_arr[i])&&(y==col_arr[i]))
	return 1;
}
return 0;
}

void main()
{
randomize();
int row=10,col=10,rsign=1,csign=0,i=0,k=6,del=100;char ch;
int frow,fcol,food_cnt=0;
layout();
fixfood(frow,fcol);
snake:
while(!kbhit())
{
if(!legal(row,col))
	{gameover(food_cnt);return;}
if (checktail(row,col,i,k))
	{gameover(food_cnt);return;}
if((row==frow)&&(col==fcol))
{
	food_cnt++;k+=2;fixfood(frow,fcol);del-=5;
}
gotoxy(row,col);
textcolor(YELLOW);cprintf("x");
col_arr[i]=col;
row_arr[i]=row;
i++;
delay(del);
gotoxy(row_arr[i-k],col_arr[i-k]);
cout<<' ';
row+=rsign;col+=csign;
}
ch=getch();
switch(ch)
{
case 'a':
if(rsign!=1)rsign=-1;csign=0;break;
case 'd':
if(rsign!=-1)rsign=1;csign=0;break;
case 'w':
if(csign!=1)csign=-1;rsign=0;break;
case 's':
if(csign!=-1)csign=1;rsign=0;break;
case 'q':
return;
}
goto snake;
}