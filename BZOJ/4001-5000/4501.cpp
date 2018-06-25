#include<bits/stdc++.h>
using namespace std;
const int MV=55,ME=4200;
const double eps=1e-7;

int N,M,K,id[505],tot,head[MV];
double dp[MV];
vector<int> lim[505];

struct edge{int to,nxt;}e[505];

struct MaxFlow
{
	struct edge
	{
		int to;
		double f;
		edge *nxt,*rev;
		edge(int t=0,edge* n=0,double f=0.0):to(t),f(f),nxt(n){}
		void* operator new(size_t);
	}*E[MV],*cur[MV];
	int S,T,dep[MV];
	
	void reset();
	void add(int u,int v,double f)
	{
		E[u]=new edge(v,E[u],f),E[v]=new edge(u,E[v],0.0);
		E[u]->rev=E[v],E[v]->rev=E[u];
	}	
	bool bfs()
	{
		int now;
		queue<int> q;
		memset(dep+1,-1,sizeof(int)*T),dep[S]=0;
		q.push(S);
		while(!q.empty())
		{
			now=q.front(),q.pop();
			for(edge *i=E[now];i;i=i->nxt)if(i->f&&!~dep[i->to])
				dep[i->to]=dep[now]+1,q.push(i->to);
		}
		return ~dep[T];
	}
	double dfs(int u,double flow)
	{
		if(u==T||flow<1e-7)return flow;
		double used=0.0,w;
		for(edge* &i=cur[u];i;i=i->nxt)if(i->f&&dep[i->to]==dep[u]+1)
			w=dfs(i->to,min(i->f,flow-used)),i->f-=w,used+=w,i->rev->f+=w;
		return used;
	}	
	bool operator()(int u,double val)
	{
		int cnt=0;
		double ans=0,tmp;
		for(int i=head[u];i;i=e[i].nxt)id[i]=++cnt;
		T=(S=cnt+1)+1,reset();
		for(int i=head[u];i;i=e[i].nxt)
		{
			tmp=dp[e[i].to]+1-val;
			if(tmp>eps)add(S,id[i],tmp),ans+=tmp;
			else if(tmp<-eps)add(id[i],T,-tmp);
			for(int j=0;j<lim[i].size();j++)add(id[i],id[lim[i][j]],1e9);
		}
		while(bfs()&&ans>1e-7)memcpy(cur+1,E+1,sizeof(edge*)*T),ans-=dfs(S,1e9);
		return ans>1e-7;
	}
}Dinic;
MaxFlow::edge ePool[ME],*ptr=ePool;
inline void* MaxFlow::edge::operator new(size_t){return ptr++;}
inline void MaxFlow::reset(){ptr=ePool,memset(E+1,0,sizeof(edge*)*T);}

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
double dfs(int u)
{
	if(dp[u]>1e-7)return dp[u];
	double l=0,r=0,mid;
	for(int i=head[u];i;i=e[i].nxt)r=max(r,dfs(e[i].to)+1);
	while(r-l>1e-5)mid=(l+r)/2,(Dinic(u,mid)?l=mid:r=mid);
	return dp[u]=l;
}

int main()
{
	read(N),read(M),read(K);
	for(int i=1,u,v;i<=M;i++)
		read(u),read(v),e[++tot]=(edge){v,head[u]},head[u]=tot;
	for(int i=1,x,y;i<=K;i++)read(x),read(y),lim[x].push_back(y);
	printf("%.4lf\n",dfs(1));
	return 0;
}
