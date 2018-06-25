#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N,m;
LL ans;

inline LL read()
{
	LL ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
inline LL phi(LL u)
{
	LL ans=u;
	for(int i=2;i<=sqrt(u);i++)  if(u%i==0)
	{
		ans-=ans/i;
		while(u%i==0)  u/=i;
	}
	if(u>1)  ans-=ans/u;
	return ans;
}

int main()
{
	N=read(),m=sqrt(N);
	for(int i=1;i<=m;i++)  if(N%i==0)
	{
		ans+=i*phi(N/i);
		if(N/i!=i)  ans+=N/i*phi(i);
	}
	printf("%lld",ans);
	return 0;
}
