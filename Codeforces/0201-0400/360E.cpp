#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=10105;

int N,M,K,S1,S2,T,head[MX],val[105],u[MX];
LL dis1[MX],dis2[MX];
char vis[MX],chn[105];

struct edge{int to,nxt,w;}e[MX];

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
}
inline void Dijkstra(int S,LL *dis)
{
	typedef pair<LL,int> pli;
	priority_queue<pli,vector<pli>,greater<pli> > q;
	memset(dis+1,0x3f,sizeof(LL)*N);
	memset(vis+1,0,sizeof(char)*N);
	q.push(make_pair(dis[S]=0,S));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=head[now];i;i=e[i].nxt)
			if(dis[e[i].to]>dis[now]+e[i].w)
				q.push(make_pair(dis[e[i].to]=dis[now]+e[i].w,e[i].to));
	}
}
template<typename Tp>inline bool check(Tp cmp)
{
	bool flag=true;
	while(flag)
	{
		flag=false;
		Dijkstra(S1,dis1),Dijkstra(S2,dis2);
		if(cmp(dis1[T],dis2[T]))return 1;
		for(int i=1;i<=K;i++)
			if(cmp(dis1[u[i]],dis2[u[i]])&&!chn[i])
				flag=true,e[i+M].w=val[i]-e[i+M].w,chn[i]=1;
	}
	return 0;
}

int main()
{
	read(N),read(M),read(K),read(S1),read(S2),read(T);
	for(int i=1,u,v,w;i<=M;i++)read(u),read(v),read(w),add(u,v,w);
	for(int i=1,v,l,r;i<=K;i++)
	{
		read(u[i]),read(v),read(l),read(r);
		val[i]=l+r,add(u[i],v,r);
	}
	if(check(less<LL>()))puts("WIN");
	else if(check(less_equal<LL>()))puts("DRAW");
	else return puts("LOSE"),0;
	for(int i=1;i<=K;i++)printf("%d ",e[i+M].w);
	return 0;
}