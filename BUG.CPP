#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<bios.h>

int r_arr[]={12,32,52,72},s_arr[]={-1,1};
int c[500],r[500],sign[500],first=1,index=0,score=0;
int bugc[500],bugr[500];

int readkey(void)
{
int key,lo,hi;
key=bioskey(0);
lo=key &0X00FF;
hi=(key&0XFF00)>>8;
return((lo==0)?hi+256:lo);
}

void createbird(int &x)
{
	x++;index++;
	r[index]=r_arr[random(4)];
	sign[index]=s_arr[random(2)];
	if(sign[index]==1)
		c[index]=5;
	else
		c[index]=45;
}

void killbird(int i)
{
	first++;
	gotoxy(r[i],c[i]);cout<<'|';
	score++;
	gotoxy(67,1);cout<<score;
}
void movebird(int &x)
{
	for(int i=first;i<x;i++)
	{
		gotoxy(r[i],c[i]);
		textcolor(LIGHTBLUE);
		cprintf("|");
		if(sign[i]==1)
			c[i]++;
		else
			c[i]--;
		if(((c[i]==45)&&(sign[i]==1))||((c[i]==5)&&(sign[i]==-1)))
			killbird(i);
		else
		{gotoxy(r[i],c[i]);textcolor(MAGENTA);cprintf("8");}

	}
}

int checkhit(int x,int a)
{
for(int i=first;i<=x;i++)
{
if((r[i]==bugc[a])&&(c[i]==bugr[a]))
{clrscr();cout<<"YOUR SCORE: "<<score;delay(4000);return 1;}
}
return 0;
}
void layout()
{
clrscr();int x;textcolor(LIGHTBLUE);
for(int y=5;y<=45;y++)
{
	for(x=12;x<=72;x+=20)
	{
		gotoxy(x,y);
		cprintf("|");
	}
}
}
void main()
{
int i=0,mood,bird_no=0,ch;
randomize();
_setcursortype(_NOCURSOR);
bugc[0]=32,bugr[0]=20;
layout();
createbird(bird_no);
gotoxy(60,1);cout<<"SCORE: 0";
play:
gotoxy(bugc[i],bugr[i]);
textcolor(YELLOW);
cprintf("@");
if(i>0)
{
	gotoxy(bugc[i-1],bugr[i-1]);
	textcolor(LIGHTBLUE); cprintf("|");
}
while(!kbhit())
{
mood=random(10);

if(!mood)
     createbird(bird_no);

delay(100);
movebird(bird_no);
if(checkhit(bird_no,i))
	return;

}
ch=readkey();
switch(ch)
{
case 331:
if(bugc[i]!=12)
{bugc[i+1]=bugc[i]-20;bugr[i+1]=bugr[i];i++;}break;
case 333:
if(bugc[i]!=72)
{bugc[i+1]=bugc[i]+20;bugr[i+1]=bugr[i];i++;}break;
case 328:
if(bugr[i]!=5)
{bugr[i+1]=bugr[i]-1;bugc[i+1]=bugc[i];i++;}break;
case 336:
if(bugr[i]!=45)
{bugr[i+1]=bugr[i]+1;bugc[i+1]=bugc[i];i++;}break;
case 'q':
return;
}
goto play;
}