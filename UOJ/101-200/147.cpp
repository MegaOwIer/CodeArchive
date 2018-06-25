#include<bits/stdc++.h>
using namespace std;

int T,n,ans,a[15],c[25];

inline int query()
{
	int tot=0;
	memset(c,0,100);
	for(int i=0;i<=13;i++)c[a[i]]++;
	while(c[4]&&c[2]>1)c[4]--,c[2]-=2,tot++;
	while(c[4]&&c[1]>1)c[4]--,c[1]-=2,tot++;
	while(c[4]&&c[2])c[4]--,c[2]--,tot++;
	while(c[3]&&c[2])c[3]--,c[2]--,tot++;
	while(c[3]&&c[1])c[3]--,c[1]--,tot++;
	return tot+c[1]+c[2]+c[3]+c[4];
}
inline void dfs(int cnt)
{
	if(cnt>=ans)return;
	int res=query();
	if(cnt+res<ans)ans=cnt+res;
	for(int i=3;i;i--)for(int j=2;j<14;j++)
	{
		int x=j;
		while(a[x]>=i)
		{
			x++;
			if((i==3&&x-j>=2)||(i==2&&x-j>=3)||(i==1&&x-j>=5))
			{
				for(int k=j;k<x;k++)a[k]-=i;
				dfs(cnt+1);
				for(int k=j;k<x;k++)a[k]+=i;
			}
		}
	}
}

int main()
{
	scanf("%d%d",&T,&n);
	while(T--)
	{
		ans=1e9;
		memset(a,0,56);
		for(int i=1,x;i<=n;i++)
		{
			scanf("%d%*d",&x);
			if(x==1)x=13;
			else if(x)x--;
			a[x]++;
		}
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
