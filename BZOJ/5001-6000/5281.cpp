#include<bits/stdc++.h>
using namespace std;
const int MX=255;

int N,W,w[MX],t[MX];
double l=0,r=1e9,mid,v[MX],f[1005],g[1005],tmp;

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline bool check(double k)
{
	for(int i=1;i<=N;i++)v[i]=t[i]-k*w[i];
	for(int i=1;i<=W;i++)f[i]=-1e20;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=W;j++)g[j]=f[j];
		for(int j=0;j<=W;j++)
			g[min(W,j+w[i])]=max(g[min(W,j+w[i])],f[j]+v[i]);
		memcpy(f,g,sizeof(f));
	}
	return f[W]>=0;
}

int main()
{
	read(N),read(W);
	for(int i=1;i<=N;i++)read(w[i]),read(t[i]);
	while(r-l>1e-8)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d",(int)(1000*mid+1e-10));
	return 0;
}
