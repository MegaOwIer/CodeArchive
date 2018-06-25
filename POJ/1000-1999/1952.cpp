#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m[5005],dp[5005],mx=1,ans,dp2[5005],num,que[5005];
bool cf;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  {scanf("%d",&m[i]);  dp[i]=1;}  dp2[n]=1;  m[0]=0x7fffffff;
	for(int i=n-1;i>=0;i--)
	{
	    for(int j=i+1;j<=n;j++)  if(m[i]>m[j])  dp[i]=max(dp[j]+1,dp[i]);
	    if(dp[i]==1)  dp2[i]=1;
	    else
		{
	    	memset(que,0,sizeof(que));  num=0;
	    	for(int j=i+1;j<=n;j++)  if(m[i]>m[j]&&dp[j]+1==dp[i])
	    	{
	    	    cf=0;
			    for(int k=1;k<=num;k++)  if(que[k]==m[j])  {cf=1;  break;}
			    if(!cf)  {dp2[i]+=dp2[j];  que[++num]=m[j];}
			}
	    }
	}
	printf("%d %d",dp[0]-1,dp2[0]);
	return 0;
}
