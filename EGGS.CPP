#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<bios.h>
int eggc[100],eggr[100],eggs_no=0,first=1,index=0;
int eggs_brk=0,eggs_caught=0;

int readkey(void)
{
int key,lo,hi;
key=bioskey(0);
lo=key &0X00FF;
hi=(key&0XFF00)>>8;
return((lo==0)?hi+256:lo);
}
void creategg(int &x)
{
	x++;index++;
	eggr[index]=random(70)+5;
	eggc[index]=2;
}

int killegg(int x,int flag)
{
	gotoxy(eggr[x],eggc[x]);
	cout<<' ';
	first++;
	if(flag)
		eggs_brk++;
	if(eggs_brk==5)
		{
			sound(700);
			delay(1000);
			nosound();
			clrscr();
			cout<<"GAME OVER";
			cout<<"\nYOUR SCORE = "<<eggs_caught;
			delay(4000);
			return 1;
		}
	return 0;
}

int movegg(int x)
{
	for(int i=first;i<x;i++)
	{
		gotoxy(eggr[i],eggc[i]);
		cout<<' ';
		eggc[i]++;
		gotoxy(eggr[i],eggc[i]);
		if(eggc[i]==48)
			{if(killegg(i,1))
				return 1;}
		else
			{textcolor(YELLOW);cprintf("@");}
	}
	return 0;
}

void main()
{
randomize();
clrscr();
_setcursortype(_NOCURSOR);
int b=1,mood,k,c;
cout<<"WELCOME TO THIS GAME\n\n";
cout<<"You have to catch the falling eggs using the basket.\n\n";
cout<<"Control the basket by the arrow keys \n\n";
cout<<"Break 5 eggs and it is game over\n\n";
cout<<"Press any key to start";
while(!kbhit())
{
//sound((random(9)+1)*100);
delay(100);
};


clrscr();
nosound();

creategg(eggs_no);
gotoxy(60,1);
cout<<"SCORE: 0";
play:
gotoxy(b+10,45);
cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b                ";
gotoxy(b,45);
textcolor(LIGHTGREEN);
cprintf("\\====/");
while(!kbhit())
{
	if(movegg(eggs_no))
		return;
	delay(50);
	nosound();
	for(k=first;k<eggs_no;k++)
	{
	if(eggc[k]==44)
		if((eggr[k]>=b)&&(eggr[k]<=b+6))
			{
			eggs_caught++;
			gotoxy(67,1);cout<<eggs_caught;
			killegg(k,0);
			sound(400);
			}
	}

	mood=random(30);
	if(!mood)
		creategg(eggs_no);

}
c=readkey();
if(c==333)
	if(b<72)
		b+=2;
if(c==331)
	if(b>2)
		b-=2;
goto play;
}