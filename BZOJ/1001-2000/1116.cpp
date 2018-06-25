#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

int n,m,fa[maxn],f1,f2;
char c;
bool fl[maxn];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v;i<=m;i++)
	{
		read(u),read(v);
		f1=find(u),f2=find(v);
		if(f1!=f2)fa[f1]=f2,fl[f2]|=fl[f1];
		else fl[f1]=1;
	}
	for(int i=1;i<=n;i++)if(fa[i]==i&&!fl[i])return puts("NIE"),0;
	return puts("TAK"),0;
}
