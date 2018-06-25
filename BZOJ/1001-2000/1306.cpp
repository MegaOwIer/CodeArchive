#include<bits/stdc++.h>
using namespace std;
const int f[]={3,1,0,0};

int n,sc[10],b[10],ans;

inline void dfs(int x,int y)
{
	if(b[x]>sc[x])return;
	if(b[x]+3*(n-y+1)<sc[x])return;
	if(x==n)ans++;
	if(y==n)
	{
		int t=sc[x]-b[x];
		if(t==2)return;
		b[y]+=f[t];
		dfs(x+1,x+2);
		b[y]-=f[t];
	}
	else
	{
		b[x]+=3,dfs(x,y+1),b[x]-=3;
		b[y]+=3,dfs(x,y+1),b[y]-=3;
		b[x]++,b[y]++,dfs(x,y+1),b[x]--,b[y]--;
	}
}	

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",sc+i);
	dfs(1,2);
	printf("%d",ans);
	return 0;
}
