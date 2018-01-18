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
float r; float R,X,Y;
cin>>r;
//gotoxy(38,12);cout<<"Hello";
//cin>>r;
for(float i=-r;i<=r;i=i+0.1)
{
for(float j=-r;j<=r;j=j+0.1)
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


