#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> > g(100005);
int n,lt[100005],rt[100005],time=1,tree[100005],m;
bool a[100005];
char q;

void dfs(int v)
{
	lt[v]=time;
	for(int i=0;i<g[v].size();i++)  {time++;  dfs(g[v][i]);}
	rt[v]=time;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void insert(int id,int del)
{
	for(;id<=n;id+=lowbit(id))  tree[id]+=del;
}
inline int ask(int id)
{
	int sum=0;
	for(int i=id;i;i-=lowbit(i))  sum+=tree[i];
	return sum;
}

int main()
{
	scanf("%d",&n);
	for(int i=1,aa,b;i<n;i++)
	{
		scanf("%d%d",&aa,&b);
		g[aa].push_back(b);
	}
	dfs(1);
	for(int i=1;i<=n;i++)  {a[i]=1;  insert(i,1);}
	scanf("%d",&m);
	for(int i=1,r;i<=m;i++)
	{
		scanf("%s%d",&q,&r);
		if(q=='C')
		{
			if(a[r])  insert(lt[r],-1);
			else  insert(lt[r],1);
			a[r]=!a[r];
		}
		else  printf("%d\n",ask(rt[r])-ask(lt[r]-1));
	}
	return 0;
}
