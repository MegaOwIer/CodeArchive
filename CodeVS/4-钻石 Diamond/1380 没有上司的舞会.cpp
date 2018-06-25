/*��Ŀ����:Ural��ѧ��N��ְԱ,���1~N�����ǵĹ�ϵ����һ����У��Ϊ�����������������ӽ���ֱ����˾��ÿ��ְԱ��һ������ָ����
           �����и���������ᣬҪ�����ְԱ�Ŀ���ָ����󡣵��ǣ�û��ְԱԸ��ֱ����˾һ����ᡣ
  ��������:��һ��һ������N��(1<=N<=6000)
           ������N�У���i+1�б�ʾi��ְԱ�Ŀ���ָ��Ri(-128<=Ri<=127)
		   ������N-1�У�ÿ������һ������L,K����ʾK��L��ֱ����˾
		   ���һ������0,0
  �������:������Ŀ���ָ����
  ��������:7
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
  �������:5*/

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
