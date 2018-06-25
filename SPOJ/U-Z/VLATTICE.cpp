#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;

int T,prime[760000],cnt,n,now;
LL phi[maxn],ans;
short miu[maxn];
bool vis[maxn];

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
void init()
{
	phi[1]=1,miu[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i])  prime[++cnt]=i,phi[i]=i-1,miu[i]=-1;
		for(int j=1;j<=cnt&&(LL)i*prime[j]<=1000000;j++)
		{
			now=i*prime[j],vis[now]=1;
			if(i%prime[j]==0)  {phi[now]=phi[i]*prime[j],miu[now]=0;break;}
			else  phi[now]=phi[i]*(prime[j]-1),miu[now]=-miu[i];
		}
	}
	for(int i=2;i<=1000000;i++)  phi[i]+=phi[i-1];
	for(int i=1;i<=1000000;i++)  phi[i]*=6;
}


int main()
{
	init();
	T=read();
	while(T--)
	{
		n=read(),ans=phi[n];
		for(int i=1;i<=n;i++)  if(miu[i])
		{
			if(miu[i]>0)  ans+=(LL)(n/i)*(n/i)*(n/i);
			else  ans-=(LL)(n/i)*(n/i)*(n/i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
