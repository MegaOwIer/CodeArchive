#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int M=1001001;

struct side {int to,next;}table[M<<1];
int head[M],tot,n,ans,fa[M],siz[M];
ll f[M];

void Add(int x,int y)
{
	table[++tot].to=y;
	table[tot].next=head[x];
	head[x]=tot;
}
void DFS1(int x)
{
	siz[x]=1;
	for(int i=head[x];i;i=table[i].next)  if(table[i].to!=fa[x])
	{
		fa[table[i].to]=x;
		DFS1(table[i].to);
		siz[x]+=siz[table[i].to];
		f[x]+=f[table[i].to]+siz[table[i].to];
	}
}
void DFS2(int x)
{
	if(x!=1)  f[x]=f[fa[x]]+n-siz[x]-siz[x];
	for(int i=head[x];i;i=table[i].next)  if(table[i].to!=fa[x])  DFS2(table[i].to);
}

int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);  Add(y,x);
	}
	DFS1(1);  DFS2(1);
	for(int i=1;i<=n;i++)  if(f[i]>f[ans])  ans=i;
	printf("%d",ans);
}
