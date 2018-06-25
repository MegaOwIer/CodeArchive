#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	char c;
	int top,bf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do bf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+bf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
typedef pair<unsigned,int> pui;
const int maxn=200005;
#define mp make_pair
#define st first
#define nd second

struct point{int x,y,id;}p[maxn];
struct edge{int to,next,w;}e[maxn<<2];
int n,tot,cnt,head[maxn],tmp;
unsigned dis[maxn];
priority_queue<pui,vector<pui>,greater<pui> > q;
bool vis[maxn];

inline bool cmpx(point x,point y){return x.x<y.x;}
inline bool cmpy(point x,point y){return x.y<y.y;}
inline void add(int u,int v,int w)
{ 
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void Dijkstra()
{
	register int i;
	memset(dis+2,0x3f,sizeof(unsigned)*(n-1));
	q.push(mp(0,1));
	while(!q.empty())
	{
		tmp=q.top().nd,q.pop();
		if(vis[tmp])continue;
		vis[tmp]=1;
		for(i=head[tmp];i;i=e[i].next)
			if(dis[e[i].to]>dis[tmp]+e[i].w)
				dis[e[i].to]=dis[tmp]+e[i].w,q.push(mp(dis[e[i].to],e[i].to));
	}
	write(dis[n]);
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(p[i].x),read(p[i].y),p[i].id=i;
	sort(p+1,p+n+1,cmpx);
	for(int i=2;i<=n;i++)add(p[i-1].id,p[i].id,p[i].x-p[i-1].x);
	sort(p+1,p+n+1,cmpy);
	for(int i=2;i<=n;i++)add(p[i-1].id,p[i].id,p[i].y-p[i-1].y);
	Dijkstra();
	return 0;
}
