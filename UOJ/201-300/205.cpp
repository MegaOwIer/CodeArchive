#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=600005;

int N,M,fa[MX],w[MX],deg[MX];
LL ans,a,b;

struct Node
{
    Node *l,*r;
    int dis;
    LL val;
    Node(LL v=0):dis(1),val(v),l(NULL),r(NULL){}
    void* operator new(size_t);
}*RT[MX];
inline void* Node::operator new(size_t)
{
    static Node Pool[MX],*ptr=Pool;
    assert(prt!=Pool+MX);
    return ptr++;
}

inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
Node* merge(Node *x,Node *y)
{
    if(!x)return y;
    if(!y)return x;
    if(x->val<y->val)swap(x,y);
    x->r=merge(x->r,y);
    if(!x->l||x->l->dis<x->r->dis)swap(x->l,x->r);
    x->dis=x->r?x->r->dis+1:1;
    return x;
}

int main()
{
    read(N),read(M);
    for(int i=2;i<=N+M;i++)
        read(fa[i]),read(w[i]),deg[fa[i]]++,ans+=w[i];
    for(int i=N+M;i>N;i--)
    {
        RT[i]=merge(new Node(w[i]),new Node(w[i]));
        RT[fa[i]]=merge(RT[fa[i]],RT[i]);
    }
    for(int i=N;i>=2;i--)
    {
        while(--deg[i])RT[i]=merge(RT[i]->l,RT[i]->r);
        a=RT[i]->val;
        RT[i]=merge(RT[i]->l,RT[i]->r);
        b=RT[i]->val;
        RT[i]=merge(merge(RT[i]->l,RT[i]->r),merge(new Node(a+w[i]),new Node(b+w[i])));
        RT[fa[i]]=merge(RT[fa[i]],RT[i]);
    }
    while(deg[1]--)RT[1]=merge(RT[1]->l,RT[1]->r);
    while(RT[1])ans-=RT[1]->val,RT[1]=merge(RT[1]->l,RT[1]->r);
    printf("%lld\n",ans);
    return 0;
}