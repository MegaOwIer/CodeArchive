#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,L,R,siz[MX],mxsz[MX],mxdep,q[MX],hd,ed;
double ans,a[MX],b[MX],sum[MX];
bool vis[MX];

struct edge
{
	int to,w;
	edge* nxt;
	edge(){}
	edge(int t,edge *n,int w):to(t),w(w),nxt(n){}
}*E[MX];

inline void read(int& x)
{
	static char c;
	static int f=0;
	c=getchar(),x=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x,f=0;
}
inline void add(int u,int v,int w)
{
	E[u]=new edge(v,E[u],w);
	E[v]=new edge(u,E[v],w);
}
int dfs1(int u,int f,int totsiz,int& O)
{
	int siz=1,mxsz=0,tmp;
	for(edge *i=E[u];i;i=i->nxt)if(i->to!=f&&!vis[i->to])
		tmp=dfs1(i->to,u,totsiz,O),siz+=tmp,mxsz=max(mxsz,tmp);
	mxsz=max(mxsz,totsiz-siz);
	if(mxsz*2<=totsiz)O=u;
	return siz;
}
inline int getRoot(int u,int totsiz)
{
	static int ans;
	dfs1(u,0,totsiz,ans);
	return ans;
}
void dfs2(int u,int f,int dep)
{
	siz[u]=1;
	for(edge *i=E[u];i;i=i->nxt)if(i->to!=f&&!vis[i->to])
		dfs2(i->to,u,dep+1),siz[u]+=siz[i->to];
	if(dep>mxdep)mxdep=dep;
}
int dfs3(int u,int f,int dep,double val)
{
	if(dep>R)return 0;
	int mxd=dep;
	a[dep]=max(a[dep],sum[u]);
	for(edge *i=E[u];i;i=i->nxt)if(i->to!=f&&!vis[i->to])
		sum[i->to]=sum[u]+i->w-val,mxd=max(mxd,dfs3(i->to,u,dep+1,val));
	return mxd;
}
inline bool check(int root,double val)
{
	int dep,maxp=0;
	double ans=-1e30,maxx=-1e30;
	fill(b+1,b+mxdep+1,-1e30);
	fill(a+1,a+mxdep+1,-1e30);
	for(edge *i=E[root];i;i=i->nxt)if(!vis[i->to])
	{
		hd=1,ed=0,sum[i->to]=i->w-val;
		dep=dfs3(i->to,root,1,val);
		if(maxp)q[++ed]=maxp;
		for(int j=1;j<=dep&&j<=R;j++)
		{
			if(hd<=ed&&q[hd]>R-j)hd++;
			if(L>=j&&L-j<=mxdep)
			{
				while(hd<=ed&&b[q[ed]]<b[L-j])ed--;
				q[++ed]=L-j;
				ans=max(ans,b[q[hd]]+a[j]);
			}
			else if(j>L)ans=max(ans,b[q[hd]]+a[j]);
		}
		for(int j=1;j<=dep;j++)
		{
			b[j]=max(b[j],a[j]);
			if(j>=L&&j<=R&&maxx<b[j])maxx=b[j],maxp=j;
		}
		fill(a+1,a+dep+1,-1e30);
	}
	return ans>0;
}
void DivideAndConquer(int u,int totsiz)
{
	if(totsiz<L)return;
	u=getRoot(u,totsiz);
	mxdep=0,dfs2(u,0,0);
	double l=ans,r=1e6,mid;
	while(r-l>1e-5)
	{
		mid=(l+r)/2;
		if(check(u,mid))l=mid;
		else r=mid;
	}
	ans=l,vis[u]=1;
	for(edge *i=E[u];i;i=i->nxt)if(!vis[i->to])
		DivideAndConquer(i->to,siz[i->to]);
}

int main()
{
	read(N),read(L),read(R);
	for(int i=01,u,v,w;i<N;i++)
		read(u),read(v),read(w),add(u,v,w);
	DivideAndConquer(1,N);
	printf("%.3lf",ans);
	return 0;
}
