#include<bits/stdc++.h>
using namespace std;
const int MX=30005;

struct Splay
{
	Splay *fa,*son[2];
	int val,sum;
	bool rev;
	Splay():fa(0){son[0]=son[1]=NULL;}
	void setv(int v){val=v,maintain();}
	bool isroot(){return !fa||fa->son[0]!=this&&fa->son[1]!=this;}
	int dir(){return this==fa->son[1];}
	void maintain()
	{
		sum=val;
		if(son[0])sum+=son[0]->sum;
		if(son[1])sum+=son[1]->sum;
	}
	void pushdown()
	{
		if(rev)
		{
			swap(son[0],son[1]);
			if(son[0])son[0]->rev^=1;
			if(son[1])son[1]->rev^=1;
		}
		rev=0;
	}
}Node[MX],*stk[MX],**top=stk;
int N,M;
char op;

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline Splay* findroot(Splay *o)
{
	while(o->fa)o=o->fa;
	return o;
}
inline void rotate(Splay *o)
{
	Splay *p=o->fa;
	int d=o->dir();
	p->son[d]=o->son[d^1];
	if(p->son[d])p->son[d]->fa=p;
	o->fa=p->fa;
	if(!p->isroot())p->fa->son[p->dir()]=o;
	p->fa=o,o->son[d^1]=p;
	p->maintain();
}
inline void splay(Splay *u)
{
	static Splay *o;
	o=u;
	while(!o->isroot())*++top=o,o=o->fa;
	*++top=o;
	while(top!=stk)(*top--)->pushdown();
	while(!u->isroot())
	{
		o=u->fa;
		if(!o->isroot())rotate(o->dir()==u->dir()?o:u);
		rotate(u);
	}
	u->maintain();
}
inline void access(Splay *u)
{
	for(Splay *p=0;u;p=u,u=u->fa)
		splay(u),u->son[1]=p,u->maintain();
}
inline void makeroot(Splay *u){access(u),splay(u),u->rev^=1;}
inline void link(Splay *u,Splay *v){makeroot(v),v->fa=u;}

int main()
{
	read(N);
	for(int i=1,u;i<=N;i++)read(u),Node[i].setv(u);
	read(M);
	for(int x,y;M--;)
	{
		do op=getchar();while(!isalpha(op));
		read(x),read(y);
		if(op=='b')
		{
			if(findroot(Node+x)==findroot(Node+y))puts("no");
			else puts("yes"),link(Node+x,Node+y);
		}
		else if(op=='p')splay(Node+x),Node[x].setv(y);
		else
		{
			if(findroot(Node+x)!=findroot(Node+y))puts("impossible");
			else makeroot(Node+x),access(Node+y),splay(Node+y),printf("%d\n",Node[y].sum);
		}
	}
	return 0;
}
