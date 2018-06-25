#include<bits/stdc++.h>
using namespace std;

int T,x,p,k,pr[15],cnt,tmp,L,R,ans,mid;

inline void divide(int u)
{
	for(int i=2;i*i<=u;i++)if(u%i==0)
	{
		while(u%i==0)u/=i;
		pr[++cnt]=i;
	}
	if(u>1)pr[++cnt]=u;
}
int solve(int U,int st,int val,int sgn)
{
	if(st>cnt)return sgn*(U/val);
	return solve(U,st+1,val,sgn)+solve(U,st+1,val*pr[st],-sgn);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&p,&k);
		cnt=0,divide(p);
		tmp=solve(x,1,1,1);
		L=x+1,R=2147483647,ans;
		while(L<=R)
		{
			mid=L+R>>1;
			if(solve(mid,1,1,1)-tmp>=k)R=mid-1,ans=mid;
			else L=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
