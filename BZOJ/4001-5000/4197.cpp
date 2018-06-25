#include<bits/stdc++.h>
using namespace std;
const int pr[]={2,3,5,7,11,13,17,19},S=255;

int N,P,f[257][257],g[2][257][257];
long long ans;
struct Number
{
	int S,rem;
	bool operator<(const Number& a)const{return rem<a.rem;}
}q[505];

int main()
{
	scanf("%d%d",&N,&P);
	for(int i=2,x;i<=N;i++)
	{
		x=i;
		for(int j=0;j<8;j++)if(x%pr[j]==0)
		{
			q[i].S|=1<<j;
			while(x%pr[j]==0)x/=pr[j];
		}
		q[i].rem=x;
	}
	sort(q+2,q+N+1),f[0][0]=1;
	for(int i=2;i<=N;i++)
	{
		if(q[i].rem!=q[i-1].rem||q[i].rem==1)
			memcpy(g[0],f,sizeof(f)),memcpy(g[1],f,sizeof(f));
		for(int j=S;~j;j--)for(int k=S;~k;k--)if(!(j&k))
		{
			if(!(q[i].S&k))
				(g[0][q[i].S|j][k]+=g[0][j][k])%=P;
			if(!(q[i].S&j))
				(g[1][j][q[i].S|k]+=g[1][j][k])%=P;
		}
		if(q[i].rem!=q[i+1].rem||q[i].rem==1)
			for(int j=S;~j;j--)for(int k=S;~k;k--)if(!(j&k))
				f[j][k]=((g[0][j][k]+g[1][j][k])%P-f[j][k]+P)%P;
	}
	for(int i=S;~i;i--)for(int j=S;~j;j--)if(!(i&j))ans+=f[i][j];
	printf("%lld\n",ans%P);
	return 0;
}
