#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[12];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int MX=100005;
#define mp make_pair
#define st first
#define nd second

struct Node
{
	int cnt;
	LL sum;
	Node *son[2];
	Node():cnt(0),sum(0){son[0]=son[1]=NULL;}
	inline void maintain()
	{
		cnt=sum=0;
		for(int i=0;i<2;i++)if(son[i])
			cnt+=son[i]->cnt,sum+=son[i]->sum;
	}
}*root[MX<<1];
int n,m,cnt,x,tim[MX];
LL ans=1,a,b,c,k;
pair<int,int> S[MX<<1];

inline void insert(Node* &o,Node* p,int pos,int L=1,int R=1e7)
{
	if(!o)o=new Node;
	if(L==R)
	{
		o->cnt=(pos>0?1:-1)+(p?p->cnt:0);
		o->sum=pos+(p?p->sum:0);
		if(!o->cnt){delete o;o=NULL;}
		return;
	}
	int mid=L+R>>1;
	if(abs(pos)<=mid)
	{
		insert(o->son[0],p?p->son[0]:NULL,pos,L,mid);
		o->son[1]=p?p->son[1]:NULL;
	}
	else
	{
		insert(o->son[1],p?p->son[1]:NULL,pos,mid+1,R);
		o->son[0]=p?p->son[0]:NULL;
	}
	o->maintain();
}
inline LL ask(Node* o,int rank)
{
	if(!o->son[0]&&!o->son[1])return o->sum/o->cnt*rank;
	int lsz=o->son[0]?o->son[0]->cnt:0;
	if(lsz==rank)return o->son[0]->sum;
	else if(lsz>rank)return ask(o->son[0],rank);
	else return ask(o->son[1],rank-lsz)+(o->son[0]?o->son[0]->sum:0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	read(m),read(n);
	for(int i=1,s,e,p;i<=m;i++)
	{
		read(s),read(e),read(p);
		S[++cnt]=mp(s,p),S[++cnt]=mp(e+1,-p);
	}
	sort(S+1,S+cnt+1);
	for(int i=1,j;i<=cnt;i++)
	{
		j=S[i].nd;
		insert(root[i],root[i-1],j);
		tim[S[i].st]=i;
	}
	for(int i=1;i<=n+1;i++)if(!tim[i])tim[i]=tim[i-1];
	while(n--)
	{
		read(x),read(a),read(b),read(c);
		k=1+(a*ans+b)%c,x=tim[x];
		if(!root[x])ans=0;
		else if(root[x]->cnt<=k)ans=root[x]->sum;
		else ans=ask(root[x],k);
		write(ans);
	}
	return 0;
}
