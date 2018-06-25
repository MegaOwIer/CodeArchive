#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,M,SG[MX];
char vis[MX];
vector<int> G[MX];

struct Node
{
    Node *son[2];
    int siz,tag;

    Node(int s=0):siz(s),tag(0){son[0]=son[1]=NULL;}
    void* operator new (size_t);
    void pushdown(int dep)
    {
        if((tag>>dep)&1)swap(son[0],son[1]);
        for(int i=0;i<2;i++)if(son[i])son[i]->tag^=tag;
        tag=0;
    }
}*TR[MX];
Node Pool[MX*20],*ptr;
inline void* Node::operator new (size_t){return ptr++;}

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void insert(Node* &o,int val,int dep)
{
    o=new Node(1);
    if(dep>=0)insert(o->son[(val>>dep)&1],val,dep-1);
}
Node* merge(Node *o,Node *p,int dep)
{
    if(!o||!p)return o?o:p;
    if(!dep)
    {
        o->siz=2;
        return o;
    }
    o->pushdown(dep);
    p->pushdown(dep);
    for(int i=0;i<2;i++)
        o->son[i]=merge(o->son[i],p->son[i],dep-1);
    o->siz=(o->son[0]?o->son[0]->siz:0)+(o->son[1]?o->son[1]->siz:0);
    return o;
}
void dfs(int u,int f)
{
    typedef vector<int>::iterator Vit;
    vis[u]=1;
    int tmp=0;
    for(Vit it=G[u].begin();it!=G[u].end();++it)
        if(*it!=f)dfs(*it,u),tmp^=SG[*it];
    insert(TR[u],tmp,16);
    for(Vit it=G[u].begin();it!=G[u].end();++it)
        if(*it!=f)TR[*it]->tag=tmp^SG[*it],TR[u]=merge(TR[u],TR[*it],16);
    SG[u]=0;
    Node *o=TR[u];
    for(int i=16;o&&i>=0;i--)
        if(o->son[0]&&o->son[0]->siz==(1<<i))SG[u]|=1<<i,o=o->son[1];
        else o=o->son[0];
}

int main()
{
    for(int T=read();T--;)
    {
        N=read(),M=read(),ptr=Pool;
        for(int i=1;i<=N;i++)G[i].clear();
        memset(vis+1,0,sizeof(char)*N);
        for(int i=1,u,v;i<=M;i++)
            u=read(),v=read(),G[u].push_back(v),G[v].push_back(u);
        int ans=0;
        for(int i=1;i<=N;i++)if(!vis[i])dfs(i,0),ans^=SG[i];
        puts(ans?"Alice":"Bob");
    }
    return 0;
}
