#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
#define st first
#define nd second
#define calc(x) ((LL)(x)*((x)+1)>>1)

struct Treap
{
	Treap* son[2];
	int siz,h,tag;
	LL sum;
	Treap():siz(1),h(0),tag(0),sum(0){son[0]=son[1]=NULL;}
	inline void ins(int _){h+=_,tag+=_;} 
	inline void maintain()
	{
		siz=1,sum=0;
		for(int i=0;i<2;i++)if(son[i])
			siz+=son[i]->siz,sum+=son[i]->sum+calc(son[i]->siz)*(son[i]->h-h);
	}
	inline void pushdown()
	{
		if(!tag)return;
		for(int i=0;i<2;i++)if(son[i])son[i]->ins(tag);
		tag=0;
	}
}*root;
int R,C,N;
pair<int,int> p[100005];
LL ans;

void build(Treap* &o,int l,int r)
{
	if(l>r)return;
	o=new Treap;
	int mid=l+r>>1;
	build(o->son[0],l,mid-1),build(o->son[1],mid+1,r);
	o->maintain();
}
inline void rotate(Treap* &o,int d)
{
	Treap* tmp=o->son[d];
	o->son[d]=tmp->son[d^1],tmp->son[d^1]=o;
	o->maintain(),tmp->maintain(),o=tmp; 
}
void insert(Treap* &o,int x)
{
	o->pushdown();
	int tmp=1+(o->son[0]?o->son[0]->siz:0);
	if(x==tmp)return o->h=0,o->maintain();
	int d=(x>tmp);
	insert(o->son[d],x-d*tmp);
	if(o->son[d]->h<o->h)rotate(o,d);
	else o->maintain();
}

int main()
{
	read(R),read(C),read(N);
	for(int i=1;i<=N;i++)read(p[i].st),read(p[i].nd);
	sort(p+1,p+N+1),ans=calc(R)*calc(C),build(root,1,C);
	for(int i=1,j=1;i<=R;i++)
	{
		root->ins(1);
		for(;j<=N&&p[j].st==i;j++)insert(root,p[j].nd);
		ans-=root->sum+calc(root->siz)*root->h;
	}
	write(ans);
	return 0;
}
