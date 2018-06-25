#include<cstdio>
#include<cctype>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=10005;

struct edge
{
	int to,next;
	edge(){};
	edge(int to,int next):to(to),next(next){}
}e[100005];
int n,m,tot,head[maxn],low[maxn],dfn[maxn],Time,blt[maxn],cnt,fl,siz[maxn];
char c;
bool ins[maxn],in[maxn];
stack<int> s;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void Tarjan(int u)
{
	low[u]=dfn[u]=++Time,s.push(u),ins[u]=1;
	for(int i=head[u];i;i=e[i].next)
		if(!low[e[i].to])Tarjan(e[i].to),low[u]=min(low[u],low[e[i].to]);
		else if(ins[e[i].to])low[u]=min(low[u],dfn[e[i].to]);
	if(dfn[u]==low[u])
	{
		cnt++;
		for(int i=s.top();;i=s.top())
		{
			s.pop(),blt[i]=cnt,siz[cnt]++,ins[i]=0;
			if(i==u)break;
		}
	}
}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)
	{
		read(u),read(v);
		e[i]=edge(v,head[u]),head[u]=i;
	}
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;i++)for(int j=head[i];j;j=e[j].next)
		if(blt[e[j].to]!=blt[i])in[blt[i]]=1;
	for(int i=1;i<=cnt;i++)if(!in[i])
	{
		if(fl)return puts("0"),0;
		fl=i;
	}
	return printf("%d",siz[fl]),0;
}
