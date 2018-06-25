#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MX=100005,P=20181019;

int N,K,a[MX][6],popcnt[65],C[9][9];
LL ans;
ULL ht[MX];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline LL calc(int S)
{
	LL ans=0;
	for(int i=1;i<=N;i++)
	{
		ht[i]=0;
		for(int j=0;j<6;j++)if((S>>j)&1)
			ht[i]=ht[i]*P+a[i][j];
	}
	sort(ht+1,ht+N+1);
	for(int i=1,j=1;i<=N;i=j)
	{
		while(j<=N&&ht[i]==ht[j])j++;
		ans+=(LL)(j-i)*(j-i-1)/2;
	}
	return ans;
}

int main()
{
	read(N),read(K);
	for(int i=0;i<=6;i++)C[i][0]=1;
	for(int i=1;i<=6;i++)for(int j=1;j<=i;j++)
		C[i][j]=C[i-1][j-1]+C[i-1][j];
	for(int i=1;i<=N;i++)for(int j=0;j<6;j++)read(a[i][j]);
	for(int i=0;i<64;i++)
	{
		popcnt[i]=popcnt[i>>1]+(i&1);
		if(popcnt[i]>=K)
			if((popcnt[i]^K)&1)ans-=calc(i)*C[popcnt[i]][K];
			else ans+=calc(i)*C[popcnt[i]][K];
	}
	printf("%lld",ans);
	return 0;
}
