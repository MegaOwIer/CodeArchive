#include<bits/stdc++.h>
using namespace std;
const int MX=40005;

namespace FastIO
{
	const int MXL=200000;
	class FastIn
	{
	private:
		char BF[MXL],*p1,*p2,c;
		char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
	public:
		FastIn():p1(BF),p2(BF){}
		void operator()(int& x)
		{
			x=0,c=getchar();
			while(!isdigit(c))c=getchar();
			while(isdigit(c))x=x*10+c-'0',c=getchar();
		}
	};
	class FastOut
	{
	private:
		char BF[MXL],*p1,*const p2;
		int bf[12],tp;
		void putchar(char c){if(p1==p2)flush();*p1++=c;}
		void flush(){fwrite(BF,1,p1-BF,stdout),p1=BF;}
	public:
		FastOut():p1(BF),p2(BF+MXL){}
		~FastOut(){flush();}
		void operator()(int& x)
		{
			bf[tp=1]='\n'-48;
			do bf[++tp]=x%10,x/=10;while(x);
			while(tp)putchar(48+bf[tp--]);
		}
	};
}

struct edge
{
	int to;
	edge *nxt;
	edge(int t,edge *i):to(t),nxt(i){}
}*E[MX];
int N,M,a[MX],ls[MX],tot,B,ans[100005],Ans,num[MX];
int dep[MX],fa[17][MX],cnt,dfn[MX],pos[MX],stk[MX],top,Bcnt;
bool vis[MX];
struct Ques
{
	int u,v,id;
	bool operator<(const Ques& a)const
	{
		if(pos[u]!=pos[a.u])return pos[u]<pos[a.u];
		return dfn[v]<dfn[a.v];
	}
}q[100005];
FastIO::FastIn IN;
FastIO::FastOut OUT;

inline void add(int u,int v)
{
	E[u]=new edge(v,E[u]);
	E[v]=new edge(u,E[v]);
}
inline int dfs(int u,int f)
{
	int siz=0;
	dfn[u]=++cnt;
	for(int i=1;(1<<i)<=dep[u];i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(edge *i=E[u];i;i=i->nxt)if(i->to!=f)
	{
		fa[0][i->to]=u,dep[i->to]=dep[u]+1;
		siz+=dfs(i->to,u);
		if(siz>=B)
		{
			++Bcnt;
			while(siz--)pos[stk[top--]]=Bcnt;
			siz=0;
		}
	}
	stk[++top]=u;
	return siz+1;
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=15;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[i][u];
	if(u==v)return u;
	for(int i=15;~i;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
inline void update(int u)
{
	if(vis[u])
	{
		num[a[u]]--;
		if(!num[a[u]])Ans--;
	}
	else
	{
		if(!num[a[u]])Ans++;
		num[a[u]]++;
	}
	vis[u]^=1;
}
inline void change(int x,int y)
{
	while(x!=y)
		if(dep[x]>dep[y])update(x),x=fa[0][x];
		else update(y),y=fa[0][y];
}

int main()
{
	IN(N),IN(M),B=1+pow(N,0.5);
	for(int i=1;i<=N;i++)IN(a[i]),ls[i]=a[i];
	sort(ls+1,ls+N+1),tot=unique(ls+1,ls+N+1)-ls;
	for(int i=1;i<=N;i++)a[i]=lower_bound(ls+1,ls+tot,a[i])-ls;
	for(int i=1,u,v;i<N;i++)IN(u),IN(v),add(u,v);
	dfs(1,-1);
	while(top)pos[stk[top--]]=Bcnt;
	for(int i=1,u,v;i<=M;i++)
	{
		IN(u),IN(v);
		if(dfn[u]>dfn[v])swap(u,v);
		q[i]=(Ques){u,v,i};
	}
	sort(q+1,q+M+1),q[0].u=q[0].v=q[1].u;
	for(int i=1,LCA;i<=M;i++)
	{
		change(q[i-1].u,q[i].u),change(q[i-1].v,q[i].v);
		LCA=lca(q[i].u,q[i].v);
		update(LCA),ans[q[i].id]=Ans,update(LCA);
	}
	for(int i=1;i<=M;i++)OUT(ans[i]);
	return 0;
}
