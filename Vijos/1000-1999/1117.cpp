#include<iostream>
using namespace std;

int m,n,cnt;
void divide(int,int,int);

int main()
{
	cin>>m>>n;
	divide(m,n,1);
	cout<<cnt;
	return 0;
}
void divide(int u,int v,int st)
{
	if(v==2)  {cnt+=(u/2-st+1)>0?(u/2-st+1):0;  return;}
	for(int i=st;i<=u/2;i++)  divide(u-i,v-1,i);
}
