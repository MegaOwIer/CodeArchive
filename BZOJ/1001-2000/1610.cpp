#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
const double eps=1e-8;

int n,f,x[maxn],y[maxn],cnt,ans;
double k[19900];
char c;
bool flag;

inline void read(int& x)
{
	x=0,c=getchar(),f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-48,c=getchar();x*=f;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(x[i]),read(y[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++)
	{
		if(x[i]==x[j])flag=1;
		else k[++cnt]=(double)(y[i]-y[j])/(x[i]-x[j]);
	}
	sort(k+1,k+cnt+1);
	for(int i=1;i<=cnt;i++)if(fabs(k[i]-k[i+1])>eps)ans++;
	printf("%d",ans+flag);
	return 0;
}
