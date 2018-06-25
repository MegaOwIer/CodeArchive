#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;

int T,n;
double p,q,f[1005],g[1005];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lf%lf",&n,&p,&q);  if(n>1000)  n=1000;
		f[0]=0,g[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(f[i-1]>g[i-1])  p=1-p,q=1-q;
			f[i]=(p*g[i-1]+(1-p)*q*f[i-1])/(1-(1-p)*(1-q));
            g[i]=(q*f[i-1]+(1-q)*p*g[i-1])/(1-(1-p)*(1-q));
			if(f[i-1]>g[i-1])  p=1-p,q=1-q;
		}
		printf("%.6lf\n",f[n]);
	}
	return 0;
}
