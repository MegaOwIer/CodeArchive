#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;

int n,fa[maxn];
char c;
bool vis[maxn];

inline void read(int& x)
{
	c=getchar(),x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}

int main()
{
	read(n);
	for(int i=1;i<=1000000;i++)fa[i]=i;
	for(int i=1,a,b;i<=n;i++)
	{
		read(a),read(b);
		int f1=find(a),f2=find(b);
		if(f1==f2){vis[f1]=1;continue;}
		if(f1>f2)swap(f1,f2);
		fa[f1]=f2,vis[f1]=1;
	}
	for(int i=1;i<=n+1;i++)if(!vis[i])return 0,printf("%d",i-1);
}
