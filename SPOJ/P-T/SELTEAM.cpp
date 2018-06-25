#include<cstdio>
#include<cctype>
using namespace std;
typedef long long LL;
const int mod=1<<23,maxn=100000;

int T,n,k;
LL ans,C[maxn|1][30];
char c;

inline void read(int& x)
{
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline LL Pow(LL a,int b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
	read(T);
	for(int i=0;i<=maxn;i++)C[i][0]=1;
	for(int i=1;i<=maxn;i++)for(int j=1;j<=24&&j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	while(T--)
	{
		read(n),read(k),ans=0;
		for(int i=1;i<=24&&i<=k;i++)
			ans=(ans+C[n][i]*i%mod*(1LL<<i-1))%mod;
		printf("%lld\n",ans);
	}
    return 0;
}
