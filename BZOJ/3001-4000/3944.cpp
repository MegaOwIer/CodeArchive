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
	template<typename T>inline void write(T x,int f=0)
	{
		if(x<0)x=-x,putchar('-');
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(buf[top--]+48);
		putchar(f?'\n':' ');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
typedef pair<LL,int> pLi;
const int maxn=5e6+5;
#define mp make_pair

int T,pr[348520],cnt,miu[maxn];
LL n,phi[maxn];
pLi ans,p[500];

inline pLi solve(unsigned t)
{
	if(t<=5e6)return mp(phi[t],miu[t]);
	if(p[n/t].first)return p[n/t];
	LL ans1=(LL)(t+1)*t/2;
	int ans2=1;
	pLi tmp;
	for(unsigned i=2,j;i<=t;i=j+1)
	{
		j=t/(t/i);
		tmp=solve(t/i);
		ans1-=tmp.first*(j-i+1);
		ans2-=tmp.second*(j-i+1);
	}
	return p[n/t]=mp(ans1,ans2);
}

int main()
{
	phi[1]=miu[1]=1;
	for(int i=2,tmp;i<=5e6;i++)
	{
		if(!phi[i])pr[++cnt]=i,miu[i]=-1,phi[i]=i-1;
		for(int j=1;j<=cnt&&(tmp=i*pr[j])<=5e6;j++)
		{
			if(i%pr[j]==0)
			{
				phi[tmp]=phi[i]*pr[j],miu[tmp]=0;
				break;
			}
			phi[tmp]=phi[i]*(pr[j]-1),miu[tmp]=-miu[i];
		}
	}
	for(int i=2;i<=5e6;i++)phi[i]+=phi[i-1],miu[i]+=miu[i-1];
	read(T);
	while(T--)
	{
		read(n),memset(p,0,sizeof(p)),ans=solve(n);
		write(ans.first),write(ans.second,1);
	}
	return 0;
}
