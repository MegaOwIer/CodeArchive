#include<bits/stdc++.h>
using namespace std;
const int maxn=20005;
typedef long long LL;
#define RVF(u) for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to]&&fa!=e[i].to)
#define REV(u) for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to])

struct edge {int to,next,w;}e[maxn<<1];
int n,head[maxn],tot,siz[maxn],mxsz[maxn],G;
LL q,p,d,cnt[3],cnt2[3];
bool vis[maxn];
char c;

inline LL gcd(LL u,LL v){return v?gcd(v,u%v):u;}
inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void dfs1(int u,int fa)
{
	mxsz[u]=0,siz[u]=1;
	RVF(u)dfs1(e[i].to,u),siz[u]+=siz[e[i].to],mxsz[u]=max(mxsz[u],siz[e[i].to]);
}
inline void dfs2(int u,int fa,int tot)
{
	mxsz[u]=max(mxsz[u],tot-siz[u]);
	if(mxsz[u]<=tot/2)G=u;
	RVF(u)dfs2(e[i].to,u,tot);
}
inline int getO(int u)
{
	dfs1(u,-1),dfs2(u,-1,siz[u]);
	return G;
}
inline void dfs3(int u,int fa,int lth)
{
	cnt[lth]++;
	RVF(u)dfs3(e[i].to,u,(lth+e[i].w)%3);
}
inline LL solve(int u)
{
	u=getO(u),vis[u]=1;
	cnt2[0]=cnt2[1]=cnt2[2]=0;
	LL ans=0;
	REV(u)
	{
		cnt[0]=cnt[1]=cnt[2]=0;
		dfs3(e[i].to,u,e[i].w);
		ans-=cnt[1]*cnt[2]+cnt[0]*(cnt[0]-1)/2;
		cnt2[0]+=cnt[0],cnt2[1]+=cnt[1],cnt2[2]+=cnt[2];
	}
	ans+=cnt2[1]*cnt2[2]+cnt2[0]*(cnt2[0]+1)/2;
	REV(u)ans+=solve(e[i].to);
	return ans;
}

int main()
{
	read(n),q=1LL*n*n;
	for(int i=1,a,b,w;i<n;i++)read(a),read(b),read(w),add(a,b,w%3);
	p=solve(1)*2+n,d=gcd(p,q);
	if(p==q)return puts("1/1"),0;
	if(!p)return puts("0/1"),0;
	printf("%lld/%lld",p/d,q/d);
	return 0;
}
