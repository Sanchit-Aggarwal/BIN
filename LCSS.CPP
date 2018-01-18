#include<iostream.h>
#include<conio.h>
#include<string.h>
struct cell
{
	int val;
	char dir;//up='u' left='l' diag='d' end='e'
};
cell o1[20][20];
void lcs(int i,int j,char *s1,char *s2)
{

	{
	cout<<"comparing for "<<s1[i]<<" and "<<s2[j];
		if(s1[i]==s2[j])
		{ cout<<" match"<<endl;
			if(i==0||j==0)
			{
			   o1[i][j].val=1;
			   o1[i][j].dir='e';
			}
			else
			{
				o1[i][j].val=1+o1[i-1][j-1].val;
			    o1[i][j].dir='d';
			}
			
		}
		else
		{
			cout<<" mismatch"<<endl;
			if(i==0||j==0)
			{
			   o1[i][j].val=0;
			   o1[i][j].dir='e';
			}
			else
			{
				
			
			if(o1[i][j-1].val>=o1[i-1][j].val)
			{
				o1[i][j].val=o1[i][j-1].val;
				o1[i][j].dir='l';
			}
			else
			{
				o1[i][j].val=o1[i-1][j].val;
				o1[i][j].dir='u';

			}
			}
		}

	}
	
}
int main()
{
	
	int arr[40][40],l1,l2;char s1[10],s2[10];
	cout<<"Enter String 1 ";
	cin>>s1;
	cout<<"Enter String 2 ";
	cin>>s2;
	l1=strlen(s1);
	l2=strlen(s2);
	cout<<endl<<"Computation started!"<<endl;
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			lcs(i,j,s1,s2);
		}
		cout<<endl;
		cout<<"ROW "<<i<<" computaion completed successfully!"<<endl;
		
	}
	
	cout<<"Memoisation-Matrix Formed"<<endl;
	for( i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			cout<<o1[i][j].val<<" ";
		}
		cout<<endl;
	}
		char string[10],count=0;
	 i=l1-1;
	 j=l2-1;
	while(1)
	{
		if(o1[i][j].dir=='d')
		{
			string[count]=s1[i];
			i--;
			j--;
			count++;
		}
		if(o1[i][j].dir=='l')
		j--;
		
		if(o1[i][j].dir=='u')
		i--;
		if(o1[i][j].dir=='e' && o1[i][j].val==1)
		{
			string[count]=s1[i];
			count++;
			break;
		}
		if(o1[i][j].dir=='e' && o1[i][j].val==0)
		break;
			
	}
	cout<<endl;
	cout<<"Largest common substring length="<<count<<endl;
	cout<<"String found is:";
	for(i=count;i>=0;i++)
	cout<<string[i];
	return(0); 
}