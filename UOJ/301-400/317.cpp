#include<bits/stdc++.h>
using namespace std;

const int MX=50005;
#define cin A_FAKE_ISTRAM

int N,D,M,cnt1,cnt2;
char s[MX];
vector<int> pos,V;

struct Istream
{
    static const int MXL=2000000;
    char bf[MXL],*p1,*p2;
    FILE *F;
    
    Istream(FILE *F=stdin):p1(bf),p2(bf),F(F){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
    Istream& operator >> (int& x)
    {
        x=0;int c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return *this;
    }
    Istream& operator >> (char& x)
    {
        while(!isalpha(x=getchar()));
        x=tolower(x);
        return *this;
    }
}cin;

struct rule
{
    int i,j;
    char hi,hj;
}q1[MX<<1],q2[MX<<1];

namespace _2SAT
{
	typedef int Array[MX<<1];
	int cnt,dfs_cnt,num;
	Array dfn,low,blt;
	bool ins[MX<<1];
    vector<int> G1[MX<<1],G2[MX<<1];
	
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
                G1[u1].push_back(u2);
				continue;
			}
			v1=getid(q1[i].j,q1[i].hj),v2=v1>N?v1-N:v1+N;
            G1[u1].push_back(v1);
            G1[v2].push_back(u2);
		}
	}
	void Tarjan(int u)
	{
        static int top=0,stk[MX<<1];
		dfn[u]=low[u]=++dfs_cnt;
		ins[stk[++top]=u]=1;
        for(int i:G1[u])
            if(!dfn[i])Tarjan(i),low[u]=min(low[u],low[i]);
            else if(ins[i])low[u]=min(low[u],dfn[i]);
        for(int i:G2[u])
            if(!dfn[i])Tarjan(i),low[u]=min(low[u],low[i]);
            else if(ins[i])low[u]=min(low[u],dfn[i]);
		if(dfn[u]==low[u])
		{
			++num;
			do blt[stk[top]]=num,ins[stk[top]]=0;
			while(stk[top--]!=u);
		}
	}
	bool solve(int S)
	{
        if(clock()>0.9*CLOCKS_PER_SEC)puts("-1"),exit(0);
		cnt=0,dfs_cnt=0;
		memset(dfn+1,0,sizeof(int)*N<<1);
        for(int i=N*2;i;i--)G2[i].clear();
		for(int i=0;i<D;i++)s[pos[i]]=(S>>i)&1?'a':'b';
		for(int i=1,u1,u2,v1,v2;i<=cnt2;i++)
		{
			if(s[q2[i].i]==q2[i].hi)continue;
			u1=getid(q2[i].i,q2[i].hi),u2=u1>N?u1-N:u1+N;
			if(s[q2[i].j]==q2[i].hj)
			{
                G2[u1].push_back(u2);
				continue;
			}
			v1=getid(q2[i].j,q2[i].hj),v2=v1>N?v1-N:v1+N;
            G2[u1].push_back(v1);
            G2[v2].push_back(u2);
		}
		for(int i=N*2;i;i--)if(!dfn[i])Tarjan(i);
		for(int i=1;i<=N;i++)if(blt[i]==blt[i+N])return 0;
		for(int i=1;i<=N;i++)
			if(blt[i]<blt[i+N])putchar(s[i]=='a'?'B':'A');
			else putchar(s[i]=='c'?'B':'C');
		return 1;
	}
}

int main()
{
    srand(time(NULL));
	scanf("%d%d%s",&N,&D,s+1);
    cin>>M;
	for(int i=1,u,v;i<=M;i++)
	{
        char hi,hj;
        cin>>u>>hi>>v>>hj;
		if(s[u]!='x'&&s[v]!='x')q1[++cnt1]=(rule){u,v,hi,hj};
		else q2[++cnt2]=(rule){u,v,hi,hj};
	}
	_2SAT::prework();
	for(int i=1;i<=N;i++)if(s[i]=='x')pos.push_back(i);
    for(int i=(1<<D)-1;~i;i--)V.push_back(i);
    random_shuffle(V.begin(),V.end());
	for(int i:V)if(_2SAT::solve(i))return 0;
	return puts("-1"),0;
}
