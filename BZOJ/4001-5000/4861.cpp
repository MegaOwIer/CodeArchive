#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=5005,mod=1000000007;

int N,M,L,lth[55];
char s[55][105],t[105];

struct ACAutomaton
{
	struct Node
	{
		Node *son[26],*fail;
		bool flag;
		int id;
		Node(int id=0):flag(false),id(id){}
		void* operator new(size_t);
	}*root;
	int siz;
	ACAutomaton():root(new Node(0)),siz(1){root->fail=root;}
	void insert(char*);
	void getfail();
	int match(Node*,char*);
}ACM;
ACAutomaton::Node nPool[MX],*ptr=nPool;
inline void* ACAutomaton::Node::operator new(size_t){return ptr++;}
inline void ACAutomaton::insert(char* s)
{
	int len=strlen(s+1);
	Node *o=root;
	for(int i=1;i<=len;i++)
	{
		if(!o->son[s[i]-'a'])o->son[s[i]-'a']=new Node(siz++);
		o=o->son[s[i]-'a'];
	}
	o->flag=true;
}
inline void ACAutomaton::getfail()
{
	queue<Node*> q;
	Node *tmp;
	for(int i=0;i<26;i++)
		if(root->son[i])root->son[i]->fail=root,q.push(root->son[i]);
		else root->son[i]=root;
	while(!q.empty())
	{
		tmp=q.front(),q.pop();
		for(int i=0;i<26;i++)
			if(tmp->son[i])
			{
				tmp->son[i]->fail=tmp->fail->son[i];
				tmp->son[i]->flag|=tmp->son[i]->fail->flag;
				q.push(tmp->son[i]);
			}
			else tmp->son[i]=tmp->fail->son[i];
	}
}
inline int ACAutomaton::match(Node *o,char *s)
{
	int lth=strlen(s+1);
	for(int i=1;i<=lth;i++)
	{
		while(!o->son[s[i]-'a'])o=o->fail;
		o=o->son[s[i]-'a'];
		if(o->flag)return -1;
	}
	return o->id;
}

namespace solve1
{
	int dp[105][MX],ans;
	void main()
	{
		dp[0][0]=1;
		for(int _=0;_<L;_++)for(int i=0;i<ACM.siz;i++)if(dp[_][i])
			for(int j=1,id;j<=N;j++)if(_+lth[j]<=L)
			{
				id=ACM.match(nPool+i,s[j]);
				if(~id)dp[_+lth[j]][id]=(dp[_+lth[j]][id]+dp[_][i])%mod;
			}
		for(int i=0;i<ACM.siz;i++)ans=(ans+dp[L][i])%mod;
		printf("%d\n",ans);
	}
}

namespace solve2
{
	struct Matrix
	{
		int d[205][205],siz;
		Matrix(int siz=0):siz(siz){memset(d,0,sizeof(d));}
		int* operator [] (int u){return d[u];}
		const int* operator [] (int u)const{return d[u];}
		void identity()
		{
			memset(d,0,sizeof(d));
			for(int i=0;i<siz;i++)d[i][i]=1;
		}
		Matrix operator * (const Matrix& a)
		{
			Matrix ans(siz);
			for(int i=0;i<siz;i++)for(int k=0;k<siz;k++)for(int j=0;j<siz;j++)
				ans[i][j]=(ans[i][j]+(LL)d[i][k]*a[k][j])%mod;
			return ans;
		}
	}A,B;
	int ans;

	inline Matrix Pow(Matrix a,int b)
	{
		Matrix ans(a.siz);
		ans.identity();
		for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;
		return ans;
	}
	void main()
	{
		int siz=ACM.siz;
		A.siz=B.siz=siz*2;
		A[0][siz]=1;
		for(int i=0;i<siz;i++)B[i+siz][i]=1;
		for(int i=0;i<siz;i++)for(int j=1,id;j<=N;j++)
		{
			id=ACM.match(nPool+i,s[j]);
			if(!~id)continue;
			if(lth[j]==1)B[i+siz][id+siz]++;
			else B[i][id+siz]++;
		}
		A=A*B,B=Pow(B,L),A=A*B;
		for(int i=0;i<siz;i++)ans=(ans+A[0][i])%mod;
		printf("%d\n",ans);
	}
}

int main()
{
	scanf("%d%d%d",&N,&M,&L);
	for(int i=1;i<=N;i++)scanf("%s",s[i]+1),lth[i]=strlen(s[i]+1);
	for(int i=1;i<=M;i++)scanf("%s",t+1),ACM.insert(t);
	ACM.getfail();
	if(L<=100)solve1::main();
	else solve2::main();
	return 0;
}