#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct frac
{
	LL a,b;
	frac(LL aa=0,LL bb=1):a(aa),b(bb){}
}ans,dp[55][55],tmp;
int n,m;
char c;
bool ch[55][55];

inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline void check(frac& a)
{
	LL d=gcd(a.a,a.b);
	a.a/=d,a.b/=d;
}
frac operator + (frac &x,frac &y)
{
    LL d=gcd(x.b,y.b);
    ans.b=x.b/d*y.b;
    ans.a=x.a*(y.b/d)+y.a*(x.b/d);
    check(ans);
    return ans;
}  
inline frac operator * (frac a,frac b)
{
	ans.a=a.a*b.a,ans.b=a.b*b.b;
	check(ans);
	return ans;
}
inline void operator += (frac& a,frac b){a=a+b;}
inline char read(){do c=getchar();while(c!='.'&&c!='*');return c;}
inline void printf(frac x){printf("%lld/%lld",x.a,x.b);}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)ch[i][j]=(read()=='*')?1:0;
	dp[1][1]=(frac){1,1},tmp=(frac){1,2};
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if(ch[i][j]) dp[i+1][j]+=tmp*dp[i][j],dp[i+1][j+1]+=tmp*dp[i][j];
		else dp[i+2][j+1]+=dp[i][j];
	}
	printf(dp[n+1][m+1]);
	return 0;
}
