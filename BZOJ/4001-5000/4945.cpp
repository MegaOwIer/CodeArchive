#include<bits/stdc++.h>
using namespace std;
const int MX=50005;

struct rule{int i,j;char hi,hj;}q1[MX<<1],q2[MX<<1];
int N,D,M,cnt1,cnt2;
char hi,hj;
vector<int> pos;
char s[MX];

namespace _2SAT
{
	typedef int Array[MX<<1];
	struct edge{int to,nxt;}e[MX<<2];
	int cnt,dfs_cnt,top,num,tot,cur_tot;
	Array dfn,low,stk,blt,head,cur;
	bool ins[MX<<1];
	
	inline int getid(int p,char c)
	{
		if(s[p]=='a')return c=='b'?p:p+N;
		if(s[p]=='b')return c=='a'?p:p+N;
		if(s[p]=='c')return c=='a'?p:p+N;
	}
	void prework()
	{
		for(int i=1,u1,u2,v1,v2;i<=cnt1;i++)
		{
			if(s[q1[i].i]==q1[i].hi)continue;
			u1=getid(q1[i].i,q1[i].hi),u2=u1>N?u1-N:u1+N;
			if(s[q1[i].j]==q1[i].hj)
			{
				e[++cur_tot]=(edge){u2,cur[u1]},cur[u1]=cur_tot;
				continue;
			}
			v1=getid(q1[i].j,q1[i].hj),v2=v1>N?v1-N:v1+N;
			e[++cur_tot]=(edge){v1,cur[u1]},cur[u1]=cur_tot;
			e[++cur_tot]=(edge){u2,cur[v2]},cur[v2]=cur_tot;
		}
	}
	void Tarjan(int u)
	{
		dfn[u]=low[u]=++dfs_cnt;
		ins[stk[++top]=u]=1;
		for(int i=head[u];i;i=e[i].nxt)
			if(!dfn[e[i].to])Tarjan(e[i].to),low[u]=min(low[u],low[e[i].to]);
			else if(ins[e[i].to])low[u]=min(low[u],dfn[e[i].to]);
		if(dfn[u]==low[u])
		{
			++num;
			do blt[stk[top]]=num,ins[stk[top]]=0;
			while(stk[top--]!=u);
		}
	}
	bool solve(int S)
	{
		cnt=0,dfs_cnt=0,tot=cur_tot;
		memcpy(head+1,cur+1,sizeof(int)*N<<1);
		memset(dfn+1,0,sizeof(int)*N<<1);
		for(int i=0;i<D;i++)s[pos[i]]=(S>>i)&1?'a':'b';
		for(int i=1,u1,u2,v1,v2;i<=cnt2;i++)
		{
			if(s[q2[i].i]==q2[i].hi)continue;
			u1=getid(q2[i].i,q2[i].hi),u2=u1>N?u1-N:u1+N;
			if(s[q2[i].j]==q2[i].hj)
			{
				e[++tot]=(edge){u2,head[u1]},head[u1]=tot;
				continue;
			}
			v1=getid(q2[i].j,q2[i].hj),v2=v1>N?v1-N:v1+N;
			e[++tot]=(edge){v1,head[u1]},head[u1]=tot;
			e[++tot]=(edge){u2,head[v2]},head[v2]=tot;
		}
		for(int i=1;i<=(N<<1);i++)if(!dfn[i])Tarjan(i);
		for(int i=1;i<=N;i++)if(blt[i]==blt[i+N])return 0;
		for(int i=1;i<=N;i++)
			if(blt[i]<blt[i+N])putchar(s[i]=='a'?'B':'A');
			else putchar(s[i]=='c'?'B':'C');
		return 1;
	}
}

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void getc(char& c)
{
	do c=getchar();while(!isalpha(c));
	c=tolower(c);
}

int main()
{
	read(N),read(D),scanf("%s",s+1),read(M);
	for(int i=1,u,v;i<=M;i++)
	{
		read(u),getc(hi),read(v),getc(hj);
		if(s[u]!='x'&&s[v]!='x')q1[++cnt1]=(rule){u,v,hi,hj};
		else q2[++cnt2]=(rule){u,v,hi,hj};
	}
	_2SAT::prework();
	for(int i=1;i<=N;i++)if(s[i]=='x')pos.push_back(i);
	for(int i=(1<<D)-1;~i;i--)
		if(_2SAT::solve(i))return 0;
	return puts("-1"),0;
}
