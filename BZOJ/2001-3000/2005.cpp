#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;

int cnt,pr[9600],phi[maxn],n,m;
bool vis[maxn];
LL ans;

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}

int main()
{
	n=read(),m=read();
	if(m>n)  swap(m,n);
	for(int i=1;i<=m;i++)  phi[i]=i;
	for(int i=2;i<=m;i++)  if(!vis[i])
	{
		pr[++cnt]=i;  phi[i]--;
		for(int j=i*2;j<=n;j+=i)  vis[j]=1,phi[j]-=phi[j]/i;
	}
	for(int i=1;i<=m;i++)  ans+=1LL*(m/i)*(n/i)*phi[i];
	printf("%lld",ans*2-1LL*m*n);
	return 0;
}
