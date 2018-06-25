#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,mod=1e9+7;
typedef long long LL;

struct prw{int p,w;}p[maxn<<3];
int n,a[maxn],cnt;
LL pw[25],ans0,ans=1;
char c;

inline bool operator < (prw a,prw b){return a.p<b.p||(a.p==b.p&&a.w<b.w);}
inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void dvd(int u)
{
	if((u&1)==0)
	{
		p[++cnt].p=2;
		while((u&1)==0)p[cnt].w++,u>>=1;
	}
	for(int i=3;i<=sqrt(u);i+=2)if(u%i==0)
	{
		p[++cnt].p=i;
		while(u%i==0)p[cnt].w++,u/=i;
	}
	if(u>1)p[++cnt]=(prw){u,1};
}
inline LL Pow(LL a,LL b)
{
	if(!b)return 1;
	if(!a)return 0;
	LL ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	read(n),pw[0]=1;
	for(int i=1;i<=n;i++)read(a[i]),dvd(a[i]);
	sort(p+1,p+cnt+1);
	for(int i=1,j;i<=cnt;i=j)
	{
		for(j=i;p[j].p==p[i].p;j++);ans0=1;
		for(int k=1;k<=p[j-1].w;k++)pw[k]=(pw[k-1]*p[i].p+1)%mod;
		for(int k=i;k<j;k++)ans0=ans0*pw[p[k].w]%mod;
		ans0=(ans0-1+mod)%mod*(p[i].p-1)%mod*Pow(p[i].p,mod-2)%mod+1;
		ans=ans*ans0%mod;
	}
	printf("%lld",ans);
	return 0;
}
