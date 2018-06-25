#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;

int n,k,q[maxn],h,t,cnt;
LL f[maxn],g[maxn],a[maxn];
char c;

template<typename T>
inline void read(T& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline double getk(int j,int k){return (double)(a[k]*a[k]-a[j]*a[j]+g[j]-g[k])/(a[k]-a[j]);}

int main()
{
	read(n),read(k);
	for(int i=1,u;i<=n;i++)
	{
		read(u);
		if(u)a[++cnt]=u+a[cnt-1];
	}
	n=cnt;
	for(int i=1;i<=k;i++)
	{
		h=1,t=0;
		for(int j=i;j<=n;j++)
		{
			while(h<t&&getk(q[t-1],q[t])>getk(q[t],j-1))t--;
			q[++t]=j-1;
			while(h<t&&getk(q[h],q[h+1])<a[j])h++;
			f[j]=g[q[h]]+(a[j]-a[q[h]])*a[q[h]];
		}
		swap(f,g);
	}
	printf("%lld",g[n]);
	return 0;
}
