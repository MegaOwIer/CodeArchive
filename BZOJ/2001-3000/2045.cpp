#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;

int T,n,m,d,prime[78500],cnt;
short miu[maxn];
bool vis[maxn];
long long ans;

template<typename T>
inline void read(T& x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  x=x*10+ch-'0',ch=getchar();
}
void init()
{
	miu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])  prime[++cnt]=i,miu[i]=-1;
		for(int j=1;j<=cnt&&(LL)i*prime[j]<=n;j++)
		{
			int t=i*prime[j];vis[t]=1;
			if(i%prime[j]==0){miu[t]=0;break;}
			miu[t]=-miu[i];
		}
	}
	for(int i=2;i<=n;i++)  miu[i]+=miu[i-1];
}

int main()
{
	read(n),read(m),read(d),n/=d,m/=d;
	if(n<m)swap(n,m);
	init();
	for(int i=1,pos;i<=m;i=pos+1)
	{
		pos=min(m/(m/i),n/(n/i));
		ans+=(LL)(m/i)*(n/i)*(miu[pos]-miu[i-1]);
	}
	printf("%lld",ans);
	return 0;
}
