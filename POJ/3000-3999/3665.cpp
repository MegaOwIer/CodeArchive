#include<cstdio>
#include<cmath>
using namespace std;

int n,t,r[1005];

int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)  scanf("%d",r+i);
	while(t--)
	{
		int mx=1;
		for(int i=2;i<=n;i++)  if(r[i]>r[mx])  mx=i;
		printf("%d\n",mx);
		int del=r[mx]/(n-1),res=r[mx]%(n-1);
		for(int i=1;i<=n;i++)  if(i!=mx)
		{
			if(!res)  r[i]+=del;
			else  r[i]+=del+1,res--;
		}
		r[mx]=0;
	}
	return 0;
}
