//children's multiplication game
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
int i=0,a=0,b=0,p=0;
char y=0;
clrscr();
randomize();
do
{
do
{
	do{a=random(10);}while(a==0);
	do{b=random(10);}while(b==0);
	cout<<"How much is "<<a<<" times "<<b<<"? ";
	cin>>p;
	while(p!=a*b)
	{
		cout<<"No, try again: ";
		cin>>p;
	}
	cout<<"Very good! ";
	i++;
}while(i<5);
cout<<"\nYou answered five questions. Continue?";
cin>>y;
}while(y=='y');
}