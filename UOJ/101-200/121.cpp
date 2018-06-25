#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
const int maxn=100005;

int n,k,d,a[maxn][105],b[105],c[105][105],T=5,id[maxn];

inline int solve(int x)
{
	int ans=0;
	if(k==2)for(int i=1;i<=d;i++)ans^=(b[i]&a[x][i]),b[i]^=a[x][i];
	else for(int i=1;i<=d;i++)for(int j=1;j<=d;j++)
		ans+=c[i][j]*a[x][i]*a[x][j],c[i][j]+=a[x][i]*a[x][j];
	return ans%k;
}

int main()
{
	read(n),read(d),read(k),srand(time(NULL));
	for(int i=1;i<=n;i++)id[i]=i;
	for(int i=1;i<=n;i++)for(int j=1;j<=d;j++)read(a[i][j]),a[i][j]%=k;
	while(T--)
	{
		for(int i=2;i<=n;i++)swap(id[i],id[rand()%i+1]);
		if(k==2)memset(b+1,0,d<<2);else memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)if(solve(id[i])!=(i-1)%k)for(int j=1,tmp;j<i;j++)
		{
			tmp=0;
			for(int l=1;l<=d;l++)tmp+=a[id[i]][l]*a[id[j]][l];
			if(tmp%k==0)return printf("%d %d",min(id[i],id[j]),max(id[i],id[j])),0;
		}
	}
	return puts("-1 -1"),0;
}
