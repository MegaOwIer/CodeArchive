#include<bits/stdc++.h>
using namespace std;
const int MX=200005;

int n,m,s,c[MX],q,u,v,d;

namespace FastIO
{
	char c;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;

char Pool[150000000],*pointer=Pool;
inline void* operator new(size_t siz){return (pointer+=siz)-siz;}
inline void operator delete(void*){}

struct Graph
{
	int V;
	struct Edge
	{
		int to,w;
		Edge* nxt;
		Edge(int t,int w,Edge *n):to(t),w(w),nxt(n){}
	}*head[MX];
	
	Graph(int v):V(v){memset(head+1,0,sizeof(Edge*)*v);}
	void add_edge(int u,int v,int w)
	{
		head[u]=new Edge(v,w,head[u]);
		head[v]=new Edge(u,w,head[v]);
	}
};

namespace Tree
{
	Graph *G;
	int dep[MX],fa[MX][20],mx[MX][20];

	inline void dfs(int u)
	{
		for(int i=1;(1<<i)<=dep[u];i++)
			fa[u][i]=fa[fa[u][i-1]][i-1],mx[u][i]=max(mx[u][i-1],mx[fa[u][i-1]][i-1]);
		for(Graph::Edge* i=G->head[u];i;i=i->nxt)if(i->to!=fa[u][0]&&!dep[i->to])
			fa[i->to][0]=u,mx[i->to][0]=i->w,dep[i->to]=dep[u]+1,dfs(i->to);
	}
	inline void work(){for(int i=1;i<=s;i++)if(!dep[c[i]])dfs(c[i]);}
	inline int query(int u,int v)
	{
		int ans=0;
		if(dep[u]>dep[v])swap(u,v);
		for(int i=17;dep[v]-dep[u];i--)if(dep[v]-dep[u]>=(1<<i))
			ans=max(ans,mx[v][i]),v=fa[v][i];
		if(u==v)return ans;
		for(int i=17;~i;i--)if(fa[u][i]!=fa[v][i])
			ans=max(ans,max(mx[u][i],mx[v][i])),u=fa[u][i],v=fa[v][i];
		return max(ans,max(mx[u][0],mx[v][0]));
	}
}

namespace Minimum_Spanning_Tree
{
	struct Edge
	{
		int u,v,w;

		Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
		bool operator < (const Edge& a)const{return w<a.w;}
	}e[MX];
	int tot,fa[MX];

	inline void add_edge(int u,int v,int w){e[++tot]=Edge(u,v,w);}
	inline int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
	inline void Kruskal()
	{
		sort(e+1,e+tot+1);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1,f1,f2;i<=tot;i++)
		{
			f1=find(e[i].u),f2=find(e[i].v);
			if(f1==f2)continue;
			Tree::G->add_edge(e[i].u,e[i].v,e[i].w);
			fa[f2]=f1;
		}
	}
}

namespace Shortest_Path
{
#define mp make_pair
#define d first
#define id second
	typedef pair<int,int> sta;
	
	Graph *G;
	int dis[MX],pre[MX],now,u[MX],v[MX],w[MX];
	char vis[MX];
	priority_queue<sta,vector<sta>,greater<sta> > q;
	
	inline void build()
	{
		for(int i=1;i<=m;i++)
			read(u[i]),read(v[i]),read(w[i]),G->add_edge(u[i],v[i],w[i]);
	}
	inline void prework(int u){dis[u]=0,pre[u]=u,q.push(mp(0,u));}
	void Dijkstra()
	{
		Graph::Edge *i;
		while(!q.empty())
		{
			now=q.top().id,q.pop();
			if(vis[now])continue;
			vis[now]=1;
			for(i=G->head[now];i;i=i->nxt)if(!pre[i->to]||dis[i->to]>dis[now]+i->w)
				pre[i->to]=pre[now],q.push(mp(dis[i->to]=dis[now]+i->w,i->to));
		}
	}
	void work()
	{
		build();
		Dijkstra();
		for(int i=1,f1,f2;i<=m;i++)
		{
			f1=pre[u[i]],f2=pre[v[i]];
			if(f1==f2)continue;
			Minimum_Spanning_Tree::add_edge(pre[u[i]],pre[v[i]],dis[u[i]]+dis[v[i]]+w[i]);
		}
	}
#undef mp
#undef d
#undef id
}

int main()
{
	read(n),read(s),read(m);
	Tree::G=new Graph(n);
	Shortest_Path::G=new Graph(n);
	memset(Shortest_Path::dis+1,0x3f,sizeof(int)*n);
	for(int i=1;i<=s;i++)read(c[i]),Shortest_Path::prework(c[i]);
	Shortest_Path::work();
	Minimum_Spanning_Tree::Kruskal();
	Tree::work();
	read(q);
	while(q--)
	{
		read(u),read(v),read(d);
		if(Minimum_Spanning_Tree::find(u)!=Minimum_Spanning_Tree::find(v))puts("NIE");
		else puts(Tree::query(u,v)>d?"NIE":"TAK");
	}
	return 0;
}
