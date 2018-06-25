#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	inline void getc(char& x){do x=getchar();while(x!='!'&&x!='+'&&x!='-');}
}
using FastIO::read;
using FastIO::getc;
typedef long long LL;
const int maxn=200005;

int n,m,cnt[maxn];
LL ans[maxn];
char c;
set<int> s[maxn];

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)
	{
		getc(c),read(u);
		if(c=='!')cnt[u]++;
		else if(c=='+')read(v),s[u].insert(v),s[v].insert(u),ans[u]-=cnt[v],ans[v]-=cnt[u];
		else read(v),s[u].erase(v),s[v].erase(u),ans[u]+=cnt[v],ans[v]+=cnt[u];
	}
	for(int i=1;i<=n;i++)for(set<int>::iterator it=s[i].begin();it!=s[i].end();++it)ans[*it]+=cnt[i];
	for(int i=1;i<n;i++)printf("%lld ",ans[i]);
	printf("%lld",ans[n]);
	return 0;
}
