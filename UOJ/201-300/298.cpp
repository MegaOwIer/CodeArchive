#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;
const LL INF=1LL<<62;

int N,L,A,B,fa[MX],q[MX],top,a[MX],b[MX];
char flag[MX];
LL w,dep[MX],sum[MX],mx[MX],l,r,mid,ans;

struct edge
{
	int to;
	LL w;
	edge(){}
	edge(int t,LL w):to(t),w(w){}
}*G[MX],Pool[MX<<1];

template<typename T>inline void read(T& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void GetGraph()
{
	static int u[MX],v[MX],deg[MX];
	static LL w[MX];
	for(int i=1;i<N;i++)
		read(u[i]),read(v[i]),read(w[i]),++deg[u[i]],++deg[v[i]];
	G[1]=Pool;
	for(int i=1;i<=N;i++)G[i+1]=G[i]+deg[i];
	for(int i=1;i<N;i++)
	{
		--deg[u[i]],--deg[v[i]];
		G[u[i]][deg[u[i]]]=edge(v[i],w[i]);
		G[v[i]][deg[v[i]]]=edge(u[i],w[i]);
	}
}
void dfs1(int u,int f,LL w)
{
	dep[u]=w,fa[u]=f;
	if(w>dep[A])A=u;
	for(edge *i=G[u];i!=G[u+1];++i)if(i->to!=f)
		dfs1(i->to,u,w+i->w);
}
LL dfs2(int u,int f,LL w)
{
	LL mx=w;
	for(edge *i=G[u];i!=G[u+1];i++)if(i->to!=f&&!flag[i->to])
		mx=max(dfs2(i->to,u,w+i->w),mx);
	return mx;
}
inline bool cmp1(int u,int v){return sum[u]+mx[u]<sum[v]+mx[v];}
inline bool cmp2(int u,int v){return sum[u]-mx[u]<sum[v]-mx[v];}
inline void Max(LL& a,LL b){if(a<b)a=b;}
inline void Min(LL& a,LL b){if(a>b)a=b;}
bool check(LL val)
{
	LL al=-INF,bl=-INF,amx=-INF,ar=INF,br=INF,bmn=INF;
	for(int i=1,j=1;i<=top;i++)
	{
		while(j<=top&&sum[a[i]]+mx[a[i]]-sum[b[j]]+mx[b[j]]>val)
			Max(amx,sum[b[j]]+mx[b[j]]),Min(bmn,sum[b[j]]-mx[b[j]]),j++;
		if(j==1)continue;
		Max(al,sum[a[i]]+mx[a[i]]+amx);
		Min(ar,sum[a[i]]-mx[a[i]]+bmn);
		Max(bl,sum[a[i]]+mx[a[i]]-bmn);
		Min(br,sum[a[i]]-mx[a[i]]-amx);
	}
	al+=L-val,ar+=val-L,bl+=L-val,br+=val-L;
	if(al>ar||bl>br)return false;
	for(int i=1,j=1,k=1,x=top,y=top;i<=top;i++)
	{
		while(j<=top&&sum[i]-sum[j]>=bl)j++;
		while(k<=top&&sum[i]-sum[k]>br)k++;
		while(x&&sum[i]+sum[x]>=al)x--;
		while(y&&sum[i]+sum[y]>ar)y--;
		if(max(k,x+1)<=min(j-1,y))return true;
	}
	return false;
}

int main()
{
	while(read(N),read(L),N+L)
	{
		GetGraph();
		dfs1(A=1,0,0),dfs1(B=A,0,0);
		memset(flag+1,0,sizeof(char)*N),top=0;
		for(int i=A;i!=B;i=fa[i])flag[q[++top]=i]=1;
		flag[q[++top]=B]=1;
		reverse(q+1,q+top+1);
		for(int i=1;i<=top;i++)
			sum[i]=dep[q[i]],mx[i]=dfs2(q[i],0,0),a[i]=b[i]=i;
		sort(a+1,a+top+1,cmp1),sort(b+1,b+top+1,cmp2);
		l=0,r=sum[top]-1,ans=sum[top];
		while(l<=r)check(mid=l+r>>1)?r=(ans=mid)-1:l=mid+1;
		printf("%lld\n",ans);
	}
	return 0;
}