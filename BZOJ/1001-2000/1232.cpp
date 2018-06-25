#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;

struct edge{int u,v,w;}e[100005];
int n,p,fa[maxn],c[maxn],cnt,ans=1005;
char ch;

inline void read(int& x)
{
	x=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-48,ch=getchar();
}
inline int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
inline bool operator < (edge a,edge b){return a.w<b.w;}

int main()
{
	read(n),read(p),cnt=n-1;
	for(int i=1;i<=n;i++)read(c[i]),fa[i]=i,ans=min(ans,c[i]);
	for(int i=1,u,v,w;i<=p;i++)
	{
		read(u),read(v),read(w);
		e[i]=(edge){u,v,w*2+c[u]+c[v]};
	}
	sort(e+1,e+p+1);
	for(int i=1;cnt;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)continue;
		fa[f1]=f2,ans+=e[i].w,cnt--;
	}
	printf("%d",ans);
	return 0;
}
