#include<bits/stdc++.h>
using namespace std;
const int MX=10005;

namespace FastIO
{
	const int MXL=200000;
	struct FastIn
	{
		char BF[MXL],*p1,*p2,c;
		FastIn():p1(BF),p2(BF){}
		char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
		void operator()(int& x)
		{
			c=getchar(),x=0;
			while(!isdigit(c))c=getchar();
			while(isdigit(c))x=x*10+c-'0',c=getchar();
		}
	};
	struct FastOut
	{
		char BF[MXL],*p1,*const p2;
		int bf[12],tp;
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

struct edge{int to,nxt,w,id;}e[MX<<1];
int T,N,head[MX],tot,w[MX],dep[MX],fa[MX],mx[MX<<2],u,v;
int siz[MX],mxs[MX],RT[MX],pos[MX],cnt,po[MX],mp[MX];
char op;
FastIO::FastIn IN;
FastIO::FastOut OUT;

inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void dfs1(int u,int f)
{
	siz[u]=1,mxs[u]=0;
	for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)
	{
		mp[i>>1]=e[i].to;
		dep[e[i].to]=dep[u]+1,w[e[i].to]=e[i].w,fa[e[i].to]=u;
		dfs1(e[i].to,u);
		siz[u]+=siz[e[i].to];
		if(siz[e[i].to]>siz[mxs[u]])mxs[u]=e[i].to;
	}
}
inline void dfs2(int u,int root)
{
	pos[u]=++cnt,po[cnt]=u,RT[u]=root;
	if(mxs[u])dfs2(mxs[u],root);
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].to!=fa[u]&&e[i].to!=mxs[u])dfs2(e[i].to,e[i].to);
}
inline void build(int l,int r,int id)
{
	if(l==r){mx[id]=w[po[l]];return;}
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1);
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
}
inline void modify(int p,int val,int L,int R,int id)
{
	if(L==R){mx[id]=val;return;}
	int mid=L+R>>1;
	if(p<=mid)modify(p,val,L,mid,id<<1);
	else modify(p,val,mid+1,R,id<<1|1);
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
}
inline int query(int l,int r,int L,int R,int id)
{
	if(l<=L&&R<=r)return mx[id];
	int mid=L+R>>1,ans=0;
	if(l<=mid)ans=max(ans,query(l,r,L,mid,id<<1));
	if(mid<r)ans=max(ans,query(l,r,mid+1,R,id<<1|1));
	return ans;
}
inline int ask(int u,int v)
{
	int ans=0;
	while(RT[u]!=RT[v])
	{
		if(dep[RT[u]]<dep[RT[v]])swap(u,v);
		ans=max(ans,query(pos[RT[u]],pos[u],1,N,1));
		u=fa[RT[u]];
	}
	if(u==v)return ans;
	if(dep[u]<dep[v])swap(u,v);
	return max(ans,query(pos[v]+1,pos[u],1,N,1));
}

int main()
{
	IN(T);
	while(T--)
	{
		IN(N);
		memset(head+1,0,sizeof(int)*N);
		tot=1,cnt=0;
		for(int i=1,u,v,w;i<N;i++)
			IN(u),IN(v),IN(w),add(u,v,w);
		dfs1(1,-1),dfs2(1,1),build(1,N,1);
		while(1)
		{
			do op=IN.getchar();while(!isalpha(op));
			if(op=='D')break;
			IN(u),IN(v);
			if(op=='Q')OUT(ask(u,v));
			else modify(pos[mp[u]],v,1,N,1);
		}
	}
	return 0;
}
