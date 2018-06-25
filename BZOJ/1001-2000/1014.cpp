#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005,P=29,mod=998244353;

int N,M,pw[MX],ipw[MX];
char s[MX],op;
bool fl;
struct Splay
{
    int siz,val,hash;
    Splay *son[2],*fa;
    Splay(int v=0,Splay *f=0):val(v),fa(f),hash(v),siz(1){son[0]=son[1]=NULL;}
    int dir(){return this==fa->son[1];}
    void maintain()
    {
        siz=1,hash=val;
        if(son[0])
        {
            siz+=son[0]->siz;
            hash=((LL)son[0]->hash*P+hash)%mod;
        }
        if(son[1])
        {
            siz+=son[1]->siz;
            hash=((LL)hash*pw[son[1]->siz]+son[1]->hash)%mod;
        }
    }
}*root,*tmp,*stk[MX],**top=stk;

inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void getalpha(char& x){do x=getchar();while(!isalpha(x));}
void build(Splay* &o,int L,int R,Splay *p)
{
    if(L>R)return;
    int mid=L+R>>1;
    o=new Splay(s[mid]-'a',p);
    build(o->son[0],L,mid-1,o);
    build(o->son[1],mid+1,R,o);
    o->maintain();
}
inline void rotate(Splay *o)
{
    Splay *p=o->fa;
    int d=o->dir();
    p->son[d]=o->son[d^1];
    if(p->son[d])p->son[d]->fa=p;
    o->fa=p->fa;
    if(p->fa)o->fa->son[p->dir()]=o;
    o->son[d^1]=p,p->fa=o;
    p->maintain();
}
inline void splay(Splay* o)
{
    static Splay* p;
    while(o->fa)
    {
        p=o->fa;
        if(p->fa)rotate(o->dir()==p->dir()?p:o);
        rotate(o);
    }
    o->maintain(),root=o;
}
inline void insert(char c)
{
    Splay *o=root->son[1];
    if(!o)
    {
    	root->son[1]=new Splay(c-'a',root);
    	root->maintain();
    }
    else
    {
    	*++top=root;
    	while(o->son[0])*++top=o,o=o->son[0];
    	o->son[0]=new Splay(c-'a',o);
    	o->maintain();
    	while(top!=stk)(*top--)->maintain();
    	splay(o->son[0]);
    }
}
inline Splay* Kth(int val)
{
    Splay *o=root;
    while(val)
    {
        if(o->son[0])
        {
            if(o->son[0]->siz>=val)o=o->son[0];
            else if(val==o->son[0]->siz+1)return o;
            else val-=o->son[0]->siz+1,o=o->son[1];
        }
        else
        {
            if(val==1)return o;
            else val--,o=o->son[1];
        }
    }
    return o;
}
inline int gethash(int x)
{
    if(x==1)return root->hash;
    if(x>N)return 0;
    return splay(Kth(x-1)),root->son[1]->hash;
}
inline int solve(int x,int y)
{
    int val1=gethash(x),val2=gethash(y),d1,d2;
    int L=0,R=N-max(x,y)+1,mid,ans;
    while(L<=R)
    {
        mid=L+R>>1;
        d1=gethash(x+mid),d2=gethash(y+mid);
        if((LL)(val1-d1+mod)*ipw[N-x-mid+1]%mod==(LL)(val2-d2+mod)*ipw[N-y-mid+1]%mod)
            ans=mid,L=mid+1;
        else R=mid-1;
    }
    return ans;
}

int main()
{
    pw[0]=ipw[0]=1;
    for(int i=1;i<=100000;i++)pw[i]=(LL)pw[i-1]*P%mod;
    for(int i=1;i<=100000;i++)ipw[i]=(LL)ipw[i-1]*481911067%mod;
    scanf("%s",s+1);
    N=strlen(s+1),build(root,1,N,NULL);
    read(M);
    for(int x,y;M--;)
    {
        getalpha(op),read(x);
        if(op=='R')
        {
            getalpha(op),splay(Kth(x));
            root->val=op-'a',root->maintain();
        }
        else if(op=='I')
        {
            getalpha(op);
            if(x)splay(Kth(x)),insert(op);
            else
            {
                tmp=new Splay(op-'a',0);
                tmp->son[1]=root,root->fa=tmp;
                tmp->maintain(),root=tmp;
            }
            N++;
        }
        else read(y),printf("%d\n",solve(x,y));
    }
    return 0;
}
