#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=30002;

struct edge {int to,next;}s[maxn<<1];
struct node {int l,r,mx,sum;}p[maxn<<2];
int n,tot,head[maxn],w[maxn],q,u,v,siz[maxn],dep[maxn],fa[maxn],mx[maxn];
int pos[maxn],sz,rt[maxn];
bool vis[maxn];
char c[5];

void add(int a,int b)
{
    s[++tot]=(edge){b,head[a]},head[a]=tot;
    s[++tot]=(edge){a,head[b]},head[b]=tot;
}
void dfs(int u)
{
    siz[u]=1;
    for(int i=head[u];i;i=s[i].next)  if(!vis[s[i].to])
    {
        vis[s[i].to]=1;  dep[s[i].to]=dep[u]+1;  fa[s[i].to]=u;
        dfs(s[i].to);
        siz[u]+=siz[s[i].to];
    }
    if(siz[u]>siz[mx[fa[u]]])  mx[fa[u]]=u;
}
void dfs2(int u,int root)
{
    if(!u)  return;
    pos[u]=++sz;  rt[u]=root;
    dfs2(mx[u],root);
    for(int i=head[u];i;i=s[i].next)  if(s[i].to!=fa[u]&&s[i].to!=mx[u])  dfs2(s[i].to,s[i].to);
}
void build(int l,int r,int id)
{
    p[id].l=l,p[id].r=r;
    if(l==r)  return;
    int mid=l+r>>1;
    build(l,mid,id<<1),build(mid+1,r,id<<1|1);
}
void insert(int l,int w,int id)
{
    if(p[id].l==p[id].r)  {p[id].mx=p[id].sum=w;  return;}
    int mid=p[id].l+p[id].r>>1;
    if(l<=mid)  insert(l,w,id<<1);
    else  insert(l,w,id<<1|1);
    p[id].sum=p[id<<1].sum+p[id<<1|1].sum;
    p[id].mx=max(p[id<<1].mx,p[id<<1|1].mx);
}
int ask_sum(int l,int r,int id)
{
    if(l>r)  swap(l,r);
    if(p[id].l==l&&p[id].r==r)  return p[id].sum;
    int mid=p[id].l+p[id].r>>1;
    if(mid>=r)  return ask_sum(l,r,id<<1);
    else  if(mid<l)  return ask_sum(l,r,id<<1|1);
          else  return ask_sum(l,mid,id<<1)+ask_sum(mid+1,r,id<<1|1);
}
int ask_max(int l,int r,int id)
{
    if(l>r)  swap(l,r);
    if(p[id].l==l&&p[id].r==r)  return p[id].mx;
    int mid=p[id].l+p[id].r>>1;
    if(mid>=r)  return ask_max(l,r,id<<1);
    else  if(mid<l)  return ask_max(l,r,id<<1|1);
          else  return max(ask_max(l,mid,id<<1),ask_max(mid+1,r,id<<1|1));
}
void ssum(int u,int v)
{
    int sum=0;
    while(rt[u]!=rt[v])
    {
        if(dep[rt[u]]<dep[rt[v]])  swap(u,v);
        sum+=ask_sum(pos[rt[u]],pos[u],1);
        u=fa[rt[u]];
    }
    if(dep[u]<dep[v])  swap(u,v);
    sum+=ask_sum(pos[v],pos[u],1);
    printf("%d\n",sum);
}
void smax(int u,int v)
{
    int ans=-1000000;
    while(rt[u]!=rt[v])
    {
        if(dep[rt[u]]<dep[rt[v]])  swap(u,v);
        ans=max(ans,ask_max(pos[rt[u]],pos[u],1));
        u=fa[rt[u]];
    }
    if(dep[u]<dep[v])  swap(u,v);
    ans=max(ans,ask_max(pos[v],pos[u],1));
    printf("%d\n",ans);
}

int main()
{
    scanf("%d",&n);  vis[1]=1;
    for(int i=1,a,b;i<n;i++)  {scanf("%d%d",&a,&b);  add(a,b);}
    for(int i=1;i<=n;i++)  scanf("%d",w+i);
    dfs(1),dfs2(1,1),build(1,n,1);
    for(int i=1;i<=n;i++)  insert(pos[i],w[i],1);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%s%d%d",c,&u,&v);
        if(c[1]=='M')  smax(u,v);
        else  if(c[1]=='S')  ssum(u,v);
              else  w[u]=v,insert(pos[u],v,1);
    }
    return 0;
}
