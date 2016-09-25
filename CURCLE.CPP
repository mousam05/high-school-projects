#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void main()
{
clrscr();
int r=0,j=0,x=0,y=0,p=0;
cout<<"enter radius of circle";
cin>>r;
cout<<"enter co-ordinates of centre";
cin>>x>>y;
randomize();
for(int i=0;i<80;++i)
{
	for(j=0;j<50;++j)
	{
		gotoxy(i,j);
		//distance formula
		if((sqrt(pow((i-x),2)+pow((j-y),2))>(r-1))&&(sqrt(pow((i-x),2)+pow((j-y),2))<(r+1)))
		{
			do{p=random(256);}while(p<40);
			cout<<(char)p;
		}
	}
}
getch();
}