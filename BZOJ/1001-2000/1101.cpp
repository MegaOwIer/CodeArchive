#include<bits/stdc++.h>
using namespace std;
namespace fastIO
{
	static int f;
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	#define getalpha(x) do x=getchar();while(!isalpha(x))
}
using namespace fastIO;
typedef long long LL;
const int maxn=50005;

int T,prime[5140],cnt,miu[maxn],a,b,d;
LL ans;
bool vis[maxn];

int main()
{
	read(T),miu[1]=1;
	for(int i=2;i<=50000;i++)
	{
		if(!vis[i])prime[++cnt]=i,miu[i]=-1;
		for(int j=1;j<=cnt&&i*prime[j]<=50000;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){miu[i*prime[j]]=0;break;}
			miu[i*prime[j]]=-miu[i];
		}
	}
	for(int i=1;i<=50000;i++)miu[i]+=miu[i-1];
	while(T--)
	{
		read(a),read(b),read(d);
		a/=d,b/=d,ans=0;
		if(a>b)swap(a,b);
		for(int i=1,now;i<=a;i=now+1)
		{
			now=min(a/(a/i),b/(b/i));
			ans+=1LL*(a/i)*(b/i)*(miu[now]-miu[i-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

