#include<bits/stdc++.h>
using namespace std;
const int MX=10005,INF=0x3f3f3f3f;

int N,M,D,head[MX],dp[MX][257],S,ans[257];
bool inq[MX];
queue<int> q;

struct edge{int to,nxt,w;}e[MX<<1];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int w)
{
	static int tot=0;
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
void prework()
{
	memset(dp,0x3f,sizeof(dp));
	int num=0;
	for(int i=1;i<=D;i++)dp[i][1<<num]=0,num++;
	for(int i=N-D+1;i<=N;i++)dp[i][1<<num]=0,num++;
	S=1<<num;
}
inline void SPFA(int opt)
{
	while(!q.empty())
	{
		int now=q.front();
		q.pop(),inq[now]=0;
		for(int i=head[now];i;i=e[i].nxt)
			if(dp[e[i].to][opt]>dp[now][opt]+e[i].w)
			{
				dp[e[i].to][opt]=dp[now][opt]+e[i].w;
				if(!inq[e[i].to])q.push(e[i].to),inq[e[i].to]=1;
			}
	}
}
inline bool check(int opt)
{
	for(int i=0,j=D*2-1;i<D;i++,j--)
		if(((opt>>i)&1)^((opt>>j)&1))return 0;
	return 1;
}

int main()
{
	read(N),read(M),read(D);
	for(int i=1,u,v,w;i<=M;i++)
		read(u),read(v),read(w),add(u,v,w);
	prework();
	for(int opt=0;opt<S;opt++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int sub=opt;sub;sub=(sub-1)&opt)
				dp[i][opt]=min(dp[i][opt],dp[i][sub]+dp[i][sub^opt]);
			if(dp[i][opt]!=INF)q.push(i),inq[i]=1;
		}
		SPFA(opt);
	}
	memset(ans,0x3f,sizeof(ans));
	for(int opt=0;opt<S;opt++)if(check(opt))
		for(int i=1;i<=N;i++)ans[opt]=min(ans[opt],dp[i][opt]);
	for(int opt=0;opt<S;opt++)
		for(int sub=opt;sub;sub=(sub-1)&opt)
			ans[opt]=min(ans[opt],ans[sub]+ans[sub^opt]);
	printf("%d\n",ans[S-1]==INF?-1:ans[S-1]);
	return 0;
}