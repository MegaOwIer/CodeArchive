#include<bits/stdc++.h>
using namespace std;

struct edge {int u,v;double w;}e[499505];
int n,k,x[1005],y[1005],fa[1005],tot;
char c;

inline bool operator < (edge a,edge b){return a.w<b.w;}
inline void read(int &x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}
inline double dist(int i,int j){return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));}
inline int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}

int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)read(x[i]),read(y[i]);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)e[++tot]=(edge){i,j,dist(i,j)};
	sort(e+1,e+tot+1);
	for(int i=1;;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)continue;
		fa[f1]=f2,n--;
		if(n==k)for(int j=i+1;;j++)
		{
			int f1=find(e[j].u),f2=find(e[j].v);
			if(f1!=f2){printf("%.2lf",e[j].w);return 0;}
		}
	}
}
