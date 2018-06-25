#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N,a[155],pr[40],cnt,d[155],sum,pw[155];
LL ans=1;

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(N);
	if(N==1)
	{
		read(N),puts(N?"0":"1");
		return 0;
	}
	d[1]=1;
	for(int i=2,tmp;i<=N;i++)
	{
		if(!d[i])pr[++cnt]=i,d[i]=i;
		for(int j=1;(tmp=i*pr[j])<=N&&pr[j]<=d[i];j++)
			d[tmp]=pr[j];
	}
	pw[N-2]=1;
	for(int i=1,u;i<=N;i++)
	{
		read(u),pw[u-1]--;
		if(!u)return puts("0"),0;
		sum+=u;
	}
	if(sum!=N*2-2)return puts("0"),0;
	for(int i=N-2;i;i--)pw[i]+=pw[i+1];
	for(int i=N-2;i>1;i--)if(d[i]!=i)
		pw[d[i]]+=pw[i],pw[i/d[i]]+=pw[i],pw[i]=0;
	for(int i=2;i<N;i++)if(pw[i])
		for(int j=1;j<=pw[i];j++)ans*=i;
	printf("%lld",ans);
	return 0;
}
