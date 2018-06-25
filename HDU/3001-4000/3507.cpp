#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=500005;

int n,m,q[maxn],l,r;
LL C[maxn],dp[maxn];

inline LL read(){LL x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
inline LL gety(int k,int j){return dp[k]+C[k]*C[k]-dp[j]-C[j]*C[j];}
inline LL getx(int k,int j){return C[k]-C[j];}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		l=0,q[r=1]=0;
		for(int i=1;i<=n;i++)
		{
			C[i]=C[i-1]+read();
			for(;l<r&&gety(q[l+1],q[l])<=2*C[i]*getx(q[l+1],q[l]);l++);
			dp[i]=m+dp[q[l]]+(C[i]-C[q[l]])*(C[i]-C[q[l]]);
			for(;l<r&&gety(i,q[r])*getx(q[r],q[r-1])<=gety(q[r],q[r-1])*getx(i,q[r]);r--);
			q[++r]=i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
