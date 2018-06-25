#include<bits/stdc++.h>
using namespace std;
const int maxn=3005,maxm=10005;
const double eps=1e-10;

struct edge{int to,next;double w;}e[maxm];
int n,m,tot,head[maxn];
double mn=-1e7,mx=1e7,dis[maxn],mid,w;
char c;
bool flag,inq[maxn];

inline void read(int& x)
{
	c=getchar(),x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,double w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
}
inline void spfa(int u)
{
	inq[u]=1;
	for(int i=head[u];i;i=e[i].next)if(dis[u]+e[i].w-mid<dis[e[i].to])
	{
		if(inq[e[i].to]){flag=1;break;}
		else
		{
			dis[e[i].to]=dis[u]+e[i].w-mid;
			spfa(e[i].to);
		}
	}
	inq[u]=0;
}
inline bool check()
{
	memset(inq,0,sizeof(inq)),memset(dis,0,sizeof(dis));
	flag=0;
	for(int i=1;i<=n;i++)
	{
		spfa(i);
		if(flag)return 1;
	}
	return 0;
}

int main()
{
	read(n),read(m);
	for(int i=1,a,b;i<=m;i++)read(a),read(b),scanf("%lf",&w),add(a,b,w);
	while(mx-mn>eps)
	{
		mid=(mn+mx)/2;
		if(check())mx=mid;
		else mn=mid;
	}
	printf("%.8lf",mn);
	return 0;
}
