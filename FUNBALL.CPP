#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<bios.h>

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
{
	clrscr();textcolor(GREEN);
	for(int i=2;i<78;i++)
	{
		gotoxy(i,2);
		cprintf("%c",177);
		gotoxy(i,47);
		cprintf("%c",177);
	}
	for(int j=3;j<48;j++)
	{
		gotoxy(2,j);
		cprintf("%c",177);
		gotoxy(77,j);
		cprintf("%c",177);
	}
}
void main()
{
int row,col,rsign,csign,b=10,ball_out=0,i,arr[]={-1,1}, c;
clrscr();
cout<<"WELCOME TO FUNBALL!\n\n";
cout<<"This is a simple game in which you have to prevent the ball from hitting the floor by using the bar.\n\n";
cout<<"You get 5 chances to keep the ball in play as long as possible.\n\n";
cout<<"Press any key to start...";
while(!kbhit())
{
sound((random(9)+1)*100);
delay(100);
nosound();
};
RESET:
clrscr();
gotoxy(30,24);
cout<<"YOU HAVE "<<5-ball_out<<" BALLS LEFT";
delay(1000);
gotoxy(30,24);
cout<<"                     ";
layout();
row=random(40)+25;col=random(20)+5;rsign=arr[random(2)];csign=arr[random(2)];
PLAY:
for(i=4;i<76;i++)
{gotoxy(i,45);
cout<<' ';}
gotoxy(b,45);
textcolor(LIGHTMAGENTA);
cprintf("OxxxxxxO");
while(!kbhit())
{	gotoxy(row,col);
	textcolor(LIGHTBLUE);
	cprintf("@");
	delay(50);
	cout<<"\b ";
	row+=rsign;
	col+=csign;
	if(row==76)
		rsign*=-1;
	if(row==3)
		rsign*=-1;
	if(col==3)
		csign*=-1;
	if((col==44)&&(row>=(b-1))&&(row<=(b+8)))
		csign*=-1;
	if(col>46)
	{
		ball_out++;
		if(ball_out==5)
		{
		clrscr();gotoxy(35,24);cout<<"GAME OVER";
		delay(4000);return;
		}
		goto RESET;
	}

}
c=readkey();
		if((c==333)&&(b<68))
			b+=2;
		if((c==331)&&(b>4))
			b-=2;
goto PLAY;
}



