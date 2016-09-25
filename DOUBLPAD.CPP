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
void main()
{
_setcursortype(_NOCURSOR);
int row,col,a,b,i,ball_out=0,rsign,csign,c;
int arr[]={-1,1};
time_t strt,now;
strt=time(0);
RESET:
clrscr();
row=40;col=24;a=24;b=40;rsign=arr[random(2)];csign=arr[random(2)];
gotoxy(30,20);
cout<<"YOU HAVE "<<5-ball_out<<" BALLS LEFT";
delay(1000);
PLAY:
clrscr();
textcolor(LIGHTGREEN);
gotoxy(b,48);
cprintf("xxxxxx");
gotoxy(b,2);
cprintf("xxxxxx");
for(i=a;i<a+6;i++)
{
	gotoxy(2,i);
	cprintf("x");
	gotoxy(78,i);
	cprintf("x");
}
while(!kbhit())
{
	gotoxy(row,col);
	textcolor(YELLOW);
	cprintf("@");
	delay(125);
	cout<<"\b ";
	row+=rsign;
	col+=csign;
	if((row>78)||(row<2)||(col>48)||(col<2))
	{
		ball_out++;
		if(ball_out==5)
		{
			clrscr();cout<<"GAME OVER";
			now=time(0);
			cout<<"\nYOU PLAYED FOR "<<difftime(now,strt)<<" SECONDS";
			delay(4000);return;
		}
		goto RESET;
	}
	if((row==3)||(row==77))
		{
		if((col>=(a-1))&&(col<=(a+6)))
		rsign*=-1;
		}
	if((col==3)||(col==47))
		{
		if((row>=(b-1))&&(row<=(b+6)))
		csign*=-1;
		}
}
c=readkey();
if(c==333)
	if(b<72)
		b+=2;
if(c==331)
	if(b>2)
		b-=2;
if(c==336)
	if(a<44)
		a+=2;
if(c==328)
	if(a>2)
		a-=2;
goto PLAY;
}
