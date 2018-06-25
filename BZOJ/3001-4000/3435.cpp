#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>
	inline void write(T x)
	{
		top=1;
		do buf[top++]=x%10,x/=10;while(x);
		while(--top)putchar(buf[top]+48);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int mod=1e9,maxn=1e5+5,maxm=4e6+5;
const double alpha=0.7564;
#define pb push_back

struct edge{int to,next,w;}e[maxn<<1];
struct Node
{
	Node *son[2];
	int val,siz,pos;
	inline void reset(int _)
	{
		val=_,siz=1,pos=rand();
		son[0]=son[1]=NULL;
	}
	inline void maintain()
	{
		siz=1;
		for(int i=0;i<2;i++)if(son[i])siz+=son[i]->siz;
	}
	inline bool cmp(int _){return _>val;}
}*rt_self[maxn],*rt_fa[maxn],used[maxm],*unused[maxm],*pool=used,**top=unused;
int n,head[maxn],tot,r[maxn],fa[maxn],dist[maxn],que[maxn],hd,siz[maxn],son[maxn],res;
LL ans;
bool vis[maxn];
vector<int> anc[maxn],id[maxn],sons[maxn],tmp;
vector<int>::iterator it;

inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline Node* newNode(int val)
{
	Node* res=(top!=unused)?*--top:pool++;
	res->reset(val);
	return res;
}
inline void del(Node* &o)
{
	if(!o)return;
	*top++=o;
	for(int i=0;i<2;i++)if(o->son[i])del(o->son[i]);
	o=NULL;
}
inline void rotate(Node* &o,int d)
{
	Node* tmp=o->son[d];
	o->son[d]=tmp->son[d^1],tmp->son[d^1]=o,tmp->siz=o->siz,o->maintain(),o=tmp;
}
inline void insert(Node* &o,int val)
{
	if(!o){o=newNode(val);return;}
	int d=o->cmp(val);
	o->siz++,insert(o->son[d],val);
	if(o->son[d]->pos<o->pos)rotate(o,d);
}
inline int qrank(Node* o,int val)
{
	if(!o)return 0;
	if(val<o->val)return qrank(o->son[0],val);
	else return (o->son[0]?o->son[0]->siz+1:1)+qrank(o->son[1],val);
}
inline int getO(int st)
{
	que[hd=1]=st,fa[st]=0;
	for(int i=1,u;i<=hd;i++)
	{
		u=que[i],siz[u]=1,son[u]=0;
		for(int j=head[u];j;j=e[j].next)
		{
			if(!vis[e[j].to]||e[j].to==fa[u])continue;
			fa[e[j].to]=u,que[++hd]=e[j].to;
		}
	}
	for(int i=hd,u,v;i>1;i--)
	{
		u=que[i],v=fa[u],siz[v]+=siz[u];
		if(siz[u]>son[v])son[v]=siz[u];
	}
	int all=siz[st],O=0,min=1e9;
	for(int i=1;i<=hd;i++)
	{
		int u=que[i];
		if(all-siz[u]>son[u])son[u]=all-siz[u];
		if(son[u]<min)min=son[u],O=u;
	}
	return O;
}
inline void dac(int st,int par)
{
	int O=getO(st);
	vis[O]=0,que[hd=1]=O,fa[O]=0,dist[O]=0;
	for(int i=1;i<=hd;i++)for(int j=head[que[i]];j;j=e[j].next)
	{
		if(!vis[e[j].to]||e[j].to==fa[que[i]])continue;
		fa[e[j].to]=que[i],dist[e[j].to]=dist[que[i]]+e[j].w,que[++hd]=e[j].to;
	}
	for(int i=1,u;i<=hd;i++)
	{
		u=que[i],id[u].pb(O),anc[u].pb(dist[u]),sons[O].pb(u),insert(rt_self[O],dist[u]-r[u]);
		if(par)insert(rt_fa[O],anc[u][anc[u].size()-2]-r[u]);
	}
	for(int i=head[O];i;i=e[i].next)if(vis[e[i].to])dac(e[i].to,O);
}
inline void rebuild(int u,int par)
{
	tmp=sons[u],res=anc[par].size();
	for(it=tmp.begin();it!=tmp.end();it++)
		vis[*it]=1,sons[*it].clear(),anc[*it].resize(res),id[*it].resize(res),del(rt_self[*it]),del(rt_fa[*it]);
	dac(u,par);
}
inline void check(int u)
{
	for(int i=0;i<anc[u].size();i++)
	{
		insert(rt_self[id[u][i]],anc[u][i]-r[u]);
		if(i)insert(rt_fa[id[u][i]],anc[u][i-1]-r[u]);
	}
	for(int i=0,siz_fa,siz_son;i<anc[u].size()-1;i++)
	{
		siz_fa=rt_self[id[u][i]]->siz,siz_son=rt_self[id[u][i+1]]->siz;
		if(siz_fa<=30)break;
		if(siz_son>alpha*siz_fa)return rebuild(id[u][i],i==0?0:id[u][i-1]);
	}
}
inline int getans(int u,int v,int w)
{
	anc[u]=anc[v],anc[u].pb(-w),id[u]=id[v],id[u].pb(u);
	for(int i=0;i<anc[u].size();i++)
	{
		anc[u][i]+=w,sons[id[u][i]].pb(u),ans+=qrank(rt_self[id[u][i]],r[u]-anc[u][i]);
		if(i)ans-=qrank(rt_fa[id[u][i]],r[u]-anc[u][i-1]);
	}
}

int main()
{
	read(n),read(n);
	for(int i=1,fa,c;i<=n;i++)
	{
		read(fa),read(c),read(r[i]),fa^=ans%mod;
		if(i==1)
		{
			anc[i].pb(0),id[i].pb(i),sons[i].pb(i),insert(rt_self[i],-r[i]),puts("0");
			continue;
		}
		add(fa,i,c),getans(i,fa,c),check(i),write(ans);
	}
	return 0;
}
