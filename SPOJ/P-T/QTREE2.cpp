#include<bits/stdc++.h>
using namespace std;
const int MX=40005;

namespace FastIO
{
	const int MXL=200000;
	struct FastIn
	{
		char BF[MXL],*p1,*p2,c;
		FastIn():p1(BF),p2(BF){}
		char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
		template<typename T>void operator()(T& x)
		{
			x=0,c=getchar();
			while(!isdigit(c))c=getchar();
			while(isdigit(c))x=x*10+c-'0',c=getchar();
		}
	};
	struct FastOut
	{
		char BF[MXL],*p1,*const p2;
		int bf[22],tp;
		FastOut():p1(BF),p2(BF+MXL){}
		~FastOut(){flush();}
		void putchar(char c){if(p1==p2)flush();*p1++=c;}
		void flush(){fwrite(BF,1,p1-BF,stdout),p1=BF;}
		template<typename T>void operator()(T x)
		{
			bf[tp=1]='\n'-48;
			do bf[++tp]=x%10,x/=10;while(x);
			while(tp)putchar(48+bf[tp--]);
		}
	};
}

struct edge{int to,nxt,w;}e[MX<<1];
int T,N,head[MX],dep[MX],dis[MX],tot,fa[17][MX],u,v,k;
char op;
FastIO::FastIn IN;
FastIO::FastOut OUT;

inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void dfs(int u,int f)
{
	fa[0][u]=f;
	for(int i=1;(1<<i)<=dep[u];i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)
		dep[e[i].to]=dep[u]+1,dis[e[i].to]=dis[u]+e[i].w,dfs(e[i].to,u);
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=15;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[i][u];
	if(u==v)return u;
	for(int i=15;~i;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
inline int getFa(int u,int k)
{
	for(int i=0;k;i++,k>>=1)if(k&1)u=fa[i][u];
	return u;
}
inline int query(int u,int v,int k)
{
	int f=lca(u,v);
	if(dep[u]-dep[f]>=k)return getFa(u,k);
	else return getFa(v,dep[u]+dep[v]-dep[f]*2-k);
}

int main()
{
	IN(T);
	while(T--)
	{
		IN(N);
		tot=0;
		memset(head+1,0,sizeof(int)*N);
		memset(fa,0,sizeof(fa));
		for(int i=1,u,v,w;i<N;i++)IN(u),IN(v),IN(w),add(u,v,w);
		dfs(1,-1);
		while(1)
		{
			do op=IN.getchar();while(!isalpha(op));
			op=IN.getchar();
			if(op=='O')break;
			IN(u),IN(v);
			if(op=='I')OUT(dis[u]+dis[v]-2*dis[lca(u,v)]);
			else IN(k),OUT(query(u,v,k-1));
		}
		OUT.putchar('\n');
	}
	return 0;
}
