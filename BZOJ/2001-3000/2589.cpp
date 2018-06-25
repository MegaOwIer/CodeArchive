#include<bits/stdc++.h>
using namespace std;
const int MX=40005,MN=205,Bsize=200;

namespace FastIO
{
	const int MXL=200000;
	struct FastIn
	{
		char BF[MXL],*p1,*p2,c;
		int f;
		FastIn():p1(BF),p2(BF),f(0){}
		char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
		template<typename T>void operator()(T& x)
		{
			x=0,c=getchar();
			while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
			while(isdigit(c))x=x*10+c-'0',c=getchar();
			if(f)x=-x,f=0;
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
		void operator()(int x)
		{
			bf[tp=1]='\n'-48;
			do bf[++tp]=x%10,x/=10;while(x);
			while(tp)putchar(48+bf[tp--]);
		}
	};
}

int N,M,a[MX],ls[MX],cnt,Ans[MN][MX],f[MX],lastans,head[MX],tot,B[MX],R[MX];
int fa[17][MX],stk[MX],top,dep[MX],RT[MN],num,bl[MX],p[MX][MN];
struct edge{int to,nxt;}e[MX<<1];
struct Array
{
	int num[MN];
	Array(){}
	void init(const Array& lst,int val,int dep)
	{
		static int cnt=0;
		memcpy(num,lst.num,sizeof(num));
		memcpy(p[++cnt],p[num[B[val]]],sizeof(p[0]));
		p[cnt][R[val]]=dep,num[B[val]]=cnt;
	}
	int operator[](int u){return p[num[B[u]]][R[u]];}
}s[MX];
FastIO::FastIn IN;
FastIO::FastOut OUT;

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
int dfs1(int u,int f)
{
	int mxdep=dep[u],tmp=++top;
	fa[0][u]=f,s[u].init(s[f],a[u],dep[u]),stk[top]=u;
	for(int i=1;(1<<i)<dep[u];i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)
		dep[e[i].to]=dep[u]+1,mxdep=max(mxdep,dfs1(e[i].to,u));
	if(mxdep-dep[u]>=Bsize||tmp==1)
	{
		RT[++num]=u;
		while(top>=tmp)bl[stk[top--]]=num;
		return dep[u]-1;
	}
	else return mxdep;
}
void dfs2(int u,int fa,int index)
{
	static int kind=0;
	if(++f[a[u]]==1)kind++;
	Ans[index][u]=kind;
	for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=fa)dfs2(e[i].to,u,index);
	if(!--f[a[u]])kind--;
}

inline int bruteforce(int u,int v)
{
	int ans=0;
	while(u!=v)
	{
		if(dep[u]<dep[v])swap(u,v);
		if(++f[a[u]]==1)ans++,stk[++top]=a[u];
		u=fa[0][u];
	}
	if(!f[a[u]])ans++;
	while(top)f[stk[top--]]=0;
	return ans;
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=15;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[i][u];
	if(u==v)return u;
	for(int i=15;~i;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
inline int solve(int u,int v)
{
	if(dep[RT[bl[u]]]<dep[RT[bl[v]]])swap(u,v);
	int ans=Ans[bl[u]][v],z=RT[bl[u]],d=dep[lca(u,v)];
	while(u!=z)
	{
		if(!f[a[u]]&&s[z][a[u]]<d&&s[v][a[u]]<d)
			f[stk[++top]=a[u]]=1,++ans;
		u=fa[0][u];
	}
	while(top)f[stk[top--]]=0;
	return ans;
}

int main()
{
	IN(N),IN(M);
	for(int i=1;i<=N;i++)B[i]=(i-1)/Bsize+1,R[i]=i%Bsize;
	for(int i=1;i<=N;i++)IN(a[i]),ls[i]=a[i];
	sort(ls+1,ls+N+1),cnt=unique(ls+1,ls+N+1)-ls-1;
	for(int i=1;i<=N;i++)a[i]=lower_bound(ls+1,ls+cnt+1,a[i])-ls;
	for(int i=1,u,v;i<N;i++)IN(u),IN(v),add(u,v);
	dep[1]=1,dfs1(1,0);
	for(int i=1;i<=num;i++)dfs2(RT[i],0,i);
	for(int i=1,x,y;i<=M;i++)
	{
		IN(x),IN(y),x^=lastans;
		if(bl[x]==bl[y])OUT(lastans=bruteforce(x,y));
		else OUT(lastans=solve(x,y));
	}
	return 0;
}
