#include<bits/stdc++.h>
using namespace std;
const int MX=500005;

int T,K,N,val[MX];
char s[MX];

struct SuffixAutomaton
{
	struct Node
	{
		Node *son[26],*fa;
		int len,val,sum;
		Node(int len=0,int val=0):len(len),val(val){}
		void* operator new(size_t);
	}*last,*t0,*q[MX<<1];
	int siz;
	SuffixAutomaton(){siz=1,last=t0=new Node;}
	void extend(int);
	void prework();
	void dfs(Node*,int);
}SAM;
SuffixAutomaton::Node nPool[MX<<1],*ptr=nPool;
inline void* SuffixAutomaton::Node::operator new(size_t){return ptr++;}
inline void SuffixAutomaton::extend(int c)
{
	static Node *np,*p,*nq,*q;
	p=last;
	np=new Node(p->len+1,1),siz++;
	while(p&&!p->son[c])p->son[c]=np,p=p->fa;
	if(!p)np->fa=t0;
	else
	{
		q=p->son[c];
		if(p->len+1==q->len)np->fa=q;
		else
		{
			nq=new Node(p->len+1),siz++;
			nq->fa=q->fa,memcpy(nq->son,q->son,sizeof(q->son));
			np->fa=q->fa=nq;
			while(p&&p->son[c]==q)p->son[c]=nq,p=p->fa;
		}
	}
	last=np;
}
inline void SuffixAutomaton::prework()
{
	for(int i=0;i<siz;i++)val[nPool[i].len]++;
	for(int i=1;i<=N;i++)val[i]+=val[i-1];
	for(int i=siz-1;~i;i--)q[--val[nPool[i].len]]=nPool+i;
	for(int i=siz-1;i;i--)
		if(T==1)q[i]->fa->val+=q[i]->val;
		else q[i]->val=1;
	t0->val=0;
	for(int i=siz-1;~i;i--)
	{
		q[i]->sum=q[i]->val;
		for(int j=0;j<26;j++)
			if(q[i]->son[j])q[i]->sum+=q[i]->son[j]->sum;
	}
}
inline void SuffixAutomaton::dfs(Node *u,int K)
{
	if(K<=u->val)return;
	K-=u->val;
	for(int i=0;i<26;i++)if(u->son[i])
	{
		if(K<=u->son[i]->sum)
		{
			putchar('a'+i),dfs(u->son[i],K);
			return;
		}
		K-=u->son[i]->sum;
	}
}

int main()
{
	scanf("%s%d%d",s+1,&T,&K);
	N=strlen(s+1);
	for(int i=1;i<=N;i++)SAM.extend(s[i]-'a');
	SAM.prework();
	if(K>SAM.t0->sum)puts("-1");
	else SAM.dfs(SAM.t0,K);
	return 0;
}