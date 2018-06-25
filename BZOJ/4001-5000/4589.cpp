#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static int top,buf[22];
	template<typename T>inline void OUT(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::OUT;
typedef long long LL;
const int maxn=50005,mod=1e9+7;

int n,m,cnt,pr[15005],mp[1<<16|1],a0[1<<16|1],X,pwn[1<<16|1];
LL a[1<<16|1],x;

inline int Pow(int a,int b)
{
	if(!a)return 0;
	int ans=1;
	for(;b;b>>=1,a=(LL)a*a%mod)if(b&1)ans=(LL)ans*a%mod;
	return ans;
}
inline void FWT(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	FWT(l,mid),FWT(mid+1,r);
	for(int i=l,j=mid+1,x;i<=mid;i++,j++)
		x=a0[i]+a0[j],a0[i]=a0[i]-a0[j],a0[j]=x;
}
inline void IFWT(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	IFWT(l,mid),IFWT(mid+1,r);
	x=a[mid+1]-a[l],a[l]=a[l]+a[mid+1],a[mid+1]=x;
}
#define Abs(x) ((x)<0?(-(x)):(x))

int main()
{
	int i,j,k;
	const int N=1<<16;
	for(i=2;i<=N;i++)
	{
		if(!mp[i])pr[++cnt]=i,mp[i]=i;
		for(j=1;j<=cnt&&pr[j]<=mp[i]&&(k=i*pr[j])<=N;j++)mp[k]=pr[j];
	}
	while(~scanf("%d%d",&n,&m))
	{
		for(X=1;X<=m;X<<=1);
		memset(a0,0,X*sizeof(int));
		for(i=1;pr[i]<=m&&i<=cnt;i++)a0[pr[i]]=1;
		FWT(0,X-1);
		int max_a=0;
		for(i=0;i<X;i++)max_a=max(max_a,Abs(a0[i]));
		if(max_a>0)
		{
			for(i=1;i<=cnt&&pr[i]<=max_a;i++)pwn[pr[i]]=Pow(pr[i],n);
			pwn[1]=1;
			for(i=4;i<=max_a;i++)if(mp[i]<i)pwn[i]=(LL)pwn[mp[i]]*pwn[i/mp[i]]%mod;
			for(i=0;i<X;i++)a[i]=(a0[i]<0&&(n&1)?-pwn[-a0[i]]:pwn[Abs(a0[i])]);
		}
		IFWT(0,X-1);
		OUT((a[0]%mod*Pow(X,mod-2)%mod+mod)%mod);
	}
	return 0;
}
