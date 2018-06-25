#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int MX=100005;

class FastIO
{
private:
    static const int MXL=200000;
    char IBF[MXL],*p1,*p2,c;
    FILE *I;
    char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
public:
    FastIO(FILE *I):I(I),p1(IBF),p2(IBF){}
    template<typename T>void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
}IO(stdin);
#define read(x) IO.read(x)

int n,m,cnt;
ULL seed=time(NULL),sum,val;
struct Splay
{
    ULL val,sum;
    bool rev;
    Splay *son[2],*fa;
    Splay():val(0),sum(0),rev(0),fa(NULL){son[0]=son[1]=NULL;}
    void maintain()
    {
        sum=val;
        if(son[0])sum^=son[0]->sum;
        if(son[1])sum^=son[1]->sum;
    }
    bool isroot(){return !fa||(fa->son[0]!=this&&fa->son[1]!=this);}
    bool dir(){return fa->son[1]==this;}
    void pushdown()
    {
        if(!rev)return;
        swap(son[0],son[1]);
        if(son[0])son[0]->rev^=1;
        if(son[1])son[1]->rev^=1;
        rev=0;
    }
}p[MX],*stk[MX],**top=stk;
typedef pair<pair<int,int>,ULL> Path;
Path RD[MX*3];
#define mp make_pair
#define st first
#define nd second

inline ULL rd(){return seed=(seed<<5)^(seed>>13)^(seed<<27);}
inline void rotate(Splay *o)
{
    static Splay *p;
    static int d;
    d=o->dir(),p=o->fa;
    o->fa=p->fa;
    if(!p->isroot())p->fa->son[p->dir()]=o;
    p->son[d]=o->son[d^1];
    if(o->son[d^1])o->son[d^1]->fa=p;
    o->son[d^1]=p,p->fa=o;
    p->maintain();
}
inline void splay(Splay *u)
{
    static Splay *o;
    *++top=u;
    for(o=u;!o->isroot();o=o->fa)*++top=o->fa;
    while(top!=stk)(*top--)->pushdown();
    while(!u->isroot())
    {
		o=u->fa;
		if(!o->isroot())
			if(u->dir()==o->dir())rotate(o);
			else rotate(u);
		rotate(u);
	}
	u->maintain();
}
inline void access(Splay *u)
{
    for(Splay *t=NULL;u;t=u,u=u->fa)
    {
        splay(u);
        u->val^=t?t->sum:0;
        u->val^=u->son[1]?u->son[1]->sum:0;
        u->son[1]=t,u->maintain();
    }
}
inline void makeroot(Splay *u){access(u),splay(u),u->rev^=1;}
inline void link(Splay *u,Splay *v)
{
    makeroot(u),makeroot(v);
    u->fa=v,v->val^=u->sum,v->sum^=u->sum;
}
inline void cut(Splay *u,Splay *v)
{
    makeroot(u),access(v),splay(v);
    v->sum^=u->sum,v->son[0]=u->fa=NULL;
}
inline void work(Splay *u){makeroot(u),u->val^=val,u->maintain();}

int main()
{
	read(n),read(n),read(m);
	for(int i=1,u,v;i<n;i++)read(u),read(v),link(&p[u],&p[v]);
	for(int op,x,y;m--;)
    {
        read(op);
        if(op==1)
        {
            read(x),read(y),cut(&p[x],&p[y]);
            read(x),read(y),link(&p[x],&p[y]);
        }
        else if(op==2)
        {
            read(x),read(y),val=rd(),sum^=val;
            RD[++cnt]=mp(mp(x,y),val);
            work(&p[x]),work(&p[y]);
        }
        else if(op==3)
        {
            read(x),val=RD[x].nd,sum^=val;
            work(&p[RD[x].st.st]),work(&p[RD[x].st.nd]);
        }
        else
        {
            read(x),read(y);
            makeroot(&p[x]),access(&p[y]),splay(&p[y]);
            puts(p[y].val==sum?"YES":"NO");
        }
    }
    return 0;
}
