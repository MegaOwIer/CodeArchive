#include<bits/stdc++.h>
using namespace std;

struct edge{int to,next,w;}e[200005];
int n,r,tot,head[5005],dis[5005],dis2[5005];
char c;
bool inq[5005];
queue<int> q;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void spfa()
{
	q.push(1),inq[1]=1,dis[1]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop(),inq[now]=0;
		for(int i=head[now];i;i=e[i].next)
		{
			if(dis[now]+e[i].w<dis[e[i].to])
			{
				dis2[e[i].to]=min(dis[e[i].to],dis2[now]+e[i].w);
				dis[e[i].to]=dis[now]+e[i].w;
				if(!inq[now])q.push(e[i].to);
				inq[e[i].to]=1;
			}
			if(dis[now]+e[i].w>dis[e[i].to]&&dis[now]+e[i].w<dis2[e[i].to])
			{
				dis2[e[i].to]=dis[now]+e[i].w;
				if(!inq[now])q.push(e[i].to);
				inq[e[i].to]=1;
			}
			if(dis[now]+e[i].w==dis[e[i].to]&&dis2[now]+e[i].w<dis2[e[i].to])
			{
				dis2[e[i].to]=dis2[now]+e[i].w;
				if(!inq[now])q.push(e[i].to);
				inq[e[i].to]=1;
			}
		}
	}
}

int main()
{
	read(n),read(r);
	memset(dis+1,0x3f,n<<2),memset(dis2+1,0x3f,n<<2);
	for(int i=1,a,b,d;i<=r;i++)read(a),read(b),read(d),add(a,b,d);
	spfa();
	printf("%d",dis2[n]);
	return 0;
}
