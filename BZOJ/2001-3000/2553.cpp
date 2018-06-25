#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
const int MX=80;

namespace FastIO
{
	char c;
	int bf[22],tp;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;

int N,len,AL;
struct Matrix
{
	int siz;
	LD val[MX][MX];
	
	LD* operator [] (int u){return val[u];}
	void operator *= (Matrix& a)
	{
		static Matrix tmp;
		for(int i=0;i<=siz;i++)for(int j=0;j<=siz;j++)tmp[i][j]=0.0;
		for(int i=0;i<=siz;i++)for(int k=0;k<=siz;k++)for(int j=0;j<=siz;j++)
			tmp[i][j]+=val[i][k]*a[k][j];
		for(int i=0;i<=siz;i++)for(int j=0;j<=siz;j++)val[i][j]=tmp[i][j];
	}
}g,ans;
struct AC_Automaton
{
	int siz,son[MX][26],fail[MX];
	bool flag[MX];
	
	void insert(char *s)
	{
		int m=strlen(s+1),now=0;
		for(int i=1;i<=m;i++)
		{
			if(!son[now][s[i]-'a'])son[now][s[i]-'a']=++siz;
			now=son[now][s[i]-'a'];
			if(flag[now])break;
		}
		flag[now]=1;
	}
	void getfail()
	{
		queue<int> q;
		int now,tmp;
		q.push(0);
		while(!q.empty())
		{
			now=q.front(),q.pop();
			for(int i=0;i<AL;i++)
			{
				if(son[now][i])
					fail[son[now][i]]=now?son[fail[now]][i]:0,q.push(son[now][i]);
				else son[now][i]=son[fail[now]][i];
			}
		}
		g[siz+1][siz+1]=1;
	}
	void build_Matrix()
	{
		LD xx=1.0/AL;
		for(int i=0;i<=siz;i++)if(!flag[i])
			for(int j=0;j<AL;j++)
			{
				if(flag[son[i][j]])g[i][siz+1]+=xx,g[i][0]+=xx;
				else g[i][son[i][j]]+=xx;
			}
		g[siz+1][siz+1]=1;
	}
}ACM;
char s[20];

inline void dfs(int u)
{
	if(ACM.flag[u])memset(ACM.son[u],0,sizeof(int)*AL);
	else for(int i=0;i<AL;i++)if(ACM.son[u][i])dfs(ACM.son[u][i]);
}

int main()
{
	read(N),read(len),read(AL);
	for(int i=1;i<=N;i++)scanf("%s",s+1),ACM.insert(s);
	dfs(0);
	ans.siz=g.siz=ACM.siz+1;
	ans[0][0]=1;
	ACM.getfail();
	ACM.build_Matrix();
	for(;len;len>>=1,g*=g)if(len&1)ans*=g;
	printf("%.9Lf",ans[0][ACM.siz+1]);
	return 0;
}
