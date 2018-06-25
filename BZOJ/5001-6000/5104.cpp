#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+9,
		  Sqrt5=383008016,invS=276601605,inv2=500000005,phi=691504013;

int N,rt1,rt2,t1,t2,ans,tmp1,tmp2;
int Pow(int,int);

namespace FindRoot
{
	int w,a,b;
	struct Complex
	{
		int r,i;
		Complex(int r=0,int i=0):r(r),i(i){}
		Complex operator*(Complex& a)
		{
			return Complex(
				((LL)r*a.r+(LL)i*a.i%mod*w)%mod,
				((LL)r*a.i+(LL)i*a.r)%mod
			);
		}
	};
	
	inline bool check(int v)
	{
		w=((LL)v*v-a+mod)%mod;
		return ::Pow(w,inv2-1)!=1;
	}
	inline int Pow(Complex a,int b)
	{
		Complex ans(1,0);
		for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;
		return ans.r;
	}
	int work(int k)
	{
		a=k;
		if(::Pow(a,inv2-1)!=1)return -1;
		while(!check(b=rand()));
		return Pow(Complex(b,1),inv2);
	}
}

namespace BSGS
{
	int B;
	map<int,int> G;
	
	void init(int val)
	{
		B=1+sqrt(mod);
		int q=Pow(val,B);
		for(int i=1,tmp=q;i<=B;i++)
			G[tmp]=i,tmp=(LL)tmp*q%mod;
	}
	int calc(int val)
	{
		int x=2147483647;
		for(int i=0,tmp=val;i<=B;i++)
		{
			if(G.count(tmp))x=min(x,(G[tmp]*B-i)%(mod-1));
			tmp=(LL)tmp*phi%mod;
		}
		return x;
	}
}

inline int Pow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(LL)a*a%mod)if(b&1)ans=(LL)ans*a%mod;
	return ans;
}

int main()
{
	scanf("%d",&N);
	if(N==1)return puts("1"),0;
	N=(LL)N*Sqrt5%mod;
	rt1=FindRoot::work(((LL)N*N+4)%mod);
	rt2=FindRoot::work(((LL)N*N-4)%mod);
	ans=2147483647;
	BSGS::init(phi);
	if(~rt1)
	{
		t1=BSGS::calc((LL)(N+rt1)*inv2%mod);
		t2=BSGS::calc((LL)(N-rt1+mod)*inv2%mod);
		if(~t1&1)ans=min(ans,t1);
		if(~t2&1)ans=min(ans,t2);
	}
	if(~rt2)
	{
		t1=BSGS::calc((LL)(N+rt2)*inv2%mod);
		t2=BSGS::calc((LL)(N-rt2+mod)*inv2%mod);
		if(t1&1)ans=min(ans,t1);
		if(t2&1)ans=min(ans,t2);
	}
	printf("%d\n",ans<2e9?ans:-1);
	return 0;
}
