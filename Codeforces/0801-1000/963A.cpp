#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1000000009;

int N,a,b,K,Q,ans,tmp,C,D;
char s[100005];

inline LL Pow(LL a,int b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>N>>a>>b>>K>>s;
	Q=Pow(b*Pow(a,mod-2)%mod,K);
	if(Q==1)D=(N+1)/K;
	else D=(Pow(Q,(N+1)/K)-1)*Pow(Q-1,mod-2)%mod;
	C=Pow(a,N),a=Pow(a,mod-2);
	for(int i=0;i<K;i++)
	{
		if(s[i]=='+')ans=(ans+(LL)C*D)%mod;
		else ans=(ans-(LL)C*D%mod+mod)%mod;
		C=(LL)C*b%mod*a%mod;
	}
	printf("%d",ans);
	return 0;
}