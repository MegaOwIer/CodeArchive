#include<bits/stdc++.h>
using namespace std;
const int MX=30005;

namespace Tools
{
	struct edge
	{
		int to,val;
		edge* nxt;
		edge(){}
		edge(int t,int v,edge *n):to(t),val(v),nxt(n){}
	};
	struct bitset
	{
		unsigned a[940];
		bitset(){memset(a,0,sizeof(a));}
		int operator[](int u){return (a[u>>5]>>(u&31))&1;}
		void operator|=(const bitset& u){for(int i=0;i<938;i++)a[i]|=u.a[i];}
		void set(int u){a[u>>5]|=1U<<(u&31);}
		void work1(bitset& u,bitset& v)
		{
			for(int i=937;i;i--)a[i]=((a[i]<<1)|(a[i-1]>>31))&u.a[i]|v.a[i];
			a[0]=(a[0]<<1)&u.a[0]|v.a[0];
		}
		void work2(bitset& u,bitset& v){for(int i=0;i<938;i++)a[i]=((a[i]>>1)|((a[i+1]&1)<<31))&u.a[i]|v.a[i];}
		void work3(bitset& u,bitset& v){for(int i=0;i<938;i++)a[i]|=u.a[i]&v.a[i];}
	};
	struct Stack
	{
		int u,f;
		edge* i;
		Stack(){}
		Stack(int u,int f,edge* i):u(u),f(f),i(i){}
	};
}

int N,M,p1=1,p2,ls[MX];
unsigned d;
char c,s[MX];
Tools::edge *E[MX];
Tools::bitset v1[26],v2[26],u1[26],u2[26],f1[MX],f2[MX],ans,ans1,ans2;
Tools::Stack stk[MX],*top=stk,tmp;

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int val)
{
	E[u]=new Tools::edge(v,val,E[u]);
	E[v]=new Tools::edge(u,val,E[v]);
}
inline void fake_dfs()
{
LOOP_START_TAG:
	if(!top->i)
	{
		top--;
		if(top==stk)return;
		goto DFS_END_TAG;
	}
	if(top->i->to==top->f)goto NEXT_LOOP_TAG;
	tmp=Tools::Stack(top->i->to,top->u,E[top->i->to]);
	*++top=tmp;
	goto LOOP_START_TAG;
DFS_END_TAG:
	f1[top->i->to].work1(v1[top->i->val],u1[top->i->val]);
	f2[top->i->to].work2(v2[top->i->val],u2[top->i->val]);
	ans1|=f1[top->i->to],ans2|=f2[top->i->to];
	ans.work3(f1[top->u],f2[top->i->to]);
	ans.work3(f2[top->u],f1[top->i->to]);
	f1[top->u]|=f1[top->i->to],f2[top->u]|=f2[top->i->to];
NEXT_LOOP_TAG:
	top->i=top->i->nxt;
	goto LOOP_START_TAG;
}

int main()
{
	read(N);
	for(int i=1,u,v;i<N;i++)
	{
		read(u),read(v);
		do c=getchar();while(!isalpha(c));
		add(u,v,c-'a');
	}
	read(M);
	for(int i=1,len,j;i<=M;i++)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		u1[s[1]-'a'].set(++p1);
		ls[i]=p1;
		for(j=2;j<=len;j++)v1[s[j]-'a'].set(++p1);
		for(j=1;j<len;j++)v2[s[j]-'a'].set(++p2);
		u2[s[len]-'a'].set(++p2);
	}
	ls[M+1]=p1+1;
	*++top=Tools::Stack(1,-1,E[1]);
	fake_dfs();
	for(int i=1,j;i<=M;i++)
	{
		d=ans1[ls[i+1]-1]|ans2[ls[i]-1];
		for(j=ls[i];j<ls[i+1]-1;j++)d|=ans[j];
		puts(d?"YES":"NO");
	}
	return 0;
}
