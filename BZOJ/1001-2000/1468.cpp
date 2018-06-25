#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=40005;
#define RVF(u) for(edge* i=head[u];i;i=i->nxt)if(!vis[i->to]&&i->to!=f)
#define RVS(u) for(edge* i=head[u];i;i=i->nxt)if(!vis[i->to])

class FastIn
{
private:
	static const int MXL=200000;
	char BF[MXL],*p1,*p2,c;
	char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
public:
	FastIn():p1(BF),p2(BF){}
	template<typename T>void operator()(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}IN;
struct edge
{
	int to,w;
	edge* nxt;
	edge(int t,edge* n,int w):to(t),nxt(n),w(w){}
}*head[MX];
int N,K,siz[MX],mxsz[MX],dis[MX],ed,st;
LL ans;
bool vis[MX];

inline void add(int u,int v,int w)
{
	head[u]=new edge(v,head[u],w);
	head[v]=new edge(u,head[v],w);
}
int dfs1(int u,int f,int totsiz)
{
	static int ans;
	siz[u]=1,mxsz[u]=0;
	RVF(u)
	{
		dfs1(i->to,u,totsiz);
		siz[u]+=siz[i->to];
		if(siz[i->to]>mxsz[u])mxsz[u]=siz[i->to];
	}
	mxsz[u]=max(mxsz[u],totsiz-siz[u]);
	if((mxsz[u]<<1)<=totsiz)ans=u;
	return ans;
}
void dfs2(int u,int f,int w)
{
	dis[++ed]=w,siz[u]=1;
	RVF(u)dfs2(i->to,u,w+i->w),siz[u]+=siz[i->to];
}
inline LL work(int st,int ed)
{
	LL ans=0;
	sort(dis+st,dis+ed+1);
	for(int i=st,j=ed;i<=ed;i++)
	{
		while(dis[i]+dis[j]>K&&j>=st)j--;
		ans+=j-st+1;
	}
	return ans;
}
void dac(int u,int totsiz)
{
	u=dfs1(u,-1,totsiz);
	st=1,ed=0,siz[u]=1;
	RVS(u)dfs2(i->to,u,i->w),ans-=work(st,ed),st=ed+1,siz[u]+=siz[i->to];
	dis[++ed]=0,ans+=work(1,ed)-1,vis[u]=1;
	RVS(u)dac(i->to,siz[i->to]);
}

int main()
{
	IN(N);
	for(int i=1,u,v,w;i<N;i++)
		IN(u),IN(v),IN(w),add(u,v,w);
	IN(K),dac(1,N),printf("%lld\n",ans/2);
	return 0;
}
