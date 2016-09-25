#include<iostream.h>
#include<conio.h>
#include<dos.h>
void main()
{
int x,y,i;
start:
x=1;y=49;i=-1;
clrscr();
while(y>0)
{
	if(x>78)
		{goto start;}
	gotoxy(x++,y);
	cout<<'@';
	delay(100);
	if(y>35)
		y+=5*i;
	else if(y>25)
		y+=3*i;
	else if(y>15)
		y+=2*i;
	else if(y>5)
		y+=1*i;
	else if(y==5)
		{i*=-1;y=6;}
}
}