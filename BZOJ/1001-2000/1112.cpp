#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void IN(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-48,c=getchar();
	}
	template<typename T>inline void OUT(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
	}
}
using FastIO::IN;
using FastIO::OUT;
typedef long long LL;
const int maxn=100005;

struct Treap
{
	int val,siz,cnt,tmp;
	LL sum;
	Treap *son[2];
	Treap(int _)
	{
		val=sum=_,siz=cnt=1,tmp=rand();
		son[0]=son[1]=NULL;
	}
	inline bool cmp(int _){return _>val;}
	inline void maintain()
	{
		siz=cnt,sum=(LL)val*cnt;
		for(int i=0;i<2;i++)if(son[i])
			sum+=son[i]->sum,siz+=son[i]->siz;
	}
}*root;
int N,K,M,a[maxn];
LL ans=9e18,sum1,sum2,tmp,sum;

inline void rotate(Treap* &o,int d)
{
	Treap* tmp=o->son[d];
	o->son[d]=tmp->son[d^1];
	tmp->son[d^1]=o;
	o->maintain(),tmp->maintain();
	o=tmp;
}
inline void insert(Treap* &o,int val)
{
	if(!o){o=new Treap(val);return;}
	if(o->val==val)o->cnt++;
	else
	{
		int d=o->cmp(val);
		insert(o->son[d],val);
		if(o->tmp>o->son[d]->tmp)rotate(o,d);
	}
	o->maintain();
}
inline void work(Treap* o,int rank)
{
	if(!o)return;
	int lsiz=o->son[0]?o->son[0]->siz:0;
	if(lsiz<rank&&rank<=lsiz+o->cnt)
	{
		tmp=o->val;
		sum1+=(rank-lsiz-1)*tmp+(o->son[0]?o->son[0]->sum:0);
		sum2+=(lsiz+o->cnt-rank)*tmp+(o->son[1]?o->son[1]->sum:0);
	}
	else if(rank<=lsiz)
	{
		sum2+=(LL)o->cnt*o->val+(o->son[1]?o->son[1]->sum:0);
		work(o->son[0],rank);
	}
	else
	{
		sum1+=(LL)o->cnt*o->val+(o->son[0]?o->son[0]->sum:0);
		work(o->son[1],rank-lsiz-o->cnt);
	}
}
inline void getans()
{
	sum1=sum2=0,work(root,M);
	sum=(M-1)*tmp-sum1+sum2-(K-M)*tmp;
	if(ans>sum)ans=sum;
}
inline void del(Treap* &o,int val)
{
	if(!o)return;
	if(val==o->val)
	{
		if(o->cnt>1)o->cnt--,o->sum-=val,o->siz--;
		else if(!o->son[0]&&!o->son[1])o=NULL;
		else if(!o->son[0])o=o->son[1];
		else if(!o->son[1])o=o->son[0];
		else rotate(o,o->son[0]->tmp>o->son[1]->tmp),del(o,val);
	}
	else o->siz--,o->sum-=val,del(o->son[o->cmp(val)],val);
}

int main()
{
	srand(19260817);
	IN(N),IN(K),M=K+1>>1;
	for(int i=1;i<=N;i++)IN(a[i]);
	for(int i=1;i<=K;i++)insert(root,a[i]);
	getans();
	for(int i=K+1;i<=N;i++)
		del(root,a[i-K]),insert(root,a[i]),getans();
	OUT(ans);
	return 0;
}
