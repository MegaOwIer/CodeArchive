#include<bits/stdc++.h>
using namespace std;
const int maxn=400005;

vector<int> g[maxn];
vector<int>::iterator it;
int n,m,k,fa[maxn],ans[maxn],hk[maxn],now,tot;
char c;
bool fl[maxn],used[maxn];

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void add(int u)
{
	int f1=find(u),f2;
	for(it=g[u].begin();it!=g[u].end();++it)if(used[*it])
	{
		f2=find(*it);
		if(f1!=f2)fa[f2]=f1,tot--;
	}
}

int main()
{
	read(n),read(m);
	for(int i=0;i<n;i++)fa[i]=i;
	for(int i=1,a,b;i<=m;i++)read(a),read(b),g[a].push_back(b),g[b].push_back(a);
	read(k);
	for(int i=1;i<=k;i++)read(hk[i]),fl[hk[i]]=1;
	for(int i=0;i<n;i++)if(!fl[i])tot++,add(i),used[i]=1;
	ans[k]=tot;
	for(int i=k;i;i--)tot++,add(hk[i]),used[hk[i]]=1,ans[i-1]=tot;
	for(int i=0;i<=k;i++)printf("%d\n",ans[i]);
	return 0;
}
