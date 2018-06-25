#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e8;

struct BigInt
{
	LL x[400];
	int lth;
	BigInt():lth(0){memset(x,0,sizeof(x));}
	BigInt(int u){x[lth=1]=u;memset(x+2,0,sizeof(LL)*398);}
	inline void print()
	{
		printf("%lld",x[lth]);
		for(int i=lth-1;i;i--)printf("%08lld",x[i]);
	}
}ans(1);
int f,n,rem,num,pw[1005];
char c;

inline void read(int& x)
{
	f=1,c=getchar(),x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
}
inline void wk(int u,int f)
{
	for(int i=2;i<=sqrt(u);i++)while(u%i==0)pw[i]+=f,u/=i;
	if(u^1)pw[u]+=f;
}
inline void operator *= (BigInt& a,BigInt& b)
{
	BigInt res;
	res.lth=a.lth+b.lth;
	for(int i=1;i<=a.lth;i++)for(int j=1;j<=b.lth;j++)
	{
		res.x[i+j-1]+=a.x[i]*b.x[j];
		res.x[i+j]+=res.x[i+j-1]/mod;
		res.x[i+j-1]%=mod;
	}
	if(!res.x[res.lth])res.lth--;
	a=res;
}
inline void Pow(int a,int b)
{
	BigInt aa(a);
	while(b)
	{
		if(b&1)ans*=aa;
		aa*=aa,b>>=1;
	}
}

int main()
{
	read(n),rem=n-2;
	for(int i=2;i<n-1;i++)wk(i,1);
	for(int i=1,u;i<=n;i++)
	{
		read(u);
		if(u==-1)num++;
		else if(u>1)
		{
			for(int j=2;j<u;j++)wk(j,-1);
			rem-=u-1;
		}
	}
	for(int i=2;i<=rem;i++)wk(i,-1);wk(num,rem);
	for(int i=2;i<=n;i++)if(pw[i])Pow(i,pw[i]);
	ans.print();
	return 0;
}
