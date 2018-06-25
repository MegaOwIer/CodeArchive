#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=500005;

struct edge {int to,next;}s[maxn<<1];
int n,m,tot,head[maxn],fa[maxn][25],dep[maxn],flag[maxn];
bool vis[maxn];

inline void add(int a,int b)
{
    s[++tot].to=b,s[tot].next=head[a],head[a]=tot;
    s[++tot].to=a,s[tot].next=head[b],head[b]=tot;
}
void dfs(int u)
{
    for(int i=head[u];i;i=s[i].next)  if(!vis[s[i].to])
    {
        vis[s[i].to]=1;
        dep[s[i].to]=dep[u]+1;
        fa[s[i].to][0]=u;
        dfs(s[i].to);
    }
}
void init()
{
    for(int j=1;j<=19;j++)  for(int i=1;i<=n;i++)
    {
        if(dep[i]<(1<<j))  continue;
        fa[i][j]=fa[fa[i][j-1]][j-1];
    }
}
inline int lca(int u,int v)
{
    if(dep[u]<dep[v])  swap(u,v);
    for(int i=19;dep[u]!=dep[v];i--)  if(dep[u]-(1<<i)>=dep[v])  u=fa[u][i];
    if(u==v)  return u;
    for(int i=19;i>=0;i--)  if(fa[u][i]!=fa[v][i])  u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
inline int dist(int u,int v) {return dep[u]+dep[v]-dep[lca(u,v)]*2;}
inline int dis(int u,int a,int b,int c) {return dist(a,u)+dist(b,u)+dist(c,u);}

int main()
{
    scanf("%d%d",&n,&m);  vis[1]=1;
    for(int i=1,a,b;i<n;i++)  {scanf("%d%d",&a,&b);  add(a,b);}
    dfs(1);  init();
    for(int i=1,a,b,c;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        int f[4]={0,lca(a,b),lca(a,c),lca(c,b)};
        if(f[1]==f[2])  printf("%d %d\n",f[3],dis(f[3],a,b,c));
        else if(f[1]==f[3])  printf("%d %d\n",f[2],dis(f[2],a,b,c));
        else if(f[3]==f[2])  printf("%d %d\n",f[1],dis(f[1],a,b,c));
    }
    return 0;
}
