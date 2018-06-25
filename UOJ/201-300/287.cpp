#include<bits/stdc++.h>
using namespace std;
const int MX=55;
#define pb push_back

int N,M,Q,pre[MX],f[MX],g[MX],pos[MX],t,ls[MX],idx,m,b[MX];
int lr[MX],rid[MX][MX];
vector<int> G[MX];
struct Permutation
{
	int a[MX];
	Permutation(){memset(a,0,sizeof(a));}
	bool isI()
	{
		for(int i=1;i<N;i++)if(a[i]!=i)return 0;
		return 1;
	}
	Permutation operator * (Permutation& b)
	{
		static Permutation ans;
		for(int i=1;i<N;i++)ans.a[i]=b.a[a[i]];
		return ans;
	}
	Permutation inverse()
	{
		static Permutation ans;
		for(int i=1;i<N;i++)ans.a[a[i]]=i;
		return ans;
	}
}s[MX][MX],r[MX][MX],rr[MX][MX],ans;
bool vis[MX],ins[MX];

inline int read()
{
	static int x;
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x;
}
inline void dfs(int u,int f)
{
	int w;
	pre[u]=f,vis[u]=1,ins[u]=1;
	for(auto i:G[u])if(i!=f)
	{
		if(vis[i])
		{
			if(!ins[i])continue;
			++t;
			for(int j=0;j<N;j++)s[1][t].a[j]=j;
			w=u;
			while(pre[w]!=i)s[1][t].a[w]=pre[w],w=pre[w];
			s[1][t].a[w]=u;
		}
		else dfs(i,u);
	}
	ins[u]=0;
}
inline void bfs()
{
	int u=b[idx],v;
	static int q[MX],hd,tl;
	static char vst[MX];
	static Permutation t;
	q[hd=tl=1]=u;
	memset(vst+1,0,sizeof(char)*(N-1));
	vst[u]=1;
	for(int i=1;i<N;i++)r[idx][i].a[1]=0;
	for(int i=1;i<N;i++)r[idx][u].a[i]=rr[idx][u].a[i]=i;
	lr[idx]=1,rid[idx][1]=u;
	while(hd<=tl)
	{
		u=q[hd++];
		for(int i=1;i<=ls[idx];i++)
		{
			t=r[idx][u]*s[idx][i],v=t.a[b[idx]];
			if(!vst[v])
			{
				vst[v]=1,q[++tl]=v;
				r[idx][v]=t,rr[idx][v]=t.inverse();
				rid[idx][++lr[idx]]=v;
			}
		}
	}
}
inline void Divide(Permutation& h)
{
	for(int i=idx+1;i<=m;i++)if(h.a[b[i]]!=b[i])
	{
		if(!r[i][h.a[b[i]]].a[1])return;
		h=h*rr[i][h.a[b[i]]];
	}
}
inline void Schreier_Sims()
{
	Permutation h;
	bool o;
	idx=m=1;
	for(int i=1;i<=ls[1];i++)for(int j=1;j<N;j++)
		if(s[1][i].a[j]!=j)b[1]=j;
	bfs();
	while(idx)
	{
		o=1;
		for(int i=1;o&&i<=lr[idx];i++)for(int j=1;j<=ls[idx];j++)
		{
			h=r[idx][rid[idx][i]]*s[idx][j];
			h=h*rr[idx][h.a[b[idx]]];
			Divide(h);
			if(!h.isI()){o=0;break;}
		}
		if(o)--idx;
		else
		{
			if(++idx>m)
			{
				ls[++m]=0;
				for(int j=1;j<N;j++)if(h.a[j]!=j)b[m]=j;
			}
			s[idx][++ls[idx]]=h;
			bfs();
		}
	}
}
inline void Transfer(int *A)
{
	int u=-1;
	for(int i=0;i<N;i++)if(!A[i])u=i;
	while(u)swap(A[u],A[pre[u]]),u=pre[u];
	for(int i=0;i<N;i++)pos[A[i]]=i;
	memcpy(A,pos,sizeof(int)*N);
}

int main()
{
	N=read(),M=read(),Q=read();
	for(int i=1,u,v;i<=M;i++)
		u=read()-1,v=read()-1,G[u].pb(v),G[v].pb(u);
	dfs(0,-1);
	if(ls[1]=t)Schreier_Sims();
	for(int i=0;i<N;i++)f[i]=read();
	Transfer(f);
	while(Q--)
	{
		for(int i=0;i<N;i++)g[i]=read();
		Transfer(g);
		for(int i=1;i<N;i++)ans.a[f[i]]=g[i];
		if(t)Divide(ans);
		puts(ans.isI()?"Yes":"No");
	}
	return 0;
}
