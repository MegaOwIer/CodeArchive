#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=50005;

int T,pr[5135],cnt,miu[MX],d[MX],S[MX],N,M;
LL ans;

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	miu[1]=1;
	for(int i=2,tmp;i<=50000;i++)
	{
		if(!d[i])pr[++cnt]=i,miu[i]=-1,d[i]=i;
		for(int j=1;pr[j]<=d[i]&&(tmp=i*pr[j])<=50000;j++)
		{
			d[tmp]=pr[j],miu[tmp]=-miu[i];
			if(d[i]==pr[j]){miu[tmp]=0;break;}
		}
	}
	cerr<<cnt<<endl;
	for(int i=2;i<=50000;i++)miu[i]+=miu[i-1];
	for(int i=1;i<=50000;i++)for(int j=1,pos;j<=i;j=pos+1)
		pos=i/(i/j),S[i]+=(LL)(i/j)*(pos-j+1);
	read(T);
	while(T--)
	{
		read(N),read(M),ans=0;
		if(N>M)swap(N,M);
		for(int i=1,pos;i<=N;i=pos+1)
		{
			pos=min(N/(N/i),M/(M/i));
			ans+=(LL)(miu[pos]-miu[i-1])*S[N/i]*S[M/i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
