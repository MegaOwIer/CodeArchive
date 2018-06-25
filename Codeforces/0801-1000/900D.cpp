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
const int mod=1e9+7;

int x,y,pr[11],cnt;
LL ans=0;

inline LL Pow(LL a,int b)
{
	LL res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
inline void fenjie(int u)
{
	for(int i=2;i<=sqrt(u);i++)if(u%i==0)
	{
		pr[++cnt]=i;
		while(u%i==0)u/=i;
	}
	if(u>1)pr[++cnt]=u;
}
inline void dfs(int st,int val,int cc)
{
	if(cc&1)ans=(ans-Pow(2,y/val-1)+mod)%mod;
	else ans=(ans+Pow(2,y/val-1))%mod;
	for(int i=st+1;i<=cnt;i++)dfs(i,val*pr[i],cc+1);
}

int main()
{
	read(x),read(y);
	if(y%x!=0)return puts("0"),0;
	y/=x,fenjie(y);
	dfs(0,1,0);
	write(ans);
	return 0;
}
