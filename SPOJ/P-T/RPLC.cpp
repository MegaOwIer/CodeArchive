#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace FastIO
{
	char c;
	int f;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar(),f=0;
		while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
	}
}
using FastIO::read;

int T,N;
LL ans,sum;

int main()
{
	read(T);
	for(int i=1;i<=T;i++)
	{
		read(N),ans=0,sum=0;
		for(int i=1,u;i<=N;i++)
			read(u),sum+=u,ans=min(ans,sum);
		printf("Scenario #%d: %lld\n",i,1-ans);
	}
	return 0;
}