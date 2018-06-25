#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
const int MX=1e5+5,MN=MX<<1;

struct Tree_edge{int u,v,w;}E[MX*5];
struct edge{int to,next;}e[MN];
int N,M,Q,h[MX],a[MX],n,par[MN],siz,val[MN],head[MN],tot,ans;
int dep[MN],fa[MN][19],ord[MX*3],top,RT[MX*3],st[MN],en[MN];
int node,sum[MX<<5],ls[MX<<5],rs[MX<<5];

inline bool operator < (Tree_edge a,Tree_edge b){return a.w<b.w;}
inline int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
inline void add(int u,int v){e[++tot]=(edge){v,head[u]},head[u]=tot;}
inline void dfs(int u)
{
	ord[++top]=u,dep[u]=dep[fa[u][0]]+1;
	for(int i=1;(1<<i)<dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].next)fa[e[i].to][0]=u,dfs(e[i].to);
	if(u>N)ord[++top]=u;
}
inline void insert(int l,int r,int& x,int f,int val)
{
	x=++node,sum[x]=sum[f]+1;
	if(l==r)return;
	int mid=l+r>>1;
	if(val<=mid)insert(l,mid,ls[x],ls[f],val),rs[x]=rs[f];
	else insert(mid+1,r,rs[x],rs[f],val),ls[x]=ls[f];
}
inline int getroot(int x,int val)
{
	for(int i=17;~i;i--)
		if((1<<i)<dep[x]&&::val[fa[x][i]]<=val)x=fa[x][i];
	return x;
}
inline int ask(int l,int r,int x,int y,int rk)
{
	if(l==r)return l;
	int mid=l+r>>1;
	if(sum[ls[y]]-sum[ls[x]]>=rk)return ask(l,mid,ls[x],ls[y],rk);
	else return ask(mid+1,r,rs[x],rs[y],rk+sum[ls[x]]-sum[ls[y]]);
}

int main()
{
	read(N),read(M),read(Q),siz=N;
	for(int i=1;i<=N;i++)read(h[i]),a[i]=h[i];
	sort(a+1,a+N+1),n=unique(a+1,a+N+1)-a-1;
	for(int i=1;i<=N;i++)h[i]=lower_bound(a+1,a+n+1,h[i])-a;
	for(int i=1;i<=M;i++)read(E[i].u),read(E[i].v),read(E[i].w);
	sort(E+1,E+M+1);
	for(int i=1;i<=N;i++)par[i]=i;
	for(int i=1,f1,f2;i<=M;i++)
	{
		f1=find(E[i].u),f2=find(E[i].v);
		if(f1==f2)continue;
		val[++siz]=E[i].w,par[f1]=par[f2]=par[siz]=siz,add(siz,f1),add(siz,f2);
	}
	for(int i=1;i<=n;i++)if(!dep[i])dfs(find(i));
	for(int i=1;i<=top;i++)
		if(ord[i]<=N)insert(1,n,RT[i],RT[i-1],h[ord[i]]);
		else
		{
			RT[i]=RT[i-1];
			if(!st[ord[i]])st[ord[i]]=i;
			else en[ord[i]]=i;
		}
	for(int i=1,v,x,k,t,a,b;i<=Q;i++)
	{
		read(v),read(x),read(k);
//		if(~ans)v^=ans,x^=ans,k^=ans;  //3551强制在线 
		t=getroot(v,x),a=RT[st[t]],b=RT[en[t]];
		if(sum[b]-sum[a]<k)ans=-1;
		else ans=::a[ask(1,n,a,b,sum[b]-sum[a]-k+1)];
		if(~ans)write(ans);else puts("-1");
	}
	return 0;
}
