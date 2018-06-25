#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005,N=16;

namespace FastIO
{
	char c;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;

int n,m,C[N][N];
LL fac[N];
double a,b,pwa[N],pwb[N];
struct Node
{
	double v[N],x[N];
	int siz,rev;
	Node *son[2],*fa;
	
	Node():siz(1),rev(0),fa(NULL){son[0]=son[1]=NULL;}
	int dir(){return this==fa->son[1];}
	bool isroot(){return !fa||(fa->son[0]!=this&&fa->son[1]!=this);}
	void maintain()
	{
		siz=1,memcpy(x,v,sizeof(x));
		for(int i=0;i<2;i++)if(son[i])
		{
			siz+=son[i]->siz;
			for(int j=0;j<N;j++)x[j]+=son[i]->x[j];
		}
	}
	void calculate(int tp,double a,double b)
	{
		memset(v,0,sizeof(v));
		if(tp==3)v[0]=b,v[1]=a;
		else
		{
			pwa[0]=pwb[0]=1;
			for(int i=1;i<N;i++)pwa[i]=pwa[i-1]*a,pwb[i]=pwb[i-1]*b;
			if(tp&1)for(int i=1,f=1,j;i<N;i+=2,f=-f)for(j=0;j<=i;j++)
				v[j]+=f*pwa[j]*pwb[i-j]*C[i][j]/fac[i];
			else for(int i=0,j;i<N;i++)for(j=0;j<=i;j++)
				v[j]+=pwa[j]*pwb[i-j]*C[i][j]/fac[i];
		}
		maintain();
	}
	void pushdown()
	{
		if(!rev)return;
		swap(son[1],son[0]);
		for(int i=0;i<2;i++)if(son[i])son[i]->rev^=1;
		rev=0;
	}
	void getval(double S)
	{
		double ans=0,cc=1;
		for(int i=0;i<N;i++,cc*=S)ans+=x[i]*cc;
		printf("%.8le\n",ans);
	}
}*s[MX],*sta[MX],**top=sta;
char op;

inline Node* find(Node *o)
{
	while(o->fa)o=o->fa;
	return o;
}
inline void rotate(Node* o)
{
	Node* p=o->fa;
	int d=o->dir();
	p->son[d]=o->son[d^1];
	if(o->son[d^1])o->son[d^1]->fa=p;
	o->fa=p->fa;
	if(!p->isroot())p->fa->son[p->dir()]=o;
	p->fa=o,o->son[d^1]=p;
	p->maintain();
}
inline void Splay(Node *x)
{
	*++top=x;
	for(Node *o=x;!o->isroot();o=o->fa)*++top=o->fa;
	while(top!=sta)(*top--)->pushdown();
	static Node *y;
	while(!x->isroot())
	{
		y=x->fa;
		if(!y->isroot())
		{
			if(x->dir()==y->dir())rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	x->maintain();
}
inline void access(Node *x){for(Node *y=NULL;x;y=x,x=x->fa)Splay(x),x->son[1]=y,x->maintain();}
inline void makeroot(Node *u){access(u),Splay(u),u->rev^=1;}
inline void link(Node *u,Node *v){makeroot(u),u->fa=v;}
inline void cut(Node *u,Node *v){makeroot(u),access(v),Splay(v),v->son[0]=u->fa=NULL,v->maintain();}

int main()
{
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
	for(int i=0;i<N;i++)C[i][0]=1;
	for(int i=1;i<N;i++)for(int j=1;j<=i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
	read(n),read(m),read(a);
	for(int i=1,tp;i<=n;i++)
	{
		read(tp),scanf("%lf%lf",&a,&b);
		s[i]=new Node();
		s[i]->calculate(tp,a,b);
	}
	for(int i=1,u,v;i<=m;i++)
	{
		do op=getchar();while(!isalpha(op));
		read(u),read(v);
		if(op=='a')link(s[u+1],s[v+1]);
		else if(op=='d')cut(s[u+1],s[v+1]);
		else if(op=='m')u++,Splay(s[u]),scanf("%lf%lf",&a,&b),s[u]->calculate(v,a,b);
		else
		{
			u++,v++,scanf("%lf",&a);
			if(find(s[u])!=find(s[v]))puts("unreachable");
			else makeroot(s[u]),access(s[v]),Splay(s[v]),s[v]->getval(a);
		}
	}
	return 0;
}
