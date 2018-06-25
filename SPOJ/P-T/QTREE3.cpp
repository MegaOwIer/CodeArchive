#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

struct edge
{
	int to;
	edge *nxt;
	edge(int t,edge *n):to(t),nxt(n){}
}*E[MX];
int N,Q,siz[MX],mxs[MX],dep[MX],fa[MX];
int pos[MX],sum[MX<<2],cnt,RT[MX],po[MX];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v)
{
	E[u]=new edge(v,E[u]);
	E[v]=new edge(u,E[v]);
}
void dfs1(int u,int f)
{
	siz[u]=1,fa[u]=f;
	for(edge *i=E[u];i;i=i->nxt)if(i->to!=f)
	{
		dep[i->to]=dep[u]+1,dfs1(i->to,u),siz[u]+=siz[i->to];
		if(siz[i->to]>siz[mxs[u]])mxs[u]=i->to;
	}
}
void dfs2(int u,int f,int root)
{
	pos[u]=++cnt,RT[u]=root,po[cnt]=u;
	if(mxs[u])dfs2(mxs[u],u,root);
	for(edge *i=E[u];i;i=i->nxt)
		if(i->to!=f&&i->to!=mxs[u])
			dfs2(i->to,u,i->to);
}
void change(int pos,int L,int R,int id)
{
	if(L==R){sum[id]^=1;return;}
	int mid=L+R>>1;
	if(pos<=mid)change(pos,L,mid,id<<1);
	else change(pos,mid+1,R,id<<1|1);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}
bool query(int l,int r,int L,int R,int id,int& ans)
{
	if(!sum[id]||l>R||L>r)return 0;
	if(L==R)return ans=po[L],1;
	int mid=L+R>>1;
	return query(l,r,L,mid,id<<1,ans)||query(l,r,mid+1,R,id<<1|1,ans);
}
int query(int x)
{
	int ans=-1;
	while(RT[x]!=1)
		query(pos[RT[x]],pos[x],1,N,1,ans),x=fa[RT[x]];
	query(1,pos[x],1,N,1,ans);
	return ans;
}

int main()
{
	read(N),read(Q);
	for(int i=1,u,v;i<N;i++)read(u),read(v),add(u,v);
	dfs1(1,0),dfs2(1,0,1);
	for(int i=1,op,x;i<=Q;i++)
	{
		read(op),read(x);
		if(op)printf("%d\n",query(x));
		else change(pos[x],1,N,1);
	}
	return 0;
}
