#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

char Pool[150000000],*p=Pool;
inline void* operator new (size_t siz){return (p+=siz)-siz;}
inline void operator delete(void*){}

class FastIO
{
private:
    static const int MXL=200000;
    char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c;
    char *const ED;
    int tp,bf[22];
    FILE *I,*O;
    char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
    void putchar(char c){if(p3==ED)flush();*p3++=c;}
    void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
public:
    FastIO(FILE *I,FILE *O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),ED(OBF+MXL){}
    ~FastIO(){flush();}
    template<typename T>void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>void write(T x)
    {
        bf[tp=1]='\n'-48;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
    }
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

struct edge{int to,nxt;}e[MX<<1];
int n,m,head[MX],tot,fa[MX][18],dep[MX],O,siz[MX],mxsz[MX],pre[MX],ans,d[MX],val[MX],totsiz;
bool vis[MX];
struct Segment
{
    int sum;
    Segment *l,*r;
    Segment():sum(0),l(NULL),r(NULL){}
}*root[MX][2];

inline void add(int u,int v)
{
    e[++tot]=(edge){v,head[u]},head[u]=tot;
    e[++tot]=(edge){u,head[v]},head[v]=tot;
}
void dfs1(int u,int f)
{
    for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)
        dep[e[i].to]=dep[u]+1,fa[e[i].to][0]=u,dfs1(e[i].to,u);
}
void getG(int u,int f)
{
    siz[u]=1,mxsz[u]=0;
    for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f&&!vis[e[i].to])
    {
        getG(e[i].to,u);
        siz[u]+=siz[e[i].to];
        mxsz[u]=max(mxsz[u],siz[e[i].to]);
    }
    mxsz[u]=max(mxsz[u],totsiz-siz[u]);
    if(mxsz[u]<mxsz[O])O=u;
}
void insert(Segment* &o,int pos,int val,int L,int R)
{
    if(!o)o=new Segment;
    o->sum+=val;
    if(L==R)return;
    int mid=L+R>>1;
    if(pos<=mid)insert(o->l,pos,val,L,mid);
    else insert(o->r,pos,val,mid+1,R);
}
void dfs2(Segment* &o,int u,int f)
{
    insert(o,d[u],val[u],0,n);
    for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f&&!vis[e[i].to])
        d[e[i].to]=d[u]+1,dfs2(o,e[i].to,u);
}
void work(int u)
{
    vis[u]=1,d[u]=0,dfs2(root[u][0],u,-1);
    for(int i=head[u];i;i=e[i].nxt)if(!vis[e[i].to])
    {
        d[e[i].to]=1,O=0,totsiz=siz[e[i].to],getG(e[i].to,-1);
        dfs2(root[O][1],e[i].to,u),pre[O]=u,work(O);
    }
}
inline int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=16;dep[u]-dep[v];i--)if(dep[u]-dep[v]>=1<<i)u=fa[u][i];
    if(u==v)return u;
    for(int i=16;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
inline void update(int u,int k)
{
    int del=k-val[u],cn;
    val[u]=k,insert(root[u][0],0,del,0,n);
    for(int i=u;pre[i];i=pre[i])
    {
        cn=dep[u]+dep[pre[i]]-2*dep[lca(u,pre[i])];
        insert(root[pre[i]][0],cn,del,0,n);
        insert(root[i][1],cn,del,0,n);
    }
}
int query(Segment *o,int l,int r,int L,int R)
{
    if(!o)return 0;
    if(L==l&&r==R)return o->sum;
    int mid=L+R>>1;
    if(r<=mid)return query(o->l,l,r,L,mid);
    else if(l>mid)return query(o->r,l,r,mid+1,R);
    else return query(o->l,l,mid,L,mid)+query(o->r,mid+1,r,mid+1,R);
}
inline int ask(int u,int k)
{
    int ans=query(root[u][0],0,k,0,n),cn;
    for(int i=u;pre[i];i=pre[i])
    {
        cn=dep[u]+dep[pre[i]]-2*dep[lca(u,pre[i])];
        ans-=query(root[i][1],0,k-cn,0,n);
        ans+=query(root[pre[i]][0],0,k-cn,0,n);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    read(n),read(m),mxsz[0]=n;
    for(int i=1;i<=n;i++)read(val[i]);
    for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
    dfs1(1,-1),totsiz=n,getG(1,-1),work(O);
    for(int i=1,op,x,y;i<=m;i++)
    {
        read(op),read(x),read(y);
        x^=ans,y^=ans;
        if(op)update(x,y);
        else write(ans=ask(x,y));
    }
    return 0;
}