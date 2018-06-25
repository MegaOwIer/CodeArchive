#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[12],f;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>
	inline void write(T x,int f=0)
	{
		top=0;
		if(x<0)putchar('-'),x=-x;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar(buf[i]+48);
		if(f)putchar(f&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=2005;

struct edge{int to,next,f,c;}e[12005];
int n,P,M,F,N,s,tot=1,head[maxn],S,T,r[maxn],ans,dis[maxn],now,frm[maxn],flow;
bool inq[maxn];
queue<int> q;

inline void add(int u,int v,int f,int c)
{
	e[++tot]=(edge){v,head[u],f,c},head[u]=tot;
	e[++tot]=(edge){u,head[v],0,-c},head[v]=tot;
}
inline bool spfa()
{
	memset(dis+1,0x3f,T<<2);
	q.push(S),dis[S]=0,frm[T]=-1;
	while(!q.empty())
	{
		now=q.front(),q.pop(),inq[now]=0;
		for(int i=head[now];i;i=e[i].next)if(e[i].f&&dis[now]+e[i].c<dis[e[i].to]) 
		{
			dis[e[i].to]=dis[now]+e[i].c,frm[e[i].to]=i^1;
			if(!inq[e[i].to])inq[e[i].to]=1,q.push(e[i].to); 
		}
	}
	return ~frm[T];
}

int main()
{
	read(n),read(P),read(M),read(F),read(N),read(s);
	T=1+(S=n<<1|1);
	for(int i=1;i<=n;i++)read(r[i]);
	for(int i=1;i<=n;i++)
	{
		add(S,i,r[i],0),add(i+n,T,r[i],0),add(S,i+n,r[i],P);
		if(i!=n)add(i,i+1,1e9,0);
	}
	for(int i=1;i+M<=n;i++)add(i,i+M+n,1e9,F);
	for(int i=1;i+N<=n;i++)add(i,i+N+n,1e9,s);
	while(spfa())
	{
		flow=1e9;
		for(int i=T;i!=S;i=e[frm[i]].to)flow=min(flow,e[frm[i]^1].f);
		ans+=flow*dis[T];
		for(int i=T;i!=S;i=e[frm[i]].to)e[frm[i]].f+=flow,e[frm[i]^1].f-=flow;
	}
	write(ans);
	return 0;
}
