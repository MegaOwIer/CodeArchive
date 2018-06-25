#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=50005;

int n,L,q[maxn],l,r;
LL sum[maxn],dp[maxn];

inline int read(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
inline double getk(int j,int k) {return (double)(dp[k]-dp[j]+(sum[k]-sum[j])*(sum[k]+sum[j]+2*L))/(sum[k]-sum[j]);}

int main()
{
	n=read(),L=read()+1;
	for(int i=1;i<=n;i++)
	{
		sum[i]=read()+sum[i-1]+1;
		for(;l<r&&getk(q[l],q[l+1])<=2*sum[i];l++);
		dp[i]=dp[q[l]]+(sum[i]-sum[q[l]]-L)*(sum[i]-sum[q[l]]-L);
		for(;l<r&&getk(q[r],i)<getk(q[r-1],q[r]);r--);
		q[++r]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}
