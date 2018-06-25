#include<bits/stdc++.h>
using namespace std;
const int MX=55;
inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int N,M,ans,g[2005],dp[2][2005],d;

struct Node
{
	int power,cost,lim,need,f[105][2005];
	char opt;
	Node *fa;
	vector<Node*> son;
	Node(){memset(f,-1,sizeof(f));}
	void readin();
	void dfs();
}P[MX];

inline void Node::readin()
{
	read(power);
	do opt=getchar();while(!isalpha(opt));
	if(opt=='B')read(cost),read(lim),lim=min(lim,M/cost);
	else
	{
		int t,u,v;
		for(read(t);t--;)
		{
			read(u),read(v);
			P[u].fa=this,P[u].need=v;
			son.push_back(P+u);
		}
	}
}
void Node::dfs()
{
	if(opt=='B')
	{
		for(int i=0;i<=lim;i++)for(int j=i;j<=lim;j++)
			f[i][j*cost]=(j-i)*power;
		return;
	}
	lim=2147483647;
	for(int i=0;i<son.size();i++)
		son[i]->dfs(),lim=min(lim,son[i]->lim/son[i]->need);
	for(int i=0;i<=lim;i++)f[i][0]=0;
	for(int i=0;i<son.size();i++)for(int j=0;j<=lim;j++)
	{
		memcpy(g,f[j],sizeof(int)*(M+1));
		memset(f[j],-1,sizeof(int)*(M+1));
		for(int k=M;~k;k--)for(int r=k;~r;r--)
			if(~g[k-r]&&~son[i]->f[j*son[i]->need][r])
				f[j][k]=max(f[j][k],g[k-r]+son[i]->f[j*son[i]->need][r]);
	}
	for(int i=0;i<=lim;i++)for(int j=i;j<=lim;j++)
		for(int k=0;k<=M;k++)if(~f[j][k])
			f[i][k]=max(f[i][k],f[j][k]+(j-i)*power);
}

int main()
{
	read(N),read(M);
	for(int i=1;i<=N;i++)P[i].readin();
	int cnt=0;
	for(int i=1;i<=N;i++)if(!P[i].fa)
	{
		P[i].dfs(),d^=1;
		memset(dp[d],0,sizeof(int)*(M+1));
		for(int j=0;j<=M;j++)for(int k=0;k<=j;k++)
			for(int l=0;l<=P[i].lim;l++)
				dp[d][j]=max(dp[d][j],dp[d^1][k]+P[i].f[l][j-k]);
	}
	for(int i=0;i<=M;i++)ans=max(ans,dp[d][i]);
	printf("%d",ans);
	return 0;
}
