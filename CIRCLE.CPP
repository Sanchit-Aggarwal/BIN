#include<iostream.h>
#include<conio.h>

struct coord
{
int x;
int y;
}o1[100];
int o=0;

void main()
{
clrscr();
int r; int R,X,Y;
cin>>r;
//gotoxy(38,12);cout<<"Hello";
//cin>>r;
for(int i=-r;i<=r;i++)
{
for(int j=-r;j<=r;j++)
{
//cout<<i<<" "<<j<<endl;
X=i*i;
Y=j*j;
R=X+Y;
if(R==r*r)
{
// cout<<"X="<<X<<" Y="<<Y;
 o1[o].x=i;
 o1[o].y=j;
 o++;
}
}
}
for(int p=0;p<o;p++)
{
gotoxy(38+o1[p].x,12+o1[p].y);
cout<<"*";
}
getch();
}


