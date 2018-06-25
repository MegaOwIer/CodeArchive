#include<bits/stdc++.h>
using namespace std;
const int MX=20000050;

int p[MX],seed,N,k,S,sum[MX],POOL[MX],*BR=POOL+10000010,a0,a1,a2;

inline int getrand(){return seed=((seed*12321)^9999)&32767;}
void generateData()
{
	int t=0,i;
	scanf("%d%d%d",&k,&seed,&S);
	N=k*2+1;
	for(i=1;i<=N;i++)p[i]=(getrand()>>7)&1,t += p[i];
	i=1;
	while(t>k)
	{
		while(!p[i])i++;
		p[i]=0,t--;
	}
	while(t<k)
	{
		while(p[i])i++;
		p[i]=1,t++;
	}
}

int main()
{
	generateData();
	for(int i=1;i<=N;i++)
		if(p[i])sum[i]=sum[i-1]+1,BR[sum[i]]++;
		else sum[i]=sum[i-1]-1;
	for(int i=k+1;i>=-k-1;i--)BR[i]+=BR[i+1];
	for(int i=1;i<=N;i++)
		if(p[i])BR[sum[i]]--;
		else
		{
			if(!BR[sum[i]+1])a0=i;
			if(BR[sum[i]+1]==S)a1=i;
		}
	memset(POOL,0,sizeof(POOL));
	for(int i=1;i<=N;i++)
		if(p[i])sum[i]=sum[i-1]-1;
		else sum[i]=sum[i-1]+1,BR[sum[i]]++;
	for(int i=k+1;i>=-k-1;i--)BR[i]+=BR[i+1];
	for(int i=1;i<=N;i++)if(!p[i])
	{
		if(BR[sum[i]+1]==S)a2=i;
		BR[sum[i]+1]++;
	}
	cout<<a0<<endl<<a1<<endl<<a2<<endl;
	return 0;
}
