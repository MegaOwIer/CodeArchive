#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef long long LL;

struct edge{int to,next,w;}e[maxn<<2];
int n,k,dis[maxn],cnt[maxn],tot,head[maxn];
LL ans;
char c;
bool inq[maxn];
queue<int> q;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
}
inline bool spfa()
{
	while(!q.empty())
	{
		int now=q.front();q.pop(),inq[now]=0;
		for(int i=head[now];i;i=e[i].next)if(dis[now]+e[i].w>dis[e[i].to])
		{
			dis[e[i].to]=dis[now]+e[i].w;
			if(++cnt[e[i].to]>=n)return 0;
			if(!inq[e[i].to])inq[e[i].to]=1,q.push(e[i].to);
		}
	}
	return 1;
}

int main()
{
	read(n),read(k);
	for(int i=1,x,a,b;i<=k;i++)
	{
		read(x),read(a),read(b);
		switch(x)
		{
			case 1:add(a,b,0),add(b,a,0);break;
			case 2:if(a==b)return puts("-1"),0;
				   add(a,b,1);break;
			case 3:add(b,a,0);break;
			case 4:if(a==b)return puts("-1"),0;
				   add(b,a,1);break;
			case 5:add(a,b,0);break;
		}
	}
	for(int i=1;i<=n;i++)q.push(i),dis[i]=cnt[i]=inq[i]=1;
	if(!spfa())return puts("-1"),0;
	for(int i=1;i<=n;i++)ans+=dis[i];
	printf("%lld",ans);
	return 0;
}
