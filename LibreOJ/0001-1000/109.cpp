#include<bits/stdc++.h>
using namespace std;
const int maxn=4000005,mod=998244353;

int n,m,fa[maxn],ans;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,op;i<=m;i++)
	{
		read(op),read(u),read(v),u++,v++;
		if(op)
		{
			u=find(u),v=find(v);
			if(u==v)ans=(ans<<1|1)%mod;
			else ans=(ans<<1)%mod;
		}
		else u=find(u),v=find(v),fa[u]=v;
	}
	printf("%lld",ans);
	return 0;
}
