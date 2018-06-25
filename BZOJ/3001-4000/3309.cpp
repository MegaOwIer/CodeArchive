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
		if(x<0)x=-x,putchar('-');
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1e7+5;

int T,pr[664600],f[maxn],cnt,a,b;
bool vis[maxn];
LL ans;

int main()
{
	f[1]=0;
	for(int i=2;i<=1e7;i++)
	{
		if(!vis[i])f[i]=1,pr[++cnt]=i;
		for(int j=1;j<=cnt&&pr[j]*i<=1e7;j++)
		{
			vis[i*pr[j]]=1;
			if(i%pr[j]==0){f[i*pr[j]]=0;break;}
			f[i*pr[j]]=-f[i];
		}
	}
	for(int i=2;i<=1e7;i++)if(f[i])
		for(LL j=i;j<=1e7;j*=i)f[j]=f[i];
	for(int i=2;i<=1e7;i++)f[i]+=f[i-1];
	read(T);
	while(T--)
	{
		read(a),read(b),ans=0;
		if(a>b)swap(a,b);
		for(int i=1,t;i<=a;i=t+1)
		{
			t=min(a/(a/i),b/(b/i));
			ans+=(LL)(a/i)*(b/i)*(f[t]-f[i-1]);
		}
		write(ans);
	}
	return 0;
}
