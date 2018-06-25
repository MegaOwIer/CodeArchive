#include<bits/stdc++.h>
using namespace std;
const int MX=300005;

int N,a[MX];
struct Trie
{
	Trie *son[2];
	int cnt;
	Trie():cnt(0){son[0]=son[1]=NULL;}
}*root=new Trie;

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void insert(int u)
{
	Trie *o=root;
	for(int i=29;~i;i--)
	{
		if(!o->son[(u>>i)&1])o->son[(u>>i)&1]=new Trie;
		o=o->son[(u>>i)&1];
		o->cnt++;
	}
}
inline int solve(int u)
{
	Trie *o=root;
	int ans=0;
	for(int i=29,d;~i;i--,ans<<=1)
	{
		d=(u>>i)&1;
		if(o->son[d]&&o->son[d]->cnt)o=o->son[d];
		else o=o->son[d^1],ans|=1;
		o->cnt--;
	}
	return ans>>1;
}

int main()
{
	read(N);
	for(int i=1;i<=N;i++)read(a[i]);
	for(int i=1,u;i<=N;i++)read(u),insert(u);
	for(int i=1;i<=N;i++)printf("%d ",solve(a[i]));
	return 0;
}
