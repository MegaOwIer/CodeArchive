#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
const int MX=125;

int N,k[MX],c[MX],sum;
LL dp[MX][250000],t,M;

template<typename T>inline void read(T& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void update(LL& a,LL b){if(a<b)a=b;}

int main()
{
	read(N),read(M);
	for(int i=1;i<=N;i++)read(k[i]);
	for(int i=1;i<=N;i++)read(c[i]);
	for(int i=0;i<N;i++)
	{
		dp[i][0]=1,sum+=k[i]*c[i];
		for(int j=0;j<=sum;j++)if(dp[i][j])
		{
			update(dp[i+1][j],dp[i][j]);
			for(int k=1;k<=::k[i+1];k++)
				update(dp[i+1][j+k*c[i+1]],min((LD)dp[i][j]*k,(LD)M));
		}
	}
	for(int i=0;;i++)
		if(dp[N][i]==M)return printf("%d\n",i),0;
}