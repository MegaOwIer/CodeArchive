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
		while(top)putchar(buf[top--]+48);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1e5+5;

int mod,pr[12],pw[12],cnt,n,m,a[7];
LL d[12],rem,fac[maxn],vp[12],ans;

inline void fenjie(int u)
{
	for(int i=2;i*i<=u;i++)if(u%i==0)
	{
		pr[++cnt]=i,d[cnt]=1;
		while(u%i==0)pw[cnt]++,d[cnt]*=i,u/=i;
	}
	if(u>1)pr[++cnt]=u,d[cnt]=u,pw[cnt]=1;
}
inline LL Pow(LL a,int b,int mod)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
	return res;
}
inline void work(int n,int id,int f)
{
	LL res=1;
	for(int i=n/pr[id];i;i/=pr[id])vp[id]+=f*i;
	for(int i=n;i;i/=pr[id])
		res=res*Pow(fac[d[id]],i/d[id],d[id])%d[id]*fac[i%d[id]]%d[id];
	if(!~f)res=Pow(res,d[id]/pr[id]*(pr[id]-1)-1,d[id]);
	(rem*=res)%=d[id];
}

int main()
{
	read(mod),fenjie(mod),fac[0]=1;
	read(n),read(m),a[++m]=n;
	for(int i=1;i<m;i++)read(a[i]),a[m]-=a[i];
	if(a[m]<0)return puts("Impossible"),0;
	for(int id=1;id<=cnt;id++)
	{
		rem=1;
		for(int i=1;i<=d[id];i++)
			if(i%pr[id]==0)fac[i]=fac[i-1];
			else fac[i]=fac[i-1]*i%d[id];
		work(n,id,1);
		for(int i=1;i<=m;i++)work(a[i],id,-1);
		rem=rem*Pow(pr[id],vp[id],d[id])%d[id];
		ans=(ans+rem*(mod/d[id])%mod*Pow(mod/d[id],d[id]/pr[id]*(pr[id]-1)-1,d[id]))%mod;
	}
	write(ans);
	return 0;
}
