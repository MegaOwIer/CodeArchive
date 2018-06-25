#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

namespace FastIO
{
	const int MXL=200000;
	class FastIn
	{
	private:
		char BF[MXL],*p1,*p2,c;
		int f;
		char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
	public:
		FastIn():p1(BF),p2(BF),f(0){}
		void operator()(int& x)
		{
			x=0,c=getchar();
			while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
			while(isdigit(c))x=x*10+c-'0',c=getchar();
			if(f)x=-x,f=0;
		}
	};
	class FastOut
	{
	private:
		char BF[MXL],*p1,*const p2;
		int bf[22],tp;
		void putchar(char c){if(p1==p2)flush();*p1++=c;}
		void flush(){fwrite(BF,1,p1-BF,stdout),p1=BF;}
	public:
		FastOut():p1(BF),p2(BF+MXL){}
		~FastOut(){flush();}
		void operator()(int x)
		{
			if(x<0)putchar('-'),x=-x;
			bf[tp=1]='\n'-48;
			do bf[++tp]=x%10,x/=10;while(x);
			while(tp)putchar(48+bf[tp--]);
		}
	};
}

namespace Tools
{
	struct edge
	{
		int to;
		edge* nxt;
		edge(){}
		edge(int t,edge* i):to(t),nxt(i){}
		void* operator new(size_t);
	}EPool[MX<<1];
	inline void* edge::operator new(size_t)
	{
		static int cnt=0;
		return EPool+(cnt++);
	}
	struct null_tag{}NT;
	struct Segment
	{
		Segment *l,*r;
		int cnt;
		Segment();
		Segment(null_tag):l(this),r(this),cnt(0){}
	}*null=new Segment(null_tag());
	inline Segment::Segment():l(null),r(null),cnt(0){}
}
using Tools::Segment;
using Tools::null;
using Tools::edge;

int N,M,a[MX],ls[MX],cnt,fa[18][MX],dep[MX];
Segment *root[MX];
edge *E[MX];
FastIO::FastIn IN;
FastIO::FastOut OUT;

inline void add(int u,int v)
{
	E[u]=new Tools::edge(v,E[u]);
	E[v]=new Tools::edge(u,E[v]);
}
inline void insert(Segment* &o,Segment *p,int pos,int l,int r)
{
	if(o==null)o=new Segment;
	o->cnt=p->cnt+1;
	if(l==r)return;
	int mid=l+r>>1;
	if(pos<=mid)insert(o->l,p->l,pos,l,mid),o->r=p->r;
	else insert(o->r,p->r,pos,mid+1,r),o->l=p->l;
}
inline void dfs(int u,int f)
{
	for(int i=1;(1<<i)<=dep[u];i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	insert(root[u],root[f],a[u],1,cnt);
	for(edge *i=E[u];i;i=i->nxt)if(i->to!=f)
		dep[i->to]=dep[u]+1,fa[0][i->to]=u,dfs(i->to,u);
}
inline int ask(Segment *u,Segment *v,Segment *f,Segment *ff){return u->cnt+v->cnt-f->cnt-ff->cnt;}
inline int query(Segment *u,Segment *v,Segment *f,Segment *ff,int l,int r,int k)
{
	if(l==r)return l;
	int _val=ask(u->l,v->l,f->l,ff->l);
	if(_val>=k)return query(u->l,v->l,f->l,ff->l,l,l+r>>1,k);
	else return query(u->r,v->r,f->r,ff->r,(l+r>>1)+1,r,k-_val);
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=16;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[i][u];
	if(u==v)return u;
	for(int i=16;~i;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}

int main()
{
	IN(N),IN(M);
	for(int i=0;i<=N;i++)root[i]=null;
	for(int i=1;i<=N;i++)IN(a[i]),ls[i]=a[i];
	sort(ls+1,ls+N+1),cnt=unique(ls+1,ls+N+1)-ls-1;
	for(int i=1;i<=N;i++)a[i]=lower_bound(ls+1,ls+cnt+1,a[i])-ls;
	for(int i=1,u,v;i<N;i++)IN(u),IN(v),add(u,v);
	dfs(1,0);
	for(int i=1,u,v,k,f;i<=M;i++)
	{
		IN(u),IN(v),IN(k),f=lca(u,v);
		OUT(ls[query(root[u],root[v],root[f],root[fa[0][f]],1,cnt,k)]);
	}
	return 0;
}
