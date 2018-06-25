#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m[100005],dp1[100005],dp2[100005],cnt,ans;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(m,0,sizeof(m));  memset(dp1,0,sizeof(dp1));  memset(dp2,0,sizeof(dp2));  ans=0;
	    for(int i=1;i<=n;i++)  scanf("%d",&m[i]);
	    for(int i=1;i<=n;i++)  {if(m[i]>m[i-1])  dp1[i]=++cnt;  else  dp1[i]=cnt=1;}
	    for(int i=n;i;i--)  {if(m[i]<m[i+1])  dp2[i]=++cnt;  else  dp2[i]=cnt=1;}
	    for(int i=1;i<=n;i++)
	    {
	        if(m[i+1]-m[i-1]>1)  ans=max(ans,dp1[i-1]+1+dp2[i+1]);
	        else  ans=max(ans,max(dp1[i-1],dp2[i+1])+1);
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
