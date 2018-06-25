#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;

int n,m;
char c,a;
struct Two_SAT
{
	struct edge{int to,next;}e[maxn<<2];
	int head[maxn],tot;
	bool mark[maxn],fail[maxn];
	stack<int> S;
	inline void add(int u,int v)
	{
		e[++tot]=(edge){v,head[u]},head[u]=tot;
	}
	inline bool dfs(int u)
	{
		if(mark[u^1])return 0;
		if(mark[u])return 1;
		mark[u]=1,S.push(u);
		for(int i=head[u];i;i=e[i].next)
		if(!dfs(e[i].to))
		return 0;
		return 1;
	}
	void solve()
	{
		for(int i=2;i<=n*2+1;i++)
		{
			while(!S.empty())mark[S.top()]=0,S.pop();
			if(!dfs(i))fail[i]=1;
			if(fail[i]&&fail[i^1])exit((puts("IMPOSSIBLE"),0));
		}
		for(int i=1;i<=n;i++)
			if(fail[i<<1])putchar('Y');
			else if(fail[i<<1|1])putchar('N');
			else putchar('?');
	}
}sol;


inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void getalpha(char& c){do c=getchar();while(!isalpha(c));}

int main()
{
	read(n),read(m);
	for(int i=1,u,v,su,sv;i<=m;i++)
	{
		read(u),getalpha(a),su=(a=='Y')?1:0;
		read(v),getalpha(a),sv=(a=='Y')?1:0;
		sol.add((u<<1)|(su^1),v<<1|sv);
		sol.add((v<<1)|(sv^1),u<<1|su);
	}
	sol.solve();
	return 0;
}
