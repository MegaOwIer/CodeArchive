#include<bits/stdc++.h>
using namespace std;

int n,k,a[6][1005],pos[6][1005],dp[1005],res,cnt[1005];
char c;
bool flag;
vector<int> ans;
vector<int>::iterator it;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(k);
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)
		read(a[i][j]),pos[i][a[i][j]]=j;
	ans.push_back(0);
	for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)
	{
		cnt[a[j][i]]++;
		if(cnt[a[j][i]]==k)
		{
			for(it=ans.begin();it!=ans.end();++it)
			{
				flag=1;
				for(int r=1;r<=k&&flag;r++)if(pos[r][*it]>pos[r][a[j][i]])flag=0;
				if(flag)dp[a[j][i]]=max(dp[a[j][i]],dp[*it]+1);
			}
			ans.push_back(a[j][i]);
		}
	}
	for(int i=1;i<=n;i++)res=max(res,dp[i]);
	printf("%d",res);
	return 0;
}
