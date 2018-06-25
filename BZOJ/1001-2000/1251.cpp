#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
    static char c;
    static int f;
    template<typename T>
    inline void read(T& x)
    {
        x=0,c=getchar(),f=1;
        while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
        while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
    }
}
using FastIO::read;
typedef long long LL;
const int maxn=50005;
 
struct Node
{
    int siz;
    LL val,mx,tag;
    bool rev;
    Node *son[2],*fa;
    Node(){siz=val=mx=tag=rev=0,son[0]=son[1]=fa=NULL;}
    Node(Node* _)
    {
        siz=1,fa=_;
        son[0]=son[1]=NULL;
        rev=val=mx=tag=0;
    }
    inline bool dir(){return this==fa->son[1];}
    inline void add(int _){val+=_,mx+=_,tag+=_;}
    inline void reverse(){swap(son[0],son[1]),rev^=1;}
    inline void maintain()
    {
        siz=1,mx=val;
        for(int i=0;i<2;i++)if(son[i])
            siz+=son[i]->siz,mx=max(mx,son[i]->mx);
    }
    inline void pushdown()
    {
        if(rev)for(int i=0;i<2;i++)if(son[i])son[i]->reverse();
        if(tag)for(int i=0;i<2;i++)if(son[i])son[i]->add(tag);
        rev=tag=0;
    }
}*root,*tmp;
int n,m;
 
inline void rotate(Node* o)
{
    int d=o->dir();
    Node* p=o->fa;
    o->fa=p->fa;
    if(p->fa)p->fa->son[p->dir()]=o;
    p->son[d]=o->son[d^1];
    if(o->son[d^1])o->son[d^1]->fa=p;
    o->son[d^1]=p,p->fa=o;
    p->maintain(),o->maintain();
}
inline void pushdown(Node* o)
{
    if(o->fa)pushdown(o->fa);
    o->pushdown();
}
inline void splay(Node* o,Node* &f)
{
    pushdown(o);
    Node *gf=f->fa,*tmp;
    while(o->fa!=gf)
    {
        tmp=o->fa;
        if(tmp->fa!=gf)rotate((o->dir()==tmp->dir())?tmp:o);
        rotate(o);
    }
    o->maintain(),f=o;
}
inline Node* getnode(Node* o,int _)
{
    int s;
    while(o)
    {
        o->pushdown(),s=1;
        if(o->son[0])s+=o->son[0]->siz;
        if(_==s)return o;
        else if(_>s)_-=s,o=o->son[1];
        else o=o->son[0];
    }
    return o;
}
inline Node* getnode(int l,int r)
{
    if(r==n)
    {
        if(l==1)return root;
        else return splay(getnode(root,l-1),root),root->son[1];
    }
    else
    {
        splay(getnode(root,r+1),root);
        if(l==1)return root->son[0];
        splay(getnode(root->son[0],l-1),root->son[0]);
        return root->son[0]->son[1];
    }
}
void build(Node* &o,Node* f,int l,int r)
{
    if(l>r)return;
    o=new Node(f);
    int mid=l+r>>1;
    build(o->son[0],o,l,mid-1),build(o->son[1],o,mid+1,r);
    o->maintain();
}
 
int main()
{
    read(n),read(m),build(root,NULL,1,n);
    for(int i=1,k,l,r,v;i<=m;i++)
    {
        read(k),read(l),read(r),tmp=getnode(l,r);
        if(k==1)read(v),tmp->add(v);
        else if(k==2)tmp->reverse();
        else printf("%lld\n",tmp->mx);
    }
    return 0;
}