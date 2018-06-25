#include<bits/stdc++.h>
using namespace std;

struct edge{int u,v,w;}e[45200];
int n,tot,u,cnt,fa[305],ans;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline bool operator < (edge a,edge b){return a.w<b.w;}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(u),e[++tot]=(edge){i,n+1,u};
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		read(u);
		if(i<j)e[++tot]=(edge){i,j,u};
	}
	sort(e+1,e+tot+1);
	for(int i=1;i<=n+1;i++)fa[i]=i;
	for(int i=1;cnt<n;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)continue;
		fa[f1]=f2,ans+=e[i].w,cnt++;
	}
	printf("%d",ans);
	return 0;
}
