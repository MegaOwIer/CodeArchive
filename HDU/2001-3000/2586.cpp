#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define clear(a) memset(a,0,sizeof(a))

struct side {int to,next,w;}s[80001];
int n,m,fa[40010][20],T,head[40010],tot,dep[40010];
long long dis[40010];

inline void reset()
{
    clear(s);  clear(dep);
    clear(fa);  clear(head);
    tot=0;  fa[1][0]=n+1;
}
void add(int a,int b,int w)
{
    s[++tot].to=b;s[tot].next=head[a];s[tot].w=w;head[a]=tot;
    s[++tot].to=a;s[tot].next=head[b];s[tot].w=w;head[b]=tot;
}
void dfs(int u)
{
    for(int i=head[u];i;i=s[i].next)  if(s[i].to!=fa[u][0])
    {
        dis[s[i].to]=dis[u]+s[i].w;
        dep[s[i].to]=dep[u]+1;
        fa[s[i].to][0]=u;
        dfs(s[i].to);
    }
}
void init()
{
    for(int i=1;(1<<i)<=n;i++)  for(int j=1;j<=n;j++)
    {
        if((1<<i)>=dep[j])  continue;
        fa[j][i]=fa[fa[j][i-1]][i-1];
    }
}
int lca(int a,int b)
{
    if(dep[a]<dep[b])  swap(a,b);
    for(int j=15;j>=0;j--)  if(dep[a]-(1<<j)>=dep[b])  a=fa[a][j];
    if(a==b)  return a;
    for(int j=15;j>=0;j--)  if(fa[a][j]!=fa[b][j])  a=fa[a][j],b=fa[b][j];
    return fa[a][0];
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        reset();
        for(int i=1,a,b,w;i<n;i++)  {scanf("%d%d%d",&a,&b,&w);  add(a,b,w);}
        dfs(1);  init();
        for(int i=1,a,b;i<=m;i++)  {scanf("%d%d",&a,&b);  printf("%lld\n",dis[a]+dis[b]-2*dis[lca(a,b)]);}
    }
    return 0;
}
