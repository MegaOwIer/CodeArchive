#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,A,B,K,pr[12],pw[12],cnt,ans;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline int Pow(int a,int b,int p=1000000007)
{
	int ans=1;
	for(;b;b>>=1,a=(LL)a*a%p)if(b&1)ans=(LL)ans*a%p;
	return ans;
}
inline void divide(int K)
{
	cnt=0;
	for(int i=3;i*i<=K;i++)if(K%i==0)
	{
		++cnt,pr[cnt]=i,pw[cnt]=0;
		while(K%i==0)K/=i,pw[cnt]++;
	}
	if(K>1)++cnt,pr[cnt]=K,pw[cnt]=1;
}
inline int solve(int A,int p,int alpha,int N)
{
	int P=Pow(p,alpha);A%=P;
	if(!A)return Pow(p,alpha-max(1,alpha-N));
	int PHI=P/p*(p-1);
	int D=gcd(PHI,N),tmp=0;
	if(A%p)return (Pow(A,PHI/D,P)==1)*D;
	while(A%p==0)A/=p,tmp++;
	if(tmp%N)return 0;
	return solve(A,p,alpha-tmp,N)*Pow(p,tmp-tmp/N);
}

int main()
{
	read(T);
	while(T--)
	{
		read(A),read(B),read(K);
		K=K<<1|1,divide(K),ans=1;
		for(int i=1;i<=cnt;i++)
			ans*=solve(B,pr[i],pw[i],A);
		printf("%d\n",ans);
	}
	return 0;
}
