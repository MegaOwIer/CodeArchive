#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;

int n,q[maxn],h,t;
LL sum[maxn],P[maxn],dp[maxn],F[maxn],X[maxn],C[maxn];
char c;

template<typename T>
inline void read(T& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline double getk(int k,int j){return (double)(dp[j]-dp[k]+sum[j]-sum[k])/(P[j]-P[k]);}

int main()
{
	read(n),q[h=t=1]=0;
	for(int i=1;i<=n;i++)
	{
		read(X[i]),read(P[i]),read(C[i]);
		sum[i]=sum[i-1]+P[i]*X[i],P[i]+=P[i-1];
		while(h<t&&getk(q[h],q[h+1])<X[i])h++;
		dp[i]=dp[q[h]]-sum[i]+sum[q[h]]+C[i]+X[i]*(P[i]-P[q[h]]);
		while(h<t&&getk(q[t],i)<getk(q[t-1],q[t]))t--;
		q[++t]=i;
	}
	printf("%lld",dp[n]);
	return 0;
}
