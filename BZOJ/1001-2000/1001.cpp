#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
struct state
{
	int po,dis;
	state(int po,int dis):po(po),dis(dis){}
	state(){}
}now;
bool operator < (state a,state b) {return a.dis>b.dis;}
int n,m,v[1005][1005][2],cnt,vs,vt,c,dis[2000000],cst;
vector<edge> g[2000000];
priority_queue<state> q;
vector<edge>::iterator it; 

void add(int s,int t,int w)
{
	g[s].push_back(edge(t,w));
	g[t].push_back(edge(s,w));
}
void build()
{
	for(int i=1;i<n;i++)for(int j=1;j<m;j++)for(int k=0;k<2;k++)v[i][j][k]=++cnt;
	vs=++cnt,vt=++cnt;
	for(int i=1;i<m;i++)v[0][i][1]=vt,v[n][i][0]=vs;
	for(int i=1;i<n;i++)v[i][0][0]=vs,v[i][m][1]=vt;
	for(int i=1;i<m;i++)scanf("%d",&c),add(vt,v[1][i][0],c);
	for(int i=1;i<n-1;i++)for(int j=1;j<m;j++)scanf("%d",&c),add(v[i][j][1],v[i+1][j][0],c);
	for(int i=1;i<m;i++)scanf("%d",&c),add(vs,v[n-1][i][1],c);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&c),add(vs,v[i][1][1],c);
		for(int j=1;j<m-1;j++)scanf("%d",&c),add(v[i][j][0],v[i][j+1][1],c);
		scanf("%d",&c),add(vt,v[i][m-1][0],c);
	}
	for(int i=1;i<n;i++)for(int j=1;j<m;j++)scanf("%d",&c),add(v[i][j][0],v[i][j][1],c);
}
int dij()
{
	memset(dis,0x7f,sizeof(dis));
	q.push(state(vs,0));
	while(!q.empty())
	{
		now=q.top(),q.pop();
		if(now.dis>dis[now.po])continue;
		if(now.po==vt)return now.dis;
		for(it=g[now.po].begin();it!=g[now.po].end();++it)
		{
			cst=now.dis+it->w;
			if(cst<dis[it->to])dis[it->to]=cst,q.push(state(it->to,cst));
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	build();
	printf("%d",dij());
	return 0;
}
