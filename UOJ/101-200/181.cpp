#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using pii=pair<int,int>;
using edge_t=tuple<int,int,int>;
const int MX=40,P=998244353;
constexpr int Inv(int u){return u==1?1:LL(P-P/u)*Inv(P%u)%P;}
const int inv1w=Inv(10000);

int N,M,vis[MX],dfs_cnt,id[MX],ans;
int sum[MX][MX],dp[MX][MX];
vector<int> stk,G[MX];
vector<edge_t> E;

inline int read()
{
	int x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x;
}
inline void update(int &a,int b){((a+=b)>=P)&&(a-=P);}
void dfs(int u)
{
	vis[u]=dfs_cnt;
	id[u]=stk.size();
	stk.push_back(u);
	for(int i:G[u])if(!vis[i])dfs(i);
}
inline int Pow(int a,int b)
{
	b%=P-1,b+=P-1;
	int ans=1;
	for(;b;b>>=1,a=(LL)a*a%P)
		(b&1)&&(ans=(LL)ans*a%P);
	return ans;
}

int main()
{
	N=read(),M=read();
	for(int i=1,u,v,w;i<=M;i++)
	{
		u=read(),v=read(),w=(LL)read()*inv1w%P;
		G[u].push_back(v);
		G[v].push_back(u);
		E.push_back(make_tuple(u,v,w));
	}
	for(int i=1;i<=N;i++)if(!vis[i])
	{
		stk.clear();
		++dfs_cnt,dfs(i);
		for(int s=0,upb=1<<stk.size();s<upb;s++)
		{
			int res=1;
			for(auto e:E)
			{
				int u=get<0>(e),v=get<1>(e);
				if(vis[u]!=dfs_cnt)continue;
				if((s>>id[u]&1)==(s>>id[v]&1))continue;
				if(s>>id[u]&1)res=2LL*res*get<2>(e)%P;
				else res=2LL*res*(P+1-get<2>(e))%P;
			}
			update(sum[dfs_cnt][__builtin_popcount(s)],res);
		}
	}
	dp[0][0]=1;
	for(int i=0;i<dfs_cnt;i++)for(int j=0;j<N;j++)if(dp[i][j])
		for(int k=0;k+j<N;k++)update(dp[i+1][k+j],(LL)dp[i][j]*sum[i+1][k]%P);
	for(int i=0;i<=N;i++)
		update(ans,(LL)dp[dfs_cnt][i]*Pow(2,i*(i-N))%P);
	cout<<(LL)ans*Pow(10000,N*N-N)%P<<endl;
	return 0;
}
