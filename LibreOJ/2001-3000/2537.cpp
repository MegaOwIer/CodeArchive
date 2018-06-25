#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=300005,mod=998244353;

int N,val[MX],M,ls[MX],Pa,Pb;
vector<int> son[MX];

struct Segment
{
    Segment *l,*r;
    int sum,tag;
    Segment(int v=0):l(0),r(0),sum(v),tag(1){}
    void* operator new (size_t);
    void modify(int val){sum=(LL)sum*val%mod,tag=(LL)tag*val%mod;}
    void pushdown()
    {
        if(l)l->modify(tag);
        if(r)r->modify(tag);
        tag=1;
    }
}*RT[MX];
inline void* Segment::operator new (size_t)
{
    static Segment Pool[MX*20],*ptr=Pool;
    return ptr++;
}

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void insert(Segment* &o,int pos,int L,int R)
{
    o=new Segment(1);
    if(L==R)return;
    int mid=L+R>>1;
    if(pos<=mid)insert(o->l,pos,L,mid);
    else insert(o->r,pos,mid+1,R);
}
Segment* merge(Segment *o,Segment *p,int P_max)
{
    if(!o&&!p)return NULL;
    if(!o)
    {
        p->pushdown();
        Pb=(Pb+p->sum)%mod;
        p->modify((Pa+P_max-2LL*Pa*P_max%mod+mod)%mod);
        return p;
    }
    if(!p)
    {
        o->pushdown();
        Pa=(Pa+o->sum)%mod;
        o->modify((Pb+P_max-2LL*Pb*P_max%mod+mod)%mod);
        return o;
    }
    o->pushdown(),p->pushdown();
    o->r=merge(o->r,p->r,P_max),o->l=merge(o->l,p->l,P_max);
    o->sum=((o->l?o->l->sum:0)+(o->r?o->r->sum:0))%mod;
    return o;
}
void dfs(int u)
{
    if(!son[u].size())
        return insert(RT[u],val[u],1,M);
    for(int i:son[u])dfs(i);
    if(son[u].size()==1)RT[u]=RT[son[u][0]];
    else Pa=Pb=0,RT[u]=merge(RT[son[u][0]],RT[son[u][1]],val[u]);
}
int dfs(Segment *o,int L,int R)
{
    if(!o)return 0;
    if(L==R)return (LL)L*ls[L]%mod*o->sum%mod*o->sum%mod;
    o->pushdown();
    int mid=L+R>>1;
    return (dfs(o->l,L,mid)+dfs(o->r,mid+1,R))%mod;
}

int main()
{
    N=read();
    for(int i=1;i<=N;i++)
        son[read()].push_back(i);
    for(int i=1;i<=N;i++)
        if(son[i].empty())ls[++M]=val[i]=read();
        else val[i]=read()*796898467LL%mod;
    sort(ls+1,ls+M+1);
    for(int i=1;i<=N;i++)if(son[i].empty())
        val[i]=lower_bound(ls+1,ls+M+1,val[i])-ls;
    dfs(1);
    printf("%d\n",dfs(RT[1],1,M));
    return 0;
}
