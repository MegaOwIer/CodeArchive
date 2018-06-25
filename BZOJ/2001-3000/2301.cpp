#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=50005;

int prime[5140],cnt,a,b,c,d,k,T;
short miu[maxn];
bool vis[maxn];

inline int read()
{
	int ans=0;  char c=getchar();
	while(c<'0'||c>'9')  c=getchar();
	while(c>='0'&&c<='9')  ans=ans*10+c-'0',c=getchar();
	return ans;
}
void init()
{
	miu[1]=1;
	for(int i=2;i<=50000;i++)
	{
		if(!vis[i])  miu[i]=-1,prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=50000;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)  {miu[i*prime[j]]=0;break;}
			miu[i*prime[j]]=-miu[i];
		}
	}
	for(int i=2;i<=50000;i++)  miu[i]+=miu[i-1];
}
inline LL cal(int m,int n)
{
	LL ans=0;
	for(int i=1,pos;i<=m&&i<=n;i=pos+1)
	{
		pos=min(m/(m/i),n/(n/i));
		ans+=(LL)(miu[pos]-miu[i-1])*(m/i)*(n/i);
	}
	return ans;
}

int main()
{
	init();
	T=read();
	while(T--)
	{
		a=read(),b=read(),c=read(),d=read(),k=read();
		--a,--c,a/=k,b/=k,c/=k,d/=k;
		printf("%lld\n",cal(b,d)-cal(a,d)-cal(b,c)+cal(a,c));
	}
	return 0;
}
