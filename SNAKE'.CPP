#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<bios.h>

int col_arr[10000],row_arr[10000],prow[100],pcol[100];

int readkey(void)
{
int key,lo,hi;
key=bioskey(0);
lo=key &0X00FF;
hi=(key&0XFF00)>>8;
return((lo==0)?hi+256:lo);
}

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
x=random(70)+5;
y=random(40)+5;
gotoxy(x,y);
textcolor(LIGHTRED);
cprintf("@");
}

void gameover(int x)
{
clrscr();
cout<<"Game Over!\nYour score: "<<x;
delay(4000);
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

void fixpoison(int &x,int &y)
{
x=random(74)+3;
y=random(43)+4;
gotoxy(x,y);
textcolor(MAGENTA);
cprintf("$");
}

int checkpoison(int x,int y,int a)
{
for(int i=0;i<=a;i++)
{
	if((prow[i]==x)&&(pcol[i]==y))
		return 1;
}
return 0;
}

void main()
{
randomize();
int row=10,col=10,rsign=1,csign=0,i=0,k=6,j=0,ch;
int frow,fcol,food_cnt=0,mood;
layout();
fixfood(frow,fcol);
gotoxy(60,1);
cout<<"SCORE: 0";
snake:
while(!kbhit())
{
if((!legal(row,col))||(checktail(row,col,i,k)))
	{gameover(food_cnt);return;}
if(checkpoison(row,col,j))
	{gameover(food_cnt);return;}
if((row==frow)&&(col==fcol))
{
	food_cnt++;
	k+=2;
	gotoxy(67,1);
	cout<<food_cnt;
	mood=random(2);
	fixfood(frow,fcol);
	if(mood)
		{fixpoison(prow[j],pcol[j]);j++;}
}
gotoxy(row,col);
textcolor(YELLOW);cprintf("x");
col_arr[i]=col;
row_arr[i]=row;
i++;
delay(80);
gotoxy(row_arr[i-k],col_arr[i-k]);
cout<<' ';
row+=rsign;col+=csign;
}
ch=readkey();
switch(ch)
{
case 331:
if(rsign!=1)rsign=-1;csign=0;break;
case 333:
if(rsign!=-1)rsign=1;csign=0;break;
case 328:
if(csign!=1)csign=-1;rsign=0;break;
case 336:
if(csign!=-1)csign=1;rsign=0;break;
case 'q':
return;
}
goto snake;
}