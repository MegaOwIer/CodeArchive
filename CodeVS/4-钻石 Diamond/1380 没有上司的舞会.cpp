/*题目描述:Ural大学有N个职员,编号1~N。他们的关系就像一棵以校长为根的树，父结点就是子结点的直接上司。每个职员有一个快乐指数。
           现在有个周年庆宴会，要求与会职员的快乐指数最大。但是，没有职员愿和直接上司一起与会。
  输入描述:第一行一个整数N。(1<=N<=6000)
           接下来N行，第i+1行表示i号职员的快乐指数Ri(-128<=Ri<=127)
		   接下来N-1行，每行输入一对整数L,K。表示K是L的直接上司
		   最后一行输入0,0
  输出描述:输出最大的快乐指数。
  样例输入:7
		   1
		   1
		   1
		   1
		   1
		   1
		   1
		   1 3
		   2 3
		   6 4
		   7 4
		   4 5
		   3 5
		   0 0
  样例输出:5*/

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,dp[6005][2],fa[6005];
vector<int> g[6005];

void dfs(int u)
{
	for(int i=0;i<g[u].size();i++)
	{
		dfs(g[u][i]);
		dp[u][1]+=dp[g[u][i]][0];
		dp[u][0]+=max(dp[g[u][i]][0],dp[g[u][i]][1]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d",&dp[i][1]);
	for(int i=1,a,b;i<n;i++)  {scanf("%d%d",&a,&b);  fa[a]=b;  g[b].push_back(a);}
	for(int i=1;i<=n;i++)  if(!fa[i])  {dfs(i);  printf("%d",max(dp[i][0],dp[i][1]));  break;}
	return 0;
}
