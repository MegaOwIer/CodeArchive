#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;

int n,mod,pw[maxn],x[maxn],prime[maxn],d[maxn],cnt;
LL ans=1;
bool vis[maxn];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void Pow(LL a,int b)
{
	if(!b)return;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
}

int main()
{
	read(n),read(mod);
	for(int i=1;i<=n;i++)read(x[i]);
	for(int i=1,c;i<=n;i++)
	{
		read(c);
		pw[c]++,pw[x[i]]--,pw[c-x[i]]--;
	}
	d[1]=1;
	for(int i=2;i<=1e6;i++)
	{
		if(!vis[i])prime[++cnt]=i,d[i]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=1e6;j++)
		{
			vis[prime[j]*i]=1;
			if(i%prime[j]==0){d[i*prime[j]]=d[i];break;}
			d[i*prime[j]]=prime[j];
		}
	}
	for(int i=1e6;i;i--)pw[i]+=pw[i+1];
	for(int i=1e6;i>1;i--)if(pw[i])
	{
		if(d[i]==i)Pow(i,pw[i]);
		else pw[d[i]]+=pw[i],pw[i/d[i]]+=pw[i];
	}
	printf("%lld",ans);
	return 0;
}
