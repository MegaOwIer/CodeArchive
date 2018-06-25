#include<bits/stdc++.h>
using namespace std;
const int MX=50005;

struct nulltag{};
struct Trie
{
	int cnt;
	Trie *son[2];
	Trie(int);
	Trie(nulltag):cnt(0){son[0]=son[1]=this;}
}*null=new Trie(nulltag()),*TR[MX];
int N,a[MX],ls[MX],pos[MX],ans;
set<int> s;

inline Trie::Trie(int v=0):cnt(v){son[0]=son[1]=null;}

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void insert(Trie* &o,Trie *p,int val)
{
	o=new Trie(p->cnt+1);
	Trie *tmp=o;
	for(int i=29,d;~i;i--)
	{
		d=(val>>i)&1;
		tmp->son[d^1]=p->son[d^1];
		tmp->son[d]=new Trie(p->son[d]->cnt+1);
		tmp=tmp->son[d],p=p->son[d];
	}
}
inline int query(Trie *o,Trie *p,int val)
{
	int ans=0;
	for(int i=29,d;~i;i--,ans<<=1)
	{
		d=(val>>i)&1;
		if(o->son[d^1]->cnt>p->son[d^1]->cnt)
			o=o->son[d^1],p=p->son[d^1],ans|=1;
		else o=o->son[d],p=p->son[d];
	}
	return ans>>1;
}

int main()
{
	TR[0]=null;
	read(N);
	for(int i=1;i<=N;i++)
		read(a[i]),insert(TR[i],TR[i-1],a[i]),ls[i]=a[i];
	sort(ls+1,ls+N+1);
	for(int i=1;i<=N;i++)pos[lower_bound(ls+1,ls+N+1,a[i])-ls]=i;
	s.insert(-2),s.insert(-1),s.insert(N+1),s.insert(N+2);
	for(int i=N,pre,suf;i;i--)
	{
		pre=*----s.lower_bound(pos[i]);
		suf=*++s.upper_bound(pos[i]);
		s.insert(pos[i]);
		if(i==N)continue;
		pre=max(pre,0),suf=min(N,suf-1);
		ans=max(ans,query(TR[suf],TR[pre],ls[i]));
	}
	printf("%d\n",ans);
	return 0;
}
