#include<conio.h>
#include<dos.h>
void main()
{
char c=65;
while(c)
{
c=getch();
sound(c*10);
delay(50);
nosound();
}
}