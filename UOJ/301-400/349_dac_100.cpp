#include<bits/stdc++.h>
#include"rts.h"
using namespace std;
const int MX=300005;

struct edge
{
	int to;
	edge* nxt;
	edge(int t=0,edge* n=0):to(t),nxt(n){}
	void* operator new (size_t);
}*head[MX];
int siz[MX],fa[MX],num[MX],rt,vis[MX],T,mn,O,fO;
bool known[MX];
vector<int> id,leaf,stk;
map<int,int> son[MX];

inline void* edge::operator new (size_t siz)
{
	static edge e[MX<<1];
	static int cnt=0;
	return e+(cnt++);
}
inline void ade(int u,int v)
{
	head[u]=new edge(v,head[u]);
	head[v]=new edge(u,head[v]);
}
inline void ads(int u,int v,int w){fa[v]=u,son[u][w]=v,num[v]=w;}
inline void dfs(int x)
{
	vis[x]=T;
	for(auto P:son[x])dfs(P.second);
	son[x].clear();
}
inline void getG(int u,int f,int totsiz)
{
	int mxsz=0;
	siz[u]=1;
	for(edge* i=head[u];i;i=i->nxt)if(i->to!=f&&vis[i->to]==T)
		getG(i->to,u,totsiz),siz[u]+=siz[i->to],mxsz=max(mxsz,siz[i->to]);
	mxsz=max(mxsz,totsiz-siz[u]);
	if(mxsz<mn)mn=mxsz,O=u,fO=f;
}
int dac(int u,int totsiz)
{
	mn=1e9;
	getG(u,-1,totsiz);
	vis[u=O]=0;
	if(~fO)siz[fO]=totsiz-siz[O];
	siz[O]=totsiz;
	for(edge* i=head[u];i;i=i->nxt)if(vis[i->to]==T)
		ads(u,dac(i->to,siz[i->to]),i->to);
	return u;
}

void play(int n,int,int dataType)
{
	srand(time(NULL));
	for(int i=2;i<=n;i++)id.push_back(i);
	random_shuffle(id.begin(),id.end());
	known[1]=1;
	if(dataType==3)
	{
		int L=1,R=1,targ;
		for(int x:id)if(!known[x])
		{
			targ=explore(L,x);
			if(known[targ])swap(L,R),targ=explore(L,x);
			while(targ!=x)known[L=targ]=1,targ=explore(L,x);
			known[L=targ]=1;
		}
		return;
	}
	rt=1,siz[1]=1;
	for(int y:id)if(!known[y])
	{
		int x,z;
		x=rt,stk.clear(),leaf.clear();
		while(x!=y)
		{
			z=explore(x,y);
			if(!known[z])ade(x,z),ads(x,z,z),leaf.push_back(z),known[z]=1;
			stk.push_back(x=son[x][z]);
		}
		for(int i:stk)siz[fa[i]]-=siz[i];
		for(int i:leaf)siz[i]=1;
		for_each(stk.rbegin(),stk.rend(),[](int i){siz[fa[i]]+=siz[i];});
		for(int x:stk)if(siz[x]>0.88*siz[fa[x]])
		{
			x=fa[x],T++,dfs(x);
			if(x==rt)fa[rt=dac(x,siz[x])]=0;
			else z=fa[x],ads(z,dac(x,siz[x]),num[x]);
			break;
		}
	}
}
