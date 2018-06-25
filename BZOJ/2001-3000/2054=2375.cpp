#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int n,m,p,q,fa[maxn],col[maxn],l,r;

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=n+1;i;i--)fa[i]=i;
	for(int i=m;i;i--)
	{
		l=(i*p+q)%n+1,r=(i*q+p)%n+1;
		if(l>r)swap(l,r);
		for(int j=find(l);j<=r;j=find(j))
			col[j]=i,fa[j]=j+1;
	}
	for(int i=1;i<=n;i++)printf("%d\n",col[i]);
	return 0;
}
