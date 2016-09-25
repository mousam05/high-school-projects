#include<iostream.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
#define size 3
void main()
{
int arr[size][size],j,row,col,guess;char c;
randomize();
do
{clrscr();
cout<<"Look at this table carefully\n";
for(int i=0;i<size;i++)
{
	for(j=0;j<size;j++)
	{	arr[i][j]=random(90)+10;
		cout<<arr[i][j]<<"  ";
	}cout<<'\n';
}
cout<<"\n\nSeconds left:  ";
for(i=0;i<7;i++)
{
	cout<<'\b'<<7-i;
	delay(1000);
}
clrscr();
row=random(size);
col=random(size);
for(i=0;i<size;i++)
{
	for(j=0;j<size;j++)
	{
		if((i==row)&&(j==col))
			cout<<"?? ";
		else
			cout<<"-- ";
	}cout<<"\n\n";
}
cout<<"Which number was in place of the question marks?";
cin>>guess;
if(guess==arr[row][col])
	cout<<"Correct!";
else
	cout<<"Incorrect! It was "<<arr[row][col];
cout<<"\nDo you want to play again? press y for yes";
}
while((c=getch())=='y');
}