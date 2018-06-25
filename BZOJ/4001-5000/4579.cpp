#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;

struct edge{int to,next;}e[maxn<<1];
int n,m,fa[maxn],tot,head[maxn],hk[maxn],cnt,f1,f2;
bool use[maxn],ans[maxn];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)read(u),read(v),add(u,v);
	for(int i=n;i;i--)fa[i]=i,read(hk[i]);
	for(int i=1;i<=n;i++)
	{
		use[hk[i]]=1,cnt++;
		for(int j=head[hk[i]];j;j=e[j].next)if(use[e[j].to])
		{
			f1=find(hk[i]),f2=find(e[j].to);
			if(f1==f2)continue;
			fa[f2]=f1,cnt--;
		}
		ans[i]=(cnt==1);
	}
	for(int i=n;i;i--)puts(ans[i]?"YES":"NO");
	return 0;
}
