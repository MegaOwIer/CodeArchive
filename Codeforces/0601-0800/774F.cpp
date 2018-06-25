#include<bits/stdc++.h>
using namespace std;

int N,val[50005],day=1,mx=1e9+1,id;

int main()
{
	scanf("%d",&N);
	if(N%7==0)
	{
		for(int i=1,u;i<=N;i++)
		{
			scanf("%d",&u);
			if(i%7&&u<mx)mx=u,id=i;
		}
		return printf("%d",id),0;
	}
	for(int i=1,u;i<=N;i++)scanf("%d",val+i),mx=min(mx,val[i]/6);
	for(int i=1;i<=N;i++)val[i]-=mx*6-6;
	while(1)
	{
		for(int i=1;i<=N;i++,day++)
			if(day==7)day=0;
			else if(!--val[i])return printf("%d",i),0;
	}
}
