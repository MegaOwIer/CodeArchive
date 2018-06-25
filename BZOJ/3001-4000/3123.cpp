#include<bits/stdc++.h>
using namespace std;
const int MX=80005;
 
struct nulltag{};
struct edge{int to,nxt;}e[MX<<1];
int N,M,T,val[MX],head[MX],tot,fa[18][MX],lastans,dep[MX];
char op;
struct UFS
{
    UFS *fa;
    int siz;
    UFS():fa(this),siz(1){}
    UFS* Root()
    {
        UFS *a=this;
        while(a->fa!=a)a=a->fa;
        return a;
    }
}*s[MX];
struct Segment
{
    Segment *l,*r;
    int val;
    Segment(int);
    Segment(nulltag):l(this),r(this),val(0){}
}*null=new Segment(nulltag()),*RT[MX];
 
inline Segment::Segment(int v=0):l(null),r(null),val(v){}
 
inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v)
{
    e[++tot]=(edge){v,head[u]},head[u]=tot;
    e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void Union(UFS* a,UFS* b)
{
    a=a->Root(),b=b->Root();
    if(a->siz<b->siz)swap(a,b);
    b->fa=a,a->siz+=b->siz;
}
inline void insert(Segment* &o,Segment *p,int pos,int L,int R)
{
    o=new Segment(p->val+1);
    if(L==R)return;
    int mid=L+R>>1;
    if(pos<=mid)insert(o->l,p->l,pos,L,mid),o->r=p->r;
    else insert(o->r,p->r,pos,mid+1,R),o->l=p->l;
}
inline void dfs(int u,int f)
{
    dep[u]=dep[f]+1,fa[0][u]=f;
    for(int i=1;i<=16;i++)fa[i][u]=fa[i-1][fa[i-1][u]];
    insert(RT[u],RT[f],val[u],0,1e9);
    for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)dfs(e[i].to,u);
}
inline int LCA(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=16;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[i][u];
    if(u==v)return u;
    for(int i=16;~i;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
    return fa[0][u];
}
inline int query(Segment *a,Segment *b,Segment *c,Segment *d,int k,int L,int R)
{
    if(L==R)return L;
    int V=a->l->val+b->l->val-c->l->val-d->l->val,mid=L+R>>1;
    if(V>=k)return query(a->l,b->l,c->l,d->l,k,L,mid);
    else return query(a->r,b->r,c->r,d->r,k-V,mid+1,R);
}
inline int ask(int u,int v,int k)
{
    int f=LCA(u,v);
    return query(RT[u],RT[v],RT[f],RT[fa[0][f]],k,0,1e9);
}
 
int main()
{
    read(N),read(N),read(M),read(T);
    for(int i=1;i<=N;i++)s[i]=new UFS;
    for(int i=1;i<=N;i++)read(val[i]);
    for(int i=1,u,v;i<=M;i++)
    {
        read(u),read(v);
        add(u,v),Union(s[u],s[v]);
    }
    RT[0]=null;
    for(int i=1;i<=N;i++)if(!fa[0][i])dfs(i,0);
    for(int i=1,x,y,k;i<=T;i++)
    {
        do op=getchar();while(!isalpha(op));
        read(x),read(y),x^=lastans,y^=lastans;
        if(op=='Q')
        {
            read(k),k^=lastans;
            printf("%d\n",lastans=ask(x,y,k));
        }
        else
        {
            if(s[x]->Root()->siz>s[y]->Root()->siz)swap(x,y);
            dfs(x,y),Union(s[x],s[y]),add(x,y);
        }
    }
    return 0;
}
