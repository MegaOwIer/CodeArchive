#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;

typedef vector<int>::iterator Vit;
const int MX=150005;
#define cin FAKE_ISTREAM

int N,M,P,to[MX<<1],Q,K[2005],ans[MX];
int dfn[MX<<1],low[MX<<1],blt[MX<<1],siz[MX<<1],Bcnt;
bool ins[MX<<1];
vector<int> G[MX],G1[MX<<1],del[MX<<1];
vector<pair<int,int> > Qu[MX<<1];
tr1::unordered_map<int,vector<int> > id;

struct Istream
{
	static const int MXL=2000000;
	char bf[MXL],*p1,*p2;
	FILE *F;
	Istream(FILE *F):p1(bf),p2(bf),F(F){}
	char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
	Istream& operator >> (int& x)
	{
		x=0;  int c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
		return *this;
	}
}cin(stdin);

inline void add_edge(int u,int v)
{
	if(G[u].size()<2)G[u].push_back(v);
	if(G[v].size()<2)G[v].push_back(u);
}
void Tarjan(int u)
{
	static int tot=0,stk[MX<<1],*top=stk;
	dfn[u]=low[u]=++tot,*++top=u,ins[u]=1;
	int v=to[u];
	G1[v].push_back(u);
	if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);
	else if(ins[v])low[u]=min(low[u],dfn[v]);
	if(dfn[u]==low[u])
	{
		++Bcnt;
		do v=*top--,ins[v]=0,blt[v]=Bcnt,siz[Bcnt]++;
		while(v!=u);
	}
}
inline void insert(int md,int mn)
{
	size_t w=lower_bound(Qu[md].begin(),Qu[md].end(),make_pair(mn,-1))-Qu[md].begin();
	if(Qu[md].size()==w)return;
	del[md][w]++;
}
void dfs1(int u,int dis,int f,int L)
{
	if(u<N)insert(dis%L,dis);
    for(Vit it=G1[u].begin();it!=G1[u].end();++it)
        if(*it!=f&&blt[*it]!=blt[u])dfs1(*it,dis+1,u,L);
}
void dfs2(int u,int dis)
{
	if(u<N)if(id.count(dis))
    {
        vector<int> &cur=id[dis];
        for(Vit it=cur.begin();it!=cur.end();++it)ans[*it]++;
    }
    for(Vit it=G1[u].begin();it!=G1[u].end();++it)dfs2(*it,dis+1);
}
void solve(int P)
{
	if(siz[blt[P]]==1)return dfs2(P,0);
	int L=siz[blt[P]];
	for(int i=0;i<L;i++)Qu[i].clear(),del[i].clear();
	for(int i=1;i<=Q;i++)Qu[K[i]%L].push_back({K[i],i});
	for(int i=0;i<L;i++)
		sort(Qu[i].begin(),Qu[i].end()),del[i].resize(Qu[i].size());
	for(int ext=L-1,i=to[P];ext>=0;ext--,i=to[i])dfs1(i,ext,-1,L);
	for(int i=0;i<L;i++)if(Qu[i].size())
	{
		ans[Qu[i][0].second]+=del[i][0];
		for(size_t j=1;j<Qu[i].size();j++)
			del[i][j]+=del[i][j-1],ans[Qu[i][j].second]+=del[i][j];
	}
}

int main()
{
	cin>>N>>M>>P;
	for(int i=1,u,v;i<=M;i++)cin>>u>>v,add_edge(u,v);
	cin>>Q;
	for(int i=1;i<=Q;i++)cin>>K[i],id[K[i]].push_back(i);
	for(int i=0;i<N;i++)
	{
		if(G[G[i][0]][0]==i)to[i]=G[i][0]+N;
		else to[i]=G[i][0];
		if(G[G[i].back()][0]==i)to[i+N]=G[i].back()+N;
		else to[i+N]=G[i].back();
	}
	for(int i=0;i<N*2;i++)if(!dfn[i])Tarjan(i);
	solve(P),solve(P+N);
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
	return 0;
}

/*
5 5 2
1 0
1 2
3 2
1 3
4 2
2
3 1

*/
