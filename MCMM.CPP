#include<iostream.h>
#include<conio.h>
struct MCM
{
	int nop;
	int split;
}o1[20][20];

void Memoisation(int n,int *p)
{
	int counter;
	for(int l=1;l<=n;l++)
	{
		for(int r=1;r<=l;r++)
		o1[l][r].nop=0;
	}counter=0;int alpha;
	for(int i=1;i<=n;i++)//garbage at 0,0 table made from 1 to n
	{   counter++;alpha=0;
		for(int j=counter;j<=n;j++)
		{   alpha++; 
			if(alpha<j)
			{
				long int min_nop=999999999,split,nop;//Assigned to any random max value to find min
				for(int k=alpha;k<=j;k++)
		 		{//if(counter>n)
		 			//continue;
					nop=o1[alpha][k].nop+o1[k+1][j].nop+p[alpha-1]*p[k]*p[j];//cout<<nop;
					if(nop<min_nop)
					{
						min_nop=nop;
						split=k;
					}
					o1[alpha][j].nop=min_nop;
					o1[alpha][j].split=split; 
				}cout<<endl;
			}
		}
	}
}
void printseq(int start,int end)
{
	if(start==end)
	return;
	int k=o1[start][end].split;cout<<"k=="<<k<<endl;
	cout<<"(";
	for(int i=start;i<=k;i++)
	cout<<i<<"x";
	cout<<")";
	cout<<"(";
	for(i=k+1;i<=end;i++)
	cout<<i<<"x";
	cout<<")"<<endl;

       //	while(k!=start)
	{
	printseq(start,k);
	}
       //	while(k+1!=end)
	{
	printseq(k+1,end);
	}


}


int main()
{
clrscr();
	int n,size[20];
	cout<<"Enter number of matrices ";
	cin>>n;
	for (int i = 0; i<n;)//Here no inc is taken as to save memory eg 2x3 and 3x4,in arry it will be as 2,3(overwritten),4
	{                        // also n+a as p0 p1 .... are 1 more than no of matrices
		cout<<"Enter sizes of  matrix "<<(i+1)<<endl;
		cout<<"Number of Rows ";
		cin>>size[i];
		cout<<"Number of columns ";
		i++;
		cin>>size[i];
	}
	Memoisation(n,size);
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<o1[i][j].nop<<"   ";
		}cout<<endl;
	}

	printseq(1,n);
	
	

return(0);
}