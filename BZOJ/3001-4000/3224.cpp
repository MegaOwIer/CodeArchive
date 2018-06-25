#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    node *fa,*son[2];
    int val,siz,cnt;
    inline bool dir(){return this==fa->son[1];}
    inline bool cmp(int u){return u>val;}
    node(int val,node* fa):val(val),fa(fa){son[0]=son[1]=0,siz=cnt=1;}
}*root;
int n,f;
char C;
 
inline void read(int& x)
{
    x=0,C=getchar(),f=1;
    while(C<'0'||C>'9'){if(C=='-')f=-1;C=getchar();}
    while(C>='0'&&C<='9')x=x*10+C-'0',C=getchar();x*=f;
}
inline void maintain(node* o)
{
    o->siz=o->cnt;
    for(int i=0;i<2;i++)if(o->son[i])
    {
        o->siz+=o->son[i]->siz;
        o->son[i]->fa=o;
    }
}
inline void rotate(node* o)
{
    node* p=o->fa;
    int d=o->dir();
    p->son[d]=o->son[d^1];
    o->son[d^1]=p,o->fa=p->fa;
    if(o->fa)o->fa->son[p->dir()]=o;
    maintain(p),maintain(o);
}
inline void splay(node* p,node* o)
{
    while(p->fa!=o)
    {
        node* t=p->fa;
        if(t->fa==o)rotate(p);
        else if(t->dir()==p->dir())rotate(t),rotate(p);
        else rotate(p),rotate(p);
    }
    if(!o)root=p;
}
inline void insert(node* &o,int val)
{
    if(!o){o=new node(val,0);return;}
    while(o->son[o->cmp(val)])
    {
        if(o->val==val)break;
        o=o->son[o->cmp(val)];
    }
    if(o->val!=val) o->son[o->cmp(val)]=new node(val,o),o=o->son[o->cmp(val)];
    else o->cnt++;
    splay(o,0);
}
inline void del(int val)
{
    if(!root->son[0]&&!root->son[1]){delete root;return;}
    node* o=root;
    while(o->val!=val)o=o->son[o->cmp(val)];
    splay(o,0);
    if(root->cnt>1){root->cnt--;return;}
    if(root->son[0]&&!root->son[1]){root=root->son[0],root->fa=0;return;}
    if(root->son[1]&&!root->son[0]){root=root->son[1],root->fa=0;return;}
    o=root,o=o->son[0];
    while(o->son[1])o=o->son[1];
    splay(o,0);
    root->son[1]=root->son[1]->son[1];
    maintain(root);
}
inline int getrank(int val)
{
    int ans=0,d;
    node* o;
    for(o=root;(o->val)!=val;o=o->son[d])
    {
        d=o->cmp(val);
        if(d)
        {
            ans+=o->cnt;
            if(o->son[0])ans+=o->son[0]->siz;
        }
    }
    if(o->son[0])ans+=o->son[0]->siz;
    return ans+1;
}
inline int getnum(int rank)
{
    node* o=root;
    while(1)
    {
        if(!o->son[0])
        {
            if(rank<=o->cnt)return o->val;
            else rank-=o->cnt,o=o->son[1];
        }
        else if(rank>(o->cnt)+(o->son[0]->siz))rank-=(o->cnt)+(o->son[0]->siz),o=o->son[1];
        else if(rank>(o->son[0]->siz)) return o->val;
        else o=o->son[0];
    }
}
inline int get(int val,int f)
{
    node* o=root;
    while(o->son[o->cmp(val)])
    {
        if(o->val==val)break;
        o=o->son[o->cmp(val)];
    }
    splay(o,0);
    if(!f)if((root->val)<val)return o->val;
    if(f)if((root->val)>val)return o->val;
    o=o->son[f];
    while(o->son[f^1])o=o->son[f^1];
    return o->val;
}
 
int main()
{
    read(n);
    for(int i=1,x,opt;i<=n;i++)
    {
        read(opt),read(x);
        switch(opt)
        {
            case 1:insert(root,x);break;
            case 2:del(x);break;
            case 3:printf("%d\n",getrank(x));break;
            case 4:printf("%d\n",getnum(x));break;
            case 5:printf("%d\n",get(x,0));break;
            case 6:printf("%d\n",get(x,1));break;
        }
    }
    return 0;
}
