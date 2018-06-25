#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=10000005;

LL phi[maxn],ans;
int p[664600],cnt,n;
bool vis[maxn];

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)  phi[i]=i;
	for(int i=2;i<=n;i++)  if(!vis[i])
	{
		p[++cnt]=i;  phi[i]=i-1;
		for(int j=i*2;j<=n;j+=i)  vis[j]=1,phi[j]-=phi[j]/i;
	}
	for(int i=2;i<=n;i++)  phi[i]+=phi[i-1];
	for(int i=1;i<=cnt;i++)  ans+=phi[n/p[i]];
	printf("%lld",(ans<<1)-cnt);
	return 0;
}
