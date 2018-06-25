#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int q,step;
LL n,x,a[70],mod[70],res[70],ans,st;
bool f[70],g[70];

int main()
{
	scanf("%lld%d",&n,&q);
	a[0]=n,mod[0]=res[0]=1;
	for(int i=1;a[i-1];i++)
	{
		f[i]=g[i-1]^1;
		if(f[i])a[i]=a[i-1]/2;
		else a[i]=a[i-1]-a[i-1]/2;
		if(a[i-1]&1)g[i]=f[i];
		else g[i]=f[i]^1;
		mod[i]=mod[i-1]<<1;
		if(!f[i])res[i]=res[i-1];
		else res[i]=res[i-1]+mod[i-1];
		res[i]%=mod[i];
		if(!res[i])res[i]=mod[i];
	}
	while(q--)
	{
		scanf("%lld",&x);
		step=0;
		while(mod[step]&&(x-res[step])%mod[step]==0)step++;
		if(!mod[step])
		{
		    printf("%lld\n",n);
		    continue;
		}
		step--;
		ans=n-a[step];
		st=f[step+1]?res[step]:res[step]+mod[step];
		step++;
		printf("%lld\n",ans+(x-st)/mod[step]+1);
	}
	return 0;
}
