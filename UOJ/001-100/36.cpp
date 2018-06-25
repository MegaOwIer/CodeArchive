#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int MX=100005;

int N,k;
ULL a[MX];

inline void solve1()
{
	ULL ans=0;
	for(int i=1;i<=N;i++)ans|=a[i];
	printf("%llu",ans>>1);
	puts(ans&1?".5":"");
}
inline void solve2()
{
	bool flag;
	ULL ans=0,res=0,tmp=0;
	for(int i=1;i<=N;i++)tmp|=a[i];
	for(int i=32;~i;i--)if(tmp>>i&1)
		for(int j=32;~j;j--)if(tmp>>j&1)
		{
			flag=0;
			for(int k=1;k<=N;k++)if((a[k]>>i&1)!=(a[k]>>j&1))
				{flag=1;break;}
			if(i+j-1-flag<0)res++;
			else ans+=1ULL<<(i+j-1-flag);
		}
	printf("%llu",ans+(res>>1));
	puts(res&1?".5":"");
}
inline void solve3()
{
	int cnt=0;
	ULL g[25],tmp[25];
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=N;i++)for(int j=22;~j;j--)if(a[i]>>j&1)
		if(tmp[j])a[i]^=tmp[j];
		else
		{
			g[cnt++]=tmp[j]=a[i];
			break;
		}
	ULL ans=0,res=0,val,a,b;
	for(int i=0;i<(1<<cnt);i++)
	{
		val=0,a=0,b=1;
		for(int j=0;j<cnt;j++)if(i>>j&1)val^=g[j];
		for(int j=0;j<k;j++)
			a*=val,b*=val,a+=b>>cnt,b&=(1<<cnt)-1;
		ans+=a,res+=b;
		ans+=res>>cnt,res&=(1<<cnt)-1;
	}
	printf("%llu",ans);
	puts(res?".5":"");
}

int main()
{
	scanf("%d%d",&N,&k);
	for(int i=1;i<=N;i++)scanf("%llu",a+i);
	if(k==1)solve1();
	else if(k==2)solve2();
	else solve3();
	return 0;
}
