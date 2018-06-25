#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22]; 
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1000005;

int N,pr[78500],cnt,pw[maxn],mn[maxn],phi[maxn];
bool vis[maxn];
LL ans[maxn];

int main()
{
	ans[1]=1;
	for(int i=2,val;i<=1e6;i++)
	{
		if(!vis[i])pr[++cnt]=i,phi[i]=i-1,ans[i]=i+i-1,mn[i]=i,pw[i]=1;
		for(int j=1;j<=cnt&&(val=pr[j]*i)<=1e6;j++)
		{
			vis[val]=1;
			if(i%pr[j]==0)
			{
				phi[val]=pr[j]*phi[i],pw[val]=pw[i]+1,mn[val]=mn[i]*pr[j];
				ans[val]=ans[i/mn[i]]*(mn[val]+(pr[j]-1)*mn[i]*pw[val]);
				break;
			}
			phi[val]=phi[i]*(pr[j]-1),mn[val]=pr[j],pw[val]=1;
			ans[val]=ans[i]*(pr[j]+pr[j]-1);
		}
	}
	for(int i=1;i<=1e6;i++)ans[i]+=ans[i-1];
	while(read(N),N)write(ans[N]-(LL)N*(N+1)/2);
	return 0;
}
