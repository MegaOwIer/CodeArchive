#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1005;

struct edge
{
	int to,next,w;
	edge(){}
	edge(int _,int __,int ___):to(_),next(__),w(___){}
}e[2][100005];
int n,m,S,head[2][maxn],dis[2][maxn],ans;
char c;
queue<int> q;
bool inq[maxn];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void Dijisktra(int r)
{
	memset(dis[r]+1,0x3f,n<<2),dis[r][S]=0;
	q.push(S),inq[S]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop(),inq[now]=0;
		for(int i=head[r][now];i;i=e[r][i].next)
			if(dis[r][now]+e[r][i].w<dis[r][e[r][i].to])
			{
				dis[r][e[r][i].to]=dis[r][now]+e[r][i].w;
				if(!inq[e[r][i].to])q.push(e[r][i].to),inq[e[r][i].to]=1;
			}
	}
}

int main()
{
	read(n),read(m),read(S);
	for(int i=1,u,v,w;i<=m;i++)
	{
		read(u),read(v),read(w);
		e[0][i]=edge(v,head[0][u],w),head[0][u]=i;
		e[1][i]=edge(u,head[1][v],w),head[1][v]=i;
	}
	Dijisktra(0),Dijisktra(1);
	for(int i=1;i<=n;i++)if(i!=S)ans=max(ans,dis[0][i]+dis[1][i]);
	printf("%d",ans);
	return 0;
}
