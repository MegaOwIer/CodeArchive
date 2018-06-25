#include<bits/stdc++.h>
using namespace std;
const int MX=600005;

struct nulltag{};
struct Trie
{
	int cnt;
	Trie *son[2];
	Trie(int);
	Trie(nulltag):cnt(0){son[0]=son[1]=this;}
	void* operator new(size_t);
}*null=new Trie(nulltag()),*TR[MX];
int N,M,ans,l,r,x;
char op;

inline Trie::Trie(int v=0):cnt(v){son[0]=son[1]=null;}
inline void* Trie::operator new(size_t)
{
	static Trie Pool[MX*23],*ptr=Pool;
	return ptr++;
}

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void insert(Trie* &o,Trie *p,int val)
{
	static Trie *tmp;
	tmp=o=new Trie(p->cnt+1);
	for(int i=23,d;~i;i--)
	{
		d=(val>>i)&1;
		tmp->son[d]=new Trie(p->son[d]->cnt+1);
		tmp->son[d^1]=p->son[d^1];
		tmp=tmp->son[d],p=p->son[d];
	}
}
inline int query(Trie *o,Trie *p,int val)
{
	int ans=0;
	for(int i=23,d;~i;i--)
	{
		d=(val>>i)&1;
		if(o->son[d^1]->cnt>p->son[d^1]->cnt)
			ans=ans<<1|1,o=o->son[d^1],p=p->son[d^1];
		else ans<<=1,o=o->son[d],p=p->son[d];
	}
	return ans;
}

int main()
{
	TR[0]=null,insert(TR[1],TR[0],0);
	read(N),read(M),N++;
	for(int i=1,u;i<N;i++)
		read(u),ans^=u,insert(TR[i+1],TR[i],ans);
	while(M--)
	{
		do op=getchar();while(!isalpha(op));
		if(op=='A')read(x),ans^=x,++N,insert(TR[N],TR[N-1],ans);
		else
		{
			read(l),read(r),read(x);
			printf("%d\n",query(TR[r],TR[l-1],ans^x));
		}
	}
	return 0;
}
