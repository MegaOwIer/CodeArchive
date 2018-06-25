#include<bits/stdc++.h>
using namespace std;
const double eps=1e-12;

int T,n,dp[1<<18],sta[360],cnt,bits[1<<18];
double x[20],y[20],a,b;

void cal(int u){for(int i=u;i;i-=i&(-i),bits[u]++);}

int main()
{
    scanf("%d",&T);
	for(int i=1;i<(1<<18);i++)cal(i);
    while(T--)
    {
        scanf("%d%*d",&n),cnt=0;
        for(int i=1;i<=n;i++)scanf("%lf%lf",x+i,y+i);
        for(int i=1;i<(1<<n);i++)dp[i]=bits[i];
        memset(sta,0,sizeof(sta));
        for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)
        {
            if(fabs(x[i]-x[j])<eps||fabs(y[i]/x[i]-y[j]/x[j])<eps)continue;
            a=(y[i]*x[j]-x[i]*y[j])/(x[i]*x[j]*(x[i]-x[j]));
            b=(x[i]*x[i]*y[j]-x[j]*x[j]*y[i])/(x[i]*x[j]*(x[i]-x[j]));
            if(a>0)continue;++cnt;
            for(int k=1;k<=n;k++)if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<eps)
			sta[cnt]|=1<<(k-1);
        }
        sort(sta+1,sta+cnt+1);
        cnt=unique(sta+1,sta+cnt+1)-sta-1;
        for(int i=0;i<(1<<n);i++)for(int j=1;j<=cnt;j++)
		dp[i|sta[j]]=min(dp[i]+1,dp[i|sta[j]]);
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}
