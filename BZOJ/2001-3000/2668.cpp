#include<bits/stdc++.h>
using namespace std;
const int MV=1250,ME=4400,INF=2147483647;
const int dx[]={-1,0,1,1,1,0,-1,-1},dy[]={1,1,1,0,-1,-1,-1,0};
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define ID id[i][j]

int N,M,id[22][22][5],cnt,tmp,B,W;
int S,T,deg[MV],u[MV],v[MV],f[MV],c[MV],tot;
char st[22][22],ed[22][22],lim[22][22];

struct MinCostMaxFlow
{
	struct edge
	{
	    int to,f,c;
	    edge *rev;
	    edge(){}
	    edge(int t,int f,int c,edge *r):to(t),f(f),c(c),rev(r){}
	}*E[MV],Pool[ME<<1],*from[MV];
	int S,T,dis[MV];
	bool inq[MV];
	
	void build_graph()
	{
		E[1]=Pool;
		for(int i=1;i<=T;i++)E[i+1]=E[i]+deg[i];
		for(int i=1;i<=tot;i++)
		{
			--deg[u[i]],--deg[v[i]];
			E[u[i]][deg[u[i]]]=edge(v[i],f[i],c[i],E[v[i]]+deg[v[i]]);
			E[v[i]][deg[v[i]]]=edge(u[i],0,-c[i],E[u[i]]+deg[u[i]]);
		}
	}
	inline bool spfa()
	{
	    queue<int> q;
	    int now;
	    memset(dis+1,0x3f,sizeof(int)*T),dis[S]=0;
	    q.push(S);
	    while(!q.empty())
	    {
	        now=q.front(),q.pop(),inq[now]=0;
	        for(edge *i=E[now];i!=E[now+1];i++)if(i->f&&dis[i->to]>dis[now]+i->c)
	        {
	            dis[i->to]=dis[now]+i->c,from[i->to]=i;
	            if(!inq[i->to])q.push(i->to),inq[i->to]=1;
	        }
	    }
	    return dis[T]<0x3f3f3f3f;
	}
	int operator()(int _S,int _T)
	{
	    int ans=0,flow=0,w;
	    S=_S,T=_T,build_graph();
	    while(spfa())
	    {
	        w=INF;
	        for(int i=T;i!=S;i=from[i]->rev->to)w=min(w,from[i]->f);
	        for(int i=T;i!=S;i=from[i]->rev->to)from[i]->f-=w,from[i]->rev->f+=w;
	        ans+=w*dis[T],flow+=w;
	    }
	    return flow==B?ans:-1;
	}
}EdmondsKarp;

inline void read(int& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int _u,int _v,int _f,int _c)
{
	++tot,u[tot]=_u,v[tot]=_v,f[tot]=_f,c[tot]=_c;
	++deg[_u],++deg[_v];
}
inline bool check(int x,int y){return x&&y&&x<=N&&y<=M;}

int main()
{
	read(N),read(M);
	rep(i,1,N)scanf("%s",st[i]+1);
	rep(i,1,N)scanf("%s",ed[i]+1);
	rep(i,1,N)scanf("%s",lim[i]+1);
	rep(i,1,N)rep(j,1,M)rep(k,1,3)ID[k]=++cnt;
	T=(S=cnt+1)+1;
	rep(i,1,N)rep(j,1,M)
	{
		tmp=lim[i][j]-'0';
		if(st[i][j]=='0'&&ed[i][j]=='1')
		{
			B++,add(S,ID[2],1,0);
			add(ID[1],ID[2],tmp>>1,0),add(ID[2],ID[3],tmp+1>>1,0);
		}
		if(st[i][j]=='1'&&ed[i][j]=='0')
		{
			W++,add(ID[2],T,1,0);
			add(ID[1],ID[2],tmp+1>>1,0),add(ID[2],ID[3],tmp>>1,0);
		}
		if(st[i][j]==ed[i][j])
			add(ID[1],ID[2],tmp>>1,0),add(ID[2],ID[3],tmp>>1,0);
		for(int k=0,x,y;k<8;k++)
		{
			x=i+dx[k],y=j+dy[k];
			if(check(x,y))add(ID[3],id[x][y][1],INF,1);
		}
	}
	if(B^W)puts("-1");
	else printf("%d\n",EdmondsKarp(S,T));
    return 0;
}
