#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=505,mod=1000000007;

int N,a[MX],b[MX],dp[MX<<1][MX],cnt,inv[MX],ans,ls[MX<<1];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void update(int& a,int b){a+=b;if(a>=mod)a-=mod;}

int main()
{
	read(N);
	for(int i=1;i<=N;i++)
	{
		read(a[i]),read(b[i]);
		ls[++cnt]=a[i],ls[++cnt]=++b[i];
	}
	sort(ls+1,ls+cnt+1),cnt=unique(ls+1,ls+cnt+1)-ls;
	for(int i=1;i<=N;i++)
	{
		a[i]=lower_bound(ls+1,ls+cnt,a[i])-ls;
		b[i]=lower_bound(ls+1,ls+cnt,b[i])-ls;
	}
	cnt-=2;
	for(int i=1;i<=cnt;i++)ls[i]=ls[i+1]-ls[i];
	inv[1]=1;
	for(int i=2;i<=N;i++)inv[i]=LL(mod-mod/i)*inv[mod%i]%mod;
	dp[0][0]=1;
    for(int i=1,s;i<=N;i++)
    {
        s=0;
        for(int j=0;j<a[i];j++)
            for(int k=min(i-1,ls[j]);k>=0;k--)update(s,dp[j][k]);
        for(int j=a[i],tmp;j<b[i];j++)
        {
            tmp=s;
            for(int k=min(i-1,ls[j]);k>=0;k--)update(s,dp[j][k]);
            for(int k=min(i,ls[j]);k>=2;k--)
                dp[j][k]=(dp[j][k]+LL(ls[j]-k+1)*inv[k]%mod*dp[j][k-1])%mod;
            dp[j][1]=(dp[j][1]+(LL)tmp*ls[j])%mod;
        }
    }
	for(int i=1;i<=cnt;i++)
        for(int j=min(N,ls[i]);j>=0;j--)
            update(ans,dp[i][j]);
	printf("%d\n",ans);
	return 0;
}