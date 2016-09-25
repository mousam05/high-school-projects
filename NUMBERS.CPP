#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<bios.h>

int readkey(void)
{
int key,lo,hi;
key=bioskey(0);
lo=key &0X00FF;
hi=(key&0XFF00)>>8;
return((lo==0)?hi+256:lo);
}
void win(int i)
{
	clrscr();
	gotoxy(25,24);
	cout<<"CONGRATS, YOU WIN LEVEL "<<i;
	for(int s=400;s<800;s+=100)
	{
		sound(s);
		delay(200);
		nosound();
	}
}
void lose(int i)
{
	clrscr();gotoxy(25,24);
	cout<<"GAME OVER. YOU LOSE IN LEVEL "<<i;
	for(int s=800;s>400;s-=100)
	{
		sound(s);
		delay(100);
		nosound();
	}
	getch();
}
void layout()
{
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
inline int legal(int x,int y)
{
return((x<77)&&(x>2)&&(y<47)&&(y>2));
}

void main()
{
randomize();clrscr();
cout<<"WELCOME TO NUMBER GAME.\n\nINSTRUCTIONS:\n";
cout<<"\n1. Take the cursor to the SMALLER of the two numbers.";
cout<<"\n2. As you go to the next level, the speed of the cursor increases.";
cout<<"\n3. You lose if you hit a wall or choose the larger number.";
cout<<"\n\nPRESS ANY KEY TO START";
int x,y,xsign=1,ysign=0,i=1,s,p,q,a,b,m,n, c;
while(!kbhit())
{
	s=100*(random(7)+1);
	sound(s);
	delay(100);
	nosound();
	delay(50);
}
for(s=1;s<4;s++)
{
	sound(s*150);
	delay(400);
	nosound();
	delay(100);
}

newlevel:
x=40,y=24;
layout();
a=random(74)+3;
b=random(44)+3;
n=random(100);
gotoxy(a,b);
cout<<n;
p=random(74)+3;
q=random(44)+3;
do{m=n-random(20)+1;}while(m<=0);
gotoxy(p,q);
cout<<m;
start:
while(!kbhit())
{
	startgame:
	if(legal(x+xsign,y+ysign))
		gotoxy(x+=xsign,y+=ysign);
	else {lose(i);return;}
	if(((wherex()==p)||(wherex()==(p+1)))&&(wherey()==q))
		{win(i++);goto newlevel;}
	else if(((wherex()==a)||(wherex()==(a+1)))&&(wherey()==b))
		{lose(i);return;}
	cout<<'@';
	delay(100-10*i);cout<<"\b ";
}
c=readkey();
if(c==328)
	{if(ysign!=1)ysign=-1;xsign=0;}
else if(c==336)
	{if(ysign!=-1)ysign=1;xsign=0;}
else if(c==331)
	{if(xsign!=1)xsign=-1;ysign=0;}
else if(c==333)
	{if(xsign!=-1)xsign=1;ysign=0;}
goto start;
}