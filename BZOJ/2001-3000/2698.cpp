#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;

int N,M,S,T,b;
LL k[maxn];
double p[maxn],ans,res,fin;

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}

int main()
{
	N=read(),M=read(),S=read(),T=read(),fin=N;
	for(int i=S;i<=T;i++)  k[i]=(LL)(i-S+1)*(1+(i-S)/2.0);
	for(int i=T+1;i<=N;i++)  k[i]=(LL)(T-S+1)*(i+1-(T+S)/2.0);
	for(int i=1;i<=N;i++)
	{
		p[i]=(double)(k[i-1]+k[N-i])/k[N];
		b=M,ans=1.0,res=p[i];
		while(b)
		{
			if(b&1)  ans=ans*res;
			res=res*res;
			b>>=1;
		}
		p[i]=ans;
	}
	for(int i=1;i<=N;i++)  fin-=p[i];
	printf("%.3lf",fin);
	return 0;
}
